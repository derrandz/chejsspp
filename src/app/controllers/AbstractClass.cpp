#include "controllers/AbstractController.hpp"

/**
 * The to-be-rendered views
 */
std::vector<View> AbstractController::viewsContainer;

/**
 * Renders all the views that are registered in the container.
 * 
 */
void AbstractController::renderViews()
{
	for(std::vector<View>::iterator view = AbstractController::viewsContainer.begin(); view != AbstractController::viewsContainer.end(); ++view) 
	{
		view->render();
	}	
}

/**
 * Registers the supplied view in the container.
 * 
 */
void AbstractController::registerView(View& newView)
{
	AbstractController::viewsContainer.push_back(newView);
}

/**
 * Runs the controller. (Might raise an exception*)
 * 
 * @return int: 0 upon success, -1 upload failure.
 */
void AbstractController::run()
{
	// this->mainAction();
	this->renderViews();
}
