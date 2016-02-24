#ifndef _ABSTRACT_CONTROLLER_INCLUDED_
#define _ABSTRACT_CONTROLLER_INCLUDED_

#include <vector>
#include "views/View.hpp"

using namespace std;

class AbstractController
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
		 * The to-be-rendered views
		 */
		static std::vector<View*> viewsContainer;

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

		/**
		 * Initializes the SDL resources for the views.
		 * 
		 */
		void initViews();

		/**
		 * Frees the SDL resources.
		 * 
		 */
		void freeViews();

	public:
		/**
		 * Registers the supplied view in the container.
		 * 
		 */
		static void registerView(View*);

		/**
		 * A supply method that will take whatever logic supplied and make sure it is run in the controller.
		 * 
		 */
		virtual void mainAction() = 0;

		/**
		 * Runs the controller. (Might raise an exception*)
		 * 
		 */
		virtual int run();


};

#endif //_ABSTRACT_CONTROLLER_INCLUDED_