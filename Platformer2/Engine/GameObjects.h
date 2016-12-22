#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>


class Game;

class GameObject
{
public:
	GameObject(std::string texturePath,sf::Vector2f pos );
	virtual void SetPos(const sf::Vector2f& pos) { m_pos = pos; m_shape.setPosition(m_pos);}
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);
	const sf::Vector2f& GetPos() { return m_pos; }
	const sf::Vector2f& GetSize() { return m_shape.getSize(); }
	void SetOwner(Game* game) { m_owner = game; }
	virtual bool  Collision(GameObject* obj) { return false; };
	const sf::Vector2f gravity;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	float Top;
	float Bottom;
	float Left;
	float Right;
	


protected:
	Game* m_owner;
	sf::Vector2f m_pos;
	sf::Vector2f m_size;
	sf::Color m_color;
	sf::RectangleShape m_shape;
	sf::Vector2f m_movement;
	sf::Vector2f m_vel;
	sf::Vector2f accel;

};

class Player : public GameObject
{
public:
	Player(std::string texturePath, sf::Vector2f pos);
	void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);
	
protected:
	bool isjumping;
	float jumpcd;
	bool playerInAir;
	bool isgrounded;
	float Ps = 100;
	

};



class Platform : public GameObject

{
public:
	Platform (std::string texturePath, sf::Vector2f pos);
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

	virtual bool Collision(GameObject* obj);

protected:


};

