#pragma once
#include "GameObjects.h"
#include <SFML\Graphics.hpp>

class Animator;
class StateMachine;

class Enemy : public GameObject
{
public:

	Enemy(std::string texturePath, sf::Vector2f pos);
	void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void CollidedWith(GameObject* other);
	bool IsGrounded() { return isgrounded; }

	void HandleInput(float dt);
	void Restrain();

	sf::SoundBuffer ZombieDBuffer;
	sf::Sound ZombieDSound;


protected:

	Animator* anim;
	StateMachine* m_stateMachine;
	float enemySpeed = 150.f;
	float jumpHeight = 0.f;
	float jumpCooldown;
	bool isjumping;
	bool isgrounded;
};

