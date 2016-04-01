#ifndef _ABSTRACT_BOARD_ENTITY_H_INCLUDED_
#define _ABSTRACT_BOARD_ENTITY_H_INCLUDED_
#include <string>
#include <tuple>
#include <algorithm>

/**
 | =====================================================
 | The abstract class that represents a board, with bits.
 | 
 */
class AbstractBoardEntity
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */
	protected:
		/**
		 * Ranks
		 * 
		 */
		static const long ranks[8];

		/**
		 * Files
		 */
		static const long files_array[8];
		enum files_enum{
			file_a = -9187201950435737472,
			file_b = 4629771061636907072,
			file_c = 2314885530818453536,
			file_d = 1157442765409226768,
			file_e = 578721382704613384,
			file_f = 289360691352306692,
			file_g = 144680345676153346,
			file_h = 72340172838076673
		};

		/**
		 * The representation of the board in bits.
		 * 
		 */
		long bitRepresentation;

		/**
		 * Is the board representing white pieces, or black pieces.
		 * As for everything else in this game, 0 represents black.
		 * 
		 */
		bool suitColor;

		/**
		 * The name.
		 * 
		 */
		std::string name;

		/**
		 * Keeps track of the last capturing element and the position he captured
		 * As to remove the capture piece from its motherboard.
		 * 
		 */
		static std::tuple<std::string, bool, long> captures_history_utility;

	/*
	 |****************************
	 |		Methodes
	 |
	 |****************************
	 */
	protected:
		/**
		 * Takes the binary string, converts it and stores it to the bitrepresentation member.
		 * @param std::string&
		 * 
		 */
		void binaryString_toBitboard(std::string&);

		/**
		 * Judges the new move as valid or invalid.
		 * @param  long : the new board's configuration that represents the new move.
		 * @param  long : the fullboard, undistinguishable
		 * @param  long : the board of the elements with the same color, undistinguishable.
		 * @return bool : true upon valid.
		 *  
		 */
		virtual bool isMoveValid(long, long, long) = 0;

		/**
		 * Extract the diff between the new and old board.
		 * @param  newboard [description]
		 * @return          [description]
		 * 
		 */
		long extractNewMove(long newboard);

		/**
		 * Returns the bitboard in which the old position of the sliding piece figures as a 1.
		 * @param  newboard [description]
		 * @return          [description]
		 * 
		 */
		long extractOldPosition(long newboard);

		/**
		 * Determines whether the new move is a capture of a regular slide.
		 * @param  oldPosition [description]
		 * @param  newPosition [description]
		 * @param  fullboard   [description]
		 * @return             [description]
		 * 
		 */
		virtual int identifyMoveType(bool xSuitColor, long oldPosition, long newPosition) = 0;

		/**
		 * Determines whether the new position is already occupied by other pieces.
		 * @param  newposition [description]
		 * @param  fullboard   [description]
		 * @return             [description]
		 * 
		 */
		bool isBoardIsEmptyAt(long newposition, long fullboard);
		
		/**
		 * Returns the distance between the two positions.
		 * @param  oldPosition [description]
		 * @param  newPosition [description]
		 * @return             [description]
		 * 
		 */
		int getDistance(long oldPosition, long newPosition);

		/**
		 * Returns the distance between the two positions.
		 * @param  oldPosition [description]
		 * @param  newPosition [description]
		 * @return             [description]
		 * 
		 */
		int getPositionOfBit(long position);
		
		/**
		 * Tells whether the targeted position is of the enemy or of the friends.
		 * @param  myFriendsBoard [description]
		 * @param  targetPosition [description]
		 * @return                [description]
		 * 
		 */
		bool isEnemyCaptured(long myFriendsBoard, long targetPosition);	
	public:
		/**
		 * Returns the suit color.
		 * @return [description]
		 * 
		 */
		bool getSuitColor();
		
		/**
		 * Saves the capture history
		 * 
		 */
		static void saveCaptureHistory(std::string, bool, long);

		/**
		 * Returns the capture history
		 * 
		 */
		static std::tuple<std::string, bool, long> getCaptureHistory();

		/**
		 * Forgets the capture history
		 * 
		 */
		static void forgetCaptureHistory();
		
		/**
		 * Returns the bit representation of the board.
		 * @return long
		 * 
		 */
		long getBitBoard();
		
		/**
		 * Constructor and destructor
		 * 
		 */
		AbstractBoardEntity(bool suitColor, std::string name);
		~AbstractBoardEntity();

		/**
		 * Alters the positions at this board.
		 * 
		 */
		virtual void alterBoard(bool isInitLoad, long fullboard, long myFriendsBoard, std::string& binaryString) = 0;
		
		/**
		 * Returns the name of the board.
		 * @return [description]
		 * 
		 */
		std::string getName();
		
		/**
		 * Loads a bitboard without verification.
		 * @param long [description]
		 * 
		 */
		void loadbitboard(long);
			
	public: 

};

#endif // _ABSTRACT_BOARD_ENTITY_H_INCLUDED_