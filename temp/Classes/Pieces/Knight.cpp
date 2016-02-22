#include "../../Headers/Pieces/Knight.hpp";

/**
 * Our beloved constructor
 * 
 */
Knight::Knight(std::string suit, int x, int y)
:Piece(suit, suit+"Knight", suit.substr(0,1)+"N", x, y)
{
	/* code */
}

/**
 * Destructor
 * 
 */
Knight::~Knight()
{
	/* code */
}

/**
 * Moves the piece as it should be moved, provided its nature and behavior.
 * 
 */
bool Knight::isMoveValid(Square* square)
{

}