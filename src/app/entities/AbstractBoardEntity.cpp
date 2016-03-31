#include "entities/AbstractBoardEntity.hpp"
#include "helpers/HelperFunctions.hpp"

/**
 | =====================================================
 | The abstract class that represents a board, with bits.
 |
 */


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
AbstractBoardEntity::AbstractBoardEntity(bool suitColor)
{
	this->suitColor = suitColor;
	this->bitRepresentation = 0L;
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