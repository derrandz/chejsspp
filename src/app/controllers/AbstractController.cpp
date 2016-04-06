#include "controllers/AbstractController.hpp"
#include <functional>
#include <emscripten.h>

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
    std::cout << "AbstractController::registerView before try" << std::endl;
    try
    {
        std::cout << "AbstractController::registerView in try" << std::endl;
        this->viewsContainer.push_back(newView);
    }
    catch(std::string e)
    {
        throw e;
    }
}

/**
 * Call the View::initSDL to initialize SDL.
 * 
 */
void AbstractController::initViews()
{
    std::cout << "AbstractController::initViews" << std::endl;

	//Start up SDL and create window
    try
    {
    	View::initSDL();
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    	throw e;
    };

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

#ifdef EMSCRIPTEN
static void dispatch_main_loop(void* fp)
{
    std::function<void()>* func = (std::function<void()>*)fp;
    (*func)();
}
#endif // EMSCRIPTEN

/**d* sdl_event_gpt
 * Runs the controller. (Might raise an exception*)
 * 
 * @return int: 0 upon success, -1 upload failure.
 */
int AbstractController::run(bool& gameStatus)
{
    std::cout << "AbstractController::run" << std::endl;
    
    // try
    // {
        this->initViews();
        this->bootstrap();
    // }
    // catch(std::string e)
    // {
        // std::cout << e << std::endl;
        // throw e;
    // };

    std::cout << "No exception was throwin yet" << std::endl;
    //Make the cursor visible.
    SDL_ShowCursor(SDL_ENABLE);

#ifdef EMSCRIPTEN
std::function<void()> one_iter_main_loop = [&](){
    std::cout << "It works" << std::endl;
    SDL_Event e;
#else        
    //Event handler
    SDL_Event e;

    //While application is running
    while( !gameStatus )
    {
#endif // EMSCRIPTEN
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

        try
        {
            this->mainAction();
            this->renderViews();
        }
        catch(std::string e)
        {
            std::cout << "Exception caught during runtime: " << std::endl;
            std::cout << "\t" << e << std::endl;

            gameStatus = false;
        }

        //Update screen
        SDL_RenderPresent( View::renderer );
#ifdef EMSCRIPTEN
    };
    emscripten_set_main_loop_arg(dispatch_main_loop, &one_iter_main_loop, 60, 1);
#else
    }
#endif // EMSCRIPTEN
    this->freeViews();
    return 0;
}