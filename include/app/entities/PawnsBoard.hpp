#ifndef _PAWNS_BOARD_H_INCLUDED_
#define _PAWNS_BOARD_H_INCLUDED_

#include "entities/AbstractBoardEntity.hpp"

class PawnsBoard : public AbstractBoardEntity
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
			/*long file_a = 72340172838076673L;
			long file_h = -9187201950435737472L;
			long possible_moves_to_right = (this->bitRepresentation >> 7) & ~file_a ;
			long possible_moves_to_left  = (this->bitRepresentation >> 7) & ~file_h ;
		
			long initial_positions = 36028797018963968;

			for (int i = 0; i < 64; ++i)
			{
				if ( ((possible_moves_to_right>>i)&1) && ((move>>i)&1) == 1) 
				{
					return true;
				}	
				else
				if ( ((possible_moves_to_left>>i)&1) && ((move>>i)&1) == 1) 
				{
					return true;
				}
			}

			if( move == initial_positions)	return true;
			std::cout << "Invalid move\n";
			return false;*/

			return true;
		};

	public:
		/**
		 * Constructor and destructor
		 * 
		 */
		PawnsBoard(bool suitColor)
		:AbstractBoardEntity(suitColor)
		{

		};
		~PawnsBoard()
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

#endif // _PAWNS_BOARD_H_INCLUDED_