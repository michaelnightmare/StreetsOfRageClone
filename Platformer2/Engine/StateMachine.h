#pragma once
#include "State.h"

class GameObject;

class StateMachine
{

private:
	//set owner of the instantiated state machine
	GameObject* m_pOwner;
	//set current state
	State* m_pCurrentState;
	// hold a pointer to the last state for a psuedo-stack
	State* m_pPreviousState;

public:

	StateMachine(GameObject* owner) :m_pOwner(owner),
		m_pCurrentState(nullptr),
		m_pPreviousState(nullptr){}

	virtual ~StateMachine() {}

	//used for initialization and for hard state sets
	void SetCurrentState(State* s) { m_pCurrentState = s; }
	void SetPreviousState(State* s) { m_pPreviousState = s; }


	//call this to update FSM i.e call current states execute
	void Update() const
	{
		//if current state exits, call its execute
		if (m_pCurrentState) { m_pCurrentState->Execute(m_pOwner); }
	}

	//change states: remember current state as previous, call exit of current state, set new state, call enter of current state
	void ChangeState(State* pNewState)
	{
		//keep record
		m_pPreviousState = m_pCurrentState;
		//call exit
		m_pCurrentState->Exit(m_pOwner);
		//set new state
		m_pCurrentState = pNewState;
		//enter new state
		m_pCurrentState->Enter(m_pOwner);
	}

	//go back to previous state
	void PopState()
	{
		ChangeState(m_pPreviousState);
	}
};

