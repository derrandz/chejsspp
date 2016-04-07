#include "entities/MainBoard.hpp"
#include "helpers/HelperFunctions.hpp"
#include "entities/PawnsBoard.hpp"
#include "entities/KnightsBoard.hpp"
#include "entities/KingBoard.hpp"
#include "entities/QueenBoard.hpp"
#include "entities/RooksBoard.hpp"
#include "entities/BishopsBoard.hpp"
#include <sstream>

/**
 * Applies the capture to the rest of the boards to propogate changes.
 * 
 */
void MainBoard::applyCaptureHistory()
{
	std::tuple<std::string, bool, long long> captures_history = AbstractBoardEntity::getCaptureHistory();

	if(std::get<0>(captures_history).compare(" ") != 0)
	{
		long long blacks = 0L;
		long long whites = 0L;

		for (subbitboards_it it = this->subBitboards.begin(); it != this->subBitboards.end() ; ++it)
		{
			std::string board_name = it->second->getName();
			bool suitcolor         = it->second->getSuitColor();

			if(board_name.compare(std::get<0>(captures_history)) != 0 && !(suitcolor&std::get<1>(captures_history)))
			{
				long long bitboard = it->second->getBitBoard();

				if( (bitboard & std::get<2>(captures_history)) != 0 )
				{
					bitboard = bitboard ^ std::get<2>(captures_history);
					it->second->loadbitboard(bitboard);
				}
			}

			if(board_name.compare("b") > -1) blacks += it->second->getBitBoard();
			else if(board_name.compare("w") > -1) whites += it->second->getBitBoard();
		}

		HelperFunctions::drawArrayBoardFromBitBoard(blacks);
		HelperFunctions::drawArrayBoardFromBitBoard(whites);

		AbstractBoardEntity::forgetCaptureHistory();
	}
	
}

/**
 * Updates the state of the final board, but in an unrecognizable way of just bitmapping everything.
 * 
 */
void MainBoard::updateFullboard()
{
	this->updateWhitesBoard();
	this->updateBlacksBoard();

	this->fullboard = this->getWhitesBoard() | this->getBlacksBoard();
}

/**
 * Updates the state of the white final board, but in an unrecognizable way of just bitmapping everything.
 * 
 */
void MainBoard::updateWhitesBoard()
{
	long long xfullboard = 0L;
	
	for (subbitboards_it it = this->subBitboards.begin(); it != this->subBitboards.end() ; ++it)
	{
		if(it->second->getSuitColor())
		{
			xfullboard += it->second->getBitBoard();
		}
	}

	this->whites_board = xfullboard;
}

void MainBoard::updateBlacksBoard()
{
	long long xfullboard = 0L;
	
	for (subbitboards_it it = this->subBitboards.begin(); it != this->subBitboards.end() ; ++it)
	{
		if( ! it->second->getSuitColor() )
		{
			xfullboard += it->second->getBitBoard();
		}
	}

	this->blacks_board = xfullboard;
}

long long MainBoard::getWhitesBoard()
{
	return this->whites_board;
}

long long MainBoard::getBlacksBoard()
{
	return this->blacks_board;
}

long long MainBoard::getFulllboardOfColor(bool suitcolor)
{
	if(suitcolor)
	{
		return this->getWhitesBoard();
	}
	else
	{
		return this->getBlacksBoard();
	}
}

/**
 * Alter the provided sub bitboard out of the 12 sub bitboards.
 * @param boardName    The name of the board, serves as an index to find it.
 * @param binaryString The bitboard that is going to be applied.
 * 
 */
void MainBoard::alterSubBitboard(bool isInitLoad, std::string boardName, std::string& binaryString)
{
	subbitboards_it iterator;

	if(boardName.compare(" ") != 0)
	{
		iterator = this->subBitboards.find(boardName);

		if( iterator != this->subBitboards.end())
		{
			iterator->second->alterBoard(isInitLoad, this->fullboard, this->getFulllboardOfColor(iterator->second->getSuitColor()), binaryString);
		}
	}

	this->applyCaptureHistory();
}

/**
 * Parses the array into a bitboard
 * @param std::string The array containing the 'graphical' board./
 * 
 */
