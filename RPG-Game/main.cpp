#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;

    sf::RenderWindow window(sf::VideoMode(1240, 800), "Game", sf::Style::Default, settings);
	
	//Load
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	sf::Texture enemyTexture;
	sf::Sprite enemySprite;

	if (playerTexture.loadFromFile("Assets/Player/Textures/_Run.png")) 
	{
		int animationFrame = 0;

		playerSprite.setTexture(playerTexture);
		playerSprite.setTextureRect(sf::IntRect(animationFrame * 120, 0, 120, 80));
		playerSprite.setScale(sf::Vector2f(2, 2));
	}

	if (enemyTexture.loadFromFile("Assets/Enemy/Textures/Bringer-of-Death-SpritSheet.png"))
	{
		enemySprite.setTexture(enemyTexture);
		enemySprite.setTextureRect(sf::IntRect(140, 0, 140, 93));
		enemySprite.setScale(sf::Vector2f(2, 2));
	}

	while (window.isOpen())
	{
		//Update
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Vector2f playerPosition = playerSprite.getPosition();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
			playerSprite.setPosition(playerPosition + sf::Vector2f(1, 0));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playerSprite.setPosition(playerPosition + sf::Vector2f(-1, 0));
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.setPosition(playerPosition + sf::Vector2f(0, -1));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.setPosition(playerPosition + sf::Vector2f(0, 1));

		//Draw
		window.clear(sf::Color::Black);
		window.draw(enemySprite);
		window.draw(playerSprite);
		window.display();
	}

    return 0;
}