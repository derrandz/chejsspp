#include "../../Headers/Pieces/Bishop.hpp"

/**
 * Our beloved constructor
 * 
 */
Bishop::Bishop(std::string suit, int x, int y)
:Piece(suit, suit+"Bishop", suit.substr(0,1)+"B", x, y)
{
	/* code */
}

/**
 * Destructor
 * 
 */
Bishop::~Bishop()
{
	
}

/**
 * Moves the piece as it should be moved, provided its nature and behavior.
 * 
 */
bool Bishop::isMoveValid(Square* square)
{
	return true;
}