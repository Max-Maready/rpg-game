#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector) {
	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	sf::Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

int main()
{
	//--------------------------Initalize-------------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);

	//--------------------------Initalize-------------------------------
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5;
	

	//--------------------------Load------------------------------------
	sf::Texture SkeletonTexture;
	sf::Sprite SkeletonSprite;
	if (SkeletonTexture.loadFromFile("C:/Test/RPG_Game- OLD/assets/Skeleton/textures/spritesheet.png")) {
		std::cout << "Skeleton image Loaded!" << std::endl;
		SkeletonSprite.setTexture(SkeletonTexture);
		SkeletonSprite.setPosition(sf::Vector2f(400, 100));

		//X,Y, Width, Height
		int XIndex = 0;
		int YIndex = 2;
		SkeletonSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		SkeletonSprite.scale(sf::Vector2f(3, 3));
	}
	else {
		std::cout << "Skeleton image failed to load." << std::endl;
	}


	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("C:/Test/RPG_Game- OLD/assets/player/textures/spritesheet.png")) {

		std::cout << "Player image Loaded!" << std::endl;
		playerSprite.setTexture(playerTexture);

		//X,Y, Width, Height
		int XIndex = 0;
		int YIndex = 0;
		playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		playerSprite.scale(sf::Vector2f(3, 3));
		playerSprite.setPosition(sf::Vector2f(1640, 800));
	}
	else {
		std::cout << "Player image failed to load." << std::endl;
	}
	
	//--------------------------Load------------------------------------

	//main game loop
	while (window.isOpen()) {

		//-------------------------UPDATE-------------------------------
		sf::Event event;
		
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		sf::Vector2f position = playerSprite.getPosition();


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			playerSprite.setPosition(position + sf::Vector2f(.5, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			playerSprite.setPosition(position + sf::Vector2f(0, -.5));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			playerSprite.setPosition(position + sf::Vector2f(0, .5));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			playerSprite.setPosition(position + sf::Vector2f(-.5, 0));
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

			bullets[bullets.size() - 1].setPosition(playerSprite.getPosition());

	
		}
		
		for (size_t i = 0; i < bullets.size(); i++)
		{
			sf::Vector2f bulletDirection = SkeletonSprite.getPosition() - bullets[i].getPosition();
			bulletDirection = NormalizeVector(bulletDirection);
			bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
		}
		
		

		//-------------------------UPDATE-------------------------------

		//--------------------------DRAW--------------------------------
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.draw(SkeletonSprite);
		
		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}

		window.display();
		//--------------------------DRAW--------------------------------
	}

	return 0;
}
