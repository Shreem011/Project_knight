#include<SFML/Graphics.hpp>
#include "../include/winScreen.h"
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<iostream>

YouWin::YouWin(float width , float height)
{
    sf::RenderWindow winWindow(sf::VideoMode(730, 500), "YOU WIN");
    sf::Texture texturesss;

    if (!texturesss.loadFromFile("/home/shreem/Downloads/wallpaper.png"))
	{
		std::cout << "Error loading paddle texture :(" << std::endl;
	}
	sf::Sprite sprites;
	sprites.setTexture(texturesss);

    fontsss.loadFromFile("/home/shreem/ProjectFiles/KNIGHT/cmake-3.18.4/arial.ttf");
    sf::Text wintext("Congratulations!!! ", fontsss, 30);
    sf::Text wintextt("You are on the next level to find the next princess" , fontsss , 30);

    while (winWindow.isOpen())
    {
        sf::Event event;
        while (winWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                winWindow.close();
        }

        winWindow.clear();
        winWindow.draw(sprites);

        //win text
        wintext.setPosition(150 , 150);
        wintext.setFillColor(sf::Color::White);
        winWindow.draw(wintext);
        wintextt.setPosition(50 , 200);
        wintextt.setFillColor(sf::Color::White);

        winWindow.draw(wintextt);
        winWindow.display();
    }
}


