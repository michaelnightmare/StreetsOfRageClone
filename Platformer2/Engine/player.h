#pragma once
#include "GameObjects.h"
#include <SFML\Graphics.hpp>

class Animator;
class StateMachine;

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
	sf::SoundBuffer PunchBuffer;
	sf::Sound PunchSound;
	sf::SoundBuffer TransformBuffer;
	sf::Sound TransformSound;
	sf::SoundBuffer JumpBuffer;
	sf::Sound JumpSound;


protected:

	Animator* anim;
	StateMachine* m_stateMachine;
	float playerSpeed = 300.f;
	float jumpHeight = 0.f; 
	float jumpCooldown;
	bool isjumping;
	bool isgrounded;
	bool facingRight;
};

