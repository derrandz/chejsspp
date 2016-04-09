#ifndef _MAIN_BOARD_H_INCLUDED_
#define _MAIN_BOARD_H_INCLUDED_

#include <map>
#include <utility>

/*#ifdef EMSCRIPTEN
	#ifndef _long_DEFINED_AS_int64_t_
		#define _long_DEFINED_AS_int64_t_
		#define long int64_t
	#endif // _long_DEFINED_AS_int64_t_
#endif // EMSCRIPTEN*/

#ifndef _ABSTRACT_BOARD_ENTITY_H_INCLUDED_

class AbstractBoardEntity;

#endif //_ABSTRACT_BOARD_ENTITY_H_INCLUDED_ 

typedef std::map<std::string, AbstractBoardEntity*>::iterator subbitboards_it;

class MainBoard
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */
	private:
		/**
		 * All the 12 boards.
		 *
		 */
		std::map<std::string, AbstractBoardEntity*> subBitboards;

		/**
		 * A bitmap for the positions, regardless of their respective boards.
		 * 
		 */
		long long fullboard;

		/**
		 * White elements' board
		 * 
		 */
		long long whites_board;

		/**
		 * Black elements' board
		 * 
		 */
		long long blacks_board;

	/*
	 |****************************
	 |		Methodes
	 |
	 |****************************
	 */
	private:
		/**
		 * Alter the provided sub bitboard out of the 12 sub bitboards.
		 * @param boardName    The name of the board, serves as an index to find it.
		 * @param binaryString The bitboard that is going to be applied.
		 * 
		 */
		void alterSubBitboard(bool isInitLoad, std::string boardName, std::string& binaryString);

		/**
		 * Parses the array into a bitboard
		 * @param std::string The array containing the 'graphical' board./
		 * 
		 */
		void arrayBoard_toBitboard(bool isInitLoad, std::string arrayBoard[][8]);

		/**
		 * Loads a given configuration of the board.
		 * @param std::string[][] The array board.
		 * 
		 */
		void loadConfiguration(bool isInitLoad, std::string conf[][8]);

		/**
		 * Returns the final board by superpositioning all of the 12 boards with the use of logical bitwise operators and chess rules.
		 * @return long long : the final bitboard
		 * For debuggin purposes.
		 * 
		 */
		long long getFinalBoard();

		/**
		 * Updates the state of the final board, but in an unrecognizable way of just bitmapping everything.
		 * 
		 */
		void updateFullboard();

		/**
		 * Updates the state of the white final board, but in an unrecognizable way of just bitmapping everything.
		 * 
		 */
		void updateWhitesBoard();
		void updateBlacksBoard();
		
		long long getWhitesBoard();
		long long getBlacksBoard();

		/**
		 * returns a specified color's board
		 * @param  suitcolor [description]
		 * @return           [description]
		 * 
		 */
		long long getFulllboardOfColor(bool suitcolor);
		
	public:
		/**
		 * returns the final bitboard
		 * @return [description]
		 * 
		 */
		long long get_final_bit_board();
		
		/**
		 * Applies the capture to the rest of the boards to propogate changes.
		 * 
		 */
		void applyCaptureHistory();

		/**
		 * Returns the final board in an array form
		 * @return std::string**
		 *         
		 */
		std::string** getFinalArrayBoard();

		/**
		 * Constructor and destructor
		 * 
		 */
		MainBoard();
		~MainBoard();

		/**
		 * Destroys one particular sub bitboard.
		 * @param std::string : The index at which the board is residing at the map.
		 * 
		 */
		void destructSubBitboard(std::string name);

		/**
		 * Initializes the board with a standard chess board configuration.
		 * 
		 */
		void initStandardBoard();

		/**
		 * Initializes the board with a standard chess board configuration.
		 * 
		 */
		void initBy(std::string conf[][8]);

		/**
		 * Takes an array board and tries to apply it to the bitboards, with validation, and returns an array board generated from the new state of the bitboard.
		 * @param std::string** 
		 * @return std::string**
		 * 
		 */
		std::string** validateMoves(std::string conf[][8], bool mainPlayerColor);

		/**
		 * For debugging.
		 * 
		 */
		void drawBoard();

		/**
		 * For debugging.
		 * 
		 */
		void drawFullBoard();
};

#endif // _MAIN_BOARD_H_INCLUDED_