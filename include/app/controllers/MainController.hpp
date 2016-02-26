#ifndef _MAIN_CONTROLLER_INCLUDED_
#define _MAIN_CONTROLLER_INCLUDED_

#include "AbstractController.hpp";

class MainController: public AbstractController
{
	/*
	 |****************************
	 |
	 |		Attributes
	 |
	 |****************************
	 */

	/*
	 |****************************
	 |
	 |		Methodes
	 |
	 |****************************
	 */
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
		MainController();
		~MainController();
		
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