#include "Game.h"
#include <iostream>
#include "SFML\Graphics.hpp"



Game::Game()
{
	
	m_player = new Player("Sprites/PNG/AlienBlueFront.png", sf::Vector2f(75, 400));
	m_platform = new Platform("Sprites/PNG/grass.png", sf::Vector2f(300, 400));

	AddObject(m_player);
	//ground

	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(50, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(178, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(306, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(434, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(562, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(690, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(818, 650)));
	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(946, 650)));


	AddObject(new Platform("Sprites/PNG/grass.png", sf::Vector2f(400, 200)));
	
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
