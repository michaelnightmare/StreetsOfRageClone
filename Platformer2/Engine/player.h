#pragma once
#include "GameObjects.h"
#include <SFML\Graphics.hpp>


class Player : public GameObject
{
public:

	Player(std::string texturePath, sf::Vector2f size, sf::Vector2f pos);
	void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

protected:

	float playerSpeed = 1000.f;
	float jumpCooldown;
	bool isjumping;
	bool isgrounded;
};

