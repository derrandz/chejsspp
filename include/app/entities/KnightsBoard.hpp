#ifndef __H_INCLUDED_
#define __H_INCLUDED_

#include "entities/AbstractBoardEntity.hpp"

class KnightsBoard : public AbstractBoardEntity
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

			long long special_case = KnightsBoard::right_diagonals[14];

			bool moveForwardRightL, moveForwardLeftL, moveForwardLateralRightL, moveForwardLateralLeftL,
				 moveBackwardRightL, moveBackwardLeftL, moveBackwardLateralRightL, moveBackwardLateralLeftL;

			if(oldPosition != special_case)
			{
				moveForwardRightL        = oldPosition<<15 == newPosition;
				moveForwardLeftL         = oldPosition<<17 == newPosition;
				moveForwardLateralRightL = oldPosition<<6 == newPosition;
				moveForwardLateralLeftL  = oldPosition<<10 == newPosition;

				moveBackwardRightL        = oldPosition>>17 == newPosition;
				moveBackwardLeftL         = oldPosition>>15 == newPosition;
				moveBackwardLateralRightL = oldPosition>>10 == newPosition;
				moveBackwardLateralLeftL  = oldPosition>>6 == newPosition;
			}
			else
			{
				long long lsb_container;

				lsb_container      = oldPosition>>17;
				lsb_container      = lsb_container<<(64-17);
				lsb_container      &= ~lsb_container + 1;
				moveBackwardRightL = lsb_container == newPosition;

				lsb_container     = oldPosition>>15;
				lsb_container     = lsb_container<<(64-15);
				lsb_container     &= ~lsb_container + 1;
				moveBackwardLeftL = oldPosition>>15 == newPosition;

				lsb_container             = oldPosition>>10;
				lsb_container             = lsb_container<<(64-10);
				lsb_container             &= ~lsb_container + 1;
				moveBackwardLateralRightL = oldPosition>>10 == newPosition;

				lsb_container            = oldPosition>>6;
				lsb_container            = lsb_container<<(64-6);
				lsb_container            &= ~lsb_container + 1;
				moveBackwardLateralLeftL = oldPosition>>6 == newPosition;
			}

			if( moveForwardRightL || moveForwardLeftL || moveForwardLateralRightL || moveForwardLateralLeftL || moveBackwardRightL || moveBackwardLeftL || moveBackwardLateralRightL || moveBackwardLateralLeftL)
			{
				if(this->isBoardIsEmptyAt(newPosition, fullboard)) return 1;
				else return 2;
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
			else if(moveType == 2)
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
		KnightsBoard(bool suitColor, std::string name)
		:AbstractBoardEntity(suitColor, name)
		{

		};
		~KnightsBoard()
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

#endif // __H_INCLUDED_