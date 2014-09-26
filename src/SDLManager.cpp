#include "SDLManager.h"

// SINGLETON PATTERN
SDLManager* SDLManager::m_pSDLManagerInstance = nullptr;
SDLManager* SDLManager::getInstance()
{
	if(!m_pSDLManagerInstance)
		m_pSDLManagerInstance = new SDLManager();
		
	return m_pSDLManagerInstance;
}
//

// INITIALIZATION AND CLEANING
bool SDLManager::init(const char* windowTitle, int x, int y, int w, int h, int initFlag, int windowFlag, int rendererFlag)
{
	std::cout << "initializing SDL...\n";
	
	std::cout << "\tSDL_init... ";
	if(SDL_Init(initFlag) == -1)
	{
		std::cout << "Error: SDL couldn't be initialized. - " << SDL_GetError() << std::endl;
		return false;
	}
	std::cout << "Ok!\n";

	std::cout << "\tSDL_CreateWindow... ";
	m_pWindow = SDL_CreateWindow(windowTitle, x, y, w, h, windowFlag);
	if(!m_pWindow)
	{
		std::cout << "Error: Couldn't create window. - " << SDL_GetError() << std::endl;
		return false;
	}
	std::cout << "Ok!\n";	

	// attention for the renderer type
	std::cout << "\tSDL_CreateRenderer... ";
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, rendererFlag);
	if(!m_pRenderer)
	{
		std::cout << "Error: Couldn't create renderer. - " << SDL_GetError() << std::endl;
		return false;
	}
	std::cout << "Ok!\n";
	
	std::cout << "SDL was properly initialized!\n";
	return true;
	
}

void SDLManager::clean()
{
	std::cout << "cleaning SDL...";
}