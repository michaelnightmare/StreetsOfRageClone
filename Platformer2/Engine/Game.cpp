#include "Game.h"
#include <iostream>
#include "SFML\Graphics.hpp"
#include "GameObjects.h"
#include "Collider.h"
#

Game::Game()
{
	m_player = new Player("Sprites/PNG/WOLFSPRITESHEET.png", sf::Vector2f(75, 410));
	AddObject(m_player);

	m_enemy = new Enemy("Sprites/PNG/ZombieSheet.png", sf::Vector2f(250, 410));
	AddObject(m_enemy);

	playerView = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f, 512.0f));
}

void Game::Update(sf::RenderWindow * window, float dt)
{
	//Destroy loop
	//for (int i = 0; i < m_gameObjects.size(); i++)
	//{
	//	GameObject* current = m_gameObjects[i];
	//	if (current->IsDestroyed())
	//	{
	//		current->Destroy();
	//	}
	//}

	//Update loop
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		current->Update(window, dt);
	}

	//Collision Loop
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
	
	playerView->setCenter(m_player->GetPosition().x + 200.f, 400);

	window->setView(*playerView);
}

void Game::AddObject(GameObject * obj)
{
	m_gameObjects.push_back(obj);
	obj->SetOwner(this);
}
