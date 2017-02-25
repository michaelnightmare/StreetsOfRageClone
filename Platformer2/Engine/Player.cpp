#include "Player.h"
#include "Game.h"
#include "GameObjects.h"
#include "StateMachine.h"
#include "StandingState.h"
#include <iostream>
#include "Animator.h"
#include "Approach.h"

Player::Player(std::string texturePath, sf::Vector2f pos)
	: GameObject(texturePath, pos)
	, isjumping(false)
	, jumpCooldown(0.0f)
	, isgrounded(true)
	, jumpHeight(0.f)
	
{   
	body.setSize(sf::Vector2f(200,250));
	anim = new Animator(this);

	//Init state machine and declare starting state
	m_stateMachine = new StateMachine(this);
	m_stateMachine->SetCurrentState(StandingState::Instance());

	m_depth = 0.5f;
	anim->ChooseRow(AnimationType::INTRO);
}

void Player::Update(sf::RenderWindow * window, float dt)
{
	GameObject::Update(window, dt);

	//Kinda unnessary, stop player from moving off the edge of the map
	Restrain();

	//Lower the jump cooldown
	jumpCooldown -= dt;
	
	//Account for gravity
	sf::Vector2f gravity(0.0f,0.0f);
	
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
	m_accel.y = gravity.y;

	//Check for movement commands
	//Start by zeroing out m_movement
	m_movement.x = 0.f;
	m_movement.y = 0.f;

	//Check for input and apply movement etc..
	HandleInput(dt);
	
	//Add acceleration to velocity, then add the velocity to movement

	m_movement += m_vel * dt; 
	

	//Add any movement to the player
	if (isjumping)
	{
		jumpHeight += 3000 * dt;
	}

	if (jumpHeight >= 150.f)
	{
		isjumping = false; 
	}

	//THIS BEHAVIOR SHOULD LIVE IN GAMEOBJECT
	//======================================================
	m_depth += m_movement.y / 110;

	if (m_depth >= 1.f)
		m_depth = 1.f;

	if (m_depth <= 0.f)
		m_depth = 0.0f;
	
	m_pos.x += m_movement.x;

	
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
	
	m_vel += gravity * dt;

	if (m_vel.y = 0)
	{
		isgrounded = true;
	}
	//Update the state machine
	m_stateMachine->Update();

	//Update the animator
	anim->Update(window, dt);

	//Set the body to the new position
	body.setPosition(m_pos);
}

void Player::CollidedWith(GameObject * other)
{
}

void Player::HandleInput(float dt)
{
	//KEY PRESSED
	//---------------------------------------------
	//Movement to the right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_movement.x = playerSpeed * dt;

		//When running state is added... delete the anim line and uncomment this line
		//m_stateMachine->ChangeState(RunningState::Instance());

		if (isgrounded)
		{
			anim->ChooseRow(AnimationType::RUN);
		}
	}

	//Movement to the left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		 
		m_movement.x = -playerSpeed * dt;
		if (isgrounded)
		{
			
			anim->ChooseRow(AnimationType::RUN);
		}
	}
	

	//Movement Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_movement.y = playerSpeed *dt ;
		
	
	}

	//Movement Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_movement.y = -playerSpeed *dt;
		
		
	}

	//Movement ATTACK
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		anim->ChooseRow(AnimationType::ATTACK);
	}

	//Jumping  
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isgrounded && jumpCooldown <= 0.0f )
	{
		anim->ChooseRow(AnimationType::JUMP);
		//Player isn't on the ground anymore
		isjumping = true; 
		isgrounded = false;
		

		std::cout << "Jumped";

		//Set cooldown for jump
		jumpCooldown = 1.0f;
	}



}

void Player::Restrain()
{
	//character cant leave the screen to the left
	if (body.getPosition().x < -35)
	{
		m_pos.x = -35;
	}
}

void Player::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}