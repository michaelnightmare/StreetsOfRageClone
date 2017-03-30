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

	void Patrol(float dt);

	

	sf::SoundBuffer ZombieDBuffer;
	sf::Sound ZombieDSound;


protected:

	Animator* anim;
	StateMachine* m_stateMachine;


	float enemySpeed = 40.f;
	float patrolTimer;
	bool enemyAlive;
	sf::Vector2f enemyPEnd;
	sf::Vector2f enemyPStart;
	sf::Vector2f movementFrame;
};

