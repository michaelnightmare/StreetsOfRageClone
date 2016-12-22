// Engine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

int main()
{
	Game game;

	sf::RenderWindow window(sf::VideoMode(1000, 700), "Platformer!");

	sf::Texture texture2;
	if (!texture2.loadFromFile("Sprites/PNG/sky.png"))
	{
		std::cout << "texture wont load";
	}
	sf::Sprite background;
	background.setTexture(texture2);
	background.setScale(4, 2);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
			
       window.draw(background);
	

		game.Update(&window, 0.01);

		game.Draw(&window);
		
		
		window.display();
	}

	return 0;
}
