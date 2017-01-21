#pragma once
#include "GameObjects.h"
#include <SFML\Graphics.hpp>

class Animator;

class Player : public GameObject
{
public:

	Player(std::string texturePath,  sf::Vector2f pos);
	void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void CollidedWith(GameObject* other);
	bool IsGrounded() { return isgrounded; }

	void HandleInput(sf::Vector2f & movement, float dt);
	void Restrain();

protected:

	Animator* anim;
	float playerSpeed = 500.f;
	float jumpCooldown;
	bool isjumping;
	bool isgrounded;
};

