#include "controllers/MainController.hpp"
#include "views/PawnView.hpp"
#include "views/BoardView.hpp"
#include "entities/AbstractBoardEntity.hpp"
#include "entities/MainBoard.hpp"
/**
 * BEHOLD THE GODS OF DEATH AND LIFE.
 * 
 */
MainController::MainController()
{

}

MainController::~MainController()
{
	
}

/**
 * Bootstrap's the controller with whatever configuration specified.
 * 
 */
void MainController::bootstrap()
{
	MainBoard mainBoard;
	mainBoard.initStandardBoard();

	try
	{
	    this->registerView(new BoardView(mainBoard.getFinalArrayBoard()));
	}
	catch(std::string e)
	{
		throw e;
	}

	std::cout << "Board View created\n";

	// mainBoard.drawBoard();
}
/**
 * Handles any event specified.
 * 
 */
void MainController::handleEvents(SDL_Event& e)
{
	std::cout << "Event handling on..." << std::endl;
	AbstractController::handleEvents(e);
}
/**
 * A supply method that will take whatever logic supplied and make sure it is run in the controller.
 * 
 */
void MainController::mainAction() const
{

}
