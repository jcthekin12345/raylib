// SolarianLanguageSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	//Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("background.jpg"))
		return EXIT_FAILURE;
	sf::Sprite background(texture);

	background.setPosition(0, 0);

	sf::Font font;
	if (!font.loadFromFile("Jaro-Regular.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Midonia Life", font, 50);
	text.setFillColor(sf::Color::White);
	text.setPosition(200, 100);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(background);

		window.draw(text);

		window.display();
	}

	return EXIT_SUCCESS;

}
	



