#include "../../Headers/Pieces/Rook.hpp"

/**
 * Our beloved constructor
 * 
 */
Rook::Rook(std::string suit, int x, int y)
:Piece(suit, suit+"Rook", suit.substr(0,1)+"R", x, y)
{

}

/**
 * Destructor
 * 
 */
Rook::~Rook()
{

}

/**
 * Moves the piece as it should be moved, provided its nature and behavior.
 * 
 */
bool Rook::isMoveValid(Square* square)
{

}