void MainBoard::arrayBoard_toBitboard(bool isInitLoad, std::string arrayBoard[][8])
{
	std::string bP = "0000000000000000000000000000000000000000000000000000000000000000";
	std::string bK = "0000000000000000000000000000000000000000000000000000000000000000";
	std::string bQ = "0000000000000000000000000000000000000000000000000000000000000000";
	std::string bB = "0000000000000000000000000000000000000000000000000000000000000000";
	std::string bN = "0000000000000000000000000000000000000000000000000000000000000000";
	std::string bR = "0000000000000000000000000000000000000000000000000000000000000000";

	std::string wP = "0000000000000000000000000000000000000000000000000000000000000000";
	std::string wK = "0000000000000000000000000000000000000000000000000000000000000000";
	std::string wQ = "0000000000000000000000000000000000000000000000000000000000000000";
	std::string wB = "0000000000000000000000000000000000000000000000000000000000000000";
	std::string wN = "0000000000000000000000000000000000000000000000000000000000000000";
	std::string wR = "0000000000000000000000000000000000000000000000000000000000000000";

	for (int i = 0; i < 64; ++i)
	{
		/**
		 * Black pieces
		 */
		if(arrayBoard[i/8][i%8].compare("bR") == 0)
		{ 
			HelperFunctions::setBinaryStringToOneAtPosition(bR, i);
		}else

		if(arrayBoard[i/8][i%8].compare("bN") == 0)
		{ 
			HelperFunctions::setBinaryStringToOneAtPosition(bN, i);
		}else

		if(arrayBoard[i/8][i%8].compare("bB") == 0)
		{ 
			HelperFunctions::setBinaryStringToOneAtPosition(bB, i);
		}else

		if(arrayBoard[i/8][i%8].compare("bK") == 0)
		{ 
			HelperFunctions::setBinaryStringToOneAtPosition(bK, i);
		}else

		if(arrayBoard[i/8][i%8].compare("bQ") == 0)
		{ 
			HelperFunctions::setBinaryStringToOneAtPosition(bQ, i);
		}else

		if(arrayBoard[i/8][i%8].compare("bP") == 0)
		{ 
			HelperFunctions::setBinaryStringToOneAtPosition(bP, i);
		}else

		/**
		 * White pieces
		 */
		if(arrayBoard[i/8][i%8].compare("wR") == 0)
		{ 
			HelperFunctions::setBinaryStringToOneAtPosition(wR, i);
		}else

		if(arrayBoard[i/8][i%8].compare("wN") == 0)
		{ 
			HelperFunctions::setBinaryStringToOneAtPosition(wN, i);
		}else

		if(arrayBoard[i/8][i%8].compare("wB") == 0)
		{ 
			HelperFunctions::setBinaryStringToOneAtPosition(wB, i);
		}else

		if(arrayBoard[i/8][i%8].compare("wK") == 0)
		{ 
			HelperFunctions::setBinaryStringToOneAtPosition(wK, i);
		}else

		if(arrayBoard[i/8][i%8].compare("wQ") == 0)
		{ 
			HelperFunctions::setBinaryStringToOneAtPosition(wQ, i);
		}else

		if(arrayBoard[i/8][i%8].compare("wP") == 0)
		{ 
			HelperFunctions::setBinaryStringToOneAtPosition(wP, i);
		}
	}

		this->alterSubBitboard(isInitLoad, "bP", bP);
		this->alterSubBitboard(isInitLoad, "bK", bK);
		this->alterSubBitboard(isInitLoad, "bQ", bQ);
		this->alterSubBitboard(isInitLoad, "bB", bB);
		this->alterSubBitboard(isInitLoad, "bN", bN);
		this->alterSubBitboard(isInitLoad, "bR", bR);

		this->alterSubBitboard(isInitLoad, "wP", wP);
		this->alterSubBitboard(isInitLoad, "wK", wK);
		this->alterSubBitboard(isInitLoad, "wQ", wQ);
		this->alterSubBitboard(isInitLoad, "wB", wB);
		this->alterSubBitboard(isInitLoad, "wN", wN);
		this->alterSubBitboard(isInitLoad, "wR", wR);
}

/**
 * Loads a given configuration of the board.
 * 
 */
