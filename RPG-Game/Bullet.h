#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	std::vector<sf::RectangleShape> bullets;
	sf::Vector2f direction;
	float speed;
public:
	void Initialize();
	void Load();
	void Update(sf::Sprite& player, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
};

