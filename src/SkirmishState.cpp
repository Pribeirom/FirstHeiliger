/*
 * Skirmish Game State
 */

#include "SkirmishState.h"

const std::string SkirmishState::s_skirmishName = "SKIRMISH";

void SkirmishState::update()
{
	//intentionally left blank
}

void SkirmishState::render()
{
	//intentionally left blank
}

bool SkirmishState::onEnter()
{
	std::cout << "entering Skirmish state\n";
	return true;
}

bool SkirmishState::onExit()
{
	std::cout << "exiting Skirmish state\n";
	return true;
}

}


