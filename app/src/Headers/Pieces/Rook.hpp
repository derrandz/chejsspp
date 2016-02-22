#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include "../Piece.hpp"

class Rook : public Piece
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
		Rook(std::string suit, int x, int y);

		/**
		 * Destructor
		 * 
		 */
		~Rook();

		/**
		 * Moves the piece as it should be moved, provided its nature and behavior.
		 * 
		 */
		bool isMoveValid(Square*);
};

#endif // __ROOK_HPP__