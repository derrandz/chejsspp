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
	private:

	protected:
		/**
		 * Determines whether the new move is a capture of a regular slide.
		 * @param  oldPosition [description]
		 * @param  newPosition [description]
		 * @param  fullboard   [description]
		 * @return             [description]
		 * 
		 */
		int identifyMoveType(bool xSuitColor, long oldPosition, long newPosition)
		{

		};

		inline int identifyMoveType(long alteredBitboard, long fullboard)
		{
			long old_position_board = this->extractOldPosition(alteredBitboard);
			long new_position_board = this->extractNewMove(alteredBitboard);

			int old_position = this->getPositionOfBit(old_position_board);
			int new_position = this->getPositionOfBit(new_position_board);

			int captured_position = 0;

			std::cout << " old position of rook " << old_position << std::endl; 
			std::cout << " new position of rook " << new_position << std::endl; 
			for (int i = old_position + 1; i <= new_position; ++i)
			{
				long temp = (fullboard)>>i;
				/*
					To validate rooks moves, we need to identify the move.
					is it to the left, or to the irght, or where exactly.
				 */
				temp &= ~temp + 1;

				if(temp == 1)
				{
					captured_position = i;
					break;
				}
			}

			return captured_position;
		};

		/**
		 * If the rook's move is a capture, it sets its destination position to the capture piece's.
		 * @param  alteredBitboard [description]
		 * @param  fullboard       [description]
		 * @return                 If the move is not a capture, 
		 * 
		 */
		inline long makePostCaptureBoard(long alteredBitboard, long fullboard, int position)
		{
			long old_position = this->extractOldPosition(alteredBitboard);
			long new_position = this->extractNewMove(alteredBitboard);

			std::string right_position_string = "0000000000000000000000000000000000000000000000000000000000000000";

			HelperFunctions::setBinaryStringToOneAtPosition(right_position_string, position);

			long right_position_board = HelperFunctions::convertStringToBitBoard(right_position_string);

			return (long)( ( (this->bitRepresentation^old_position)^new_position ) | right_position_board );
		}

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

			if(0 == newPosition) return false; // If there was no new move

			int distance = this->getDistance(oldPosition, newPosition);

			if( (oldPosition & RooksBoard::files::file_a) != 0) // if rook is on A's only
			{
				int rank_number = this->getRankNumber( this->getPositionOfBit(newPosition) );

				if( rank_number != -1)
				{
					long rank = AbstractBoardEntity::ranks[ rank_number ];
					if( (newPosition&rank) != 0) return true; //If the horizontal move is allowed
					else 
					if( distance%8 == 0 ) return true; // If the vertical move is alowed
					else return false;
				}

			}
			else if( (oldPosition & RooksBoard::files::file_h) != 0) // if rook is on H's only
			{

			}
			else if( (oldPosition & RooksBoard::ranks[0]) != 0) // if rook is on rank_1
			{

			}
			else if( (oldPosition & RooksBoard::ranks[7]) != 0) // if rook is on rank_8
			{

			}
			else if( (oldPosition & RooksBoard::files::file_a & RooksBoard::ranks[0]) != 0) // if rook is on left lower corner.
			{

			}
			else if( (oldPosition & RooksBoard::files::file_h & RooksBoard::ranks[0]) != 0) // if rook is on right lower corner.
			{

			}
			else if( (oldPosition & RooksBoard::files::file_a & RooksBoard::ranks[7]) != 0) // if rook is on left top corner.
			{

			}
			else if( (oldPosition & RooksBoard::files::file_h & RooksBoard::ranks[7]) != 0) // if rook is on right top corner.
			{

			}
			else // rook is on the middle of no where.
			{

			}

			return false;
		};

		inline int getRankNumber(int position)
		{
			return position/8;
		};

	public:
		/**
		 * Constructor and destructor
		 * 
		 */
		RooksBoard(bool suitColor, std::string name)
		:AbstractBoardEntity(suitColor, name)
		{

		};
		~RooksBoard()
		{

		};

		/**
		 * Alters the positions at this board.
		 * 
		 */
		inline void alterBoard(bool isInitLoad, long fullboard, std::string& binaryString)
		{
			long alteredBitboard = HelperFunctions::convertStringToBitBoard(binaryString);

			if(!isInitLoad)
			{
				if(this->isMoveValid(alteredBitboard, fullboard))
				{
					int moveType = this->identifyMoveType(alteredBitboard, fullboard);
					std::cout << "moveType Rooks " << moveType << std::endl; 
					if(moveType != 0)
					{
						long cc = this->makePostCaptureBoard(alteredBitboard, fullboard, moveType);
						this->bitRepresentation = cc;
						std::cout << "capture board " << moveType << std::endl; 
						HelperFunctions::drawArrayBoardFromBitBoard(cc);
					}
					else
						this->bitRepresentation = alteredBitboard;
				}
			}
			else
			{
				this->bitRepresentation = alteredBitboard;
			}	
		};

};

#endif // _ROOKS_BOARD_H_INCLUDED_