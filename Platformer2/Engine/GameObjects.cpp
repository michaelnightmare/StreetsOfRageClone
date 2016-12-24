#include "stdafx.h"
#include "GameObjects.h"
#include "Game.h"
#include <iostream>
#include <vector>

GameObject::GameObject(std::string texturePath, sf::Vector2f pos)
	: m_pos(pos)
	

{

	m_sprite.setPosition(m_pos);

	if (texturePath != "")
	{
		m_texture.loadFromFile(texturePath);
		m_sprite.setTexture(m_texture);

	}

	Top = m_sprite.getPosition().y;
	Bottom = m_sprite.getPosition().y + m_sprite.getScale().y;
	Right = m_sprite.getPosition().x + m_sprite.getScale().x;
	Left = m_sprite.getPosition().x;
	m_vel.x = 0;
	m_vel.y = 0;
	


}

void GameObject::Update(sf::RenderWindow * window, float dt)
{
//	m_sprite.setPosition(m_pos);
}



void GameObject::Draw(sf::RenderWindow * window)
{
	window->draw(m_sprite);
}

/////////////////////////////// PLAYER

Player::Player(std::string texturePath, sf::Vector2f pos)
	: GameObject(texturePath, pos)
	, isjumping(false)
	, jumpcd(0.0f)
	, playerInAir(false)
	, isgrounded(true)

	
	
	
{
	
	m_sprite.setOrigin(m_sprite.getTextureRect().width * 0.5f, m_sprite.getTextureRect().height * 0.5f);
	

}

void Player::Update(sf::RenderWindow * window, float dt)
{
	//---------------------------------------------------
	
	jumpcd -= dt;

	
	

	sf::Vector2f gravity(0.0f, 10.f);
	accel = gravity;

	GameObject::Update(window, dt);


	//Constrain left and right and top of the screen
		if (m_sprite.getPosition().x < 0)
		{
			m_pos = sf::Vector2f(0, m_sprite.getPosition().y);
		}
		if (m_sprite.getPosition().x + m_sprite.getScale().x > 1000)
		{
			m_pos = sf::Vector2f(1000 - m_sprite.getScale().x, m_sprite.getPosition().y);
		}
		
		//top and bottom
		if (m_sprite.getPosition().y < 0)
		{
			m_pos = sf::Vector2f(m_sprite.getPosition().x, 0);
		}
	/*	if (m_sprite.getPosition().y + m_shape.getSize().y > 500)
		{
			m_pos = sf::Vector2f(m_sprite.getPosition().x, 500- m_sprite.getScale().y);
		}*/
		

	//--------------------------------------------------
	//Movement of Character

	sf::Vector2f  m_movement (0,0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_movement.x = Ps * dt;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_movement.x = - Ps * dt;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_movement.y = Ps * dt;
	}  

	//Jumping  
  
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isgrounded || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isgrounded)
	{     
			isjumping = true;

		
	{
			
			m_vel.y = -70;
			
			
	}
	}
	
 

   m_vel += accel *dt;
   m_movement += m_vel * dt;

	m_pos.x += m_movement.x;
	

	for (int i = 0; i < m_owner->m_gameObjects.size(); i++)
	{
		GameObject* current = m_owner->m_gameObjects[i];
		if (current != this)
		{
			if (current->Collision(this))
			{
				m_pos.x -= m_movement.x;
				break;
			}
		}
		

	}

	m_pos.y += m_movement.y;

	isgrounded = false; 

	for (int i = 0; i < m_owner->m_gameObjects.size(); i++)
	{
		GameObject* current = m_owner->m_gameObjects[i];
		
		if (current != this)
		{
			if (current->Collision(this))
			{
				m_pos.y -= m_movement.y;
				m_vel.y = 0;
				isgrounded = true; 
				
				break;
			}
		}


	}

	m_sprite.setPosition(m_pos);
}

void Player::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}







///////////////////////////// Platform
 Platform::Platform(std::string texturePath, sf::Vector2f pos)
	: GameObject("Sprites/PNG/grass.png", pos)

{
	m_sprite.setOrigin(m_sprite.getTextureRect().width * 0.5f, m_sprite.getTextureRect().height * 0.5f);

}

bool  Platform::Collision(GameObject* obj)
 {

	 if ((obj->GetPos().y + obj->GetSize().y > Top) && 
		 (obj->GetPos().y  < Bottom) && 
		 (obj->GetPos().x + obj->GetSize().x  > Left) &&
		 (obj->GetPos().x < Right))
	 {
		 
		
	

		 return true; 
		 
		
	 }
	
	
	
	return false; 
	
	
 }

 void Platform::Update(sf::RenderWindow * window, float dt)
 {
	 GameObject::Update(window, dt);
 }

 void Platform::Draw(sf::RenderWindow* window)
 {
	 GameObject::Draw(window);
	 window->draw(m_sprite);
 }


 