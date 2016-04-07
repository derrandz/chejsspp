#ifndef _HELPER_FUNCTIONS_H_INCLUDED_
#define _HELPER_FUNCTIONS_H_INCLUDED_
#include <string>
#include <bitset>
#include <iostream>

/*#ifdef EMSCRIPTEN
	#ifndef _long_DEFINED_AS_int64_t_
		#define _long_DEFINED_AS_int64_t_
		#define long int64_t
	#endif // _long_DEFINED_AS_int64_t_
#endif // EMSCRIPTEN*/

namespace HelperFunctions
{
	/**
	 * Sets the 64bit binary string to 1 in the provided position.
	 * @param binary   The binary string.
	 * @param position The position at which 1 is going to take place.
	 * 
	 */
	void setBinaryStringToOneAtPosition(std::string& binary, int position);

	/**
	 * Converts a binary string to a lon longg.
	 * @param  binaryString The binary string, the bitboard in bits, but in a string format.
	 * @return              The binary string in long long, e.g : for 0010 will return 2. 
	 */
	long long convertStringToBitBoard(std::string&);

	/**
	 * Prints a bitboard into the screen in a form on an array.
	 * @param bitboard : the actualized bitboard.
	 * 
	 */
	void drawArrayBoardFromBitBoard(long long bitboard);

	/**
	 * Checks whether a and b collides, provided that a is the cursor, and b is a rect with 80x80 dimensions.
	 * @param  xa [self-descriptive]
	 * @param  ya [self-descriptive]
	 * @param  xb [self-descriptive]
	 * @param  yb [self-descriptive]
	 * @return bool
	 * 
	 */
	bool checkCollision(int xa, int ya, int xb, int yb);

	/**
	 * [maskOut description]
	 * @param  long long [description]
	 * @param  long long [description]
	 * @return      [description]
	 */
	long long applyMask_Keep(long long board, long long mask);

	/**
	 * [maskOut description]
	 * @param  long long [description]
	 * @param  long long [description]
	 * @return      [description]
	 */
	long long applyMask_Delete(long long board, long long mask);
};

#endif // _HELPER_FUNCTIONS_H_INCLUDED_