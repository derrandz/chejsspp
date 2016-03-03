#ifndef _BOARD_VIEW_H_INCLUDED_
#define _BOARD_VIEW_H_INCLUDED_

#include "views/View.hpp"
#include "views/SquareView.hpp"
#include "views/PieceView.hpp"
#include <map>

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
	private:
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

	protected:
		/**
		 * A board has two type of squares, black and white, and they are views as well.
		 * 
		 */
		SquareView* squares[2];

		/**
		 * A board has many pieces regardless of their type, and they are dynamically added and deleted.
		 * 
		 */
		std::map<std::string, std::vector<PieceView*>> pieces;

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
	public:
		/**
		 * Constructor
		 * 
		 */
		BoardView(std::string**);
		
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
		 * Returns the board in an 8*8 strings array, and each index, there should be either an empty string, or a string representing a piece, such as "wP" for white pawn
		 * @return std::string[] : Array of strings.
		 * 
		 */
		// std::string[][] getBoardConfiguration();

};

#endif // _BOARD_VIEW_H_INCLUDED_