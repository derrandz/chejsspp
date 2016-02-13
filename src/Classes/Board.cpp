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
	/**
	 * 
	 * i takes care of the y coordinates.
	 * j takes care of the x coordinates.
	 * 
	 */
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
	/**
	 * Black pieces
	 */
	this->pieces[0][0] = new Piece("black", "blackRookLeft", "bRl", 0, 0);
	this->pieces[0][1] = new Piece("black", "blackKnightLeft", "bNl", 80, 0);
	this->pieces[0][2] = new Piece("black", "blackBishopLeft", "bBl", 80*2, 0);
	this->pieces[0][3] = new Piece("black", "blackKing", "bK", 80*3, 0);
	this->pieces[0][4] = new Piece("black", "blackQueen", "bQ", 80*4, 0);
	this->pieces[0][5] = new Piece("black", "blackBishopRight", "bBr", 80*5, 0);
	this->pieces[0][6] = new Piece("black", "blackKnightRight", "bNr", 80*6, 0);
	this->pieces[0][7] = new Piece("black", "blackRookRight", "bRr", 80*7, 0);

	for (int i = 8; i < 16; i++)
	{
		this->pieces[0][i] = new Piece("black", "blackPion", "bP", 0, 0);
	}

	/**
	 * White pieces
	 *
	 * The coordinates that are supplied to these pieces don't matter.
	 * 
	 */
	this->pieces[1][0] = new Piece("white", "whiteRookLeft", "wRl", 0, 0);
	this->pieces[1][1] = new Piece("white", "whiteKnightLeft", "wNl", 0, 0);
	this->pieces[1][2] = new Piece("white", "whiteBishopLeft", "wBl", 0, 0);
	this->pieces[1][3] = new Piece("white", "whiteKing", "wK", 0, 0);
	this->pieces[1][4] = new Piece("white", "whiteQueen", "wQ", 0, 0);
	this->pieces[1][5] = new Piece("white", "whiteBishopRight", "wBr", 0, 0);
	this->pieces[1][6] = new Piece("white", "whiteKnightRight", "wNr", 0, 0);
	this->pieces[1][7] = new Piece("white", "whiteRookRight", "wRr", 0, 0);

	for (int i = 8; i < 16; i++)
	{
		this->pieces[1][i] = new Piece("white", "whitePion", "wP", 80*(i/8), 80);
	}
	
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 16; j++)
		{
			if( !this->pieces[i][j])
			{
				throw 0;
			}	
			else
			{
				this->pieces[i][j]->loadMedia();
			}
		}
	}	

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

	/**
	 * Black pieces
	 */
	for (int i = 0; i < 8; i++)
	{
		this->loadPieceAtSquare( this->squares[0][i] , this->pieces[0][i] );
	}

	for (int i = 0, j = 8; i < 8; i++, j++)
	{
		this->loadPieceAtSquare( this->squares[1][i] , this->pieces[0][j] );
	}

	/**
	 * White pieces
	 */
	for (int i = 0; i < 8; i++)
	{
		this->loadPieceAtSquare( this->squares[7][i] , this->pieces[1][i] );
	}

	for (int i = 0, j = 8; i < 8; i++, j++)
	{
		this->loadPieceAtSquare( this->squares[6][i] , this->pieces[1][j] );
	}

	return true;
}

/**
 * Renders the board's squares.
 * 
 */
void Board::renderSquares()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			this->squares[i][j]->render();
		}
	}
}

/**
 * Renders the board's pieces.
 * 
 */
void Board::renderPieces()
{
	// if(this->isPieceMoving())
	// {
	// 	for (int i = 0; i < 2; ++i)
	// 	{
	// 		for (int j = 0; j < 16; ++j)
	// 		{
	// 			if( this->pieces[i][j]->code.compare(this->getMovingPiece().code) != 0 )
	// 			{
	// 				this->pieces[i][j]->render();
	// 			}
	// 		}

	// 		this->getMovingPiece().render();
	// 	}
	// }
	// else
	// {
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 16; ++j)
			{
				this->pieces[i][j]->render();
			}
		}	
	// }
	
}

void Board::render()
{
	this->renderSquares();
	this->renderPieces();
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
			else
			{
				Square* square = &piece->getCurrentSquare();
				piece->assignSquare(square);
				std::cout << "\n Failed to locate the square." << std::endl;
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
	if(x >= 0 && x < 640 /2)
	{
		if( y >= 0 && y < 640 /2)
		{
			/**
			 * This represents the top left side of the board.
			 */
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
		else if( y >= 640 /2 && y < 640)
		{
			/**
			 * This represents the bottom left side of the board.
			 */
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
	else if( x >= 640 / 2 && x < 640)
	{
		if( y >= 0 && y < 640 /2)
		{
			/**
			 * This represents the top right side of the board.
			 */
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
		else if( y >= 640 /2 && y < 640)
		{
			/**
			 * This represents the bottom right side of the board.
			 */
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
