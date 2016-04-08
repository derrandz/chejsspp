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
		_ExceptionHandler::throw_exception("_GameManagerResolvingException", "Could not resolve the single instance of the GameManager");
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

    AbstractController* controller_ptr  = *this->controllersContainer.begin();
    try
    {
	    return controller_ptr->run(this->gameStatus);
    }
    catch(const _ExceptionHandler& exception)
    {
        std::cout << "Exception raised at _$GameManager::run:  const _ExceptionHandler&" << std::endl;
		std::cout << "Exception caught during the initialization of the controller: " << std::endl;
        std::cout << "\t" << "_$GameManager::run" << std::endl;
        throw exception;
    }
    catch(const std::exception& exception)
    {
        std::cout << "Exception caught at: _$GameManager::run: const std::exception&  " << std::endl;
        throw exception;
    }
    catch(...)
    {
        std::cout << "Could not catch this: _$GameManager::run." << std::endl;
        std::exception_ptr eptr;
        eptr = std::current_exception();
        std::rethrow_exception(eptr);
    }
}