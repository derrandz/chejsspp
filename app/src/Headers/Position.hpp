#ifndef __POSITION_HPP__
#define __POSITION_HPP__

#include <SDL.h>

using namespace std;

class Position
{
	/*
	 |****************************
	 |
	 |		Attributes
	 |
	 |****************************
	 */
	private:
		/**
		 * The SDL Rectangle that is entouring the piece/square that is owning this position.
		 * 
		 */
		SDL_Rect box;

	public:

	/*
	 |****************************
	 |
	 |		Methodes
	 |
	 |****************************
	 */
	public:
		/**
		 * Constructor
		 */
		Position(int height, int width, int x, int y);

		/**
		 * Destructor
		 * 
		 */
		~Position();
		
		/**
		 * Accessor method, gets the SDL_Rect object
		 * 
		 * @return SDL_Rect
		 */
		SDL_Rect& getBox();
		
		/**
		 * Accessor method, gets the SDL_Rect object
		 * 
		 * @return SDL_Rect
		 */
		SDL_Rect getCopyOfBox();
		
		/**
		 * Returns the height of the box
		 * 
		 * @return unsigned int
		 */
		unsigned int getHeight();

		/**
		 * Returns the height of the box
		 * 
		 * @return unsigned int
		 */
		unsigned int getWidth();
		
		/**
		 * Returns the current position on the X's axis.
		 * 
		 * @return unsigned int : x coordinate
		 */
		unsigned int currentX();

		/**
		 * Returns the current position on the Y's axis.
		 * 
		 * @return unsigned int : y coordinate
		 */
		unsigned int currentY();

		/**
		 * The operator='s definition.
		 * Copies rposition's attributes to the rposition's.
		 * 
		 */
		Position operator=(Position&);

};

#endif // __POSITION_HPP__