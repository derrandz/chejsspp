#ifndef _PIECE_VIEW_H_INCLUDED_
#define _PIECE_VIEW_H_INCLUDED_

#include "views/View.hpp"

class PieceView : public View
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */
	protected:
		/**
		 * White for true
		 * Black for false // Since Black is the absence of light.
		 */
		bool suitColor;

	/*
	 |****************************
	 |		Methodes
	 |
	 |****************************
	 */
	protected:
		/**
		 |
		 | getWhiteSuitPath() & getBlackSuitPath() Methods Description
		 |============================================================
		 |
		 |	Our problem is as follows:
		 |		Our base class is PieceView, and it has for each piece type a derivetive.
		 |		We need to put a path for black and white suits, for each piece type, so that
		 |		in the constructor, we would be able to specify what suit is for what piece, dynamically.
		 |		
		 |		
		 |		Doing so in the base class would not respond to our needs.
		 |		So, as you might have guessed, we will put for each derivetive class a static attribute,
		 |		with these two overriden methods to return the proper path to the base constructor.
		 |	
		 |		This way, we would have solved our issue.
		 */
		/**
		 * Returns the white suit's path's class attribute's of the derivetives.
		 * 
		 * @return std::string&
		 */
		inline virtual std::string getWhiteSuitPath()
		{

		}

		/**
		 * Returns the black suit's path's class attribute's of the derivetives.
		 * 
		 * @return std::string&
		 */
		inline virtual std::string getBlackSuitPath()
		{
			
		}


	public: 
		/**
		 * Constructor and destructor
		 * 
		 */
		PieceView(bool suitColor, int x, int y, int height, int width)
		:View("", x, y, height, width)
		{
			this->suitColor = suitColor;
			this->myRect.h = height;
			this->myRect.w = width;
			this->myRect.x = x;
			this->myRect.y = y;
		};
		
		~PieceView()
		{
			
		}

};

#endif // _PIECE_VIEW_H_INCLUDED_