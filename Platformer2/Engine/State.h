#pragma once

class GameObject;

class State
{
public:
	virtual			~State() {}

	virtual void	Enter(GameObject*) = 0;
	virtual void	Execute(GameObject*) = 0;
	virtual void	Exit(GameObject*) = 0;
};