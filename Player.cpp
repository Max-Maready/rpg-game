#include "Player.h"
#include <iostream>
#include "Skeleton.h"
#include "Math.h"


void Player::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(boundingRectangle);
	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}

void Player::Initialize() {
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);


	size = sf::Vector2i(64, 64);
}

void Player::Update(Skeleton& skeleton, float deltaTime) {
	sf::Vector2f position = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.setPosition(position + sf::Vector2f(.5, 0) * playerSpeed * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.setPosition(position + sf::Vector2f(0, -.5) * playerSpeed * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprite.setPosition(position + sf::Vector2f(0, .5) * playerSpeed * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.setPosition(position + sf::Vector2f(-.5, 0) * playerSpeed * deltaTime);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

		bullets[bullets.size() - 1].setPosition(sprite.getPosition());


	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
		bulletDirection = Math::NormalizeVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
	}

	boundingRectangle.setPosition(sprite.getPosition());

	if (Math::DidRectCollide(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds())) {
		std::cout << "Collision!" << std::endl;
	}
}

void Player::Load() {
	if (texture.loadFromFile("C:/Test/RPG_Game- OLD/assets/player/textures/spritesheet.png")) {

		std::cout << "Player image Loaded!" << std::endl;
		sprite.setTexture(texture);

		//X,Y, Width, Height
		int XIndex = 0;
		int YIndex = 0;
		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(sf::Vector2f(1640, 800));
		sprite.scale(sf::Vector2f(3, 3));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else {
		std::cout << "Player image failed to load." << std::endl;
	}
}