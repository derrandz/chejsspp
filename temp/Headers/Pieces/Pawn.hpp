#ifndef __PAWN_HPP__
#define __PAWN_HPP__

#include "../Piece.hpp"

class Pawn : public Piece
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
		Pawn(std::string suit, int x, int y);

		/**
		 * Destructor
		 * 
		 */
		~Pawn();

		/**
		 * Moves the piece as it should be moved, provided its nature and behavior.
		 * 
		 */
		bool isMoveValid(Square*);
};

#endif // __PAWN_HPP__