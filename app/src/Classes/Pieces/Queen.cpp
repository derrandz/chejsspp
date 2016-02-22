#include "../../Headers/Pieces/Queen.hpp";

/**
 * Our beloved constructor
 * 
 */
Queen::Queen(std::string suit, int x, int y)
:Piece(suit, suit+"Queen", suit.substr(0,1)+"Q", x, y)
{
	/* code */
}

/**
 * Destructor
 * 
 */
Queen::~Queen()
{

}

/**
 * Moves the piece as it should be moved, provided its nature and behavior.
 * 
 */
bool Queen::isMoveValid(Square* square)
{

}