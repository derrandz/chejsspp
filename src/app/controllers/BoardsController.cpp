#include "controllers/BoardsController.hpp"
#include "views/PawnView.hpp"
#include "views/BoardView.hpp"
#include "entities/AbstractBoardEntity.hpp"
#include "entities/MainBoard.hpp"
/**
 * BEHOLD THE GODS OF DEATH AND LIFE.
 * 
 */
BoardsController::BoardsController()
{
	this->bitboard = NULL;
}

BoardsController::~BoardsController()
{
	delete this->bitboard;
}

/**
 * Bootstrap's the controller with whatever configuration specified.
 * 
 */
void BoardsController::bootstrap()
{
    std::cout << "BoardsController::bootstrap" << std::endl;
	
	this->bitboard = new MainBoard();
	this->bitboard->initStandardBoard();

    std::cout << "BoardsController::bootstrap about to try" << std::endl;
	
	BoardView* ptr;
	try
	{
	    std::cout << "BoardsController::bootstrap in try section" << std::endl;
	    ptr = new BoardView(false, this->bitboard->getFinalArrayBoard());
	    // this->bitboard->drawBoard();
	}
	catch(std::string e)
	{
		std::cout << e << std::endl;
		throw e;
	}

    this->registerView(ptr);
	std::cout << "Board View created\n";

	// mainBoard.drawBoard();
}
/**
 * Handles any event specified.
 * 
 */
void BoardsController::handleEvents(SDL_Event& e)
{
	AbstractController::handleEvents(e);
}
/**
 * A supply method that will take whatever logic supplied and make sure it is run in the controller.
 * 
 */
void BoardsController::mainAction() const
{
	this->validateMoves();
}

/**
 * Takes the board configuration from the BoardView, sends it to the bitboard for validation.
 *
 * If it is valid, the bitboard will take the changes and return the BoardView's version again.
 * Otherwise, it will revert the BoardView's configuration to the right one.
 * 
 */
void BoardsController::validateMoves() const
{
	//Since that is the only view we have pushed for this controller.
	BoardView* graphicalboard = dynamic_cast<BoardView*>(*(this->viewsContainer.begin()));

	// std::cout << std::endl << std::endl << "----- ----- Graphical Board [Before validation]----- -----" << std::endl;
	// graphicalboard->drawBoard();
	// std::cout << std::endl << std::endl << "----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;

	std::string** validated_configuration;

	validated_configuration = this->bitboard->validateMoves( graphicalboard->boardConfiguration , graphicalboard->getMainPlayerColor() );	

	// std::cout << std::endl << std::endl << "----- ----- The validated board is :----- -----" << std::endl;
	// this->bitboard->drawBoard();
	// this->bitboard->drawFullBoard();
	// std::cout << std::endl << std::endl << "----- ----- ----- ----- ----- ----- ----- -----" << std::endl;

	// if(thereWasAMove);
	// #if _EMSCRIPTEN_
	// 	//send the move to the mf
	// 	//
	// 	graphicalboard->loadBoard(false, validated_configuration);
	// #endif // _EMSCRIPTEN_
	graphicalboard->loadBoard(true, validated_configuration);

	// std::cout << std::endl << std::endl << "----- ----- Graphical Board [After Validation] ----- -----" << std::endl;
	// graphicalboard->drawBoard();
	// std::cout << std::endl << std::endl << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
}