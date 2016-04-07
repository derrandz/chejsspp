#ifndef _ROOK_VIEW_H_INCLUDED_
#define _ROOK_VIEW_H_INCLUDED_

#include "views/PieceView.hpp"
#include "exceptions/ChessGameCustomException"
#include "Helpers/_ExceptionHandler"

class RookView : public PieceView
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
			return RookView::whiteSuitPath;
		}

		/**
		 * Returns the black suit's path's class attribute's of the derivetives.
		 * 
		 * @return std::string
		 */
		inline std::string getBlackSuitPath()
		{
			return RookView::blackSuitPath;
		}

	public: 
		/**
		 * Constructor and destructor
		 * 
		 */
		RookView(bool suitColor, std::string name, int x, int y, int height, int width)
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
				_ExceptionHandler::throw_exception("_RookViewInitException", "Could not load image :" + this->filePath);
		    }
		    else
		    {
		    	std::cout << "RookView init: success.";
		    }
		};
		
		~RookView();

};

#endif // _ROOK_VIEW_H_INCLUDED_