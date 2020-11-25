#include<SFML/Graphics.hpp>
#include "../include/gameOverScreen.h"
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<iostream>

gameOver::gameOver(float width , float height)
{
    sf::RenderWindow overWindow(sf::VideoMode(700, 500), "GAMEOVER");
    sf::Texture texturess;

    if (!texturess.loadFromFile("/home/shreem/Downloads/wallpaper.png"))
	{
		std::cout << "Error loading paddle texture :(" << std::endl;
	}
	sf::Sprite sprite;
	sprite.setTexture(texturess);

	fontss.loadFromFile("/home/shreem/ProjectFiles/KNIGHT/cmake-3.18.4/arial.ttf");
    sf::Text overtext("you are out of moves", fontss, 30);
    sf::Text overtextt("GAME OVER", fontss, 30);

    while (overWindow.isOpen())
    {
        sf::Event event;
        while (overWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                overWindow.close();
        }

        overWindow.clear();
        overWindow.draw(sprite);

        //gameover text
        overtext.setPosition(150 , 150);
        overtext.setFillColor(sf::Color::White);
        overtextt.setPosition(200 , 250);
        overtextt.setFillColor(sf::Color::White);

        overWindow.draw(overtext);
        overWindow.draw(overtextt);

        overWindow.display();
    }
}

