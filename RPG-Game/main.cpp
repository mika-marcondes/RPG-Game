#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;

    sf::RenderWindow window(sf::VideoMode(1240, 800), "Game", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	
	Player player;
	Enemy enemy;
	Bullet bullet;

	player.Initialize();
	enemy.Initialize();
	bullet.Initialize();

	player.Load();
	enemy.Load();
	bullet.Load();

	while (window.isOpen())
	{
		//Update
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.Update(enemy.sprite);
		enemy.Update();
		bullet.Update(player.sprite, window);

		//Draw
		window.clear(sf::Color::Black);

		player.Draw(window);
		enemy.Draw(window);
		bullet.Draw(window);

		window.display();
	}

    return 0;
}