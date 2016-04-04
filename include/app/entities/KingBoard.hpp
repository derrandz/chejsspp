#ifndef _KING_BOARD_H_INCLUDED_
#define _KING_BOARD_H_INCLUDED_

#include "entities/AbstractBoardEntity.hpp"

class KingBoard : public AbstractBoardEntity
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

		};

		inline int identifyMoveType(bool xSuitColor, long oldPosition, long newPosition, long fullboard)
		{
			if(0 == newPosition) return 0; // If there was no new move
			
			bool moveForward, moveBackwards, moveRight, moveLeft, 
				 moveForwardDiagonal_right, moveForwardDiagonal_left, 
				 moveBackwardsDiagonal_right, moveBackwardsDiagonal_left;
			
			moveForward                 = oldPosition<<8 == newPosition;
			moveBackwards               = oldPosition>>8 == newPosition;
			moveRight                   = oldPosition>>1 == newPosition;
			moveLeft                    = oldPosition<<1 == newPosition;
			moveForwardDiagonal_right   = oldPosition<<7 == newPosition;
			moveForwardDiagonal_left    = oldPosition<<9 == newPosition;
			moveBackwardsDiagonal_right = oldPosition>>9 == newPosition;
			moveBackwardsDiagonal_left  = oldPosition>>7 == newPosition;

			if(moveForward || moveRight || moveLeft || moveBackwards || moveForwardDiagonal_right || moveForwardDiagonal_left || moveBackwardsDiagonal_right || moveBackwardsDiagonal_left)
			{
				if(this->isBoardIsEmptyAt(newPosition, fullboard))	return 1; //a slide
				else return 2; //a capture
			}
			else return 0;
		};

		/**
		 * Judges the new move as valid or invalid.
		 * @param  long : the new board's configuration that represents the new move.
		 * @return bool : true upon valid.
		 *  
		 */
		inline bool isMoveValid(long move, long fullboard, long myFriendsBoard)
		{
			long oldPosition = this->extractOldPosition(move);
			long newPosition = this->extractNewMove(move);

			int moveType = this->identifyMoveType(this->suitColor, oldPosition, newPosition, fullboard);

			if(moveType == 1) return true;
			else if( moveType == 2)
			{
				if(!this->isCaptureLegal(myFriendsBoard, newPosition)) return false;
				else
				{
					AbstractBoardEntity::saveCaptureHistory(this->name, this->suitColor, newPosition);
					return true;
				}
			}
			else return false;
		};

	public:
		/**
		 * Constructor and destructor
		 * 
		 */
		KingBoard(bool suitColor, std::string name)
		:AbstractBoardEntity(suitColor, name)
		{

		};

		~KingBoard()
		{
			
		}

		/**
		 * Alters the positions at this board.
		 * 
		 */
		inline void alterBoard(bool isInitLoad, long fullboard, long myFriendsBoard, std::string& binaryString)
		{
			AbstractBoardEntity::alterBoard(isInitLoad, fullboard, myFriendsBoard, binaryString);
		};

};

#endif // _KING_BOARD_H_INCLUDED_