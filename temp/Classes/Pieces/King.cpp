#include "../../Headers/Pieces/King.hpp"

/**
 * Our beloved constructor
 * 
 */
King::King(std::string suit, int x, int y)
:Piece(suit, suit+"King", suit.substr(0,1)+"K", x, y)
{
	/* code */
}

/**
 * Destructor
 * 
 */
King::~King()
{
	/* code */
}

/**
 * Moves the piece as it should be moved, provided its nature and behavior.
 * 
 */
bool King::isMoveValid(Square* square)
{
	return true;
}