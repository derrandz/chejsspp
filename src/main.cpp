#include "Headers/Board.hpp"

SDL_Window* 	 gWindow = NULL; //The window we'll be rendering to
SDL_Renderer* gRenderer = NULL; //The window renderer

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "Chessboard",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN );


        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

void close()
{

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        if(!SDL_ShowCursor(SDL_ENABLE))
        {
            std::cout << "Unable to set cursor to shown.\n";
        }
        // SDL_SetWindowGrab(gWindow, SDL_TRUE);

        //Main loop flag
        bool quit = false;

        //Event handler
        SDL_Event e;

        // The chess board
        
        Board mainBoard;

        // Init board
        mainBoard.init();

        //While application is running
        while( !quit )
        {
            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                mainBoard.handleEvents(e);

                //User requests quit
                switch( e.type )
                {
                    case SDL_QUIT:
                        quit = true;
                    break;

                    case SDL_KEYDOWN:
                        if( e.key.keysym.sym == SDLK_ESCAPE )
                        {
                            quit = true;
                        }
                    break;

                    default:
                        quit = false;
                        break;
                }

            }

            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );
            // SDL_ShowCursor(SDL_DISABLE);

            mainBoard.render();

            /*if( mainBoard.isPieceMoving() )
            {
                std::cout << "\n Moving Piece is "<<  mainBoard.getMovingPiece().name <<" \n";
            }
            else
            {
                std::cout << "\n No piece is currently being moved. \n";
            }*/
            //Update screen
            SDL_RenderPresent( gRenderer );
        }

        //Free resources and close SDL
        close();
    }

    return 0;
}
