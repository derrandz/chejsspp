#ifndef _SQUARE_VIEW_H_INCLUDED_
#define _SQUARE_VIEW_H_INCLUDED_

#include "views/View.hpp"
#include "helpers/_ExceptionHandler.hpp"

class SquareView : public View
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */
	/**
	 * The white suit's path.
	 * 
	 */
	static const std::string whiteSuitPath;

	/**
	 * The black suit's path.
	 * 
	 */
	static const std::string blackSuitPath;

	/*
	 |****************************
	 |		Methodes
	 |
	 |****************************
	 */
	
	/*
	 |****************************
	 |		Methodes
	 |
	 |****************************
	 */
	public: 
		/**
		 * Constructor and destructor
		 * 
		 */
		SquareView(bool color, int height, int width)
		:View("", 0, 0, height, width)
		{
			if(color)
			{
				this->filePath = SquareView::whiteSuitPath;
			}
			else
			{
				this->filePath = SquareView::blackSuitPath;
			}

			if(!this->load())
			{
				_ExceptionHandler::throw_exception("_SquareViewInitException", "Could not load image : " + this->filePath);
			}
		};

		~SquareView();

};

#endif // _SQUARE_VIEW_H_INCLUDED_