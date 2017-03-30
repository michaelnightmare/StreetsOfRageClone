#include "Enemy.h"
#include <iostream>
#include "Animator.h"
#include "StateMachine.h"
#include "StandingState.h"

Enemy::Enemy(std::string texturePath, sf::Vector2f pos)
	: GameObject(texturePath, pos)
	, enemyPStart(m_pos.x, 0)
	, enemyPEnd(m_pos.x - 40, 0)
	, patrolTimer(2.f)
	, enemyAlive(true)
	

{
	body.setSize(sf::Vector2f(225, 225));

	anim = new Animator(this);
	anim->ChooseRow(AnimationType::WALKL);
	m_stateMachine = new StateMachine(this);
	//m_stateMachine->SetCurrentState(StandingState::Instance());
	movementFrame = enemyPEnd - enemyPStart;


	ZombieDSound.setBuffer(ZombieDBuffer);
	if (!ZombieDBuffer.loadFromFile("Audio/ZombieD.wav"))
	{
		std::cout << "error";
	}
	
}

void Enemy::Update(sf::RenderWindow * window, float dt)
{
	

	Patrol(dt);

	//Update state
	//m_stateMachine->Update();

	//Update animator
	anim->Update(window, dt);

	//Set the body to the new position
	body.setPosition(m_pos);

	GameObject::Update(window, dt);
}

void Enemy::CollidedWith(GameObject * other)
{
}

//void Enemy::HandleInput(float dt)
//{
//	//Movement to the right
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
//	{
//		m_movement.x = enemySpeed * dt;
//		anim->ChooseRow(AnimationType::WALK);
//	}
//	
//
//	//Movement to the left
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
//	{
//		m_movement.x = -enemySpeed * dt;
//		anim->ChooseRow(AnimationType::WALKL);
//	}
//
//
//	//Movement Up
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
//	{
//		m_movement.y = enemySpeed *dt;
//	}
//
//	//Movement Down
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
//	{
//		m_movement.y = -enemySpeed *dt;
//
//
//	}
//
//	//Movement ATTACK
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
//	{
//		anim->ChooseRow(AnimationType::DEAD);
//		ZombieDSound.play();
//	}
//	
//
//	
//	
//}



void Enemy::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}

void Enemy::Patrol(float dt)
{
	if (enemyAlive)
	{
		patrolTimer -= dt;

		if (patrolTimer <= 0.f)
		{
			movementFrame.x *= -1;
			patrolTimer = 2.f;

			if (movementFrame.x > 0)
				anim->ChooseRow(AnimationType::WALK);

			else
				anim->ChooseRow(AnimationType::WALKL);
		}

		m_pos.x += movementFrame.x *dt;
	}
	else
	{

	}
}
