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
#ifdef EMSCRIPTEN
		std::cout << exception.str() << std::endl;
#endif
		throw exception.str();
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
    this->bootApp();

    std::cout << "GameManager::run()" << std::endl;
    
    AbstractController* controller_ptr  = *this->controllersContainer.begin();
    try
    {
	    return controller_ptr->run(this->gameStatus);
    }
    catch(std::string e)
	{
		std::cout << e << std::endl;
		throw e;
	}
	catch(const std::exception& e)
	{
		std::cout << "Uncaught exception @GameManager::run" << e.what() << "!\n";
		throw e;
	}
	catch(...)
	{
		std::cout << "Uncaught exception @GameManager::run" << "!\n";
		std::stringstream exception;

        exception <<  "There was an uncaught exception @GameManager::run caused by controller_ptr->run()";

        throw exception.str();
	}
}