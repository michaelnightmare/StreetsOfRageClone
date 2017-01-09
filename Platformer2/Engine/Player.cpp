#include "Player.h"
#include "Game.h"
#include "GameObjects.h"
#

Player::Player(std::string texturePath, sf::Vector2f size, sf::Vector2f pos)
	: GameObject(texturePath, size, pos)
	, isjumping(true)
	, jumpCooldown(0.0f)
	, isgrounded(false)
{
}

void Player::Update(sf::RenderWindow * window, float dt)
{
	GameObject::Update(window, dt);

	//Lower the jump cooldown
	jumpCooldown -= dt;

	//Account for gravity
	sf::Vector2f gravity(0.0f, 5.f);
	m_accel = gravity;

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
		m_vel.y = -70.f;

		//Set cooldown for jump
		jumpCooldown = 1.5f;
	}

	m_vel += m_accel * dt;
	m_movement += m_vel * dt;

	//Add any movement to the player

	m_pos.x += m_movement.x;
	m_pos.y += m_movement.y;

	//Check if player is colliding with a platform
	for (int i = 0; i < m_owner->m_gameObjects.size(); i++)
		{
			GameObject* current = m_owner->m_gameObjects[i];
			
			//Check if current object is a platform
			Platform* platform = dynamic_cast<Platform*>(current);

			//If it is a platform
			if (platform )
			{
				//if player is colliding with platform

				// WHY IS THIS BEING SET TO TRUE EVERY LOOP EVEN WHEN THERES NO COLLISION????????

				//The Reason Gravity isn't working (And he phases through the ground when it decides to work)

				//===========================================================================================================
				if (this->GetCollider().CheckCollision(platform->GetCollider(), 1.0f));
				{
					//Undo the y move
					m_pos.y -= m_movement.y;

					//Set velocity to 0 in the y
					m_vel.y = 0;

					//Player is on the ground
					isgrounded = true;

					break;
				}
				//===========================================================================================================
			}
			
		}

	//Set the body to the new position
	body.setPosition(m_pos);
}

void Player::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}