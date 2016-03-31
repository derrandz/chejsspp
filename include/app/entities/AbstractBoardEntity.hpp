#ifndef _ABSTRACT_BOARD_ENTITY_H_INCLUDED_
#define _ABSTRACT_BOARD_ENTITY_H_INCLUDED_
#include <string>
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
		static std::pair<std::string, long> captures_history_utility;

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
		 * @return bool : true upon valid.
		 *  
		 */
		virtual bool isMoveValid(long, long) = 0;

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
		
	public:
		/**
		 * Saves the capture history
		 * 
		 */
		static void saveCaptureHistory(std::string, long);

		/**
		 * Returns the capture history
		 * 
		 */
		static std::pair<std::string,long> getCaptureHistory();

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
		virtual void alterBoard(bool isInitLoad, long fullboard, std::string& binaryString) = 0;
		
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