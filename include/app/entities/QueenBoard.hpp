#ifndef _QUEEN_BOARD_H_INCLUDED_
#define _QUEEN_BOARD_H_INCLUDED_

#include "entities/AbstractBoardEntity.hpp"

class QueenBoard : public AbstractBoardEntity
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */

	/*
	 |****************************
	 |		Methodes
	 |
	 |****************************
	 */
	protected:
		/**
		 * Judges the new move as valid or invalid.
		 * @param  long : the new board's configuration that represents the new move.
		 * @return bool : true upon valid.
		 *  
		 */
		inline bool isMoveValid(long move)
		{
			return true;
		};

	public:
		/**
		 * Constructor and destructor
		 * 
		 */
		QueenBoard(bool suitColor)
		:AbstractBoardEntity(suitColor)
		{

		};
		~QueenBoard()
		{

		};

		/**
		 * Alters the positions at this board.
		 * 
		 */
		inline void alterBoard(std::string& binaryString)
		{
			AbstractBoardEntity::alterBoard(binaryString);
		};
};

#endif // _QUEEN_BOARD_H_INCLUDED_