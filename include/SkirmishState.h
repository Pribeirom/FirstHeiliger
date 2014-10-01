/*
	SKIRMISH GAME STATE
	instance that will handle a 
	short battle with few player
	objectives. Designed to be
	a fast, sidequest, non-crucial
	instance.
*/

#include "GameState.h"

class SkirmishState : public GameState
{
public:
	virtual void update();
	virtual void render();
	
	virtual bool onEnter();
	virtual bool onExit();
	
	virtual std::string getStateName() const { return s_skirmishName; }

private:
	static const std::string s_skirmishName;
};