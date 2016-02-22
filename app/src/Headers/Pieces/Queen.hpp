#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include "../Piece.hpp"

class Queen : public Piece
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
		Queen(std::string suit, int x, int y);

		/**
		 * Destructor
		 * 
		 */
		~Queen();

		/**
		 * Moves the piece as it should be moved, provided its nature and behavior.
		 * 
		 */
		bool isMoveValid(Square*);
};

#endif // __QUEEN_HPP__