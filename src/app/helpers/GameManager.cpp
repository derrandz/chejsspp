#include "helpers/GameManager.hpp"
#include "controllers/MainController.hpp"

/**
 * Runs the mainloop of the game.
 * 
 * @return 0 upon success, -1 upon failure.
 */
int GameManager::run()
{
	//Start up SDL and create window
    try
    {
    	View::initSDL();
    }
    catch(std::string e)
    {
    	std::cout << e;
        return -1;
    };

	//Instantiate a controller
	MainController mainController;

    mainController.mainAction();
    
	//Make the cursor visible.
    SDL_ShowCursor(SDL_ENABLE);

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            switch( e.type )
            {
                case SDL_QUIT: quit = true; break;

                case SDL_KEYDOWN: if( e.key.keysym.sym == SDLK_ESCAPE ) quit = true; break;

                default: quit = false; break;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor( View::renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( View::renderer );

        mainController.run();

        //Update screen
        SDL_RenderPresent( View::renderer );
    }

    //Free resources and close SDL
    View::closeSDL();

    return 0;
}