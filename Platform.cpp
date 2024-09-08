#include "Platform.h"

Platform::Platform(sf::Texture* textura, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(textura);
	body.setPosition(position);
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
