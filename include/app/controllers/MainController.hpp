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
		 * A supply method that will take whatever logic supplied and make sure it is run in the controller.
		 * 
		 */
		void mainAction();


};

#endif //_MAIN_CONTROLLER_INCLUDED_