#include "helpers/GameManager.hpp"
#include "controllers/BoardsController.hpp"

/**
 * Where the singletonED instance is going to be stored.
 * 
 */
GameManager* GameManager::instance = NULL;

/**
 * Creates the instance and binds it to its little container.
 * 
 */
void GameManager::bootstrap()
{
	if(GameManager::instance == NULL)
	{
		GameManager::instance = new GameManager();
	}
}


/**
 * Returns the static singletonED instance.
 * @return const GameManager*
 * 
 */
GameManager* GameManager::getInstance()
{
	GameManager::bootstrap();

	GameManager* instancePtr = GameManager::instance;

	if(instancePtr != NULL)
	{
		return GameManager::instance;
	}
	else
	{
		std::stringstream exception;

		exception << "GameManager instance has not been initialized properly.\n";

		// throw exception.str();
	}
}

/**
 * THE FORBIDDEN CITY!
 *
 * The methods that are put private as to forbid their usage.
 * 
 */
GameManager::GameManager(){}
// GameManager::GameManager(GameManager const&){}
// void GameManager::operator=(GameManager const&){}

/**
 * Registers a controller into the GameManager's container.
 * 
 */
void GameManager::registerController(AbstractController* controller)
{
    GameManager::getInstance()->controllersContainer.push_back(controller);
}

/**
 * Boots the application, instantiates the controller and makes it global
 * @return boolean: returns true upon success, throws an exception upon failure.
 * 
 */
void GameManager::bootApp()
{
    GameManager::getInstance()->registerController(new BoardsController());
}

/**
 * Runs the mainloop of the game.
 * 
 * @return 0 upon success, -1 upon failure.
 */
int GameManager::run()
{
#ifndef _EMSCRIPTEN_
    this->bootApp();

    AbstractController* controller_ptr  = *this->controllersContainer.begin();
    // try
    // {
	    return controller_ptr->run(this->gameStatus);
    // }
    // catch(std::string e)
    // {
    // 	throw e;
    // }
#else
    this->bootApp();

    AbstractController* controller_ptr  = *this->controllersContainer.begin();

    // try
    // {
    	this->initViews_public();
        this->bootstrap();

        //Make the cursor visible.
	    SDL_ShowCursor(SDL_ENABLE);

	    //Event handler
	    SDL_Event e;

	    //Handing over the controller to emscripten to match the main loop with the browser's
		emscripten_set_main_loop(controller_ptr->one_iter_main_loop(this->gameStatus, e), 60, 1);
		
	    this->freeViews_public();
	    return 0;
    // }
    // catch(std::string e)
    // {
    // 	std::cout << e << std::endl;
    // 	throw e;
    // }

#endif // _EMSCRIPTEN_
}