#include "entities/AbstractBoardEntity.hpp"
#include "helpers/HelperFunctions.hpp"

/**
 | =====================================================
 | The abstract class that represents a board, with bits.
 |
 */

/**
 * Ranks
 * 
 */

const long AbstractBoardEntity::ranks[8] = 
{
		-72057594037927936, // RANK 1
		71776119061217280, // RANK 2
		280375465082880, // RANK 3
		1095216660480, // RANK 4
		4278190080, // RANK 5
		16711680, // RANK 6
		65280, // RANK 7
		255 // RANK 8
};

/**
 * Keeps track of the last capturing element and the position he captured
 * As to remove the capture piece from its motherboard.
 * 
 */
std::pair<std::string, long> AbstractBoardEntity::captures_history_utility = std::make_pair(" ", 0L);

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
bool AbstractBoardEntity::isMoveValid(long move, long fullboard)
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
void AbstractBoardEntity::alterBoard(bool isInitLoad, long fullboard, std::string& binaryString)
{
	long alteredBitboard = HelperFunctions::convertStringToBitBoard(binaryString);

	if(!isInitLoad)
	{
		if(this->isMoveValid(alteredBitboard, fullboard))
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
void AbstractBoardEntity::saveCaptureHistory(std::string capturing_board, long new_move)
{
	AbstractBoardEntity::captures_history_utility.first  = capturing_board;
	AbstractBoardEntity::captures_history_utility.second = new_move;
}

/**
 * Returns the capture history
 * 
 */
std::pair<std::string,long> AbstractBoardEntity::getCaptureHistory()
{
	return AbstractBoardEntity::captures_history_utility;
}

/**
 * Forgets the capture history
 * 
 */
void AbstractBoardEntity::forgetCaptureHistory()
{
	AbstractBoardEntity::captures_history_utility.first  = " ";
	AbstractBoardEntity::captures_history_utility.second = 0L;
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
