#include "../../Headers/Pieces/Pawn.hpp"

/**
 * Our beloved constructor
 * 
 */
Pawn::Pawn(std::string suit, int x, int y)
:Piece(suit, suit+"Pawn", suit.substr(0,1)+"P", x, y)
{

}

/**
 * Destructor
 * 
 */
Pawn::~Pawn()
{

}

/**
 * Moves the piece as it should be moved, provided its nature and behavior.
 * 
 */
bool Pawn::isMoveValid(Square* square)
{

	if(this->currentSquare == NULL)
	{
		std::cout << "HERE" << std::endl;
		return false;
	}

	if(square != NULL)
	{
		int x, y, newX, newY;

		x = this->currentSquare->getPosition().getBox().x;
		y = this->currentSquare->getPosition().getBox().y;

		newX = square->getPosition().getBox().x;
		newY = square->getPosition().getBox().y;

		if( x == x || (x == newX - 80) || (x == newX + 80) )
		{
			if(y == newY + 80)
			{
				return true;
			}
		}

		return false;
	}

	return false;
}