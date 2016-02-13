#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include "General.hpp"
#include "Square.hpp"

using namespace std;

class Square;

class Piece
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
		 * The squares position on the board
		 * 
		 */
		Position position;

		/**
		 * The square that this piece currently holds/occupies
		 * 
		 */
		Square* currentSquare;
	
		/**
		 * Indicates whether the piece is being draged
		 * 
		 */
		static bool dragging;
		
	public:
		/**
		 * The square's suit, whether it is white or black.
		 * 
		 */
		std::string suit;

		/**
		 * The piece's name 
		 * 
		 */
		std::string name;

		/**
		 * The piece's code
		 * 
		 */
		std::string code;

		/**
		 * The piece's suit path
		 * 
		 */
		std::string suitPath;

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
		bool loadTexture();

	public:
		/**
		 * Constructor
		 * 
		 */
		Piece(std::string suit, std::string name, std::string code, int x, int y);

		/**
		 * Destructor
		 * 
		 */
		~Piece();

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
		 * Returns the currently occupied square
		 * 
		 */
		Square& getCurrentSquare();

		/**
		 * Moves the piece to the provided square
		 *
		 */
		Square& changeSquare(Square& square);

		/**
		 * Changes the current position of the piece
		 * @param x : the x coordinate
		 * @param y : the y coordinate
		 */
		void changeBoxPosition(int x, int y);

		/**
		 * Handles the drag-n-drop event
		 * 
		 * @param  e SDL_Event& : The event that has been triggered
		 * @return   boolean
		 */
		bool handleEvents(SDL_Event& e);

		/**
		 * Moves the piece as it should be moved, provided its nature and behavior.
		 * 
		 */
		// virtual void move() = 0;
		
		/**
		 * Tells whether a couple (x, y) coordinates collides with this piece's box.
		 * 
		 */
		bool collidesWith(int x, int y);
		
		/**
		 * Triggers the dragging event
		 */
		void triggerDraggingEvent();

		/**
		 * Assigns to this piece the current square.
		 * 
		 */
		void assignSquare(Square* square);
};

#endif // __PIECE_HPP__