void MainBoard::loadConfiguration(bool isInitLoad, std::string conf[][8])
{
	std::cout << "MainBoard::loadConfiguration" << std::endl;
	this->arrayBoard_toBitboard(isInitLoad, conf);
	this->updateFullboard();
	std::cout << "MainBoard::loadConfiguration done" << std::endl;
}

/**
 * Initializes the board with a standard chess board configuration.
 * 
 */
void MainBoard::initStandardBoard()
{
	std::cout << "MainBoard::initStandardBoard" << std::endl;
	std::string standardBoard[8][8] = {
		{"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"},
		{"bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP"},
		{" ", " ", " ", " ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " ", " ", " ", " "},
		{"wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP"},
		{"wR", "wN", "wB", "wK", "wQ", "wB", "wN", "wR"},
	};

	this->loadConfiguration(true, standardBoard);
}

/**
 * Returns the final board by superpositioning all of the 12 boards with the use of logical bitwise operators and chess rules.
 * @return long long : the final bitboard
 */
long long MainBoard::getFinalBoard()
{
	long long finalBitboard = 0L;

	// std::string binaryTestBoard = "1111111100000000000000000000000000000000000000000000000011111111";
	
	for (subbitboards_it it = this->subBitboards.begin(); it != this->subBitboards.end() ; ++it)
	{
		finalBitboard += it->second->getBitBoard();
	}

	return (finalBitboard);
}

/**
 * Returns the final board in an array form
 * @return std::string**
 *         
 */
std::string** MainBoard::getFinalArrayBoard()
{
	std::string** board;

	board = new std::string*[8];
	for(int i=0; i<8; i++) board[i] = new std::string[8];

	long long bR, bN, bB, bK, bQ, bP;
	long long wR, wN, wB, wK, wQ, wP;

	/**
	 * Black bitboards
	 */
	bR = (this->subBitboards.find("bR") != this->subBitboards.end()) ? this->subBitboards["bR"]->getBitBoard() : 0L;
	bN = (this->subBitboards.find("bN") != this->subBitboards.end()) ? this->subBitboards["bN"]->getBitBoard() : 0L;
	bB = (this->subBitboards.find("bB") != this->subBitboards.end()) ? this->subBitboards["bB"]->getBitBoard() : 0L;
	bK = (this->subBitboards.find("bK") != this->subBitboards.end()) ? this->subBitboards["bK"]->getBitBoard() : 0L;
	bQ = (this->subBitboards.find("bQ") != this->subBitboards.end()) ? this->subBitboards["bQ"]->getBitBoard() : 0L;
	bP = (this->subBitboards.find("bP") != this->subBitboards.end()) ? this->subBitboards["bP"]->getBitBoard() : 0L;

	/**
	 * White bitboards.
	 * 
	 */
	wR = (this->subBitboards.find("wR") != this->subBitboards.end()) ? this->subBitboards["wR"]->getBitBoard() : 0L;
	wN = (this->subBitboards.find("wN") != this->subBitboards.end()) ? this->subBitboards["wN"]->getBitBoard() : 0L;
	wB = (this->subBitboards.find("wB") != this->subBitboards.end()) ? this->subBitboards["wB"]->getBitBoard() : 0L;
	wK = (this->subBitboards.find("wK") != this->subBitboards.end()) ? this->subBitboards["wK"]->getBitBoard() : 0L;
	wQ = (this->subBitboards.find("wQ") != this->subBitboards.end()) ? this->subBitboards["wQ"]->getBitBoard() : 0L;
	wP = (this->subBitboards.find("wP") != this->subBitboards.end()) ? this->subBitboards["wP"]->getBitBoard() : 0L;

	for (int i = 0; i < 64; ++i)
	{
		/**
		 * Black pieces
		 */
		if((bR >> i)&1)
		{ 

			board[7 - i/8][7 - i%8] = "bR";
		
		}else

		if((bN >> i)&1)
		{ 

			board[7 - i/8][7 - i%8] = "bN";
		
		}else

		if((bB >> i)&1)
		{ 

			board[7 - i/8][7 - i%8] = "bB";
		
		}else

		if((bK >> i)&1)
		{ 

			board[7 - i/8][7 - i%8] = "bK";
		
		}else

		if((bQ >> i)&1)
		{ 

			board[7 - i/8][7 - i%8] = "bQ";
		
		}else

		if((bP >> i)&1)
		{ 

			board[7 - i/8][7 - i%8] = "bP";
		
		}else

		/**
		 * White pieces
		 */
		if((wR >> i)&1)
		{ 

			board[7 - i/8][7 - i%8] = "wR";
		
		}else

		if((wN >> i)&1)
		{ 

			board[7 - i/8][7 - i%8] = "wN";
		
		}else

		if((wB >> i)&1)
		{ 

			board[7 - i/8][7 - i%8] = "wB";
		
		}else

		if((wK >> i)&1)
		{ 

			board[7 - i/8][7 - i%8] = "wK";
		
		}else

		if((wQ >> i)&1)
		{ 

			board[7 - i/8][7 - i%8] = "wQ";
		
		}else

		if((wP >> i)&1)
		{ 

			board[7 - i/8][7 - i%8] = "wP";
		
		}
		else
		{
			board[7 - i/8][7 - i%8] = " ";
		}
	}

	return board;
}

/**
 * Constructor and destructor
 * 
 */
MainBoard::MainBoard()
{
    std::cout << "MainBoard::MainBoard" << std::endl;
	/**
	 * Black pieces
	 */
	this->subBitboards["bR"] = new RooksBoard(false, "bR");
	this->subBitboards["bB"] = new BishopsBoard(false, "bB");
	this->subBitboards["bK"] = new KingBoard(false, "bK");
	this->subBitboards["bQ"] = new QueenBoard(false, "bQ");
	this->subBitboards["bP"] = new PawnsBoard(false, "bP");
	this->subBitboards["bN"] = new KnightsBoard(false, "bN");

	/**
	 * White pieces
	 */
	this->subBitboards["wR"] = new RooksBoard(true, "wR");
	this->subBitboards["wB"] = new BishopsBoard(true, "wB");
	this->subBitboards["wK"] = new KingBoard(true, "wK");
	this->subBitboards["wQ"] = new QueenBoard(true, "wQ");
	this->subBitboards["wP"] = new PawnsBoard(true, "wP");
	this->subBitboards["wN"] = new KnightsBoard(true, "wN");
    std::cout << "MainBoard::MainBoard done" << std::endl;
}

MainBoard::~MainBoard()
{
	for (subbitboards_it it = this->subBitboards.begin(); it != this->subBitboards.end(); ++it)
	{
		delete it->second;
	    this->subBitboards.erase(it);
	}
}

/**
 * Destroys one particular sub bitboard.
 * @param std::string : The index at which the board is residing at the map.
 * 
 */
void MainBoard::destructSubBitboard(std::string name)
{
	subbitboards_it itr = this->subBitboards.find(name);

	if (itr != this->subBitboards.end())
	{
	    delete itr->second;
	    this->subBitboards.erase(itr);
	}
}

/**
 * Initializes the board with a standard chess board configuration.
 * 
 */
void MainBoard::initBy(std::string conf[][8])
{
	this->loadConfiguration(true, conf);
}

/**
 * For debugging.
 * 
 */
void MainBoard::drawBoard()
{
	long long finalBoard = this->getFinalBoard();
	std::cout << std::endl << "----- ----- ----- Arrayboard from bitboards ----- ----- -----" << std::endl;
	HelperFunctions::drawArrayBoardFromBitBoard(finalBoard);	
	std::cout << std::endl << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
}

/**
 * For debugging.
 * 
 */
void MainBoard::drawFullBoard()
{
	std::cout << std::endl << "----- ----- ----- Arrayboard from fullboard ----- ----- -----" << std::endl;
	HelperFunctions::drawArrayBoardFromBitBoard(this->fullboard);	
	std::cout << std::endl << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
}

/**
 * Takes an array board and tries to apply it to the bitboards, with validation, and returns an array board generated from the new state of the bitboard.
 * @param std::string** 
 * @return std::string**
 * 
 */
std::string** MainBoard::validateMoves(std::string arrayBoard[][8], bool mainPlayerColor)
{
	if(mainPlayerColor)
	{
		this->loadConfiguration(false, arrayBoard);
	}
	else
	{
		std::string reversedBoard[8][8];
	
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				reversedBoard[7-i][7-j] = arrayBoard[i][j];
			}
		}
		
		this->loadConfiguration(false, reversedBoard);
	}

	return this->getFinalArrayBoard();
}