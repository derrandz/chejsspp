#include "helpers/HelperFunctions.hpp"
#include <stdint.h>

#ifdef EMSCRIPTEN
	#define long int64_t;
#endif // EMSCRIPTEN

/**
 * Sets the 64bit binary string to 1 in the provided position.
 * @param binary   The binary string.
 * @param position The position at which 1 is going to take place.
 * 
 */
void HelperFunctions::setBinaryStringToOneAtPosition(std::string& binary, int position)
{
	binary.replace(position, 1, "1");
}

/**
 * Converts a binary string to a long.
 * @param  binaryString The binary string, the bitboard in bits, but in a string format.
 * @return              The binary string in long, e.g : for 0010 will return 2. 
 */
long HelperFunctions::convertStringToBitBoard(std::string& binaryString)
{
	std::cout << "HelperFunctions::convertStringToBitBoard" << std::endl;
	std::bitset<64>  x(binaryString);

	std::cout << "HelperFunctions::convertStringToBitBoard about to convert. " << std::endl;
	long convertedString = x.to_ulong();
	std::cout << "HelperFunctions::convertStringToBitBoard converted peacefully :" << convertedString << std::endl;
	return convertedString;
}

/**
 * Prints a bitboard into the screen in a form on an array.
 * @param bitboard : the actualized bitboard.
 * 
 */
void HelperFunctions::drawArrayBoardFromBitBoard(long bitboard)
{
	std::string board[8][8];

	for (int i = 0; i < 64; ++i)
	{
		board[i/8][i%8] = " . ";
	}	

	for (int i = 0; i < 64; ++i)
	{
		if(((bitboard >> i)&1) == 1) /*If it contains a 1 at i's position*/
		{
			board[7 - i/8][7 - i%8] = " P ";
		}
	}

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			std::cout << board[i][j]  << " ";
		}

		std::cout << std::endl;
	}
}

/**
 * Checks whether a and b collides, provided that a is the cursor, and b is a rect with 80x80 dimensions.
 * @param  xa [self-descriptive]
 * @param  ya [self-descriptive]
 * @param  xb [self-descriptive]
 * @param  yb [self-descriptive]
 * @return bool
 * 
 */
bool HelperFunctions::checkCollision(int xa, int ya, int xb, int yb)
{
	bool is_at_x = ( xa > xb ) && ( xa <= xb + 80 );
	bool is_at_y = ( ya >= yb ) && ( ya <= yb + 80 );

	return is_at_y && is_at_x;
}

/**
 * [maskOut description]
 * @param  long [description]
 * @param  long [description]
 * @return      [description]
 */
long HelperFunctions::applyMask_Keep(long board, long mask)
{
	return board&mask;
}

/**
 * [maskOut description]
 * @param  long [description]
 * @param  long [description]
 * @return      [description]
 */
long HelperFunctions::applyMask_Delete(long board, long mask)
{
	return ( board | mask ) ^ board;
}
