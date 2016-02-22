#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include "Texture.hpp"
#include "Position.hpp"

class Piece;

using namespace std;

class Square
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
		 * The square's texture (image)
		 * 
		 */
		Texture texture;

		/**
		 * The squares width, also its texture's width.
		 * 
		 */
		int width;
		
		/**
		 * The squares height, also its texture's height.
		 * 
		 */
		int height;

		/**
		 * The squares position on the board
		 * 
		 */
		Position position;

		/**
		 * The piece that currently holds the space of this square
		 * 
		 */
		Piece* piece;
		
	public:
		/**
		 * Path to the white suit image
		 * 
		 */
		static std::string whiteSuitPath;

		/**
		 * Path to the black suit image
		 * 
		 */
		static std::string blackSuitPath;
		
		/**
		 * The square's suit, whether it is white or black.
		 * 
		 */
		std::string suit;

		/**
		 * The square's coordinates in chess language
		 */
		std::string coordinates;

	/*
	 |****************************
	 |
	 |		Methodes
	 |
	 |****************************
	 */
	private:
		/**
		 * Loads the texture from its source file.
		 *
		 * @param int
		 * @return bool : returns true upon success, and false upon failure
		 */
		bool loadTexture(int);
	public:
		/**
		 * Constructor
		 * 
		 */
		Square(std::string coordinates, std::string suit, unsigned int height, unsigned int width, int x, int y);

		/**
		 * Destructor
		 * 
		 */
		~Square();

		/**
		 * Handles the textures loading
		 * 
		 * @return boolean
		 */
		bool loadMedia();
		
		/**
		 * Renders the square to the screen
		 * 
		 */
		void render();

		/**
		 * Returns the current position
		 *
		 */
		Position& getPosition();

		/**
		 * Returns the current position
		 *
		 */
		Position getCopyOfPosition();

		/**
		 * Returns the box
		 *
		 */
		SDL_Rect& getBox();

		/**
		 * Returns the piece that is currently occupying this square
		 * 
		 */
		Piece& getOccupyingPiece();

		/**
		 * Returns whether it has a piece or not.
		 * 
		 */
		bool hasPiece();

		/**
		 * Assigns a piece to this square
		 * 
		 */
		void assignPiece(Piece* piece);

		/**
		 * Assigns a piece to this square
		 * 
		 */
		static void assignPiece_static(Piece* piece);

		/**
		 * Tells whether this square collides with the coordinates couple (x, y)
		 * 
		 * @param  x : The x coordinate
		 * @param  y : The y coordinate
		 * @return  Returns true if the (x, y) coordinates are within this squares' surface.
		 */
		bool collidesWith(int x, int y);
};

#endif // __SQUARE_HPP__