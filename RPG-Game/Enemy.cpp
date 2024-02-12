#include "Enemy.h"

void Enemy::Initialize()
{
	size = sf::Vector2i(140, 93);

	boundBox.setFillColor(sf::Color::Transparent);
	boundBox.setOutlineColor(sf::Color::Red);
	boundBox.setOutlineThickness(1);
}

void Enemy::Load()
{
	if (texture.loadFromFile("Assets/Enemy/Textures/Bringer-of-Death-SpritSheet.png"))
	{
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(140, 0, 140, 93));
		sprite.setPosition(sf::Vector2f(800, 400));
		sprite.setScale(sf::Vector2f(2, 2));

		boundBox.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
}

void Enemy::Update()
{
	boundBox.setPosition(sprite.getPosition());
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundBox);
}
