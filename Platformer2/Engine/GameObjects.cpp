#include "stdafx.h"
#include "GameObjects.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include "Player.h"
#include "Collider.h"

GameObject::GameObject(std::string texturePath, sf::Vector2f size, sf::Vector2f pos)
	: m_pos(pos)
{
	//m_sprite.setPosition(m_pos);

	if (texturePath != "")
	{
		m_texture.loadFromFile(texturePath);
	}

	m_size.x = m_texture.getSize().x;
	m_size.y = m_texture.getSize().y;

	body.setPosition(m_pos);
	body.setSize(m_size);
	body.setTexture(&m_texture);

	m_vel.x = 0;
	m_vel.y = 0;
}

void GameObject::Update(sf::RenderWindow * window, float dt)
{
}

void GameObject::Draw(sf::RenderWindow * window)
{
	window->draw(body);
}

void GameObject::CollidedWith(GameObject * other)
{

}

///////////////////////////// Platform
 Platform::Platform(std::string texturePath, sf::Vector2f size, sf::Vector2f pos)
	: GameObject("Sprites/PNG/grass.png", size, pos)
{
}


 void Platform::CollidedWith(GameObject * other)
 {
	
 }


 void Platform::Update(sf::RenderWindow * window, float dt)
 {
	 GameObject::Update(window, dt);
 }

 void Platform::Draw(sf::RenderWindow* window)
 {
	 GameObject::Draw(window);
 }


 