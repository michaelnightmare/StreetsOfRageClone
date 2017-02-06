#pragma once
#include "GameObjects.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include  "Player.h"
#include "Enemy.h"

class Game
{
public:
	Game();

	void Update(sf::RenderWindow* window, float dt);
	void Draw(sf::RenderWindow* window);
	void AddObject(GameObject* obj);
	std::vector<GameObject*> m_gameObjects;



private:
	Player* m_player;
	sf::View* playerView;
	Enemy* m_enemy;
};

