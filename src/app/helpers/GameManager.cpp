#include "helpers/GameManager.hpp"
#include "controllers/MainController.hpp"

/**
 * Where the game's controllers are going to be stored.
 * 
 */
std::vector<MainController> GameManager::controllersContainer;

/**
 * Boots the application, instantiates the controller and makes it global
 * @return boolean: returns true upon success, throws an exception upon failure.
 * 
 */
int GameManager::bootApp()
{
    MainController controller;
    GameManager::registerController(controller);
}

/**
 * Destructor and Constructor
 * 
 */
GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

/**
 * Registers a controller into the GameManager's container.
 */
void GameManager::registerController(MainController controller)
{
    GameManager::controllersContainer.push_back(controller);
}

/**
 * Runs the mainloop of the game.
 * 
 * @return 0 upon success, -1 upon failure.
 */
int GameManager::run()
{
	GameManager gameManager;

    gameManager.bootApp();

    return GameManager::controllersContainer.begin()->run();
}