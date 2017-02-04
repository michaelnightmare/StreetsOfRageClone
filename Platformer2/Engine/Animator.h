#pragma once
#include <SFML\Graphics.hpp>
#include "GameObjects.h"
#include "Player.h"

enum AnimationType
{
	IDLE,
	INTRO,
	ATTACK,
	MORPH,
	RUN,
	RUNL,
	SPECIAL,
	JUMP,
	HIT,
	DEAD
};

class Animator
{
public:
	Animator(GameObject* AnimatedObj);
	virtual void Update(sf::RenderWindow* window, float dt);

	int GetRow() { return m_row; }

	int ChooseRow(AnimationType type);
	void LoopAnimation(float dt, int framecount);
	bool flip;

protected:

	GameObject* owner;

	float m_timeElapsed;
	float m_timer;
   
	int m_column;
	int m_row;
	int framecount;
};