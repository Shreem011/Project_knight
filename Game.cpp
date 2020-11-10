#include<SFML/Graphics.hpp>
#include "../include/Game.h"
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<iostream>

//float gridSizef = 110;

bool gamescreen::valid(int i , int j)
{
    for(int i=0 ; i<8 ; i++)
    {
        for(int j=0 ; j<8 ; j++)
        {
            if (i < 0 || i >= 8 || j < 0 || j >= 8) //border
                return false;
            else
                return true;
        }
    }
}


gamescreen::gamescreen(float width , float height)
{
    //float gridSizef = 110;
    //unsigned gridSizeU = static_cast<unsigned>(gridSizef);


    sf::RenderWindow gamewindow(sf::VideoMode(1090, 890), "Knight TRavial" , sf::Style::Default);
    sf::RectangleShape shape(sf::Vector2f(gridSizef , gridSizef));


    if (!texknight.loadFromFile("/home/shreem/Downloads/whiteKnight.png"))
	{
		//std::cout << "Error loading paddle texture :(" << std::endl;
	}
	knight.setTexture(texknight);
    knight.setPosition(static_cast<float>(posX*gridSizef) , static_cast<float>(posY*gridSizef));
    //knight.setOrigin(0.f , 0.f);

    //drawing chessboard
    sf::RectangleShape tileMap[8][8];
    for(int x = 0 ; x< 8 ; x++)
    {
        for(int y = 0 ; y< 8 ; y++)
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

    //window events
    while (gamewindow.isOpen())
    {
        kposX = knight.getPosition().x ;
        kposY = knight.getPosition().y ;
        sf::Event event;

        //everything happens here....moving of knight , closing window
        while (gamewindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                gamewindow.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {


               int mouseX = event.mouseButton.x ;
               int mouseY = event.mouseButton.y ;

               //top left
               if(mouseX>(kposX-2*gridSizef) && mouseX<(kposX-1*gridSizef) && mouseY>(kposY-1*gridSizef) && mouseY<(kposY-0*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX-2*gridSizef) , static_cast<float>(kposY-1*gridSizef));
               }
               //top mid left
               else if(mouseX>(kposX-1*gridSizef) && mouseX<(kposX-0*gridSizef) && mouseY>(kposY-2*gridSizef) && mouseY<(kposY-1*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX-1*gridSizef) , static_cast<float>(kposY-2*gridSizef));
               }
               //top mid right
               else if(mouseX>(kposX+1*gridSizef) && mouseX<(kposX+2*gridSizef) && mouseY>(kposY-2*gridSizef) && mouseY<(kposY-1*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX+1*gridSizef) , static_cast<float>(kposY-2*gridSizef));
               }
                //top right
               else if(mouseX>(kposX+2*gridSizef) && mouseX<(kposX+3*gridSizef) && mouseY>(kposY-1*gridSizef) && mouseY<(kposY-0*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX+2*gridSizef) , static_cast<float>(kposY-1*gridSizef));
               }
                //bottom left
               else if(mouseX>(kposX-2*gridSizef) && mouseX<(kposX-1*gridSizef) && mouseY>(kposY+1*gridSizef) && mouseY<(kposY+2*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX-2*gridSizef) , static_cast<float>(kposY+1*gridSizef));
               }
                //bottom mid left
               else if(mouseX>(kposX-1*gridSizef) && mouseX<(kposX-0*gridSizef) && mouseY>(kposY+2*gridSizef) && mouseY<(kposY+3*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX-1*gridSizef) , static_cast<float>(kposY+2*gridSizef));
               }
                //bottom mid right
               else if(mouseX>(kposX+1*gridSizef) && mouseX<(kposX+2*gridSizef) && mouseY>(kposY+2*gridSizef) && mouseY<(kposY+3*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX+1*gridSizef) , static_cast<float>(kposY+2*gridSizef));
               }
                //bottom right
               else if(mouseX>(kposX+2*gridSizef) && mouseX<(kposX+3*gridSizef) && mouseY>(kposY+1*gridSizef) && mouseY<(kposY+2*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX+2*gridSizef) , static_cast<float>(kposY+1*gridSizef));
               }
            }
       }


        //clears everything
        gamewindow.clear();

        //displaying chessboard
        gamewindow.draw(shape);
        for(int x = 0 ; x< 8 ; x++)
        {
            for(int y = 0 ; y< 8; y++)
            {
                gamewindow.draw(tileMap[x][y]);
            }
         }

        //displaying knight on chessboard
        gamewindow.draw(knight);

        //display everything on window
        gamewindow.display();
    }

  }

