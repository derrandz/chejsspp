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
			bool moveForward, moveForwardDiagonalLeft, moveForwardDiagonalRight;

			if(xSuitColor) // white pieces
			{
				moveForward              = oldPosition<<8 == newPosition; 
				moveForwardDiagonalRight = oldPosition<<9 == newPosition; 
				moveForwardDiagonalLeft  = oldPosition<<7 == newPosition;
			}
			else // black pieces
			{
				moveForward              = oldPosition>>8 == newPosition; 
				moveForwardDiagonalRight = oldPosition>>9 == newPosition; 
				moveForwardDiagonalLeft  = oldPosition>>7 == newPosition;
			}

			if(0 == newPosition) return 0; // If there was no new move

			if(moveForward) return 1;
			else if(moveForwardDiagonalLeft || moveForwardDiagonalRight) return 2;
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

			int moveType = this->identifyMoveType(this->suitColor, oldPosition, newPosition);

			if(moveType == 1) return this->isBoardIsEmptyAt(newPosition, fullboard); // Prohibits the slide if the square is not empty.
			else if( moveType == 2)
			{
				if(!this->isBoardIsEmptyAt(newPosition, fullboard)) //Prohibits the capture if the square is empty.
				{
					if(!this->isCaptureLegal(myFriendsBoard, newPosition)) return false;
					else
					{
						AbstractBoardEntity::saveCaptureHistory(this->name, this->suitColor, newPosition);
						return true;
					}
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
		inline void alterBoard(bool isInitLoad, long fullboard, long myFriendsBoard, std::string& binaryString)
		{
			AbstractBoardEntity::alterBoard(isInitLoad, fullboard, myFriendsBoard, binaryString);
		};

};

#endif // _PAWNS_BOARD_H_INCLUDED_