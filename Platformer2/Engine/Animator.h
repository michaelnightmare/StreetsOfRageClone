#pragma once
#include <SFML\Graphics.hpp>
#include "GameObjects.h"

enum AnimationType
{
	IDLE,
	IDLEL,
	ENEMYIDLE,
	ENEMYIDLEL,
	INTRO,
	ATTACK,
	MORPH,
	RUN,
	RUNL,
	SPECIAL,
	JUMP,
	JUMPL,
	HIT,
	DEAD,
	WALK,
	WALKL
};

class Animator
{
public:
	Animator(GameObject* AnimatedObj);
	virtual void Update(sf::RenderWindow* window, float dt);

	int GetRow() { return m_row; }

	int ChooseRow(AnimationType type);
	void LoopAnimation(float dt, int framecount);
	
protected:

	GameObject* owner;

	float m_timeElapsed;
	float m_timer;
   
	int m_column;
	int m_row;
	int framecount;
};