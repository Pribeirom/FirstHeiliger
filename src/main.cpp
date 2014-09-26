/*
	STARTING POINT
	this is were all framework take
	place and all pieces are tied 
	up together to form the game.
*/
#include <iostream>

#include "SDLManager.h" //will be replaced to Game class
#define sdl SDLManager::getInstance() //will be replaced to Game class

int main(int argc, char* argv[])
{
	std::cout << "main.cpp started!\n";
	
	sdl->init(); //will be replaced to Game class
	
	return 0;
}