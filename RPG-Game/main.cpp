#include <SFML/Graphics.hpp>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Game", sf::Style::Default, settings);
	
	sf::CircleShape circle(40.f);
	circle.setFillColor(sf::Color::Magenta);
	circle.setPosition(sf::Vector2f(100,200));

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
		window.draw(circle);
		window.display();
	}

    return 0;
}