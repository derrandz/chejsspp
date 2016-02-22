#include "controllers/MainController.hpp"
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
 * A supply method that will take whatever logic supplied and make sure it is run in the controller.
 * 
 */
void MainController::mainAction()
{
	View testView = View("../res/board/pieces/black/bB_80.png", 80, 80, 0, 0);

	this->registerView(testView);
}
