/*
	VIRTUAL GAME STATE (BLUEPRINT)
	to be used as game state pattern
	for menus and game instances.
*/

#include <iostream>
#include <string>

class GameState
{
public:
	virtual void update() = 0;
	virtual void render() = 0;
	
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	
	virtual std::string getStateName() const = 0;
};
