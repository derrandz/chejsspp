#ifndef _GAME_MANAGER_INCLUDED
#define _GAME_MANAGER_INCLUDED

#include <vector>

class MainController;

class GameManager
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */

	/*
	 |****************************
	 |		Methodes
	 |
	 |****************************
	 */
	private:
		/**
		 * Where the game's controllers are going to be stored.
		 * 
		 */
		static std::vector<MainController> controllersContainer;

		/**
		 * Boots the application
		 * @return boolean: returns true upon success, throws an exception upon failure.
		 * 
		 */
		int bootApp();

		/**
		 * Registers a controller into the GameManager's container.
		 */
		static void registerController(MainController);

	public: 
		static int run();	

		GameManager();
		~GameManager();

		

};

#endif // _GAME_MANAGERINCLUDED_