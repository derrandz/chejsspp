#include "views/BoardView.hpp"
#include "views/PawnView.hpp"

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
		PieceView* ptr = new PawnView(true, 0, 0, 80, 80);
		this->pieces.push_back(ptr);
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
BoardView::BoardView()
:View("", 0, 0, 0, 0)
{
	this->myRect.h = View::SCREEN_HEIGHT;
	this->myRect.w = View::SCREEN_WIDTH;

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
 * Renders the actual view to the screen.
 * 
 */
void BoardView::render()
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

	std::cout << "Should have render squares by now." << std::endl;	
}
