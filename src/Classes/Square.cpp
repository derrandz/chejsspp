#include "../Headers/Square.hpp"

/**
 * Path to the white suit image
 * 
 */
std::string Square::whiteSuitPath = "../res/board/square/white_suit.jpg";

/**
 * Path to the black suit image
 * 
 */
std::string Square::blackSuitPath = "../res/board/square/black_suit.jpg";

/**
 * Constructor
 * 
 */
Square::Square(std::string xcoordinates, std::string suit, unsigned int xheight, unsigned int xwidth, int x, int y):
texture(xheight, xwidth),
position((int)xheight, (int)xwidth, (int)x, (int)y)
{
	this->coordinates = xcoordinates;
	this->width    = xwidth;
	this->height   = xheight;
	this->suit     = suit;
	this->piece    = NULL;
}

/**
 * Destructor
 * 
 */
Square::~Square()
{
	// free();
}

/**
 * Handles the textures loading
 * 
 * @return boolean
 */
bool Square::loadMedia()
{
	bool status = true;

	try
	{
		if(suit.compare("white") == 0)
		{
			status &= this->loadTexture(0);
		}
		else
		{
			status &= this->loadTexture(1);
		}
	}
	catch(int e)
	{
		std::cout << "Could not load a square's texture.\n";
	}

	if(!status)
	{
		throw 0;
	}

	return status;
}


/**
 * Loads the texture from its source file.
 * 
 * @return bool : returns true upon success, and false upon failure
 */
bool Square::loadTexture(int suit)
{

	bool status = false;

	if(suit)
	{
		status = this->texture.loadFromFile(Square::whiteSuitPath);
	}
	else
	{
		status = this->texture.loadFromFile(Square::blackSuitPath);
	}


	if(!status)
	{
		throw 0;
	}
	
	return status;
}

/**
 * Renders the square to the screen
 * 
 */
void Square::render()
{
	this->texture.render( this->position.getBox().x, this->position.getBox().y, NULL, 0.0, NULL, SDL_FLIP_NONE);
}

/**
 * Returns the current position
 *
 */
Position& Square::getPosition()
{
	return this->position;
}

/**
 * Returns the current position
 *
 */
Position Square::getCopyOfPosition()
{
	return this->position;
}

/**
 * Returns the box
 *
 */
SDL_Rect& Square::getBox()
{
	return this->getPosition().getBox();
}

/**
 * Returns the piece that is currently occupying this square
 * 
 */
Piece& Square::getOccupyingPiece()
{
	return *(this->piece);
}

/**
 * Returns whether it has a piece or not.
 * 
 */
bool Square::hasPiece()
{
	return &(this->getOccupyingPiece()) != NULL;
}

/**
 * Assigns a piece to this square
 * 
 */
void Square::assignPiece(Piece* piece)
{
	this->piece = piece;
}

/**
 * Assigns a piece to this square
 * 
 */
void Square::assignPiece_static(Piece* piece)
{
	// this->piece = *piece;
}

/**
 * Tells whether this square collides with the coordinates couple (x, y)
 * 
 * @param  x : The x coordinate
 * @param  y : The y coordinate
 * @return  Returns true if the (x, y) coordinates are within this squares' surface.
 */
bool Square::collidesWith(int x, int y)
{
	SDL_Rect& myBox = this->getBox();

	bool isXContained = ( x >= myBox.x ) && (x <= myBox.x + myBox.w);
	bool isYContained = ( y >= myBox.y ) && (y <= myBox.y + myBox.h );

	return isXContained && isYContained;
}