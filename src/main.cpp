#include <iostream>
#include <string>
#include "helpers/GameManager.hpp"

int main( int argc, char* args[] )
{
	std::cout << "Hi there" << std::endl;
	/**
	 * Bootstrap code.
	 * 
	 */
	GameManager* gameManager;

	try
	{
		gameManager = GameManager::getInstance();
	}
	catch(std::string e)
	{
		std::cout << e << std::endl;
	}
    catch(const std::exception& e)
    {
        std::cout << "Uncaught exception @main caused by GameManager::getInstance()" << e.what() << "!\n";
    }
    catch(...)
    {
        std::cout <<  "There was an uncaught exception @BoardView::BoardView caused by init()" << std::endl;
    }

	try
	{
		std::cout << "Hi there 3" << std::endl;
	    return gameManager->run();
	}
	catch(std::string e)
	{
		std::cout << e << std::endl;
		return -1;
	}
	catch(const std::exception& e)
	{
		std::cout << "Uncaught exception @main caused by gameManager->run()" << e.what() << "!\n";
		return -1;
	}
	catch(...)
	{
		std::cout << "Uncaught exception @main" << "!\n";
		return -1;
	}
}
