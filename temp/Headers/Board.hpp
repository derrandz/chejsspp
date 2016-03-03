#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "Piece.hpp"

class Board
{
	/*
	 |****************************
	 |
	 |		Attributes
	 |
	 |****************************
	 */
	private:
		/**
		 * The single static board instance that gives this class its singleton design pattern behavior
		 * 
		 */
		static Board* SingleInstance;

		/**
		 * Has the game ended, or not
		 *
		 * True for ended, false for not.
		 * 
		 */
		bool gameStatus;

		/**
		 * The winning side: black or white
		 *
		 * While the game is still going, this attribute shall hold the value NULL
		 * 
		 */
		std::string winner;

		/**
		 * The white and black squares that fill up the board
		 * 
		 */
		Square *squares[8][8];
		
		/**
		 * The polymorphic pointer array that holds up all the pieces in the play
		 * The first row is for white pieces
		 * The Second row is for black pieces
		 */
		Piece *pieces[2][16];

		/**
		 * The board array representation.
		 * 
		 */
		std::string board[8][8];
		/**
		 * The piece that is being currently dragged.
		 * 
		 */
		Piece* currentlyMovingPiece;

		//Will possibily add a configuration file as an attribute
		

	/*
	 |****************************
	 |
	 |		Methodes
	 |
	 |****************************
	 */
	private:
		/**
		 * Renders the squares to their positions at the board
		 * 
		 * @return bool : returns true upon success, and false upon failure.
		 */
		bool initSquares();

		/**
		 * Loads a piece into a certain square.
		 *
		 */
		void loadPieceAtSquare(Square* square, Piece* piece);

		/**
		 * Renders the pieces to their positions at the board
		 * 
		 * @return bool : returns true upon success, and false upon failure.
		 */
		bool initPieces();

	public: 
		/**
		 * 
		 * Constructor
		 * 
		 */
		Board();

		/**
		 * Destructor
		 * 
		 */
		~Board();

		/**
		 * Returns the singleton instance
		 * 
		 */
		static Board getBoard();
		
		/**
		 * Handles drag-n-drop moving pieces event
		 * 
		 */
		void handleEvents(SDL_Event& e);

		/**
		 * Returns the singleton instance
		 * 
		 * @return Board
		 */
		static Board& getInstance();

		/**
		 * Renders the squares, the pieces in their positions, the board.
		 *
		 */
		void render();

		/**
		 * Initializes the board by loading the squares in their respective positions, and also the pieces.
		 * 
		 * @return bool : returns true upon success, and false upon failure.
		 */
		bool init();

		/**
		 * Binds the currently moving piece to the attribute
		 * 
		 */
		void bindMovingPiece(Piece& piece);

		/**
		 * Binds the currently moving piece to the attribute
		 * 
		 */
		void unbindMovingPiece();

		/**
		 * Returns the currently moving piece. Returns null when no piece is moving.
		 * 
		 */
		Piece& getMovingPiece();

		/**
		 * Returns the currently moving piece. Returns null when no piece is moving.
		 * 
		 */
		bool isPieceMoving();

		/**
		 * Gets the clicked piece "geographically", using a dicotomic approach.
		 *
		 * @param x: the x coordinate of the mouse cursor
		 * @param y: the y coordinate of the mouse cursor
		 * @Returns bool : If it eventually realizes that a piece has been clicked, it returns true.
		 */
		bool getClickedPiece(int x, int y);

		/**
		 * Finds the square which includes the couple (x, y) in his surface.
		 * 
		 * @param  x : the x coordinate.
		 * @param  y : the y coordinate.
		 * @return Returns the found square, otherwise NULL.
		 */
		Square* find(int x, int y);

		/**
		 * Renders the board's squares.
		 * 
		 */
		void renderSquares();

		/**
		 * Renders the board's pieces.
		 * 
		 */
		void renderPieces();
};

#endif // __BOARD_HPP__