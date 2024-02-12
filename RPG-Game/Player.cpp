#include "Player.h"

void Player::Initialize()
{
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/_Run.png"))
	{
		int animationFrame = 0;

		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(animationFrame * 120, 0, 120, 80));
		sprite.setScale(sf::Vector2f(2, 2));
		sprite.setPosition(sf::Vector2f(0, 0));
	}
}

void Player::Update()
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
}

void Player::Draw()
{
}
