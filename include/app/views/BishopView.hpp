#ifndef _BISHOP_VIEW_H_INCLUDED_
#define _BISHOP_VIEW_H_INCLUDED_

#include "views/PieceView.hpp"

class BishopView : public PieceView
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
		 * @return std::string&
		 */
		inline std::string getWhiteSuitPath()
		{
			return BishopView::whiteSuitPath;
		}

		/**
		 * Returns the black suit's path's class attribute's of the derivetives.
		 * 
		 * @return std::string&
		 */
		inline std::string getBlackSuitPath()
		{
			return BishopView::blackSuitPath;
		}

	public: 
		/**
		 * Constructor and destructor
		 * 
		 */
		BishopView(bool suitColor, std::string name, int x, int y, int height, int width)
		:PieceView(suitColor, name, x, y, height, width)
		{
			if(suitColor)
			{
				this->filePath = this->getWhiteSuitPath();
			}
			else
			{
				this->filePath = this->getBlackSuitPath();
			}

		    if(!this->load())
		    {
		    	std::stringstream exception;

		    	exception << "BishopViewException: Could not load image : " << this->filePath;

		    	throw exception.str();
		    }
		};
		
		~BishopView();

};

#endif // _BISHOP_VIEW_H_INCLUDED_