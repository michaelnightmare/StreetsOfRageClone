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

	//Account for gravity
	/*sf::Vector2f gravity(0.0f, 600.f);
	m_accel = gravity ;*/

	//Check for movement commands

	sf::Vector2f  m_movement(0, 0);

	HandleInput(m_movement, dt);
	
	m_vel += m_accel * dt;
	m_movement += m_vel * dt;

	//Add any movement to the player

	m_pos.x += m_movement.x;
	m_pos.y += m_movement.y;
	
	/*m_pos.y = m_depth * 50 - jumpHeight;*/
	anim->Update(window, dt);

	//Set the body to the new position
	body.setPosition(m_pos);
}

void Player::CollidedWith(GameObject * other)
{
}

void Player::HandleInput(sf::Vector2f& movement, float dt)
{
	//Movement to the right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x = playerSpeed * dt;
		anim->ChooseRow(AnimationType::RUN);
	}

	//Movement to the left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x = -playerSpeed * dt;
	}

	//Movement Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement.y = m_depth - playerSpeedz * dt;
	}

	//Movement Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement.y = m_depth + playerSpeedz * dt ;
	}

	//Movement ATTACK
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		anim->ChooseRow(AnimationType::ATTACK);
	}

	//Movement DEATH
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		anim->ChooseRow(AnimationType::DEAD);
	}

	//Movement MORPH
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) )
	{
		anim->ChooseRow(AnimationType::MORPH);
	}

	//Movement HIT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		anim->ChooseRow(AnimationType::HIT);
	}

	//Movement SPECIAL
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		anim->ChooseRow(AnimationType::SPECIAL);
	}

	//Jumping  

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isgrounded)
	{
		//Player isn't on the ground anymore
		isgrounded = false;
		m_vel.y = -500.f;

		//Set cooldown for jump
		jumpCooldown = 1.5f;
	}
}

void Player::Restrain()
{
	//character cant leave the screen to the left
	if (body.getPosition().x < -35)
	{
		m_pos = sf::Vector2f(-35, body.getPosition().y);
	}
}

void Player::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}