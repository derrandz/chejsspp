#ifndef _BOARD_VIEW_H_INCLUDED_
#define _BOARD_VIEW_H_INCLUDED_

#include "views/View.hpp"
#include "views/SquareView.hpp"
#include "views/PieceView.hpp"

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
		std::vector<PieceView*> pieces;

	/*
	 |****************************
	 |
	 |		Methodes
	 |
	 |****************************
	 */
	private:
		

	public:
		/**
		 * Constructor
		 * 
		 */
		BoardView();
		
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

};

#endif // _BOARD_VIEW_H_INCLUDED_