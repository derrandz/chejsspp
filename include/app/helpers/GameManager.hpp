#ifndef _GAME_MANAGER_INCLUDED
#define _GAME_MANAGER_INCLUDED

#include <vector>

class AbstractController;

class GameManager
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */
	private:
		/**
		 * Where the singletonED instance is going to be stored.
		 * 
		 */
		static GameManager* instance;

		/**
		 * Indicates whether the game has ended or not.
		 * 
		 */
		bool gameStatus;

		/**
		 * Where the game's controllers are going to be stored.
		 * 
		 */
		std::vector<AbstractController*> controllersContainer;

		/**
		 * THE FORBIDDEN CITY!
		 *
		 * The methods that are put private as to forbid their usage.
		 * 
		 */
		GameManager();
        // GameManager(GameManager const&);
        // void operator=(GameManager const&);

	/*
	 |****************************
	 |		Methodes
	 |
	 |****************************
	 */
	private:
		/**
		 * Creates the instance and binds it to its little container.
		 * 
		 */
		static void bootstrap();
		
		/**
		 * Boots the application
		 * 
		 */
		void bootApp();

		/**
		 * Registers a controller into the GameManager's container.
		 */
		void registerController(AbstractController*);

	public: 
		/**
		 * Returns the static singletonED instance.
		 * @return const GameManager*
		 * 
		 */
		static GameManager* getInstance();

		/**
		 * Launches the game.
		 * @return int
		 * 
		 */
		int run();	

};

#endif // _GAME_MANAGERINCLUDED_