#include "../Headers/Board.hpp"

/**
 * Constructor
 * 
 */
Piece::Piece(std::string suit, std::string name, std::string code, int x, int y):
position((int)squareHeight, (int)squareWidth, (int)x, (int)y)
{
	this->suit          = suit;
	this->name          = name;
	this->code          = code;
	this->suitPath      = "../res/board/pieces/"+this->suit+"/"+ this->code+"_80.png";
	this->currentSquare = NULL;
}

/**
 * Destructor
 * 
 */
Piece::~Piece()
{

}

/**
 * Loads the texture from its source file.
 *
 * @param int
 * @return bool : returns true upon success, and false upon failure
 */
bool Piece::loadTexture()
{
	bool status = false;

	status = this->texture.loadFromFile(this->suitPath);

	if(!status)
	{
		throw 0;
	}
	
	return status;
}

/**
 * Handles the textures loading
 * 
 * @return boolean
 */
bool Piece::loadMedia()
{
	bool status = true;

	try
	{
		status &= this->loadTexture();
	}
	catch(int e)
	{
		std::cout << "Could not load a piece's texture.\n";
	}

	if(!status)
	{
		throw 0;
	}

	return status;
}

/**
 * Renders the square to the screen
 * 
 */
void Piece::render()
{
	int x      = this->position.getBox().x;
	int y      = this->position.getBox().y;

	this->texture.render( x, y, NULL, 0.0, NULL, SDL_FLIP_NONE);
}

/**
 * Returns the current position
 *
 */
Position& Piece::getPosition()
{
	return this->position;
}

/**
 * Returns the current position
 *
 */
Position Piece::getCopyOfPosition()
{
	return this->position;
}

/**
 * Returns the box
 *
 */
SDL_Rect& Piece::getBox()
{
	return this->getPosition().getBox();
}

/**
 * Changes the current position of the piece
 * @param x : the x coordinate
 * @param y : the y coordinate
 */
void Piece::changeBoxPosition(int x, int y)
{
	this->getPosition().getBox().x = x;
	this->getPosition().getBox().y = y;
}

/**
 * Returns the currently occupied square
 * 
 */
Square& Piece::getCurrentSquare()
{
	return *(this->currentSquare);
}

/**
 * Moves the piece to the provided square
 *
 */
Square& Piece::changeSquare(Square& square)
{
	this->position = square.getPosition();
	this->currentSquare = &square;

	return *(this->currentSquare);
}

/**
 * Handles the drag-n-drop event
 * 
 */
bool Piece::handleEvents(SDL_Event& e)
{
	// SDL_Rect& myBox = this->getBox();

	// int x, y;

	// if(dragging)
	// {
 //    	SDL_GetMouseState( &x, &y );
 //        this->changeBoxPosition(x - 160/2, y - 160/2);

 //        if(Square::find(x,y) != NULL)
 //    	{
	//         Square::find(x,y).assignPiece(this);	
 //    	}
 //    	else
 //    	{
 //    		// Assigns the position of the piece to the one it was on previously.
	//         this->changeBoxPosition(this.currentSquare.getBox().x, this.currentSquare.getBox().y);
 //    	}
	// }

	// if( dragging && e.type == SDL_MOUSEBUTTONUP )
 //    {
 //    	dragging = false;
 //       	Board::getInstance().unbindMovingPiece(); 
 //    }

	// if( e.type == SDL_MOUSEBUTTONDOWN || (e.type == SDL_MOUSEMOTION && dragging) )
	// {
 //        SDL_GetMouseState( &x, &y );
	
	// 	bool isPieceClicked_X = ( x > myBox.x ) && (x <= myBox.x + myBox.w);
	// 	bool isPieceClicked_Y = ( y >= myBox.y ) && (y <= myBox.y + myBox.h );

	// 	bool isPieceClicked =  isPieceClicked_X && isPieceClicked_Y;

	// 	if(isPieceClicked)
	// 	{
	// 		dragging = true;
	// 	}
	   	
	//    	Board::getInstance().bindMovingPiece(*this); 
	// }
}

/**
 * Triggers the dragging event
 */
void Piece::triggerDraggingEvent()
{
	int x, y;
	SDL_GetMouseState( &x, &y );
	this->changeBoxPosition(x -80/2, y-80/2);
}

/**
 * Tells whether a couple (x, y) coordinates collides with this piece's box.
 * 
 */
bool Piece::collidesWith(int x, int y)
{
	SDL_Rect& myBox = this->getBox();

	bool isPieceClicked_X = ( x > myBox.x ) && (x <= myBox.x + myBox.w);
	bool isPieceClicked_Y = ( y >= myBox.y ) && (y <= myBox.y + myBox.h );

	return isPieceClicked_X && isPieceClicked_Y;
}

/**
 * Moves the piece as it should be moved, provided its nature and behavior.
 * This method is going to be overriden for each piece type.
 * 
 */
bool Piece::isMoveValid(Square* square)
{
	if(square != NULL)
	{
		return true;
	}
}

/**
 * Assigns to this piece the current square.
 * 
 */
void Piece::assignSquare(Square* square, int load)
{
	if(square != NULL)
	{
		if(load)
		{
			this->currentSquare = square;
			this->position = this->currentSquare->getPosition();
		}
		else
		{
			if(this->isMoveValid(square))
			{
				this->currentSquare = square;
				this->position = square->getPosition();	
			}
			else
			{
				this->position = this->currentSquare->getPosition();
			}
		}
	}
}