#include "SDLManager.h"

// SINGLETON PATTERN
SDLManager* SDLManager::m_pSDLManagerInstance = nullptr;
SDLManager* SDLManager::getInstance()
{
	if(!m_pSDLManagerInstance)
		m_pSDLManagerInstance = new SDLManager();
		
	return m_pSDLManagerInstance;
}

std::string SDLManager::getResourcePath(std::string path)
{
	#ifdef _WIN32
		const char PATH_SEP = '\\';
	#else
		const char PATH_SEP = '/';
	#endif
	
	static std::string baseRes;
	if (baseRes.empty())
	{
		char *basePath = SDL_GetBasePath();
		if (basePath)
		{
			baseRes = basePath;
			SDL_free(basePath);
		} else {
			std::cout << "Error getting resource path: " << SDL_GetError() << std::endl;
			return "";
		}
		size_t pos = baseRes.rfind("bin");
		baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
	}
	
	if (path.empty())
	{
		return baseRes;
	} else if (PATH_SEP == '\\') {
		std::replace(path.begin(), path.end(), '/', PATH_SEP);
	}
	return baseRes+path;
}

// INITIALIZATION AND CLEANING
bool SDLManager::init(const char* windowTitle, int x, int y, int w, int h, int initFlag, int windowFlag, int rendererFlag)
{
	std::cout << "initializing SDL:\n";
	
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
	
	std::cout << "SDL is fully functional!\n";
	return true;
	
}

void SDLManager::clean()
{
	std::cout << "cleaning SDL...";
	
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
	
	std::cout << "Ok!\n";
}

// IMAGE MANAGEMENT (LOADING, DRAWING, ETC)
bool SDLManager::loadImage(std::string filePath, std::string nameRef)
{
	std::cout << "loading image: " << filePath.c_str() << "... ";
	
	SDL_Surface* pTempSurface = IMG_Load(filePath.c_str());
	if(!pTempSurface)
	{
		std::cout << "\n\tError: " << IMG_GetError() << std::endl;
		return false;
	}
	
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(m_pRenderer ,pTempSurface);
	SDL_FreeSurface(pTempSurface);
	
	if(!pTexture)
	{
		std::cout << "\n\tError: " << IMG_GetError() << std::endl;
		return false;
	}
	
	imageMap[nameRef] = pTexture;
	std::cout << "Ok!\n";
	return true;
}

void SDLManager::drawImage(std::string nameRef, int x, int y, double r, double xScale, double yScale, SDL_Point* center, SDL_RendererFlip flipFlag)
{
	SDL_Rect srcRect;
	SDL_Rect desRect;
	srcRect.x = srcRect.y = 0;
	SDL_QueryTexture(imageMap[nameRef], nullptr, nullptr, &srcRect.w, &srcRect.h);
	desRect.x = x;
	desRect.y = y;
	desRect.w = srcRect.w*xScale;
	desRect.h = srcRect.h*yScale;
	
	SDL_RenderCopyEx(m_pRenderer, imageMap[nameRef], &srcRect, &desRect, r, center, flipFlag);
}