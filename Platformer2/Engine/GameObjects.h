#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include "Collider.h"

class Game;

class GameObject
{
public:

	GameObject(std::string texturePath, sf::Vector2f pos );
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

	const sf::Vector2f& GetPos() { return m_pos; }
	void SetOwner(Game* game) { m_owner = game; }
	virtual void CollidedWith(GameObject* other);


	Collider GetCollider() { return Collider(body); }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::RectangleShape body;
	
protected:

	Game* m_owner;
	sf::Vector2f m_pos;
	sf::Vector2f m_size;
	sf::Vector2f m_movement;
	sf::Vector2f m_depthmovement;
	sf::Vector2f m_vel;
	sf::Vector2f m_accel;

	//Position in the 'Z' (height on the road)
	float m_depth;
	
	sf::Texture m_texture;

};
