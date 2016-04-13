#include <iostream>
#include <string>
#include "helpers/GameManager.hpp"
#include "helpers/_ExceptionHandler.hpp"

#ifdef EMSCRIPTEN
    #include <emscripten.h>
#endif
int main( int argc, char* args[] )
{
	/**
	 * Bootstrap code.
	 * 
	 */
	GameManager* gameManager;

	try
	{
		gameManager = GameManager::getInstance();
	}
	catch(const _ExceptionHandler& exception)
    {
		std::cout << "Exception caught in main: const _ExceptionHandler&" << std::endl;
        std::cout << exception.what() << std::endl;
    }
    catch(const std::exception& exception)
    {
        std::cout << "Exception caught in main: const std::exception&  " << std::endl;
        std::cout << exception.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Could not catch this in main: _$GameManager::getInstance." << std::endl;
    }

	try
	{
	    return gameManager->run();
	}
	catch(const _ExceptionHandler& exception)
    {
		std::cout << "Exception caught in main: const _ExceptionHandler&" << std::endl;
        std::cout << exception.what() << std::endl;
    }
    catch(const std::exception& exception)
    {
        std::cout << "Exception caught in main: const std::exception&  " << std::endl;
        std::cout << exception.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Could not catch this in main: _$GameManager::run." << std::endl;
    }
}
