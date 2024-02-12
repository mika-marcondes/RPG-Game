#include "Player.h"
#include <iostream>

void Player::Initialize()
{
	size = sf::Vector2i(120, 80);

	boundBox.setFillColor(sf::Color::Transparent);
	boundBox.setOutlineColor(sf::Color::Red);
	boundBox.setOutlineThickness(1);
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/_Run.png"))
	{
		int animationFrame = 0;

		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(animationFrame * 120, 0, size.x, size.y));
		sprite.setPosition(sf::Vector2f(0, 0));
		sprite.setScale(sf::Vector2f(2, 2));
		
		boundBox.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
}

void Player::Update(sf::Sprite& enemy)
{
	sf::Vector2f position = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.setPosition(position + sf::Vector2f(1, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		sprite.setPosition(position + sf::Vector2f(-1, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		sprite.setPosition(position + sf::Vector2f(0, -1));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		sprite.setPosition(position + sf::Vector2f(0, 1));

	boundBox.setPosition(sprite.getPosition());
	
	if (sprite.getGlobalBounds().intersects(enemy.getGlobalBounds()))
		std::cout << "Collision!" << std::endl;
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundBox);
}