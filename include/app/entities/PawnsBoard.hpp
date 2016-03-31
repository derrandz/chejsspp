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
		 * Determines whether the new move is a capture of a regular slide.
		 * @param  oldPosition [description]
		 * @param  newPosition [description]
		 * @param  fullboard   [description]
		 * @return             [description]
		 * 
		 */
		inline int identifyMoveType(bool xSuitColor, long oldPosition, long newPosition)
		{
			long file_a = 72340172838076673L;
			long file_h = -9187201950435737472L;

			if(0 == newPosition) return 0; // If there was no new move

			if(xSuitColor)//white pieces
			{
				if( (oldPosition<<8) == newPosition)	return 1;
				else
				{
					if( (oldPosition&file_a) != 0) // if the pawn is on the A's
					{
						if( ( (oldPosition&file_a)<<7 ) == newPosition) return 2;
					}	
					else if( (oldPosition&file_h) != 0) // if the pawn is on the H's
					{
						if( ( (oldPosition&file_h)<<9 ) == newPosition) return 2;
					}	
					else
					{
						if( (oldPosition<<9) == newPosition || (oldPosition<<7) == newPosition ) return 2;
						else return 0;
					}
				}
			}
			else // black pieces
			{
				if( (oldPosition>>8) == newPosition)	return 1;
				else
				{
					if( (oldPosition&file_a) != 0) // if the pawn is on the A's
					{
						if( ( (oldPosition&file_a)>>7 ) == newPosition) return 2;
					}	
					else if( (oldPosition&file_h) != 0) // if the pawn is on the H's
					{
						if( ( (oldPosition&file_h)>>9 ) == newPosition) return 2;
					}	
					else
					{
						if( (oldPosition>>9) == newPosition || (oldPosition>>7) == newPosition ) return 2;
						else return 0;
					}
				}
			}
		};

		/**
		 * Judges the new move as valid or invalid.
		 * @param  long : the new board's configuration that represents the new move.
		 * @return bool : true upon valid.
		 *  
		 */
		inline bool isMoveValid(long move, long fullboard)
		{
			long oldPosition = this->extractOldPosition(move);
			long newPosition = this->extractNewMove(move);

			int moveType = this->identifyMoveType(this->suitColor, oldPosition, newPosition);

			if(moveType == 1)
			{
				return this->isBoardIsEmptyAt(newPosition, fullboard); // Prohibits the slide if the square is not empty.
			}
			else if( moveType == 2)
			{
				if(!this->isBoardIsEmptyAt(newPosition, fullboard)) //Prohibits the capture if the square is empty.
				{
					AbstractBoardEntity::saveCaptureHistory(this->name, newPosition);
					return true;
				}
				else return false;
			}
			else return false;
		};

	public:
		/**
		 * Constructor and destructor
		 * 
		 */
		PawnsBoard(bool suitColor, std::string name)
		:AbstractBoardEntity(suitColor, name)
		{

		};
		~PawnsBoard()
		{

		};

		/**
		 * Alters the positions at this board.
		 * 
		 */
		inline void alterBoard(bool isInitLoad, long fullboard, std::string& binaryString)
		{
			AbstractBoardEntity::alterBoard(isInitLoad, fullboard, binaryString);
		};

};

#endif // _PAWNS_BOARD_H_INCLUDED_