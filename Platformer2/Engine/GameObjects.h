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
	virtual void SetPos(const sf::Vector2f& pos) { m_pos = pos; }
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);
	const sf::Vector2f& GetPos() { return m_pos; }
	void SetOwner(Game* game) { m_owner = game; }
	virtual bool  Collision(GameObject* obj) { return false; };
	const sf::Vector2f gravity;
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	float Top;
	float Bottom;
	float Left;
	float Right;

	Collider GetCollider() { return Collider(body); }
	sf::Vector2f GetPosition() { return body.getPosition(); }


protected:
	Game* m_owner;
	sf::Vector2f m_pos;
	sf::Vector2f m_size;
	sf::Color m_color;
	sf::Vector2f m_movement;
	sf::Vector2f m_vel;
	sf::Vector2f accel;
	sf::RectangleShape body;

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

