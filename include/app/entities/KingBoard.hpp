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
		inline int identifyMoveType(bool xSuitColor, long long oldPosition, long long newPosition)
		{

		};

		inline int identifyMoveType(bool xSuitColor, long long oldPosition, long long newPosition, long long fullboard)
		{
			if(0 == newPosition) return 0; // If there was no new move
			
			long long special_case = KingBoard::right_diagonals[14];

			bool moveForward, moveBackwards, moveRight, moveLeft, 
				 moveForwardDiagonal_right, moveForwardDiagonal_left, 
				 moveBackwardsDiagonal_right, moveBackwardsDiagonal_left;
			
			if(oldPosition != special_case)
			{
				moveForward                 = oldPosition<<8 == newPosition;
				moveBackwards               = oldPosition>>8 == newPosition;
				moveRight                   = oldPosition>>1 == newPosition;
				moveLeft                    = oldPosition<<1 == newPosition;
				moveForwardDiagonal_right   = oldPosition<<7 == newPosition;
				moveForwardDiagonal_left    = oldPosition<<9 == newPosition;
				moveBackwardsDiagonal_right = oldPosition>>9 == newPosition;
				moveBackwardsDiagonal_left  = oldPosition>>7 == newPosition;
			}	
			else
			{
				long long lsb_container;

				lsb_container = oldPosition>>8;
				lsb_container = lsb_container<<(64-8);
				lsb_container &= ~lsb_container + 1;
				moveBackwards = lsb_container == newPosition;
				
				lsb_container = oldPosition>>1;
				lsb_container = lsb_container<<(64-1);
				lsb_container &= ~lsb_container + 1;
				moveRight     = lsb_container == newPosition;

				lsb_container               = oldPosition>>1;
				lsb_container               = lsb_container<<(64-1);
				lsb_container               &= ~lsb_container + 1;
				moveBackwardsDiagonal_right = lsb_container == newPosition;
			}

			if(moveForward || moveRight || moveLeft || moveBackwards || moveForwardDiagonal_right || moveForwardDiagonal_left || moveBackwardsDiagonal_right || moveBackwardsDiagonal_left)
			{
				if(this->isBoardIsEmptyAt(newPosition, fullboard))	return 1; //a slide
				else return 2; //a capture
			}
			else return 0;
		};

		/**
		 * Judges the new move as valid or invalid.
		 * @param  long long : the new board's configuration that represents the new move.
		 * @return bool : true upon valid.
		 *  
		 */
		inline bool isMoveValid(long long move, long long fullboard, long long myFriendsBoard)
		{
			long long oldPosition = this->extractOldPosition(move);
			long long newPosition = this->extractNewMove(move);

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
		inline void alterBoard(bool isInitLoad, long long fullboard, long long myFriendsBoard, std::string& binaryString)
		{
			AbstractBoardEntity::alterBoard(isInitLoad, fullboard, myFriendsBoard, binaryString);
		};

};

#endif // _KING_BOARD_H_INCLUDED_