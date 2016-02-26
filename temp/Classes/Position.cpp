#include "../Headers/Position.hpp";

/**
 * Constructor
 */
Position::Position(int height, int width, int x, int y)
{
	this->box.h = height;
	this->box.w = width;

	this->box.x = x;
	this->box.y = y;
}

/**
 * Destructor
 * 
 */
Position::~Position()
{

}

/**
 * Accessor method, gets the SDL_Rect object
 * 
 * @return SDL_Rect
 */
SDL_Rect& Position::getBox()
{
	return this->box;
}
/**
 * Returns the current position on the X's axis.
 * 
 * @return unsigned int : x coordinate
 */
unsigned int Position::currentX()
{
	return this->box.x;
}

/**
 * Returns the current position on the Y's axis.
 * 
 * @return unsigned int : y coordinate
 */
unsigned int Position::currentY()
{
	return this->box.y;
}

/**
 * Returns the height of the box
 * 
 * @return unsigned int
 */
unsigned int Position::getHeight()
{
    return this->box.h;
}

/**
 * Returns the height of the box
 * 
 * @return unsigned int
 */
unsigned int Position::getWidth()
{
    return this->box.w;
}

/**
 * Accessor method, gets the SDL_Rect object
 * 
 * @return SDL_Rect
 */
SDL_Rect Position::getCopyOfBox()
{
	return this->box;
}

/**
 * The operator='s definition.
 * Copies rposition's attributes to the lposition's.
 * 
 */
Position Position::operator=(Position& rPosition)
{
	SDL_Rect rPositionBox = rPosition.getCopyOfBox();

	this->box.w = rPositionBox.w;
	this->box.h = rPositionBox.h;
	this->box.x = rPositionBox.x;
	this->box.y = rPositionBox.y;

	return *this;
}