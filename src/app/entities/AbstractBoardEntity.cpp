#include "entities/AbstractBoardEntity.hpp"
#include "helpers/HelperFunctions.hpp"

/**
 | =====================================================
 | The abstract class that represents a board, with bits.
 |
 */

/**
 * Diagonals
 * 
 */
const long AbstractBoardEntity::right_diagonals[15] = 
{
	// 1, //white
	// 258, //black
	// 66052,//white
	// 16909320,//black
	// 4328785936,//white
	// 1108169199648,//black
	// 283691315109952,//white
	// 72624976668147840,//black
	// 145249953336295424,//white
	// 290499906672525312,//black
	// 580999813328273408,//white
	// 1161999622361579520,//black
	// 2323998145211531264,//white
	// 4647714815446351872,//black
	// 9223372036854775808//white
	1,
	1,
	1,
	1,
	
	1,
	1,
	1,
	1,

	1,
	1,
	1,
	1,
	1,
	1,
	1,


};

const long AbstractBoardEntity::left_diagonals[15] = 
{
	// 128,//black
	// 32832,//white
	// 8405024,//black
	// 2151686160,//white
	// 550831656968,//black
	// 141012904183812,//white
	// 36099303471055874,//black
	// -9205322385119247871,//white
	// 4620710844295151872,//black
	// 2310355422147575808,//white
	// 1155177711073755136,//black
	// 577588855528488960,//white
	// 288794425616760832,//black
	// 144396663052566528,//white
	// 72057594037927936//black

	1,
	1,
	1,
	1,
	
	1,
	1,
	1,
	1,

	1,
	1,
	1,
	1,
	1,
	1,
	1,
};



/**
 * Ranks
 * 
 */
const long AbstractBoardEntity::ranks[8] = 
{
		// 255, // RANK 1
		// 65280, // RANK 2
		// 16711680, // RANK 3
		// 4278190080, // RANK 4
		// 1095216660480, // RANK 5
		// 280375465082880, // RANK 6
		// 71776119061217280, // RANK 7
		// -72057594037927936 // RANK 8 

	1,
	1,
	1,
	1,
	
	1,
	1,
	1,
	1,
};

/**
 * Files
 * 
 */
const long AbstractBoardEntity::files_array[8] =
{
	// -9187201950435737472, //file_a 
	// 4629771061636907072,  //file_b 
	// 2314885530818453536,  //file_c
	// 1157442765409226768,  //file_d
	// 578721382704613384,   //file_e
	// 289360691352306692,   //file_f
	// 144680345676153346,   //file_g 
	// 72340172838076673    //file_h
		1,
	1,
	1,
	1,
	
	1,
	1,
	1,
	1,
};


/**
 * Keeps track of the last capturing element and the position he captured
 * As to remove the capture piece from its motherboard.
 * 
 */
std::tuple<std::string, bool, long> AbstractBoardEntity::captures_history_utility = std::make_tuple(" ", false, 0L);

/**
 * Loads a bitboard without verification.
 * @param long [description]
 * 
 */
void AbstractBoardEntity::loadbitboard(long bitboard)
{
	this->bitRepresentation = bitboard;
}

std::string AbstractBoardEntity::getName()
{
	return this->name;
}

/**
 * Determines whether the new position is already occupied by other pieces.
 * @param  newposition [description]
 * @param  fullboard   [description]
 * @return             [description]
 * 
 */
bool AbstractBoardEntity::isBoardIsEmptyAt(long newPosition, long fullboard)
{
	return (fullboard & newPosition) == 0;
}

/**
 * Extract the diff between the new and old board.
 * @param  newboard [description]
 * @return          [description]
 * 
 */
long AbstractBoardEntity::extractNewMove(long newboard)
{
	return (this->bitRepresentation | newboard)^this->bitRepresentation;
}

/**
 * Returns the bitboard in which the old position of the sliding piece figures as a 1.
 * @param  newboard [description]
 * @return          [description]
 * 
 */
long AbstractBoardEntity::extractOldPosition(long newboard)
{
	return (this->bitRepresentation | newboard)^newboard;
}

/**
 * Takes the binary string, converts it and stores it to the bitrepresentation member.
 * @param std::string&
 * 
 */
void AbstractBoardEntity::binaryString_toBitboard(std::string&)
{

}

/**
 * Judges the new move as valid or invalid.
 * @param  long : the new board's configuration that represents the new move.
 * @return bool : true upon valid.
 *  
 */
