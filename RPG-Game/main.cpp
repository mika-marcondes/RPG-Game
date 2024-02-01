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

	if (playerTexture.loadFromFile("Assets/Player/Textures/_Idle.png")) 
	{
		playerSprite.setTexture(playerTexture);
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
		
		//Draw
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.display();
	}

    return 0;
}