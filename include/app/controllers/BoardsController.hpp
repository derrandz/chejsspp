#ifndef _MAIN_CONTROLLER_INCLUDED_
#define _MAIN_CONTROLLER_INCLUDED_

#include "AbstractController.hpp"
#include "entities/MainBoard.hpp"

class BoardsController: public AbstractController
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */
	protected:
		MainBoard *bitboard;

	/*
	 |****************************
	 |
	 |		Methodes
	 |
	 |****************************
	 */
	private:
		/**
		 * Takes the board configuration from the BoardView, sends it to the bitboard for validation.
		 *
		 * If it is valid, the bitboard will take the changes and return the BoardView's version again.
		 * Otherwise, it will revert the BoardView's configuration to the right one.
		 * 
		 */
		void validateMoves() const;

	protected:
		/**
		 * Renders all the views that are registered in the container.
		 * 
		 */
		void renderViews();

	public:
		/**
		 * Life and death angels.
		 * 
		 */
		BoardsController();
		~BoardsController();
		
		/**
		 * Bootstrap's the controller with whatever configuration specified.
		 * 
		 */
		void bootstrap();

		/**
		 * Handles any event specified.
		 * 
		 */
		void handleEvents(SDL_Event& e);

		/**
		 * A supply method that will take whatever logic supplied and make sure it is run in the controller.
		 * 
		 */
		void mainAction() const;

};

#endif //_MAIN_CONTROLLER_INCLUDED_