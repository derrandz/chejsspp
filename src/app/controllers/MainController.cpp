#include "controllers/MainController.hpp"
#include "views/PawnView.hpp"
#include "views/BoardView.hpp"

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
	try
	{
	    this->registerView(new BoardView(/* Will later specify a certain configuration to load with.*/));
	}
	catch(std::string e)
	{
		throw e;
	}

	std::cout << "Board View created\n";
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
