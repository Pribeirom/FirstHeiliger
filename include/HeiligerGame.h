#ifndef HEILIGERGAME_H
#define HEILIGERGAME_H

#include <iostream>
#include <string>
#include "SDLManager.h"
#define sdl SDLManager::getInstance()

class HeiligerGame
{
public:
	//constructor and destructor
	HeiligerGame(){};
	~HeiligerGame(){};

	void init();
	void changeGameState(std::string nameRef);

private:

}

#endif