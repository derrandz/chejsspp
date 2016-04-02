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

		/**
		 * Takes out the board elements whos number is higher than the bitNumber provided.
		 * @param  board     [description]
		 * @param  bitNumber [description]
		 * @return           [description]
		 * 
		 */
		inline long copyBoardTilBit(long board, int bitNumber)
		{
			std::string binary = "0000000000000000000000000000000000000000000000000000000000000000";

			for (int i = 1; i <= bitNumber ; ++i)
			{
				long tmp = board>>i;
				
				tmp &= ~tmp+1; //LSB

				if( tmp&1 == 1 )
					HelperFunctions::setBinaryStringToOneAtPosition(binary, 63 - i);
			}
			return HelperFunctions::convertStringToBitBoard(binary);
		};

	protected:
		/**
		 * Returns the file or the rank on which the move is taking place.
		 * @param  old_position [description]
		 * @param  new_position [description]
		 * @return              long
		 * 
		 */
		inline long identifyMoveField(long old_position, long new_position)
		{
			long historyOfMove = old_position | new_position;

			std::cout << "historyOfMove" << std::endl;
			HelperFunctions::drawArrayBoardFromBitBoard(historyOfMove);

			/* is it file? */
			for (int i = 0; i < 8; ++i)
			{
				long temp_one = RooksBoard::files_array[i] | historyOfMove;
				long temp_two = temp_one ^RooksBoard::files_array[i];
			    if( temp_two == 0)
			   		return RooksBoard::files_array[i];
			}
			
			/* is it rank? */
			for (int i = 0; i < 8; ++i)
			{
				long temp_one = RooksBoard::ranks[i] | historyOfMove;
				long temp_two = temp_one^ RooksBoard::ranks[i];
				if( temp_two  == 0)
					return RooksBoard::ranks[i];
			}

			return -1;
		};

		/**
		 * Idenitifies the direction
		 * @param  old_position [description]
		 * @param  new_position [description]
		 * @return              [description]
		 * 
		 */
		inline long identifyMoveDirection(long old_position, long new_position)
		{
			return new_position - old_position;
		};

		inline std::string getMoveDirection(long old_position, long new_position)
		{
			std::string up      = "up";
			std::string down    = "down";
			std::string left    = "left";
			std::string right   = "right";
			std::string invalid = "invalid";

			long direction    = this->identifyMoveDirection(old_position, new_position);
			long rank_or_file = this->identifyMoveField(old_position, new_position);

			if(rank_or_file == -1) return invalid;

			for (int i = 0; i < 8; ++i)
			{
				if( (rank_or_file ^ RooksBoard::ranks[i]) == 0)
				{
					if(direction > 0)
					{
						return left;
					}
					else
					{
						return right;
					}
				}
			}

			for (int i = 0; i < 8; ++i)
			{
				if( (rank_or_file ^ RooksBoard::files_array[i]) == 0)
				{
					if(direction > 0)
					{
						return up;
					}
					else
					{
						return down;
					}
				}
			}
		};

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

		/**
		 * Overridding the unimplemented identifyMoveType
		 * @param  old_position  [description]
		 * @param  newPosition   [description]
		 * @param  fullboard     [description]
		 * @param  moveDirection [description]
		 * @return               [description]
		 * 
		 */
		inline int identifyMoveType(long old_position, long new_position, long fullboard, long moveDirection)
		{

		};

		inline int getRankOf(long position)
		{
			for (int i = 0; i < 8; ++i)
				if( ((RooksBoard::ranks[i] & position) ^ position) == 0 ) return i;

			return -1;
		};

		inline int getFileOf(long position)
		{
			for (int i = 0; i < 8; ++i)
				if( ((RooksBoard::files_array[i] & position) ^ position) == 0 ) return i;

			return -1;
		};

		/**
		 * [getBoardBetweenPositions description]
		 * @param  old_position [description]
		 * @param  new_position [description]
		 * @param  direction    [description]
		 * @return              [description]
		 * 
		 */
		inline long getBoardBetweenPositions(long old_position, long new_position, long fullboard, long field, std::string direction)
		{
			long board_old_and_new         = old_position | new_position;
			long fullboard_on_moving_field = HelperFunctions::applyMask_Keep(fullboard, field);

			long mask = 0L;

			if( direction.compare("up") == 0 || direction.compare("down") == 0)
			{
				int rank_one = this->getRankOf(old_position), 
					rank_two = this->getRankOf(new_position);

					if( rank_one != -1 && rank_two != -1)
					{
						for (int i = std::max(rank_one, rank_two); i < 8; ++i)
							mask += RooksBoard::ranks[i];

						for (int i = std::min(rank_one, rank_two); i >= 0; --i)
							mask += RooksBoard::ranks[i];
					}
			}
			else if( direction.compare("left") == 0 || direction.compare("right") == 0)
			{
				long file_one = this->getFileOf(old_position), 
					 file_two = this->getFileOf(new_position);


					if(file_one != -1 && file_two != -1)
					{
						for (int i = std::max(file_one, file_two); i < 8; ++i)
							mask += RooksBoard::files_array[i];

						for (int i = std::min(file_one, file_two); i >= 0; --i)
							mask += RooksBoard::files_array[i];
					}
			}

			mask = HelperFunctions::applyMask_Keep(mask, field);

			fullboard_on_moving_field = fullboard_on_moving_field ^ old_position;
			fullboard_on_moving_field = (fullboard_on_moving_field | mask) ^ mask;

			return fullboard_on_moving_field;			
		};

		/**
		 * [isBoardEmptyBetweenOldAndNew description]
		 * @return [description]
		 * 
		 */
		inline bool isBoardEmptyBetweenOldAndNew(long old_position, long new_position, long fullboard, long move_direction, std::string direction)
		{
			if( direction.compare("invalid") == 0 ) return false;

			long what_in_between = this->getBoardBetweenPositions(old_position, new_position, fullboard, move_direction, direction);

			if( what_in_between == 0) return true;
			else return false;
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

			if(0 == newPosition) return false; // If there was no new move

			bool isBoardEmptyBetweenOldAndNew = this->isBoardEmptyBetweenOldAndNew( oldPosition, 
															newPosition, 
															fullboard, 
															this->identifyMoveField(oldPosition, newPosition),
															this->getMoveDirection(oldPosition, newPosition)
															);
			
			bool isNewPositionEmpty = this->isBoardIsEmptyAt(newPosition, fullboard);

			if(isBoardEmptyBetweenOldAndNew)
			{
				if(isNewPositionEmpty) return true;
				else
				{
					/* Save capture */
					if(this->isCaptureLegal(myFriendsBoard, newPosition))
					{
						AbstractBoardEntity::saveCaptureHistory(this->name, this->suitColor, newPosition);
						return true;
					}
					else
						return false;
				}
			}
			else
				return false;
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
		inline void alterBoard(bool isInitLoad, long fullboard, long myFriendsBoard, std::string& binaryString)
		{
			long alteredBitboard = HelperFunctions::convertStringToBitBoard(binaryString);

			if(!isInitLoad)
			{
				if(this->isMoveValid(alteredBitboard, fullboard, myFriendsBoard))
				{
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