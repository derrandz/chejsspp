#include "controllers/AbstractController.hpp"

/**
 * Constructor & destructor
 * 
 */
AbstractController::AbstractController()
{

}

AbstractController::~AbstractController()
{
    for(std::vector<View*>::iterator view = this->viewsContainer.begin(); view != this->viewsContainer.end(); ++view) 
    {
        View* ptr = *view;

        delete ptr;
    }
}

/**
 * Renders all the views that are registered in the container.
 * 
 */
void AbstractController::renderViews()
{
	for(std::vector<View*>::iterator view = this->viewsContainer.begin(); view != this->viewsContainer.end(); ++view) 
	{
        View* ptr = *view;

        ptr->render();
	}	
}

/**
 * Registers the supplied view in the container.
 * 
 */
void AbstractController::registerView(View* newView)
{
	this->viewsContainer.push_back(newView);
}

/**
 * Call the View::initSDL to initialize SDL.
 * 
 */
void AbstractController::initViews()
{
	//Start up SDL and create window
    // try
    // {
    	View::initSDL();
    // }
/*    catch(std::string e)
    {
    	throw e;
    };*/

}

void AbstractController::freeViews()
{
    //Free resources and close SDL
    View::closeSDL();
}

/**
 * Handles any event specified.
 * 
 */
void AbstractController::handleEvents(SDL_Event& e)
{
    for(std::vector<View*>::iterator view = this->viewsContainer.begin(); view != this->viewsContainer.end(); ++view) 
    {
        View* ptr = *view;

        ptr->handleEvents(e);
    }   
}

/**
 * Bootstrap's the controller with whatever configuration specified.
 * 
 */
void AbstractController::bootstrap()
{
    
}

/**
 * Runs the controller. (Might raise an exception*)
 * 
 * @return int: 0 upon success, -1 upload failure.
 */
int AbstractController::run(bool& gameStatus)
{
	// try
	// {
		this->initViews();
        this->bootstrap();
	// }
	/*catch(std::string e)
	{
		throw e;
	};*/


	//Make the cursor visible.
    SDL_ShowCursor(SDL_ENABLE);

    //Event handler
    SDL_Event e;


    //While application is running
    while( !gameStatus )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            switch( e.type )
            {
                case SDL_QUIT: gameStatus = true; break;

                case SDL_KEYDOWN: if( e.key.keysym.sym == SDLK_ESCAPE ) gameStatus = true; break;

                default: gameStatus = false; break;
            }

            this->handleEvents(e);
        }

        //Clear screen
        SDL_SetRenderDrawColor( View::renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( View::renderer );

        // try
        // {
            this->mainAction();
            this->renderViews();
        // }
    /*    catch(std::string e)
        {
            std::cout << "Exception caught during runtime: " << std::endl;
            std::cout << "\t" << e << std::endl;

            gameStatus = false;
        }
*/        //Update screen
        SDL_RenderPresent( View::renderer );
    }

    this->freeViews();
    return 0;
}

#if __EMSCRIPTEN__
/**
 * initViews made public
 * 
 */
void AbstractController::initViews_public()
{
    this->initViews();
}

/**
 * freeViews made public.
 * 
 */
void AbstractController::freeViews_public()
{
    this->freeViews();
}

/**
 * Runs the controller. (Might raise an exception*)
 * This function will run a single frame of the mainloop, this is customized for emscripten.
 * 
 */
void AbstractController::one_iter_main_loop(bool& gameStatus, SDL_Event& e)
{
    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 )
    {
        switch( e.type )
        {
            case SDL_QUIT: gameStatus = true; break;

            case SDL_KEYDOWN: if( e.key.keysym.sym == SDLK_ESCAPE ) gameStatus = true; break;

            default: gameStatus = false; break;
        }

        this->handleEvents(e);
    }

    //Clear screen
    SDL_SetRenderDrawColor( View::renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( View::renderer );

    // try
    // {
        this->mainAction();
        this->renderViews();
   /* }
    catch(std::string e)
    {
        std::cout << "Exception caught during runtime: " << std::endl;
        std::cout << "\t" << e << std::endl;

        gameStatus = false;
    }*/
    //Update screen
    SDL_RenderPresent( View::renderer );
}
#endif // __EMSCRIPTEN__