#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

#include "../Piece.hpp"

class Bishop : public Piece
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
		Bishop(std::string suit, int x, int y);

		/**
		 * Destructor
		 * 
		 */
		~Bishop();

		/**
		 * Moves the piece as it should be moved, provided its nature and behavior.
		 * 
		 */
		bool isMoveValid(Square*);
};

#endif // __BISHOP_HPP__