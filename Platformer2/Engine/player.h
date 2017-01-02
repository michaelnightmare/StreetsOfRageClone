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
	bool isjumping;
	float jumpcd;
	bool playerInAir;
	bool isgrounded;
	float Ps = 1000;

};

