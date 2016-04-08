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
	this->bitboard = new MainBoard();
	this->bitboard->initStandardBoard();

	BoardView* ptr;
	try
	{
	    ptr = new BoardView(true, this->bitboard->getFinalArrayBoard());
	    // this->bitboard->drawBoard();
	}
	catch(const _ExceptionHandler& exception)
    {
        std::cout << "Exception raised at _$BoardsController::bootstrap:  const _ExceptionHandler&" << std::endl;
        std::cout << "Exception caught in the main loop: " << std::endl;
        std::cout << "\t" << "_$BoardsController::bootstrap" << std::endl;
        throw exception;
    }
    catch(const std::exception& exception)
    {
        std::cout << "Exception caught at: _$BoardsController::bootstrap: const std::exception&  " << std::endl;
        throw exception;
    }
    catch(...)
    {
        std::cout << "Could not catch this: _$BoardsController::bootstrap." << std::endl;
        std::exception_ptr eptr;
        eptr = std::current_exception();
        std::rethrow_exception(eptr);
    }

    this->registerView(ptr);
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