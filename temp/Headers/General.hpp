#ifndef __GENERAL_H_INCLUDED__
#define __GENERAL_H_INCLUDED__

#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <sstream>

using namespace std;

extern SDL_Renderer* gRenderer; //The window renderer

extern const int boardHeight;
extern const int boardWidth;
extern const int squareHeight;
extern const int squareWidth;

#endif // __GENERAL_H_INCLUDED__