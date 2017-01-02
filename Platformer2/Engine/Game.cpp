#include "Game.h"
#include <iostream>
#include "SFML\Graphics.hpp"

Game::Game()
{
	
	m_player = new Player("Sprites/PNG/AlienBlueFront.png", sf::Vector2f(200,200), sf::Vector2f(75, 100));
	AddObject(m_player);

	//ground
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(130, 100), sf::Vector2f(50, 650), m_player));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(130, 100), sf::Vector2f(178, 650), m_player));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(130, 100), sf::Vector2f(306, 650), m_player));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(130, 100), sf::Vector2f(434, 650), m_player));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(130, 100), sf::Vector2f(562, 650), m_player));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(130, 100), sf::Vector2f(690, 650), m_player));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(130, 100), sf::Vector2f(818, 650), m_player));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(130, 100), sf::Vector2f(946, 650), m_player));

	//Floating platform
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(130, 100), sf::Vector2f(400, 200), m_player));
}

void Game::Update(sf::RenderWindow * window, float dt)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		current->Update(window, dt);
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
