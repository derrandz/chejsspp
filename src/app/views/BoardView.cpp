#include "views/BoardView.hpp"
#include "views/PawnView.hpp"
#include "views/KingView.hpp"
#include "views/BishopView.hpp"
#include "views/KnightView.hpp"
#include "views/QueenView.hpp"
#include "views/RookView.hpp"

/**
 * Initializes the squares.
 * 
 */
bool BoardView::initSquares()
{
	/* Black Square */
	try
	{
		this->squares[0] = new SquareView(false, 80, 80);	
	}
	catch(std::string e)
	{
		throw e;
	}

	/* White Square */
	try
	{
		this->squares[1] = new SquareView(true, 80, 80);	
	}
	catch(std::string e)
	{
		throw e;
	}

}

/**
 * Initializes the squares.
 * =========================
 *
 * This method will generate pieces according to a certain configuration passed over from the backend.
 * However, for now, it will be rendering pieces statically.
 * 
 */
bool BoardView::initPieces()
{
	try
	{
		/**
		 * Black pieces
		 */
		this->pieces["bR"] = std::vector<PieceView*>(2, new RookView(false, 0, 0, 80, 80));
		this->pieces["bN"] = std::vector<PieceView*>(2, new KnightView(false, 0, 0, 80, 80));
		this->pieces["bB"] = std::vector<PieceView*>(2, new BishopView(false, 0, 0, 80, 80));
		this->pieces["bK"] = std::vector<PieceView*>(1, new KingView(false, 0, 0, 80, 80));
		this->pieces["bQ"] = std::vector<PieceView*>(1, new QueenView(false, 0, 0, 80, 80));
		this->pieces["bP"] = std::vector<PieceView*>(8, new PawnView(false, 0, 0, 80, 80));

		/**
		 * White pieces
		 */
		this->pieces["wR"] = std::vector<PieceView*>(2, new RookView(true, 0, 0, 80, 80));
		this->pieces["wN"] = std::vector<PieceView*>(2, new KnightView(true, 0, 0, 80, 80));
		this->pieces["wB"] = std::vector<PieceView*>(2, new BishopView(true, 0, 0, 80, 80));
		this->pieces["wK"] = std::vector<PieceView*>(1, new KingView(true, 0, 0, 80, 80));
		this->pieces["wQ"] = std::vector<PieceView*>(1, new QueenView(true, 0, 0, 80, 80));
		this->pieces["wP"] = std::vector<PieceView*>(8, new PawnView(true, 0, 0, 80, 80));
	}
	catch(std::string e)
	{
		throw e;
	}
}

/**
 * Initializes the BoardView with all the needed component views.
 * @return boolean
 * 
 */
bool BoardView::init()
{
	try
	{
		this->initSquares();
	}
	catch(std::string e)
	{
		throw e;
	}

	try
	{
		this->initPieces();
	}
	catch(std::string e)
	{
		throw e;
	}
}

/**
 * Constructor and destructor
 * 
 */
BoardView::BoardView(std::string** xboard)
:View("", 0, 0, 0, 0)
{
	this->myRect.h = View::SCREEN_HEIGHT;
	this->myRect.w = View::SCREEN_WIDTH;

	for (int i = 0; i < 64; ++i)
	{
		this->boardConfiguration[i/8][i%8] = xboard[i/8][i%8];
	}

	try
	{
		this->init();
	}
	catch(std::string e)
	{
		std::stringstream exception;

		exception << "BoardViewInitException: Exception caught during board initalization: " << std::endl;
		exception << "\t" << e << std::endl;

		throw exception.str();
	}
}

BoardView::~BoardView()
{

}

/**
 * Initializes the squares.
 * 
 */
void BoardView::renderSquares()
{
	bool color = true;

	for (int i = 0; i < 8; ++i, color=!color)
	{
		for (int j = 0; j < 8; ++j, color = !color)
		{
			if(color)
			{
				this->squares[1]->render(j*80, i*80);
			}
			else
			{
				this->squares[0]->render(j*80, i*80);
			}
		}
	}
}

/**
 * Initializes the squares.
 * 
 */
void BoardView::renderPieces()
{
	int rendered_bP = 0,
		rendered_bN = 0,
		rendered_bR = 0,
		rendered_bB = 0,
		rendered_bK = 0,
		rendered_bQ = 0,

		rendered_wP = 0,
		rendered_wN = 0,
		rendered_wR = 0,
		rendered_wB = 0,
		rendered_wK = 0,
		rendered_wQ = 0;

	pieces_it piecesIterator;

	for (int i = 0; i < 64; ++i)
	{
		std::string pieceName = this->boardConfiguration[i/8][i%8];
		piecesIterator = this->pieces.find(pieceName);

		if(piecesIterator != this->pieces.end())
		{
			PieceView* extptr;

			if(pieceName.compare("bP") == 0)
			{
				extptr = (piecesIterator->second.at(rendered_bP));
				
				rendered_bP++;
			}
			else
			if(pieceName.compare("bR") == 0)
			{
				extptr = (piecesIterator->second.at(rendered_bR));
				
				rendered_bR++;
			}
			else
			if(pieceName.compare("bN") == 0)
			{
				extptr = (piecesIterator->second.at(rendered_bN));
				
				rendered_bN++;
			}
			else
			if(pieceName.compare("bB") == 0)
			{
				extptr = (piecesIterator->second.at(rendered_bB));
				
				rendered_bB++;
			}
			else
			if(pieceName.compare("bK") == 0)
			{
				extptr = (piecesIterator->second.at(rendered_bK));
				
				rendered_bK++;
			}
			else
			if(pieceName.compare("bQ") == 0)
			{
				extptr = (piecesIterator->second.at(rendered_bQ));
				
				rendered_bQ++;
			}
			else
				/********** White pieces **********/
			if(pieceName.compare("wP") == 0)
			{
				extptr = (piecesIterator->second.at(rendered_wP));
				
				rendered_wP++;
			}
			else
			if(pieceName.compare("wR") == 0)
			{
				extptr = (piecesIterator->second.at(rendered_wR));
				
				rendered_wR++;
			}
			else
			if(pieceName.compare("wN") == 0)
			{
				extptr = (piecesIterator->second.at(rendered_wN));
				
				rendered_wN++;
			}
			else
			if(pieceName.compare("wB") == 0)
			{
				extptr = (piecesIterator->second.at(rendered_wB));
				
				rendered_wB++;
			}
			else
			if(pieceName.compare("wK") == 0)
			{
				extptr = (piecesIterator->second.at(rendered_wK));
				
				rendered_wK++;
			}
			else
			if(pieceName.compare("wQ") == 0)
			{
				extptr = (piecesIterator->second.at(rendered_wQ));
				
				rendered_wQ++;
			}
			else
			{
				continue;	
			}

			extptr->render((i%8) * 80, (i/8) * 80);
		}
	}
}

/**
 * Renders the actual view to the screen.
 * 
 */
void BoardView::render()
{
	this->renderSquares();
	this->renderPieces();
}
