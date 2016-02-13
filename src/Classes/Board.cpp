#include "../Headers/Board.hpp"

const int boardHeight = 640;
const int boardWidth = 640;
const int squareHeight = 80;
const int squareWidth = 80;

/**
 * Singleton Instance
 */
Board* Board::SingleInstance = NULL;

/**
 * Cosntructors
 *
 */
Board::Board()
{
	this->gameStatus = false;
	this->winner = " ";
	this->currentlyMovingPiece = NULL;
	Board::SingleInstance = this;
}

/**
 * Destructor
 * 
 */
Board::~Board()
{
	// free();
}

/**
 * Initializes the squares with the right suites and positions
 * 
 * @return boolean
 */
bool Board::initSquares()
{
	for (int i = 0, turn = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(turn == 0)
			{
				this->squares[i][j] = new Square("white", squareHeight, squareWidth, squareWidth*j, squareHeight*i);
				turn = 1;
			}
			else if(turn == 1)
			{
				this->squares[i][j] = new Square("black", squareHeight, squareWidth, squareWidth*j, squareHeight*i);
				turn = 0;
			}

			// Checking whether the init went okay.
			if( !this->squares[i][j] )
			{
				throw 0;
			}
			else
			{
				try
				{
					this->squares[i][j]->loadMedia();
				}
				catch(int e)
				{
					std::cout << "Initialized square but failed to load media.\n";
				}
			}
		}

		if(turn == 0)
		{
			turn = 1;
		}
		else if(turn == 1)
		{
			turn = 0;
		}
	}

	std::cout << "All squares have been successfully initialized.\n";
	return true;
}

/**
 * Initializes the pieces into their right positions
 * 
 * @return boolean
 */
bool Board::initPieces()
{
	this->pieces[0][0] = new Piece("Black", "blackBishop", "bB", 0, 0);
	this->pieces[0][1] = new Piece("Black1", "blackBishop1", "bB1", 160, 0);
	
	if( !this->pieces[0][0] && !this->pieces[0][1])
	{
		throw 0;
	}	
	else
	{
		this->pieces[0][0]->loadMedia();
		this->pieces[0][1]->loadMedia();
	}	
	/*
	// White pieces
	for (int i = 0; i < 16; ++i)
	{
		this->pieces[0][i] = new Piece();
	}

	// Black pieces
	for (i = 0; i < 16; ++i)
	{
		this->pieces[1][i] = new Piece();
	}
	*/

	std::cout << "All pieces have been successfully initialized.\n";

	return true;
}

/**
 * Loads a piece into a certain square.
 *
 */
void Board::loadPieceAtSquare(Square* square, Piece* piece)
{
	square->assignPiece(piece);
	piece->assignSquare(square);
}

/**
 * Initializes the board with its squares and pieces.
 * 
 * @return boolean
 */
bool Board::init()
{
	//Initializes the board with squares and pieces
	
	try
	{
		this->initSquares();
	}
	catch (int e) //Will eventually be replaced with real exceptions
	{ 
		std::cout << "\nCould not initialize the squares";
	}

	
	try
	{
		this->initPieces();
	}
	catch (int e) //Will eventually be replaced with real exceptions
	{ 
		std::cout << "\nCould not initialize the pieces";
	}

	this->loadPieceAtSquare( this->squares[0][0] , this->pieces[0][0] );
	this->loadPieceAtSquare( this->squares[0][1] , this->pieces[0][1] );
	return true;
}

void Board::render()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			this->squares[i][j]->render();
		}
	}

	this->pieces[0][0]->render();
	this->pieces[0][1]->render();

	// for (int i = 0; i < 2; ++i)
	// {
	// 	for (int j = 0; j < 16; ++j)
	// 	{
	// 		this->pieces[i][j]->render();
	// 	}
	// }
}

/**
 * Gets the clicked piece "geographically", using a dicotomic approach.
 *
 * @param x: the x coordinate of the mouse cursor
 * @param y: the y coordinate of the mouse cursor
 * @Returns bool : If it eventually realizes that a piece has been clicked, it returns true.
 */
