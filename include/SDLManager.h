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
#include <map>
#include <algorithm>
#include "SDL.h"
#include "SDL_image.h"

class SDLManager
{
public:
	//singleton pattern
	static SDLManager* getInstance();
	std::string getResourcePath(std::string path = "");
	
	//housekeeping
	void sayHello(){ std::cout << "SDLManager.h loaded!\n"; };

	//initialization and cleaning
	bool init(const char* windowTitle = "Default Game Window", int x = 0, int y = 0, int w = 640, int h = 480, int initFlag = SDL_INIT_EVERYTHING, int windowFlag = SDL_WINDOW_SHOWN, int rendererFlag = SDL_RENDERER_ACCELERATED);
	void clean();
	
	//image management (loading, drawing, etc.)
	bool loadImage(std::string filePath, std::string nameRef);
	void drawImage(std::string nameRef, int x = 0, int y = 0, double r = 0.0, double xScale = 1.0, double yScale = 1.0, SDL_Point* center = nullptr, SDL_RendererFlip flipFlag = SDL_FLIP_NONE);
	
	~SDLManager(){};
private:
	//singleton pattern
	static SDLManager* m_pSDLManagerInstance;
	
	//window and renderer handlers
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	
	//image management (loading, drawing, etc.)
	std::map<std::string, SDL_Texture*> imageMap;
	
	SDLManager(){};
};

#endif