#include "Player.h"
#include "Game.h"
#include "GameObjects.h"
#include <iostream>

Player::Player(std::string texturePath, sf::Vector2f pos)
	: GameObject(texturePath, pos)
	, isjumping(true)
	, jumpCooldown(0.0f)
	, isgrounded(false) 
{   
	body.setTextureRect(sf::IntRect(10, 10, 50, 100));
	body.setSize(sf::Vector2f(75,200));
}

void Player::Update(sf::RenderWindow * window, float dt)
{
	GameObject::Update(window, dt);

	//character cant leave the screen to the left
	if (body.getPosition().x < 0)
	{
		m_pos = sf::Vector2f(0, body.getPosition().y);
	}
	//player cant jump out of the top of the screen
	if (body.getPosition().y < 150)
	{
		m_pos = sf::Vector2f(body.getPosition().x, 150);
	}

	//Lower the jump cooldown
	jumpCooldown -= dt;

	//Account for gravity
	sf::Vector2f gravity(0.0f, 600.f);
	m_accel = gravity ;

	//Check for movement commands

	sf::Vector2f  m_movement(0, 0);

	//Movement to the right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_movement.x = playerSpeed * dt;
	}

	//Movement to the left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_movement.x = -playerSpeed * dt;
	}

	//Jumping  

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isgrounded || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isgrounded)
	{
		//Player isn't on the ground anymore
		isgrounded = false;
		m_vel.y = -500.f ;

		//Set cooldown for jump
		jumpCooldown = 1.5f;
	}

	m_vel += m_accel * dt;
	m_movement += m_vel * dt;

	//Add any movement to the player

	m_pos.x += m_movement.x;
	m_pos.y += m_movement.y;

	if (isgrounded)
	{
		m_pos.y -= m_movement.y;
	}

	//Set the body to the new position
	body.setPosition(m_pos);
}

void Player::CollidedWith(GameObject * other)
{
	Platform* platform = dynamic_cast<Platform*>(other);

	if (platform)
	{
		isgrounded = true;
	}
	else 
	{
		isgrounded = false;
	}
}

void Player::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}