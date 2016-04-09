#include "controllers/BoardsController.hpp"
#include "views/PawnView.hpp"
#include "views/BoardView.hpp"
#include "entities/AbstractBoardEntity.hpp"
#include "entities/MainBoard.hpp"
#include "helpers/javascript_api.hpp"

/**
 * BEHOLD THE GODS OF DEATH AND LIFE.
 * 
 */
BoardsController::BoardsController()
{
	this->bitboard = NULL;
}

BoardsController::~BoardsController()
{
	delete this->bitboard;
}

/**
 * Bootstrap's the controller with whatever configuration specified.
 * 
 */
void BoardsController::bootstrap()
{
	this->bitboard = new MainBoard();
	this->bitboard->initStandardBoard();

	BoardView* ptr;
	try
	{
	    ptr = new BoardView(true, this->bitboard->getFinalArrayBoard());
	    // this->bitboard->drawBoard();
	}
	catch(const _ExceptionHandler& exception)
    {
        std::cout << "Exception raised at _$BoardsController::bootstrap:  const _ExceptionHandler&" << std::endl;
        std::cout << "Exception caught in the main loop: " << std::endl;
        std::cout << "\t" << "_$BoardsController::bootstrap" << std::endl;
        throw exception;
    }
    catch(const std::exception& exception)
    {
        std::cout << "Exception caught at: _$BoardsController::bootstrap: const std::exception&  " << std::endl;
        throw exception;
    }
    catch(...)
    {
        std::cout << "Could not catch this: _$BoardsController::bootstrap." << std::endl;
        std::exception_ptr eptr;
        eptr = std::current_exception();
        std::rethrow_exception(eptr);
    }

    this->registerView(ptr);
	// mainBoard.drawBoard();
}
/**
 * Handles any event specified.
 * 
 */
void BoardsController::handleEvents(SDL_Event& e)
{
	AbstractController::handleEvents(e);
}
/**
 * A supply method that will take whatever logic supplied and make sure it is run in the controller.
 * 
 */
void BoardsController::mainAction() const
{
	this->validateMoves();
}

/**
 * Takes the board configuration from the BoardView, sends it to the bitboard for validation.
 *
 * If it is valid, the bitboard will take the changes and return the BoardView's version again.
 * Otherwise, it will revert the BoardView's configuration to the right one.
 * 
 */
void BoardsController::validateMoves() const
{
	long long old_bit_board, new_bit_board;

	//Since that is the only view we have pushed for this controller.
	BoardView* graphicalboard = dynamic_cast<BoardView*>(*(this->viewsContainer.begin()));

	// std::cout << std::endl << std::endl << "----- ----- Graphical Board [Before validation]----- -----" << std::endl;
	// graphicalboard->drawBoard();
	// std::cout << std::endl << std::endl << "----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;

	std::string** validated_configuration;
	
	old_bit_board = this->bitboard->get_final_bit_board();

	validated_configuration = this->bitboard->validateMoves( graphicalboard->boardConfiguration , graphicalboard->getMainPlayerColor() );	

	new_bit_board = this->bitboard->get_final_bit_board();

	// std::cout << std::endl << std::endl << "----- ----- The validated board is :----- -----" << std::endl;
	// this->bitboard->drawBoard();
	// this->bitboard->drawFullBoard();
	// std::cout << std::endl << std::endl << "----- ----- ----- ----- ----- ----- ----- -----" << std::endl;

#ifdef EMSCRIPTEN
		std::cout << "EMSCRIPTEN_SOCKET" << std::endl;
		if(graphicalboard->isReceiving())
		{
			std::cout << "Board Receiving" << std::endl;
			char* _js_flat_board_char;
			bool javascript_api_response = javascript_api::receive_board(&_js_flat_board_char);
			std::string _js_flat_board_string(_js_flat_board_char);
			
			if(_js_flat_board_string.compare("__null__") != 0)
			{
				if(javascript_api_response) // double check
				{
					std::string** _js_validated_board = HelperFunctions::array_flat_board(_js_flat_board_string);
					std::cout << "Received board: " << std::endl;
					HelperFunctions::drawArrayBoard(_js_validated_board);
					graphicalboard->loadBoard(true, _js_validated_board);
				}
				else
				{
					std::cout << "Did not receive board yet." << std::endl;
					graphicalboard->loadBoard(false, validated_configuration);
				}
			}
			else
			{
				std::cout << "Did not receive board yet." << std::endl;
				graphicalboard->loadBoard(false, validated_configuration);
			}
		}
		else
		{
			if(this->send_move(old_bit_board, new_bit_board))
			{
				std::string flat_board = HelperFunctions::flatten_array_board(validated_configuration);
				std::cout << "Sending flat board: " << flat_board << std::endl;
				javascript_api::send_board(flat_board.c_str());
				//Take off him the control as he played a valid move and he needs to wait for the other side.
				graphicalboard->loadBoard(false, validated_configuration);
			}
			else
			{
				//Hand him over the control again as to play a valid move.
				graphicalboard->loadBoard(true, validated_configuration);
			}
		}
#else
	graphicalboard->loadBoard(true, validated_configuration);
#endif // EMSCRIPTEN

	// std::cout << std::endl << std::endl << "----- ----- Graphical Board [After Validation] ----- -----" << std::endl;
	// graphicalboard->drawBoard();
	// std::cout << std::endl << std::endl << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
}

/**
 * Tells whether a move has been applied to the board or not.
 *  
 */
bool BoardsController::send_move(long long old_board, long long validated_board) const
{
	long long result = old_board ^ validated_board;
	if(result == 0) return false;
	return true;
}