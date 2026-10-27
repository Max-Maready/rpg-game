#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

#include "Player.h"
#include "Skeleton.h"



int main()
{
	//--------------------------Initalize-------------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
	window.setFramerateLimit(240);
	Player player;
	Skeleton skeleton;

	player.Initialize();
	skeleton.Initialize();

	player.Load();
	skeleton.Load();
	//--------------------------Initalize-------------------------------
	
	sf::Clock clock;

	//main game loop
	while (window.isOpen()) {

		sf::Time deltaTimeTimer = clock.restart();
		float deltaTime = deltaTimeTimer.asMilliseconds();

		//-------------------------UPDATE-------------------------------
		sf::Event event;
		
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

	

		skeleton.Update(deltaTime);
		player.Update(skeleton, deltaTime);
		//-------------------------UPDATE-------------------------------

		//--------------------------DRAW--------------------------------
		window.clear(sf::Color::Black);
		skeleton.Draw(window);
		player.Draw(window);
		window.display();
		//--------------------------DRAW--------------------------------
	}

	return 0;
}
