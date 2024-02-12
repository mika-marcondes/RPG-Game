#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Texture texture;
	sf::RectangleShape boundBox;
	sf::Vector2i size;
public:
	sf::Sprite sprite;

	void Initialize();
	void Load();
	void Update(sf::Sprite& enemy);
	void Draw(sf::RenderWindow& window);
};