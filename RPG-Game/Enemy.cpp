#include "Enemy.h"

void Enemy::Initialize()
{
}

void Enemy::Load()
{
	if (texture.loadFromFile("Assets/Enemy/Textures/Bringer-of-Death-SpritSheet.png"))
	{
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(140, 0, 140, 93));
		sprite.setScale(sf::Vector2f(2, 2));
		sprite.setPosition(sf::Vector2f(800, 400));
	}
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
}
