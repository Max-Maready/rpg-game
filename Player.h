#pragma once
#include "Skeleton.h"
#include <SFML/Graphics.hpp>

class Player {
private:
	sf::Texture texture;
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5;
	float playerSpeed = 2.0f;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

	float width = 64;
	float height = 64;


public:
	sf::Sprite sprite;
	void Initialize();
	void Load();
	void Update(Skeleton& skeleton, float deltaTime);
	void Draw(sf::RenderWindow& window);
};