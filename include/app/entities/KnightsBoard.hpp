#ifndef __H_INCLUDED_
#define __H_INCLUDED_

#include "entities/AbstractBoardEntity.hpp"

class KnightsBoard : public AbstractBoardEntity
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */

	/*
	 |****************************
	 |		Methodes
	 |
	 |****************************
	 */
	protected:
		/**
		 * Judges the new move as valid or invalid.
		 * @param  long : the new board's configuration that represents the new move.
		 * @return bool : true upon valid.
		 *  
		 */
		inline bool isMoveValid(long move, long fullboard)
		{
			return true;
		};

	public:
		/**
		 * Constructor and destructor
		 * 
		 */
		KnightsBoard(bool suitColor)
		:AbstractBoardEntity(suitColor)
		{

		};
		~KnightsBoard()
		{
			
		}

		/**
		 * Alters the positions at this board.
		 * 
		 */
		inline void alterBoard(bool isInitLoad, long fullboard, std::string& binaryString)
		{
			AbstractBoardEntity::alterBoard(isInitLoad, fullboard, binaryString);
		};

};

#endif // __H_INCLUDED_