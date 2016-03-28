#ifndef _BISHOPS_BOARD_H_INCLUDED_
#define _BISHOPS_BOARD_H_INCLUDED_

#include "entities/AbstractBoardEntity.hpp"

class BishopsBoard : public AbstractBoardEntity
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
		BishopsBoard(bool suitColor)
		:AbstractBoardEntity(suitColor)
		{

		};
		~BishopsBoard()
		{
			
		}

		/**
		 * Alters the positions at this board.
		 * 
		 */
		inline void alterBoard(std::string& binaryString)
		{
			AbstractBoardEntity::alterBoard(binaryString);
		};

};

#endif // _BISHOPS_BOARD_H_INCLUDED_