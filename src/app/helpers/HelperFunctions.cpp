#include "views/BoardView.hpp"
#include <stdlib.h>

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
 * Converts a binary string to a long long 
 * @param  binaryString The binary string, the bitboard in bits, but in a string format.
 * @return              The binary string in long long  e.g : for 0010 will return 2. 
 */
long long HelperFunctions::convertStringToBitBoard(std::string& binaryString)
{
	std::bitset<64>  x(binaryString);

	long long convertedString = x.to_ullong();
	return convertedString;
}

/**
 * Prints an array into the screen in a form on an array.
 * @param bitboard : the actualized bitboard.
 * 
 */
void HelperFunctions::drawArrayBoard(std::string** arrayboard)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			std::cout << arrayboard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

/**
 * Prints a bitboard into the screen in a form on an array.
 * @param bitboard : the actualized bitboard.
 * 
 */
void HelperFunctions::drawArrayBoardFromBitBoard(long long bitboard)
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
 * @param  long long [description]
 * @param  long long [description]
 * @return      [description]
 */
long long HelperFunctions::applyMask_Keep(long long board, long long mask)
{
	return board&mask;
}

/**
 * [maskOut description]
 * @param  long long [description]
 * @param  long long [description]
 * @return      [description]
 */
long long HelperFunctions::applyMask_Delete(long long board, long long mask)
{
	return ( board | mask ) ^ board;
}

/**
 * Flattens an array board for sending
 * @param	std::string** : the array board
 * @return	std::string : the flat board
 * 
 */
std::string HelperFunctions::flatten_array_board(std::string** array_board)
{
	std::string flat_board = "";
	for (int i = 0; i < 64; ++i)
	{
		flat_board += array_board[i/8][i%8] + "__";
	}

	return flat_board;
}

/**
 * Reverses flatten_array_board
 * @param	std::string : the flat board
 * @return	std::string** : the array board
 * 
 */
std::string** HelperFunctions::array_flat_board(std::string flat_board)
{
	/* Initializing the array board */
	std::string** array_board;

	array_board = new std::string*[8];
	for(int i=0; i<8; i++) array_board[i] = new std::string[8];
	/* Initializing the array board */

	std::string _flat_board_copy(flat_board); // a safe container for the flat board, as we will modifying it
	std::string delimiter = "__";
	std::string token;
	size_t pos = 0;
	int i = 0;

	while ((pos = _flat_board_copy.find(delimiter)) != std::string::npos) {
	    token = _flat_board_copy.substr(0, pos);
	    array_board[i/8][i%8] = token;
	    _flat_board_copy.erase(0, pos + delimiter.length());

	    if(i<64) i++;
	}

	return array_board;
}

/**
 * This function will be called as a callback after receiving a board from the other side throug the socket.
 *
 * @param void* : the pointer that takes cares of the visual rendering.
 * @param char* : the received flat board.
 * 
 */
void HelperFunctions::_load_received_board_success_callback(void* graphicalboard_ptr, char* received_flat_board)
{
	// BoardView
	BoardView* graphicalboard = static_cast<BoardView*>(graphicalboard_ptr);

	const char* _const_char_received_flat_board;
	_const_char_received_flat_board = static_cast<const char*>(received_flat_board);

	std::string _js_flat_board_string(_const_char_received_flat_board);
	std::cout << "std::string _js_flat_board_string(_char, 193);" << std::endl;
	
	// convert the string flat board into an array board/
	std::string** _js_validated_board = HelperFunctions::array_flat_board(_js_flat_board_string);
	std::cout << "std::string** _js_validated_board = HelperFunctions::array_flat_board(_js_flat_board_string);" << std::endl;

	//debugging
	// std::cout << "Received board: " << std::endl;
	// std::cout << "_js_flat_board_string: " << _js_flat_board_string << std::endl;
	// std::cout << "received_flat_board: " << *received_flat_board << std::endl;
	// HelperFunctions::drawArrayBoard(_js_validated_board);

	//Load the board, do not wait for receipt, instead set the mode ready to send his next move.
	graphicalboard->loadBoard(true, _js_validated_board);
}

void HelperFunctions::load_board_failure_callback(void* graphicalboard_ptr, char* validated_board)
{
	BoardView* graphicalboard = static_cast<BoardView*>(graphicalboard_ptr);
	
	std::string _js_validated_board((char*)validated_board);

	std::string** _js_validated_board_array = HelperFunctions::array_flat_board(_js_validated_board);
	
	graphicalboard->loadBoard(false, _js_validated_board_array);
}
