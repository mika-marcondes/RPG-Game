#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;

    sf::RenderWindow window(sf::VideoMode(1240, 800), "Game", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	
	float bulletSpeed = 0.04;
	sf::Vector2f bulletDir;

	std::vector<sf::RectangleShape> bullets;

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
		playerSprite.setPosition(sf::Vector2f(0, 0));
	}

	if (enemyTexture.loadFromFile("Assets/Enemy/Textures/Bringer-of-Death-SpritSheet.png"))
	{
		enemySprite.setTexture(enemyTexture);
		enemySprite.setTextureRect(sf::IntRect(140, 0, 140, 93));
		enemySprite.setScale(sf::Vector2f(2, 2));
		enemySprite.setPosition(sf::Vector2f(800, 400));
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

		sf::Vector2f playerPos = playerSprite.getPosition();

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f mouseCoords = window.mapPixelToCoords(mousePos, window.getDefaultView());

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playerSprite.setPosition(playerPos + sf::Vector2f(1, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playerSprite.setPosition(playerPos + sf::Vector2f(-1, 0));
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.setPosition(playerPos + sf::Vector2f(0, -1));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.setPosition(playerPos + sf::Vector2f(0, 1));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
		{
			bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));

			int i = bullets.size() - 1;
			bullets[i].setPosition(playerSprite.getPosition() + sf::Vector2f(120, 80));
			bulletDir = mouseCoords - bullets[i].getPosition();
		}

		for (size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].setPosition(bullets[i].getPosition() + bulletDir * bulletSpeed);
		}

		//Draw
		window.clear(sf::Color::Black);
		window.draw(enemySprite);
		window.draw(playerSprite);

		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}

		window.display();
	}

    return 0;
}