bool Board::getClickedPiece(int x, int y)
{

	Square* square = this->find(x, y);

	if(square != NULL)
	{
		if(square->hasPiece())
		{
			Piece* piece = &(square->getOccupyingPiece());

			if(piece->collidesWith(x,y))
			{
				this->bindMovingPiece(*piece);
				return true;
			}
		}
	}
	
	return false;
}

/**
 * Binds the currently moving piece to the attribute
 * 
 */
void Board::bindMovingPiece(Piece& piece)
{
	this->currentlyMovingPiece = &piece;
}

/**
 * Binds the currently moving piece to the attribute
 * 
 */
void Board::unbindMovingPiece()
{
	this->currentlyMovingPiece = NULL;
}

/**
 * Returns the singleton instance
 * 
 */
Board& Board::getInstance()
{
	return *Board::SingleInstance;
}

/**
 * Returns the currently moving piece. Returns null when no piece is moving.
 * 
 */
Piece& Board::getMovingPiece()
{
	return *(this->currentlyMovingPiece);
}

/**
 * Returns the currently moving piece. Returns null when no piece is moving.
 * 
 */
bool Board::isPieceMoving()
{
	return this->currentlyMovingPiece != NULL;
}

/**
 * Handle all events respective to the bord
 * @param e EventObject
 */
void Board::handleEvents(SDL_Event& e)
{
	//Listens to the events and responds accordingly
	
	if(this->isPieceMoving())
	{
		this->getMovingPiece().triggerDraggingEvent();
	}
	else
	{
		if(e.type == SDL_MOUSEBUTTONDOWN)
		{
			std::cout << "\nClick event has been caught.\n\n";
			int x, y;

	        SDL_GetMouseState( &x, &y );

	        if(this->getClickedPiece(x, y))
	        {
	        	std::cout << "The clicked piece has been caught.\n";
	        	this->getMovingPiece().triggerDraggingEvent();
	        	std::cout << "Theoretically, the piece is beeing dragged\n";
	        }
	        else
	        {
	        	std::cout << "Failed to catch the clicked piece.\n";
	        }

		}
	}

	if( e.type == SDL_MOUSEBUTTONUP)
	{
		std::cout << "Click-released event has been caught.\n";

		if(this->isPieceMoving())
		{
			int x, y;
	        
	        SDL_GetMouseState( &x, &y );

			Piece* piece   = &this->getMovingPiece();
			Square* square = this->find(x, y);
			
			if(square != NULL)
			{
				square->assignPiece(piece);
				piece->assignSquare(square);
			}

	       	this->unbindMovingPiece(); 
			std::cout << "The moving piece has been released.\n";
		}
	}
}

/**
 * Finds the square which includes the couple (x, y) in his surface.
 * 
 * @param  x : the x coordinate.
 * @param  y : the y coordinate.
 * @return Returns the found square, otherwise NULL.
 */
Square* Board::find(int x, int y)
{
	if(x >= 0 && x < 1280 /2)
	{
		if( y >= 0 && y < 1280 /2)
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if(this->squares[i][j]->collidesWith(x, y))
					{
						return this->squares[i][j];
					}
				}
			}
		}
		else if( y >= 1280 /2 && y < 1280)
		{
			for (int i = 4; i < 8; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if(this->squares[i][j]->collidesWith(x, y))
					{
						return this->squares[i][j];
					}
				}
			}
		}

	}
	else if( x >= 1280 / 2 && x < 1280)
	{
		if( y >= 0 && y < 1280 /2)
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 4; j < 8; ++j)
				{
					if(this->squares[i][j]->collidesWith(x, y))
					{
						return this->squares[i][j];
					}
				}
			}
		}
		else if( y >= 1280 /2 && y < 1280)
		{
			for (int i = 4; i < 8; ++i)
			{
				for (int j = 4; j < 8; ++j)
				{
					if(this->squares[i][j]->collidesWith(x, y))
					{
						return this->squares[i][j];
					}
				}
			}
		}
	}

	return NULL;
}