bool AbstractBoardEntity::isMoveValid(long move, long fullboard, long myFriendsBoard)
{
	std::cout << "AbstractBoardEntity::isMoveValid is being called" << std::endl;
	return true;
}


/**
 * Constructor and destructor
 * 
 */
AbstractBoardEntity::AbstractBoardEntity(bool suitColor, std::string name)
{
	this->bitRepresentation = 0L;
	this->name              = name;
	this->suitColor         = suitColor;
}

AbstractBoardEntity::~AbstractBoardEntity()
{

}

/**
 * Alters the positions at this board.
 * 
 */
void AbstractBoardEntity::alterBoard(bool isInitLoad, long fullboard, long myFriendsBoard, std::string& binaryString)
{
	long alteredBitboard = HelperFunctions::convertStringToBitBoard(binaryString);

	if(!isInitLoad)
	{
		if(this->isMoveValid(alteredBitboard, fullboard, myFriendsBoard))
		{
			this->bitRepresentation = alteredBitboard;
		}
	}
	else
	{
		this->bitRepresentation = alteredBitboard;
	}
}

/**
 * Returns the bit representation of the board.
 * @return long
 * 
 */
long AbstractBoardEntity::getBitBoard()
{
	return this->bitRepresentation;
}


/**
 * Returns the capture history
 * 
 */
void AbstractBoardEntity::saveCaptureHistory(std::string capturing_board, bool suitColor, long new_move)
{
	std::get<0>(AbstractBoardEntity::captures_history_utility) = capturing_board;
	std::get<1>(AbstractBoardEntity::captures_history_utility) = suitColor;
	std::get<2>(AbstractBoardEntity::captures_history_utility) = new_move;
}

/**
 * Returns the capture history
 * 
 */
std::tuple<std::string, bool,long> AbstractBoardEntity::getCaptureHistory()
{
	return AbstractBoardEntity::captures_history_utility;
}

/**
 * Forgets the capture history
 * 
 */
void AbstractBoardEntity::forgetCaptureHistory()
{
	std::get<0>(AbstractBoardEntity::captures_history_utility) = " ";
	std::get<1>(AbstractBoardEntity::captures_history_utility) = false;
	std::get<2>(AbstractBoardEntity::captures_history_utility) = 0L;
}

/**
 * Returns the distance between the two positions.
 * @param  oldPosition [description]
 * @param  newPosition [description]
 * @return             [description]
 * 
 */
int AbstractBoardEntity::getDistance(long oldPosition, long newPosition)
{
	return this->getPositionOfBit(newPosition) - this->getPositionOfBit(oldPosition);
}


/**
 * Returns the distance between the two positions.
 * @param  oldPosition [description]
 * @param  newPosition [description]
 * @return             [description]
 * 
 */
int AbstractBoardEntity::getPositionOfBit(long position)
{
	long tmp;

	for (int i = 1, tmp = 0L; i <= 64; ++i)
	{
		tmp = position>>i;

		if(tmp == 1)
			return i+1;
	}

	return -1;
}

/**
 * Returns the suitcolor
 * @return [description]
 * 
 */
bool AbstractBoardEntity::getSuitColor()
{
	return this->suitColor;
}

/**
 * Tells whether the targeted position is of the enemy or of the friends.
 * @param  myFriendsBoard [description]
 * @param  targetPosition [description]
 * @return                [description]
 * 
 */
bool AbstractBoardEntity::isCaptureLegal(long myFriendsBoard, long targetPosition)
{
	// std::cout << "Friends" << std::endl;
	// HelperFunctions::drawArrayBoardFromBitBoard(myFriendsBoard);
	// std::cout << "Target Position" << std::endl;
	// HelperFunctions::drawArrayBoardFromBitBoard(targetPosition);

	// std::cout << "Target Position & myFriendsBoard" << std::endl;
	// HelperFunctions::drawArrayBoardFromBitBoard(targetPosition&myFriendsBoard);

	// std::cout << "(Target Position & myFriendsBoard)^targetPosition" << std::endl;
	// HelperFunctions::drawArrayBoardFromBitBoard((targetPosition&myFriendsBoard)^targetPosition);
	long no_name = targetPosition&myFriendsBoard;
		 no_name ^= targetPosition;

	if(no_name == targetPosition) return true;
	else return false;
}	 