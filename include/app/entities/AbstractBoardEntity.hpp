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
		virtual bool isMoveValid(long) = 0;

	public:
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
		AbstractBoardEntity(bool suitColor);
		~AbstractBoardEntity();

		/**
		 * Alters the positions at this board.
		 * 
		 */
		virtual void alterBoard(std::string& binaryString) = 0;

	public: 

};

#endif // _ABSTRACT_BOARD_ENTITY_H_INCLUDED_