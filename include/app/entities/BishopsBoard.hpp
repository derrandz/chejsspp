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

		/** Returns the file or the rank on which the move is taking place.
		 * @param  old_position [description]
		 * @param  new_position [description]
		 * @return              long
		 * 
		 */
		inline long long identifyMoveField(long long old_position, long long new_position)
		{
			long long historyOfMove = old_position | new_position;

			std::cout << "historyOfMove" << std::endl;
			HelperFunctions::drawArrayBoardFromBitBoard(historyOfMove);

			/* is it left diagonal? */
			for (int i = 0; i < 15; ++i)
			{
				long long temp_one = BishopsBoard::left_diagonals[i] | historyOfMove;
				long long temp_two = temp_one ^BishopsBoard::left_diagonals[i];
			    if( temp_two == 0)
			   		return BishopsBoard::left_diagonals[i];
			}

			/* is it right diagonal? */
			for (int i = 0; i < 15; ++i)
			{
				long long temp_one = BishopsBoard::right_diagonals[i] | historyOfMove;
				long long temp_two = temp_one^ BishopsBoard::right_diagonals[i];
				if( temp_two  == 0)
					return BishopsBoard::right_diagonals[i];
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
		inline long long identifyMoveDirection(long long old_position, long long new_position)
		{
			return new_position - old_position;
		};

		inline std::string getMoveDirection(long long old_position, long long new_position)
		{
			std::string upleft    = "up_left";
			std::string downleft  = "down_left";
			std::string upright   = "up_right";
			std::string downright = "down_right";
			std::string invalid   = "invalid";

			long long direction    = this->identifyMoveDirection(old_position, new_position);
			long long rank_or_file = this->identifyMoveField(old_position, new_position);

			std::cout << "rank_or_file: " << rank_or_file << std::endl;

			if(rank_or_file == -1) return invalid;

			for (int i = 0; i < 15; ++i)
			{
				if( (rank_or_file ^ BishopsBoard::left_diagonals[i]) == 0)
				{
					if(direction > 0)
					{
						return upleft;
					}
					else
					{
						return downleft;
					}
				}
			}

			for (int i = 0; i < 15; ++i)
			{
				if( (rank_or_file ^ BishopsBoard::right_diagonals[i]) == 0)
				{
					if(direction > 0)
					{
						return upright;
					}
					else
					{
						return downright;
					}
				}
			}
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
		inline int identifyMoveType(long long old_position, long long new_position, long long fullboard, long long moveDirection)
		{

		};

		inline int getLeftDiagonalOf(long long position)
		{
			for (int i = 0; i < 15; ++i)
				if( ((BishopsBoard::left_diagonals[i] & position) ^ position) == 0 ) return i;

			return -1;
		};

		inline int getRightDiagonalOf(long long position)
		{
			for (int i = 0; i < 15; ++i)
				if( ((BishopsBoard::right_diagonals[i] & position) ^ position) == 0 ) return i;

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
		inline long long getBoardBetweenPositions(long long old_position, long long new_position, long long fullboard, long long field, std::string direction)
		{
			long long board_old_and_new         = old_position | new_position;
			long long fullboard_on_moving_field = HelperFunctions::applyMask_Keep(fullboard, field);

			long long mask = 0L;

			if( direction.compare("up_left") == 0 || direction.compare("down_left") == 0)
			{
				int rank_one = this->getRightDiagonalOf(old_position), 
					rank_two = this->getRightDiagonalOf(new_position);

					if( rank_one != -1 && rank_two != -1)
					{
						for (int i = std::max(rank_one, rank_two); i < 15; ++i)
							mask += BishopsBoard::right_diagonals[i];

						for (int i = std::min(rank_one, rank_two); i >= 0; --i)
							mask += BishopsBoard::right_diagonals[i];
					}
			}
			else if( direction.compare("up_right") == 0 || direction.compare("down_right") == 0)
			{
				long long file_one = this->getLeftDiagonalOf(old_position), 
					 file_two = this->getLeftDiagonalOf(new_position);


					if(file_one != -1 && file_two != -1)
					{
						for (int i = std::max(file_one, file_two); i < 15; ++i)
							mask += BishopsBoard::left_diagonals[i];

						for (int i = std::min(file_one, file_two); i >= 0; --i)
							mask += BishopsBoard::left_diagonals[i];
					}
			}

			std::cout << "The pitchup has moved on: " <<std::endl;
			HelperFunctions::drawArrayBoardFromBitBoard(field);

			std::cout << "The Mask that is to be applied without field " <<std::endl;
			HelperFunctions::drawArrayBoardFromBitBoard(mask);

			mask = HelperFunctions::applyMask_Keep(mask, field);

			std::cout << "The Mask that is to be applied " <<std::endl;
			HelperFunctions::drawArrayBoardFromBitBoard(mask);

			fullboard_on_moving_field = fullboard_on_moving_field ^ old_position;
			fullboard_on_moving_field = (fullboard_on_moving_field | mask) ^ mask;

			std::cout << "The fullboard" <<std::endl;
			HelperFunctions::drawArrayBoardFromBitBoard(fullboard);

			std::cout << "The fullboard after masking " <<std::endl;
			HelperFunctions::drawArrayBoardFromBitBoard(fullboard_on_moving_field);

			return fullboard_on_moving_field;			
		};

		/**
		 * [isBoardEmptyBetweenOldAndNew description]
		 * @return [description]
		 * 
		 */
		inline bool isBoardEmptyBetweenOldAndNew(long long old_position, long long new_position, long long fullboard, long long move_direction, std::string direction)
		{
			if( direction.compare("invalid") == 0 ) return false;

			long long what_in_between = this->getBoardBetweenPositions(old_position, new_position, fullboard, move_direction, direction);

			if( what_in_between == 0) return true;
			else return false;
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

			if(0 == newPosition) return false; // If there was no new move

			bool isBoardEmptyBetweenOldAndNew = this->isBoardEmptyBetweenOldAndNew( oldPosition, 
															newPosition, 
															fullboard, 
															this->identifyMoveField(oldPosition, newPosition),
															this->getMoveDirection(oldPosition, newPosition)
															);
			
			bool isNewPositionEmpty = this->isBoardIsEmptyAt(newPosition, fullboard);

			std::cout << " isBoardEmptyBetweenOldAndNew: " << isBoardEmptyBetweenOldAndNew << std::endl;
			std::cout << " isNewPositionEmpty: " << isNewPositionEmpty << std::endl;

			if(isBoardEmptyBetweenOldAndNew)
			{
				if(isNewPositionEmpty) return true;
				else
				{
					/* Save capture */
					if(this->isCaptureLegal(myFriendsBoard, newPosition))
					{
						std::cout << " isCaptureLegal: " << "true" << std::endl;
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
		BishopsBoard(bool suitColor, std::string name)
		:AbstractBoardEntity(suitColor, name)
		{

		};
		~BishopsBoard()
		{
			
		};

		/**
		 * Alters the positions at this board.
		 * 
		 */
		inline void alterBoard(bool isInitLoad, long long fullboard, long long myFriendsBoard, std::string& binaryString)
		{
			AbstractBoardEntity::alterBoard(isInitLoad, fullboard, myFriendsBoard, binaryString);
		};

};

#endif // _BISHOPS_BOARD_H_INCLUDED_