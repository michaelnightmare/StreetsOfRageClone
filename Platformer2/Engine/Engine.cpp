// Engine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

int main()
{
	Game game;
	srand(static_cast<unsigned int>(time(0)));

	sf::RenderWindow window(sf::VideoMode(1000, 700), "Platformer!");

	sf::Texture texture;
	if (!texture.loadFromFile("Sprites/PNG/level.png"))
	{
		std::cout << "texture wont load";
	}

	sf::Sprite background;
	background.setTexture(texture);
	background.setScale(4,2);
	background.setPosition(0, -420.f);
	
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time dt = clock.restart();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

        window.draw(background);
		game.Update(&window, dt.asSeconds());
		game.Draw(&window);

		
		window.display();
	}

	return 0;
}
