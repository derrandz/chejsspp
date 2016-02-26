#ifndef _QUEEN_VIEW_H_INCLUDED_
#define _QUEEN_VIEW_H_INCLUDED_

#include "views/View.hpp"

class QueenView : public PieceView
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */
	private:
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
	protected:
		/**
		 * Returns the white suit's path's class attribute's of the derivetives.
		 * 
		 * @return std::string
		 */
		inline std::string getWhiteSuitPath()
		{
			return QueenView::whiteSuitPath;
		}

		/**
		 * Returns the black suit's path's class attribute's of the derivetives.
		 * 
		 * @return std::string
		 */
		inline std::string getBlackSuitPath()
		{
			return QueenView::blackSuitPath;
		}

	public: 
		/**
		 * Constructor and destructor
		 * 
		 */
		QueenView(std::string path, int x, int y, int height, int width)
		:PieceView(suitColor, x, y, height, width)
		{

		};
		
		~QueenView();

};

#endif // _QUEEN_VIEW_H_INCLUDED_