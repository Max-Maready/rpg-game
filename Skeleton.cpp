#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	boundingRectangle.setOutlineThickness(1);


	size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
	if (texture.loadFromFile("C:/Test/RPG_Game- OLD/assets/Skeleton/textures/spritesheet.png")) {
		std::cout << "Skeleton image Loaded!" << std::endl;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(400, 100));

		//X,Y, Width, Height
		int XIndex = 0;
		int YIndex = 2;
		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.scale(sf::Vector2f(3, 3));

		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else {
		std::cout << "Skeleton image failed to load." << std::endl;
	}
}

void Skeleton::Update(float deltaTime)
{
	boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);
}
