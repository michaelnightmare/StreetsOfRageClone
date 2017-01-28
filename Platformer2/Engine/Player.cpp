#include "Player.h"
#include "Game.h"
#include "GameObjects.h"
#include <iostream>
#include "Animator.h"

Player::Player(std::string texturePath, sf::Vector2f pos)
	: GameObject(texturePath, pos)
	, isjumping(false)
	, jumpCooldown(0.1f)
	, isgrounded(true)
	, jumpHeight(0.f)
{   
	body.setSize(sf::Vector2f(200,250));
	anim = new Animator(this);
}

void Player::Update(sf::RenderWindow * window, float dt)
{
	GameObject::Update(window, dt);

	Restrain();

	//Lower the jump cooldown
	jumpCooldown -= dt;
	jumpHeight -= dt;

	//Account for gravity
	sf::Vector2f gravity(0.0f, -20.f);
	m_accel = gravity;

	//Check for movement commands
	//Start by zeroing out m_movement
	m_movement.x = 0.f;
	m_movement.y = 0.f;

	HandleInput(dt);
	
	m_vel += m_accel * dt;
	m_movement += m_vel * dt;

	//Add any movement to the player

	//THIS BEHAVIOR SHOULD LIVE IN GAMEOBJECT
	//======================================================
	m_depth += m_movement.y / 110;

	if (m_depth >= 1)
		m_depth = 1.f;
	if (m_depth <= 0)
		m_depth = 0;

	m_pos.x += m_movement.x;

	//y pos = depth * roadHeight + min (top of road) plus the height of the jump
	m_pos.y = m_depth * -110 + 410 + jumpHeight;
	

	if (jumpHeight <= 0)
	{
		jumpHeight = 0.f;
	}
	//=======================================================
	
	/*m_pos.y = m_depth * 110 - jumpHeight;*/
	anim->Update(window, dt);

	//Set the body to the new position
	body.setPosition(m_pos);
}

void Player::CollidedWith(GameObject * other)
{
}

void Player::HandleInput(float dt)
{
	//Movement to the right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_movement.x = playerSpeed * dt;
		anim->ChooseRow(AnimationType::RUN);
	}

	//Movement to the left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_movement.x = -playerSpeed * dt;
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && jumpCooldown <= 0.f)
	{
		//Player isn't on the ground anymore
		//isgrounded = false;
		jumpHeight = -100.f;

		//Set cooldown for jump
		jumpCooldown = 1.5f;
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