#include "Game.h"
#include <iostream>
#include "SFML\Graphics.hpp"
#include "GameObjects.h"
#include "Collider.h"
#

Game::Game()
{
	m_player = new Player("Sprites/PNG/Werewolfdark.png", sf::Vector2f(75, 460));
	AddObject(m_player);

	//ground
	//AddObject(new Platform("Sprites/PNG/grounddark.png", sf::Vector2f(0, 650)));

	playerView = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(550.0f, 750.0f));
	

	//Floating platform
	//AddObject(new Platform("Sprites/PNG/grass.png",  sf::Vector2f(400, 200)));
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
	
	if (m_player->IsGrounded())
	{
		playerView->setCenter(m_player->GetPosition());
	}

	else
	{
		//Need to update the x position to the player while keeping the player's old y pos
		//Find a fix to this magic number that will definitely break further in the level
		playerView->setCenter(m_player->GetPosition().x, 460.f);
	}

	

	window->setView(*playerView);
}

void Game::AddObject(GameObject * obj)
{
	m_gameObjects.push_back(obj);
	obj->SetOwner(this);
}
