#ifndef HEILIGERGAME_H
#define HEILIGERGAME_H

#include <iostream>
#include <string>
#include "SDLManager.h"
#define sdl SDLManager::getInstance()

class HeiligerGame
{
public:
	void init();
	
	void handleEvents();
	void update();
	void render();
	
	void changeGameState(std::string nameRef);

	//constructor and destructor
	HeiligerGame(){};
	~HeiligerGame(){};
private:
	bool isRunning;
	bool isPaused;
	

};

#endif