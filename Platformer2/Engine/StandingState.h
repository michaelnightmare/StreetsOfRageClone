#pragma once
#include "State.h"
class StandingState : public State
{
	StandingState() {}

public:

	static StandingState* Instance();

	virtual void Enter(GameObject* owner);
	virtual void Execute(GameObject* owner);
	virtual void Exit(GameObject* owner);
};

