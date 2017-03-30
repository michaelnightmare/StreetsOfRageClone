#include "Animator.h"
#include <iostream>


Animator::Animator(GameObject* AnimatedObj) : owner(AnimatedObj),

m_column(0), m_row(0), m_timer(0.15f), m_timeElapsed(0.f)
{
	
}

void Animator::Update(sf::RenderWindow* window, float dt)
{
	//Starts idle (base row = 0, base column = 0)
	
		owner->body.setTextureRect(sf::IntRect(m_column * 128, m_row * 128, 128, 128));
	
	LoopAnimation(dt,framecount);
}

int Animator::ChooseRow(AnimationType type)
{
	switch (type)
	{
	case AnimationType::INTRO:
	{
		framecount = 5;
		return m_row = 5;
		break;
	}

	case AnimationType::ATTACK:
	{
		framecount = 5;
		return m_row = 1;
		break;
	}
	case AnimationType::MORPH:
	{
		framecount = 5;
		return m_row = 5;
		break;
	}

	case AnimationType::HIT:
	{
		framecount = 6;
		return m_row = 6;
		break;
	}
	case AnimationType::RUN:
	{
		
		framecount = 5;
		return m_row = 3;
		break;
	}
	case AnimationType::RUNL:
	{
		
		framecount = 5;
		return m_row = 9;
		break;
	}
	case AnimationType::DEAD:
	{
		framecount = 5;
		return m_row = 4;
		break;
	}
	case AnimationType::SPECIAL:
	{
		framecount = 5;
		return m_row = 7;
		break;
	}
	case AnimationType::JUMP:
	{

		framecount = 3;
		return m_row = 2;
		break;
	}

	case AnimationType::JUMPL:
	{

		framecount = 3;
		return m_row = 8;
		break;
	}
	
	case AnimationType::IDLE:
	{
		framecount = 5;
		return m_row = 0;
		break;
	}

	case AnimationType::IDLEL :
	{
		framecount = 5;
		return m_row = 10;
		break;
	}


	case AnimationType::ENEMYIDLE:
	{
		framecount = 5;
		return m_row = 0;
		break;
	}
	case AnimationType::ENEMYIDLEL:
	{
		framecount = 5;
		return m_row = 5;
		break;
	}

	case AnimationType::WALK:
	{
		framecount = 7;
		return m_row = 3;
		break;
	}

	case AnimationType::WALKL:
	{
		framecount = 7;
		return m_row = 6;
		break;
	}

	}
}

void Animator::LoopAnimation(float dt,int framecount)
{
	m_timeElapsed -= dt;

	if (m_timeElapsed <= 0)
	{
		m_timeElapsed = m_timer;
		m_column++;
	}

	if (m_column > framecount)

	{
		m_column = 0;

		if (m_row != 18) // If character isn't dead
		{
			m_row = 0; //switch back to idle (maybe better way to do)
		}
	}
}