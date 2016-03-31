#ifndef _HELPER_FUNCTIONS_H_INCLUDED_
#define _HELPER_FUNCTIONS_H_INCLUDED_
#include <string>
#include <bitset>
#include <iostream>

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
	 * Converts a binary string to a long.
	 * @param  binaryString The binary string, the bitboard in bits, but in a string format.
	 * @return              The binary string in long, e.g : for 0010 will return 2. 
	 */
	long convertStringToBitBoard(std::string&);

	/**
	 * Prints a bitboard into the screen in a form on an array.
	 * @param bitboard : the actualized bitboard.
	 * 
	 */
	void drawArrayBoardFromBitBoard(long bitboard);

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
};

#endif // _HELPER_FUNCTIONS_H_INCLUDED_