/*
	SDL MANAGER SINGLETON
	A class that holds all info and
	functions relative to deal with
	Simple Direct Layer to create
	windows, to properly treat inputs,
	to manage textures and so on and
	so forth.
*/

#ifndef SDLMANAGER_H
#define SDLMANAGER_H

#include <iostream>
#include <string>
#include "SDL.h"

class SDLManager
{
public:
	//singleton pattern
	static SDLManager* getInstance();
	
	//housekeeping
	void sayHello(){ std::cout << "SDLManager.h loaded!\n"; };

	//initialization and cleaning
	bool init(const char* windowTitle = "Default Game Window", int x = 0, int y = 0, int w = 640, int h = 480, int initFlag = SDL_INIT_EVERYTHING, int windowFlag = SDL_WINDOW_SHOWN, int rendererFlag = SDL_RENDERER_ACCELERATED);
	void clean();
	
	~SDLManager(){};
private:
	//singleton pattern
	static SDLManager* m_pSDLManagerInstance;
	
	//window and renderer handlers
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	
	SDLManager(){};
};

#endif