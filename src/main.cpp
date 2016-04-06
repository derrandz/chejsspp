#include <iostream>
#include <string>
#include "helpers/GameManager.hpp"
#include <emscripten.h>

int main( int argc, char* args[] )
{
	/**
	 * Bootstrap code.
	 * 
	 */
	GameManager* gameManager;

	// try
	// {
		gameManager = GameManager::getInstance();
	// }
	// catch(std::string e)
	// {
		// std::cout << e << std::endl;
	// }
	
	// try
	// {
	    return gameManager->run();
	// }
	// catch(std::string e)
	// {
		// std::cout << e << std::endl;
		return -1;
	// }
}
