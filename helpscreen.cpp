#include<SFML/Graphics.hpp>
#include "../include/helpscreen.h"
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<iostream>

help::help(float width , float height)
{
    sf::RenderWindow helpwindow(sf::VideoMode(800, 800), "HELP");
    sf::Texture texture;

    if (!texture.loadFromFile("/home/shreem/Downloads/whiteKnight.png"))
	{
		std::cout << "Error loading paddle texture :(" << std::endl;
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);

    while (helpwindow.isOpen())
    {
        sf::Event event;
        while (helpwindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                helpwindow.close();
        }

        helpwindow.clear();
        helpwindow.draw(sprite);
        helpwindow.display();
    }
}
