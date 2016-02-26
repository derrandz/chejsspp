#ifndef __KING_HPP__
#define __KING_HPP__

#include "../Piece.hpp"

class King : public Piece
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
		King(std::string suit, int x, int y);

		/**
		 * Destructor
		 * 
		 */
		~King();

		/**
		 * Moves the piece as it should be moved, provided its nature and behavior.
		 * 
		 */
		bool isMoveValid(Square*);
};

#endif // __KING_HPP__