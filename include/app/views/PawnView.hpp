#ifndef _PAWN_VIEW_H_INCLUDED_
#define _PAWN_VIEW_H_INCLUDED_

#include "views/PieceView.hpp"

class PawnView : public PieceView
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
		static std::string const whiteSuitPath;

		/**
		 * The black suit's path.
		 * 
		 */
		static std::string const blackSuitPath;

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
			return PawnView::whiteSuitPath;
		}

		/**
		 * Returns the black suit's path's class attribute's of the derivetives.
		 * 
		 * @return std::string
		 */
		inline std::string getBlackSuitPath()
		{
			return PawnView::blackSuitPath;
		}

	public: 
		/**
		 * Constructor and destructor
		 * 
		 */
		PawnView(bool suitColor, std::string name, int x, int y, int height, int width)
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
		    	ChessGameCustomException _exception("Could not load image : " + this->filePath);

		    	throw _exception;
		    }
		};
		
		~PawnView()
		{
			
		}

};

#endif // _PAWN_VIEW_H_INCLUDED_