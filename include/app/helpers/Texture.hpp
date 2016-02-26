#ifndef __TEXTURE_H_INCLUDED__
#define __TEXTURE_H_INCLUDED__

#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <sstream>

using namespace std;


//Texture wrapper class
class Texture
{
	/*
	 |****************************
	 |
	 |		Attributes
	 |
	 |****************************
	 */
	private:
		//The actual texture
		SDL_Texture* texture;

		//Image dimensions
		int width;
		int height;

	/*
	 |****************************
	 |
	 |		Methodes
	 |
	 |****************************
	 */
	public:
		//Initializes variables
		Texture(int=40, int=40);

		//Deallocates memory
		~Texture();

		//Loads image at specified path
		bool loadFromFile( std::string path );

		//Creates image from font string
		#ifdef _SDL_TTF_H
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		#endif
		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

		//Gets image dimensions
		int getWidth();

		//Gets image dimentions
		int getHeight();
};



#endif // TEXTURE_H_INCLUDED
