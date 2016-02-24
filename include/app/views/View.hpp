#ifndef _VIEW_H_INCLUDED_
#define _VIEW_H_INCLUDED_

#include "../helpers/Texture.hpp"

class View
{
	/*
	 |****************************
	 |
	 |		Attributes
	 |
	 |****************************
	 */
	protected:
		/**
		 * The imageFile put in an SDL_Texture
		 * 
		 */
		Texture myTexture;

		/**
		 * The rendering rect that will specify the dimensions and coordinates.
		 * 
		 */
		SDL_Rect myRect;

	public:
		/**
		 * The path to the view file.
		 * 
		 */
		std::string filePath;

		/**
		 * The window and the renderer.
		 * 
		 */
		static SDL_Window*	 window;
		static SDL_Renderer* renderer;

		//The screen dimensions.
		static int SCREEN_WIDTH;
		static int SCREEN_HEIGHT;
	/*
	 |****************************
	 |
	 |		Methodes
	 |
	 |****************************
	 */
	protected:
		/**
		 * loads the image file to the texture.
		 * 
		 * @return boolean: returns true upon success.
		 */
		bool load();
	public: 
		/**
		 * Initializes the SDL loaders that will deal with everything about image loading.
		 * 
		 */
		static bool initSDL();

		/**
		 * Frees the SDL resources.
		 * 
		 */
		static void closeSDL();

		/**
		 * Constructor and destructor
		 * 
		 */
		View(std::string path, int height, int width, int x, int y);
		~View();
		/**
		 * Renders the actual view to the screen.
		 * 
		 */
		void render();
};

#endif _VIEW_H_INCLUDED__