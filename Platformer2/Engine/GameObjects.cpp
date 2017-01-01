#include "stdafx.h"
#include "GameObjects.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include "player.h"
#include "Collider.h"

GameObject::GameObject(std::string texturePath, sf::Vector2f size, sf::Vector2f pos)
	: m_pos(pos), m_size(size)
{
	//m_sprite.setPosition(m_pos);

	if (texturePath != "")
	{
		m_texture.loadFromFile(texturePath);
		m_sprite.setTexture(m_texture);
	}

	Top = m_sprite.getPosition().y;
	Bottom = m_sprite.getPosition().y + m_sprite.getScale().y;
	Right = m_sprite.getPosition().x + m_sprite.getScale().x;
	Left = m_sprite.getPosition().x;

	body.setPosition(m_pos);
	body.setSize(m_size);
	body.setOrigin(m_size / 2.0f);
	body.setTexture(&m_texture);

	m_vel.x = 0;
	m_vel.y = 0;
}

void GameObject::Update(sf::RenderWindow * window, float dt)
{
}

void GameObject::Draw(sf::RenderWindow * window)
{
	window->draw(m_sprite);
}

///////////////////////////// Platform
 Platform::Platform(std::string texturePath, sf::Vector2f size, sf::Vector2f pos, Player* player)
	: GameObject("Sprites/PNG/grass.png", size, pos), m_player(player)
{
	//m_sprite.setOrigin(m_sprite.getTextureRect().width * 0.5f, m_sprite.getTextureRect().height * 0.5f);
}

bool  Platform::Collision(GameObject* obj)
 {
	 if ((obj->GetPos().y + obj->Top > Top) && 
		 (obj->GetPos().y  < Bottom) && 
		 (obj->GetPos().x + obj->Bottom  > Left) &&
		 (obj->GetPos().x < Right))
	 {
		 return true; 
	 }

	return false; 
 }

 void Platform::Update(sf::RenderWindow * window, float dt)
 {
	 GameObject::Update(window, dt);

	 this->GetCollider().CheckCollision(m_player->GetCollider(), 1.0f);
 }

 void Platform::Draw(sf::RenderWindow* window)
 {
	 GameObject::Draw(window);
	 window->draw(body);
 }


 