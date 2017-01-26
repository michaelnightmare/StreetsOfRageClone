#include "stdafx.h"
#include "GameObjects.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include "Player.h"
#include "Collider.h"

GameObject::GameObject(std::string texturePath, sf::Vector2f pos)
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

	//Setting default position to the bottom of the screen, set in Child's constructor
	m_depth = 0.f;
}

void GameObject::Update(sf::RenderWindow * window, float dt)
{
	CalculateDepth(m_depth);

	
	

	std::cout << m_depth << std::endl;
	/*m_pos.y = m_depth * 60;*/
}

void GameObject::Draw(sf::RenderWindow * window)
{
	window->draw(body);
}

void GameObject::CollidedWith(GameObject * other)
{

}

float GameObject::CalculateDepth(float& depth)
{
	float min = 410.f;
	float max = 300.f;

	m_depth = (m_pos.y - min) / (max - min);

	return m_depth;
}




 