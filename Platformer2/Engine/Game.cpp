#include "Game.h"
#include <iostream>
#include "SFML\Graphics.hpp"
#include "GameObjects.h"
#include "Collider.h"
#

Game::Game()
{
	m_player = new Player("Sprites/PNG/AlienBlueFront.png", sf::Vector2f(150,150), sf::Vector2f(75, 500));
	AddObject(m_player);

	//ground
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(100, 100), sf::Vector2f(50, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(100, 100), sf::Vector2f(150, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(100, 100), sf::Vector2f(250, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(100, 100), sf::Vector2f(350, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(100, 100), sf::Vector2f(450, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(100, 100), sf::Vector2f(550, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(100, 100), sf::Vector2f(650, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(100, 100), sf::Vector2f(750, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(100, 100), sf::Vector2f(850, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(100, 100), sf::Vector2f(950, 650)));

	//Floating platform
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(100, 80), sf::Vector2f(400, 200)));
}

void Game::Update(sf::RenderWindow * window, float dt)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		current->Update(window, dt);
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		for (int j = 0; j < m_gameObjects.size(); j++)
		{
			GameObject* other = m_gameObjects[j];
			if (current->GetCollider().CheckCollision(other->GetCollider()))
			{
				current->CollidedWith(other);
				
			}
		}
	}



}

void Game::Draw(sf::RenderWindow * window)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		current->Draw(window);
	}
}

void Game::AddObject(GameObject * obj)
{
	m_gameObjects.push_back(obj);
	obj->SetOwner(this);
}
