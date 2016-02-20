#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "../Piece.hpp"

class Knight : public Piece
{
	/*
	 |****************************
	 |
	 |		Attributes
	 |
	 |****************************
	 */
	private:

	public:

	/*
	 |****************************
	 |
	 |		Methodes
	 |
	 |****************************
	 */
	private:

	public:
		/**
		 * Our beloved constructor
		 * 
		 */
		Knight(std::string suit, int x, int y);

		/**
		 * Destructor
		 * 
		 */
		~Knight();

		/**
		 * Moves the piece as it should be moved, provided its nature and behavior.
		 * 
		 */
		bool isMoveValid(Square*);
};

#endif // __KNIGHT_HPP__