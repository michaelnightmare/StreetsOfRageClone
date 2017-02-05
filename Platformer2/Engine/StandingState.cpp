#include "StandingState.h"
#include <iostream>

StandingState* StandingState::Instance()
{
	static StandingState instance;
	return &instance;
}

void StandingState::Enter(GameObject * owner)
{
	//Return to idle animation here
	//Any other things that need to get done
	std::cout << "Entering Standing State... " << std::endl;
}

void StandingState::Execute(GameObject * owner)
{
	//Loop through idle, wait for input
	std::cout << "Executing Standing State... " << std::endl;
}

void StandingState::Exit(GameObject * owner)
{
	//Any exit conditions will happen here (probably not essential for this state)
	std::cout << "Exiting Standing State... " << std::endl;
}
