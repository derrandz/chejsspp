#include "views/View.hpp"
#include <sstream>
#include "helpers/_ExceptionHandler.hpp"
#include <string>

/**
 * Static members initialization
 * 
 */
SDL_Window*   View::window   = NULL; // The window
SDL_Renderer* View::renderer = NULL; // The renderer

//The screen dimensions.
int View::SCREEN_WIDTH  = 640;
int View::SCREEN_HEIGHT = 640;
/**
 * Initializes the SDL loaders that will deal with everything about image loading.
 * 
 */
bool View::initSDL()
{
	 //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        const char* sdl_error = SDL_GetError();
        std::string message   = "SDL could not initialize! SDL Error:"; 
        std::string extra(sdl_error, 255);

        try{
            _ExceptionHandler::throw_exception("_ViewSDLInitException: ", message + extra);
        }
        catch(const std::exception& exception)
        {
            throw exception;
        };
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!\n" );
        }

        //Create window
        View::window = SDL_CreateWindow( "Chessboard",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    View::SCREEN_WIDTH,
                                    View::SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN );


        if( View::window == NULL )
        {
            std::string str(SDL_GetError());

            try{
                _ExceptionHandler::throw_exception("_ViewSDLInitException: ","Window could not be created! SDL Error:" + str + "." );
            }
            catch(const std::exception& exception)
            {
                throw exception;
            };
        }
        else
        {
            //Create renderer for window
            View::renderer = SDL_CreateRenderer( View::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( View::renderer == NULL )
            {
                std::string str( SDL_GetError() );
                try{
                _ExceptionHandler::throw_exception("_ViewSDLInitException: ","Renderer could not be created! SDL Error:" + str + "." );
                }
                catch(const std::exception& exception)
                {
                    throw exception;
                };
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( View::renderer, 0xFF, 0xFF, 0xFF, 0xFF );

                /*//Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    std::stringstream output;

                    output << "SDL_image could not initialize! SDL_image Error:" + IMG_GetError() + "\n";
                    throw output.str();
                }*/
            }
        }
    }
    return true;
}

/**
 * Frees the SDL resources
 * 
 */
void View::closeSDL()
{
    //Destroy window
    SDL_DestroyRenderer( View::renderer );
    SDL_DestroyWindow( View::window );

    View::renderer = NULL;
    View::window = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

/**
 * Constructor and destructor
 * 
 */
View::View(std::string path, int x, int y, int height, int width)
:myTexture(height, width)
{
	this->filePath = path;
	this->myRect.h = height;
	this->myRect.w = width;
	this->myRect.x = x;
	this->myRect.y = y;
}

View::~View()
{
	// delete();
}

/**
 * loads the image file to the texture.
 * 
 * @return boolean: returns true upon success.
 */
bool View::load()
{
	return this->myTexture.loadFromFile(this->filePath);
}

/**
 * Renders the actual view to the screen.
 * 
 */
void View::render()
{
	this->myTexture.render(this->myRect.x, this->myRect.y, NULL, 0.0, NULL, SDL_FLIP_NONE);
}

/**
 * Renders the actual view to the screen.
 * 
 */
void View::render(int x, int y)
{
    this->myTexture.render(x, y, NULL, 0.0, NULL, SDL_FLIP_NONE);
}

/**
 * Utility method. Detects whether the click is on this view or not.
 * 
 */
bool View::isSelected(int x, int y)
{
    SDL_Rect& myBox = this->myRect;

    bool isSelected_X = ( x > myBox.x ) && (x <= myBox.x + myBox.w);
    bool isSelected_Y = ( y >= myBox.y ) && (y <= myBox.y + myBox.h );

    return isSelected_X && isSelected_Y;
}

/**
 * Handles the events related to this view, keyboard and mouse events.
 * @param e SDL_Event
 * 
 */
void View::handleEvents(SDL_Event& e)
{
    
}