#ifndef _ROOKS_BOARD_H_INCLUDED_
#define _ROOKS_BOARD_H_INCLUDED_

#include "entities/AbstractBoardEntity.hpp"

class RooksBoard : public AbstractBoardEntity
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
		RooksBoard(bool suitColor)
		:AbstractBoardEntity(suitColor)
		{

		};
		~RooksBoard()
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

#endif // _ROOKS_BOARD_H_INCLUDED_