#include<SFML/Graphics.hpp>
#include "../include/Game.h"
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<iostream>

gamescreen::gamescreen(float width , float height)
{
    float gridSizef = 110;
    unsigned gridSizeU = static_cast<unsigned>(gridSizef);
    sf::RenderWindow gamewindow(sf::VideoMode(1090, 890), "Knight TRavial" , sf::Style::Default);

    sf::RectangleShape shape(sf::Vector2f(gridSizef , gridSizef));

    const int mapSize = 8;
    sf::RectangleShape tileMap[mapSize][mapSize];
    for(int x = 0 ; x< mapSize ; x++)
    {
        for(int y = 0 ; y<mapSize ; y++)
        {
            if(x%2 == 0)
            {
                if(y%2 == 0) {tileMap[x][y].setFillColor(sf::Color::White);}
                else tileMap[x][y].setFillColor(sf::Color::Cyan);
            }
            else
            {
                if(y%2 == 0) {tileMap[x][y].setFillColor(sf::Color::Cyan);}
                else tileMap[x][y].setFillColor(sf::Color::White);
            }
            tileMap[x][y].setSize(sf::Vector2f(gridSizef , gridSizef));
            tileMap[x][y].setOutlineThickness(2.f);
            tileMap[x][y].setOutlineColor(sf::Color::Red);
            tileMap[x][y].setPosition(x*gridSizef , y*gridSizef);
        }
    }

    while (gamewindow.isOpen())
    {

        sf::Event event;
        while (gamewindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gamewindow.close();
        }

        gamewindow.clear();

        gamewindow.draw(shape);
        for(int x = 0 ; x< mapSize ; x++)
        {
            for(int y = 0 ; y<mapSize ; y++)
            {
                gamewindow.draw(tileMap[x][y]);
            }
         }


        gamewindow.display();
    }

}
