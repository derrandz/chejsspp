#include "controllers/AbstractController.hpp"

/**
 * The to-be-rendered views
 */
std::vector<View*> AbstractController::viewsContainer;

/**
 * Renders all the views that are registered in the container.
 * 
 */
void AbstractController::renderViews()
{
	for(std::vector<View*>::iterator view = AbstractController::viewsContainer.begin(); view != AbstractController::viewsContainer.end(); ++view) 
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
	AbstractController::viewsContainer.push_back(newView);
}

/**
 * Call the View::initSDL to initialize SDL.
 * 
 */
void AbstractController::initViews()
{
	//Start up SDL and create window
    try
    {
    	View::initSDL();
    }
    catch(std::string e)
    {
    	throw e;
    };

}

void AbstractController::freeViews()
{
    //Free resources and close SDL
    View::closeSDL();
}

/**
 * Runs the controller. (Might raise an exception*)
 * 
 * @return int: 0 upon success, -1 upload failure.
 */
int AbstractController::run()
{
	try
	{
		this->initViews();
	}
	catch(std::string e)
	{
		std::cout << e << std::endl;
		return -1;
	};

    this->mainAction();
    
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

        this->renderViews();

        //Update screen
        SDL_RenderPresent( View::renderer );
    }

    this->freeViews();
    return 0;
}
