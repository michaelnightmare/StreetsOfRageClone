#include "Player.h"

Player::Player(std::string texturePath, sf::Vector2f pos)
	: GameObject(texturePath, m_size, pos)
	, isjumping(false)
	, jumpcd(0.0f)
	, playerInAir(false)
	, isgrounded(true)
{
	//m_sprite.setOrigin(m_sprite.getTextureRect().width * 0.5f, m_sprite.getTextureRect().height * 0.5f);
}

void Player::Update(sf::RenderWindow * window, float dt)
{
	//---------------------------------------------------

	jumpcd -= dt;
	sf::Vector2f gravity(0.0f, 10.f);
	accel = gravity;

	GameObject::Update(window, dt);

	//Movement of Character

	sf::Vector2f  m_movement(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_movement.x = Ps * dt;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_movement.x = -Ps * dt;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_movement.y = Ps * dt;
	}

	//Jumping  

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isgrounded || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isgrounded)
	{
		isjumping = true;
		m_vel.y = -70;
	}

	m_vel += accel *dt;
	m_movement += m_vel * dt;

	m_pos.x += m_movement.x;

	//OLD COLLISION DETECTION, KEEPING AROUND UNTIL COLLISION METHOD IS SOLIDIFIED

	//for (int i = 0; i < m_owner->m_gameObjects.size(); i++)
	//{
	//	GameObject* current = m_owner->m_gameObjects[i];
	//	if (current != this)
	//	{
	//		if (current->Collision(this))
	//		{
	//			m_pos.x -= m_movement.x;
	//			break;
	//		}
	//	}	
	//}

	m_pos.y += m_movement.y;

	isgrounded = false;

	//OLD COLLISION DETECTION, KEEPING AROUND UNTIL COLLISION METHOD IS SOLIDIFIED

	//for (int i = 0; i < m_owner->m_gameObjects.size(); i++)
	//{
	//	GameObject* current = m_owner->m_gameObjects[i];
	//	
	//	if (current != this)
	//	{
	//		if (current->Collision(this))
	//		{
	//			m_pos.y -= m_movement.y;
	//			m_vel.y = 0;
	//			isgrounded = true; 
	//			
	//			break;
	//		}
	//	}
	//}

	m_sprite.setPosition(m_pos);
}

void Player::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
	window->draw(body);
}