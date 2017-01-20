#include "Animator.h"
#include "GameObjects.h"
#include <iostream>
#include "Player.h"


Animator::Animator(GameObject* AnimatedObj) : owner(AnimatedObj),

m_column(0), m_row(0), m_timer(0.35f), m_timeElapsed(0.f)
{
}

void Animator::Update(sf::RenderWindow* window, float dt)
{
	//Starts idle (base row = 0, base column = 0)
	owner->body.setTextureRect(sf::IntRect(m_column * 96, m_row * 96, 96, 96));

	LoopAnimation(dt);
}

int Animator::ChooseRow(AnimationType type)
{
	switch (type)
	{
	case AnimationType::ATTACK:
	{
		return m_row = 4;
		break;
	}
	case AnimationType::DEFEND:
	{
		return m_row = 1;
		break;
	}

	case AnimationType::HIT:
	{
		return m_row = 3;
		break;
	}
	case AnimationType::RUN:
	{
		return m_row = 8;
		break;
	}
	case AnimationType::DEAD:
	{
		return m_row = 12;
		break;
	}
	default:
	{
		return m_row = 0;
		break;
	}
	}
}

void Animator::LoopAnimation(float dt)
{
	m_timeElapsed -= dt;

	if (m_timeElapsed <= 0)
	{
		m_timeElapsed = m_timer;
		m_column++;
	}

	if (m_column > 3)

	{
		m_column = 0;

		if (m_row != 18) // If character isn't dead
		{
			m_row = 0; //switch back to idle (maybe better way to do)
		}
	}
}