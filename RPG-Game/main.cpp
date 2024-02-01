#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Game", sf::Style::Default, settings);
	
	//Load
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/Player/Textures/_Run.png")) 
	{
		int animationFrame = 0;

		playerSprite.setTexture(playerTexture);
		playerSprite.setTextureRect(sf::IntRect(animationFrame * 120, 0, 120, 80));
		std::cout << "Player image loaded!" << std::endl;
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
		window.draw(playerSprite);
		window.display();
	}

    return 0;
}