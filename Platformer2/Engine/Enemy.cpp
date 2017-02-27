#include "Enemy.h"
#include <iostream>
#include "Animator.h"
#include "StateMachine.h"
#include "StandingState.h"

Enemy::Enemy(std::string texturePath, sf::Vector2f pos)
	: GameObject(texturePath, pos)
	, isjumping(false)
	, jumpCooldown(0.0f)
	, isgrounded(true)
	, jumpHeight(0.f)

{
	body.setSize(sf::Vector2f(225, 225));

	anim = new Animator(this);
	m_stateMachine = new StateMachine(this);
	m_stateMachine->SetCurrentState(StandingState::Instance());

	m_depth = 0.5f;

	ZombieDSound.setBuffer(ZombieDBuffer);
	if (!ZombieDBuffer.loadFromFile("Audio/ZombieD.wav"))
	{
		std::cout << "error";
	}
	
}

void Enemy::Update(sf::RenderWindow * window, float dt)
{
	GameObject::Update(window, dt);

	//Kinda unnessary, stop player from moving off the edge of the map
	Restrain();

	//Lower the jump cooldown
	jumpCooldown -= dt;

	//Account for gravity
	sf::Vector2f gravity(0.0f, 0.0f);

	//If player is on the ground dont apply gravity
	if (isgrounded)
	{
		gravity.y = 0.f;
	}
	else //Player is in the air, apply said gravity
	{
		gravity.y = -300.f * dt;
	}

	//Add gravity into acceleration
	m_accel.y += gravity.y;

	//Check for movement commands
	//Start by zeroing out m_movement
	m_movement.x = 0.f;
	m_movement.y = 0.f;

	//Check for input and apply movement etc..
	HandleInput(dt);

	//Add acceleration to velocity, then add the velocity to movement
	m_vel += m_accel * dt;
	m_movement += m_vel * dt;


	//Add any movement to the player

	//THIS BEHAVIOR SHOULD LIVE IN GAMEOBJECT
	//======================================================
	m_depth += m_movement.y / 110;

	if (m_depth >= 1.f)
		m_depth = 1.f;

	if (m_depth <= 0.f)
		m_depth = 0.0f;

	m_pos.x += m_movement.x;

	//y pos = depth * -roadHeight + (top of road) minus jumpHeight
	m_pos.y = m_depth * -110 + 410 - jumpHeight;
	jumpHeight += gravity.y;
	//=======================================================

	//Clamp jumpHeight
	if (jumpHeight <= 0)
	{
		jumpHeight = 0.f;
	}

	//Check if player is on the ground
	if (jumpHeight == 0)
	{
		isgrounded = true;
	}

	m_vel = m_vel + gravity * dt;

	if (m_vel.y = 0)
	{
		isgrounded = true;
	}

	//Update state
	m_stateMachine->Update();

	//Update animator
	anim->Update(window, dt);

	//Set the body to the new position
	body.setPosition(m_pos);
}

void Enemy::CollidedWith(GameObject * other)
{
}

void Enemy::HandleInput(float dt)
{
	//Movement to the right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
	{
		m_movement.x = enemySpeed * dt;
		anim->ChooseRow(AnimationType::RUNL);
	}
	

	//Movement to the left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
	{
		m_movement.x = -enemySpeed * dt;
		anim->ChooseRow(AnimationType::RUNL);
	}


	//Movement Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
	{
		m_movement.y = enemySpeed *dt;
	}

	//Movement Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
	{
		m_movement.y = -enemySpeed *dt;


	}

	//Movement ATTACK
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
	{
		anim->ChooseRow(AnimationType::DEAD);
		ZombieDSound.play();
	}
	

	//Jumping  
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isgrounded && jumpCooldown <= 0.0f)
	{
		anim->ChooseRow(AnimationType::JUMP);
		//Player isn't on the ground anymore
		isgrounded = false;
		jumpHeight = m_vel.y + 150.f;

		std::cout << "Jumped";

		//Set cooldown for jump
		jumpCooldown = 1.0f;
	}
	
}

void Enemy::Restrain()
{
	//character cant leave the screen to the left
	if (body.getPosition().x < -35)
	{
		m_pos.x = -35;
	}
}

void Enemy::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}