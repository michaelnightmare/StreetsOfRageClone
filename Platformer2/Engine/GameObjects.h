#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include "Collider.h"

class Game;
class Player;

class GameObject
{
public:
	GameObject(std::string texturePath, sf::Vector2f size, sf::Vector2f pos );
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

	const sf::Vector2f& GetPos() { return m_pos; }
	void SetOwner(Game* game) { m_owner = game; }

	Collider GetCollider() { return Collider(body); }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	virtual bool  Collision(GameObject* obj) { return false; }



	float Top;
	float Bottom;
	float Left;
	float Right;
	//============================================================

protected:
	Game* m_owner;
	sf::Vector2f m_pos;
	sf::Vector2f m_size;
	sf::Vector2f m_movement;
	sf::Vector2f m_vel;
	sf::Vector2f m_accel;
	sf::RectangleShape body;
	sf::Sprite m_sprite;
	sf::Texture m_texture;


};



class Platform : public GameObject

{
public:
	Platform (std::string texturePath, sf::Vector2f size, sf::Vector2f pos, Player* player);
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

	virtual bool Collision(GameObject* obj);

private:
	//Super dirty, find way to fix collider to avoid this being necessary
	Player* m_player;
};

