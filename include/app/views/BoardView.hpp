#ifndef _BOARD_VIEW_H_INCLUDED_
#define _BOARD_VIEW_H_INCLUDED_

#include "views/View.hpp"
#include "views/SquareView.hpp"
#include "views/PieceView.hpp"
#include <map>
#include <vector>

class PieceView;

typedef std::map<std::string, std::vector<PieceView*>>::iterator pieces_it;

class BoardView : public View
{
	/*
	 |****************************
	 |
	 |		Attributes
	 |
	 |****************************
	 */
	protected:
		/**
		 * A board has two type of squares, black and white, and they are views as well.
		 * 
		 */
		SquareView** squares;

		/**
		 * The board's pieces in place.
		 * 
		 */
		PieceView*** pieces;

		/**
		 * The piece that is being currently moved.
		 * 
		 */
		PieceView* activePiece;

		/**
		 * Active piece's old place in the board.
		 * 
		 */
		int* activePieceCoordinates;
		
		/**
		 * Main player's color.
		 * 
		 */
		bool mainPlayerColor;

		/**
		 * Indicates whether you have the right to move a piece.
		 * 
		 */
		bool isMyTurn;	
	public:
		/**
		 * The board's graphical representation in strings.
		 * 
		 */
		std::string boardConfiguration[8][8]; 

	/*
	 |****************************
	 |
	 |		Methodes
	 |
	 |****************************
	 */
	protected:
		/**
		 * Initializes the squares.
		 * 
		 */
		bool initSquares();
		
		/**
		 * Initializes the squares.
		 * 
		 */
		bool initPieces();

		/**
		 * Initializes the squares.
		 * 
		 */
		void renderSquares();
		
		/**
		 * Initializes the squares.
		 * 
		 */
		void renderPieces();

		/**
		 * Initializes the BoardView with all the needed component views.
		 * @return boolean
		 * 
		 */
		bool init();

		/**
		 * Handles the click event.
		 * @param e the SDL_Event object
		 * 
		 */
		void handleClickEvent(SDL_Event& e);

		/**
		 * Self-descriptive
		 * @param PieceView*
		 * 
		 */
		void registerMovingPiece(PieceView*);

		/**
		 * Self-descriptive
		 * @param PieceView*
		 * 
		 */
		void forgetMovingPiece();

		/**
		 * Self-descriptive
		 * @return [description]
		 * 
		 */
		PieceView* getMovingPiece();

		/**
		 * Self-descriptive.
		 * @return boolean
		 * 
		 */
		bool isThereAMovingPiece();

		/**
		 * Gets the piece that is holding the square at (x, y) coordinates.
		 * @return [description]
		 * 
		 */
		PieceView* getPieceAt(int& x, int& y);

		/**
		 * Returns the exact coordinates of the square that collides with the provided coordinates.
		 * @param  x int
		 * @param  y int
		 * @return   int* : array
		 */
		int* getSquareAt(int& x, int& y);

		/**
		 * Puts the moving piece in the host square, in the screen and also in the boardConfiguration array.
		 * @param x int
		 * @param y int
		 * 
		 */
		void bindMovingPieceToSquare(int& x, int& y);

		/**
		 * Binds the moving piece to its old position, in the screen and also in the boardCOnfiguration array.
		 * 
		 */
		void bindMovingPieceToPreviousPosition();

		/**
		 * Updates thep pieces from the boardConfiguration
		 * 
		 */
		void updatePieces();

		/**
		 * Destructs the pieces array and reinitializes it with NULL;
		 * 
		 */
		void destructPieces();

	public:

		/**
		 * Returns the main players' color.
		 * @return bool
		 * 
		 */
		bool getMainPlayerColor();

		/**
		 * Loads a provided configuration.
		 * @param bool
		 * @param std::string**
		 * 
		 */
		void loadBoard(bool, std::string**);

		/**
		 * Constructor
		 * 
		 */
		BoardView(bool mainPlayerColor, std::string**);
		
		/**
		 * Destructor
		 * 
		 */
		~BoardView();

		/**
		 * Renders the actual view to the screen.
		 * 
		 */
		void render();

		/**
		 * Handles the events related to this view, keyboard and mouse events.
		 * @param e SDL_Event
		 * 
		 */
		void handleEvents(SDL_Event& e);

		/**
		 * Draws the board, for debugging purposes.
		 * 
		 */
		void drawBoard();
	
		/**
		 * Using the isMyTurn variable, we determine if the board is in a 'lisetning' state to receive the board of the other side,
		 * @return bool
		 * 
		 */
		bool isReceiving();

		/**
		 * Returns the board in an 8*8 strings array, and each index, there should be either an empty string, or a string representing a piece, such as "wP" for white pawn
		 * @return std::string[] : Array of strings.
		 * 
		 */
		// std::string[][] getBoardConfiguration();

};

#endif // _BOARD_VIEW_H_INCLUDED_