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
}
