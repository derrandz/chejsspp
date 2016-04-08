#ifndef _PIECE_VIEW_H_INCLUDED_
#define _PIECE_VIEW_H_INCLUDED_

#include "views/View.hpp"
#include "helpers/HelperFunctions.hpp"
#include "helpers/_ExceptionHandler.hpp"

class PieceView : public View
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */
	protected:
		/**
		 * White for true
		 * Black for false // Since Black is the absence of light.
		 */
		bool suitColor;

		/**
		 * Name
		 */
		std::string name;
	/*
	 |****************************
	 |		Methodes
	 |
	 |****************************
	 */
	protected:
		/**
		 |
		 | getWhiteSuitPath() & getBlackSuitPath() Methods Description
		 |============================================================
		 |
		 |	Our problem is as follows:
		 |		Our base class is PieceView, and it has for each piece type a derivetive.
		 |		We need to put a path for black and white suits, for each piece type, so that
		 |		in the constructor, we would be able to specify what suit is for what piece, dynamically.
		 |		
		 |		
		 |		Doing so in the base class would not respond to our needs.
		 |		So, as you might have guessed, we will put for each derivetive class a static attribute,
		 |		with these two overriden methods to return the proper path to the base constructor.
		 |	
		 |		This way, we would have solved our issue.
		 */
		/**
		 * Returns the white suit's path's class attribute's of the derivetives.
		 * 
		 * @return std::string&
		 */
		inline virtual std::string getWhiteSuitPath()
		{

		}

		/**
		 * Returns the black suit's path's class attribute's of the derivetives.
		 * 
		 * @return std::string&
		 */
		inline virtual std::string getBlackSuitPath()
		{
			
		}

		/**
		 * [isAt description]
		 * @param  x int
		 * @param  y int
		 * @return   boolean
		 * 
		 */
		inline bool isAt(int x, int y)
		{
			bool is_at_x = ( x > myRect.x ) && (x <= myRect.x + myRect.w);
			bool is_at_y = ( y >= myRect.y ) && (y <= myRect.y + myRect.h );

			return is_at_y && is_at_x;
		};

		/**
		 * Finds the exact square's coordinates that x and y collides with.
		 * @param  x : The x coordinate of the colliding piece
		 * @param  y : the y coordinate of the colliding piece
		 * @return   int* : returns [x, y] of the found square. returns [-1, -1] upon failure.
		 * 
		 */
		inline int* findDest(int x, int y)
		{
			int* found_coordinates = new int[2];

			if(x >= 0 && x < 640 /2)
			{
				if( y >= 0 && y < 640 /2)
				{
					/**
					 * This represents the top left side of the board.
					 */
					for (int i = 0; i < 4; ++i)
					{
						for (int j = 0; j < 4; ++j)
						{
							if(HelperFunctions::checkCollision(x, y, i*80, j*80))
							{
								found_coordinates[0] = i*80;
								found_coordinates[1] = j*80;
							}
						}
					}
				}
				else if( y >= 640 /2 && y < 640)
				{
					/**
					 * This represents the bottom left side of the board.
					 */
					for (int i = 4; i < 8; ++i)
					{
						for (int j = 0; j < 4; ++j)
						{
							if(HelperFunctions::checkCollision(x, y, i*80, j*80))
							{
								found_coordinates[0] = i*80;
								found_coordinates[1] = j*80;
							}
						}
					}
				}

			}
			else if( x >= 640 / 2 && x < 640)
			{
				if( y >= 0 && y < 640 /2)
				{
					/**
					 * This represents the top right side of the board.
					 */
					for (int i = 0; i < 4; ++i)
					{
						for (int j = 4; j < 8; ++j)
						{
							if(HelperFunctions::checkCollision(x, y, i*80, j*80))
							{
								found_coordinates[0] = i*80;
								found_coordinates[1] = j*80;
							}
						}
					}
				}
				else if( y >= 640 /2 && y < 640)
				{
					/**
					 * This represents the bottom right side of the board.
					 */
					for (int i = 4; i < 8; ++i)
					{
						for (int j = 4; j < 8; ++j)
						{
							if(HelperFunctions::checkCollision(x, y, i*80, j*80))
							{
								found_coordinates[0] = i*80;
								found_coordinates[1] = j*80;
							}
						}
					}
				}
			}
			else
			{
				found_coordinates[0] = -1;
				found_coordinates[1] = -1;		
			}

			return found_coordinates;
		};

	public: 
		/**
		 * Constructor and destructor
		 * 
		 */
		PieceView() { };
		PieceView(bool suitColor, std::string name, int x, int y, int height, int width)
		:View("", x, y, height, width)
		{
			this->name      = name;
			this->suitColor = suitColor;
			this->myRect.h  = height;
			this->myRect.w  = width;
			this->myRect.x  = x;
			this->myRect.y  = y;
		};
		
		~PieceView()
		{
			
		}

		/**
		 * Handles the events related to this view, keyboard and mouse events.
		 * @param e SDL_Event
		 * 
		 */
		inline void handleEvents(SDL_Event& e)
		{
		};

		/**
		 * Moves the pieces to the described coordinates.
		 * @param x coordinate x.
		 * @param y coordinate y.
		 * 
		 */
		inline virtual void move(int x, int y)
		{
			this->myRect.x = x;
			this->myRect.y = y;
		};

		/**
		 * Returns the x coordinate.
		 * @return int
		 * 
		 */
		inline int getX()
		{
			return this->myRect.x;
		}
		
		/**
		 * Returns the y coordinate
		 * @return int
		 * 
		 */
		inline int getY()
		{
			return this->myRect.y;
		}

		/**
		 * returns the name
		 * @return std::string
		 * 
		 */
		inline std::string getName()
		{
			return this->name;
		}
};

#endif // _PIECE_VIEW_H_INCLUDED_