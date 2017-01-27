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

	void HandleInput(float dt);
	void Restrain();

protected:

	Animator* anim;
	float playerSpeed = 300.f;
	float jumpHeight = 200.f; 
	float jumpCooldown;
	bool isjumping;
	bool isgrounded;
};

