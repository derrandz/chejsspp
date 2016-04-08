#ifndef _VIEW_H_INCLUDED_
#define _VIEW_H_INCLUDED_

#include "../helpers/Texture.hpp"
#include <vector>
#include "helpers/_ExceptionHandler.hpp"

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

		/**
		 * The path to the view file.
		 * 
		 */
		std::string filePath;

	public:
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

		/**
		 * Utility method. Detects whether the click is on this view or not.
		 * 
		 */
		bool isSelected(int x, int y);

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
		View(){ };
		View(std::string path, int x, int y, int height, int width);
		~View();
		
		/**
		 * Renders the actual view to the screen.
		 * 
		 */
		virtual void render();

		/**
		 * Renders the actual view to the screen.
		 * 
		 */
		virtual void render(int x, int y);

		/**
		 * Handles the events related to this view, keyboard and mouse events.
		 * @param e SDL_Event
		 * 
		 */
		virtual void handleEvents(SDL_Event& e);
};

#endif _VIEW_H_INCLUDED__