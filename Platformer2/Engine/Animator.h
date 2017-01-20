#pragma once
#include <SFML\Graphics.hpp>
#include "GameObjects.h"
#include "Player.h"

enum AnimationType
{
	IDLE,
	ATTACK,
	DEFEND,
	RUN,
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
	void LoopAnimation(float dt);

protected:

	GameObject* owner;

	float m_timeElapsed;
	float m_timer;

	int m_column;
	int m_row;
};