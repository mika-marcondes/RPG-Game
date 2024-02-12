#include "Bullet.h"

void Bullet::Initialize()
{
	speed = 0.04;
}

void Bullet::Load()
{
}

void Bullet::Update(sf::Sprite& player, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mouseCoords = window.mapPixelToCoords(mousePos, window.getDefaultView());

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));

		int i = bullets.size() - 1;
		bullets[i].setPosition(player.getPosition() + sf::Vector2f(120, 80));
		direction = mouseCoords - bullets[i].getPosition();
	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].setPosition(bullets[i].getPosition() + direction * speed);
	}
}

void Bullet::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}
