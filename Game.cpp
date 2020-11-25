#include<SFML/Graphics.hpp>

#include "../include/Game.h"
#include "../include/gameOverScreen.h"
#include "../include/winScreen.h"

#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

#include<queue>
#include<iostream>

bool gamescreen::valid(int x , int y)
{
    if(x<0 && x>8 && y<0 && y>8)
        return false;
    else
        return true;
}


gamescreen::gamescreen(float width , float height)
{
    //opening of game window
    sf::RenderWindow gamewindow(sf::VideoMode(1090, 890), "Knight TRavial" , sf::Style::Default);
    sf::RectangleShape shape(sf::Vector2f(gridSizef , gridSizef));

    //recording moves
    fonts.loadFromFile("/home/shreem/ProjectFiles/KNIGHT/cmake-3.18.4/arial.ttf");
    sf::Text move("MOVES : ", fonts, 40);
    sf::Text m(" ", fonts, 50);
    sf::Text hint("HINT" , fonts , 30);

     //background wallpaper
    if (!texback.loadFromFile("/home/shreem/Downloads/wallpaper.png"))
	{
		//std::cout << "Error loading paddle texture :(" << std::endl;
	}
	background.setTexture(texback);

    //knight texture
    if (!texknight.loadFromFile("/home/shreem/Downloads/whiteKnight.png"))
	{
		//std::cout << "Error loading paddle texture :(" << std::endl;
	}
	knight.setTexture(texknight);
    knight.setPosition(static_cast<float>(posX*gridSizef) , static_cast<float>(posY*gridSizef));
    //knight.setOrigin(0.f , 0.f);


    if (!texprincess.loadFromFile("/home/shreem/Downloads/princess.png" , sf::IntRect(0,0,200,200)))
	{
		//std::cout << "Error loading paddle texture :(" << std::endl;
	}
	princess.setTexture(texprincess);
    princess.setPosition(static_cast<float>(destX*gridSizef) , static_cast<float>(destY*gridSizef));



   //drawing chessboard size 8*8
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
            tileMap[x][y].setOutlineColor(sf::Color::Black);
            tileMap[x][y].setPosition(x*gridSizef , y*gridSizef);
        }
    }

    //for hint not implememnted yet
    sf::RectangleShape box;
    box.setFillColor(sf::Color::Yellow);
    box.setOutlineThickness(2.f);
    box.setOutlineColor(sf::Color::White);
    box.setSize(sf::Vector2f(80 , 50));
    box.setPosition(930 , 300);

    //for hint not implemented yet
    sf::RectangleShape display;
    display.setSize(sf::Vector2f(108 ,108));
    display.setFillColor(sf::Color::Yellow);
    display.setOutlineColor(sf::Color::Black);
    display.setOutlineThickness(2.f);
    display.setPosition(1000 , 1000);

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

               //tracks the location where mouse button is pressed
               int mouseX = event.mouseButton.x ;
               int mouseY = event.mouseButton.y ;

               //top left
               if(mouseX>(kposX-2*gridSizef) && mouseX<(kposX-1*gridSizef) && mouseY>(kposY-1*gridSizef) && mouseY<(kposY-0*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX-2*gridSizef) , static_cast<float>(kposY-1*gridSizef));
                   moves--;
               }
               //top mid left
               else if(mouseX>(kposX-1*gridSizef) && mouseX<(kposX-0*gridSizef) && mouseY>(kposY-2*gridSizef) && mouseY<(kposY-1*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX-1*gridSizef) , static_cast<float>(kposY-2*gridSizef));
                   moves--;
               }
               //top mid right
               else if(mouseX>(kposX+1*gridSizef) && mouseX<(kposX+2*gridSizef) && mouseY>(kposY-2*gridSizef) && mouseY<(kposY-1*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX+1*gridSizef) , static_cast<float>(kposY-2*gridSizef));
                   moves--;
               }
                //top right
               else if(mouseX>(kposX+2*gridSizef) && mouseX<(kposX+3*gridSizef) && mouseY>(kposY-1*gridSizef) && mouseY<(kposY-0*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX+2*gridSizef) , static_cast<float>(kposY-1*gridSizef));
                   moves--;
               }
                //bottom left
               else if(mouseX>(kposX-2*gridSizef) && mouseX<(kposX-1*gridSizef) && mouseY>(kposY+1*gridSizef) && mouseY<(kposY+2*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX-2*gridSizef) , static_cast<float>(kposY+1*gridSizef));
                   moves--;
               }
                //bottom mid left
               else if(mouseX>(kposX-1*gridSizef) && mouseX<(kposX-0*gridSizef) && mouseY>(kposY+2*gridSizef) && mouseY<(kposY+3*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX-1*gridSizef) , static_cast<float>(kposY+2*gridSizef));
                   moves--;
               }
                //bottom mid right
               else if(mouseX>(kposX+1*gridSizef) && mouseX<(kposX+2*gridSizef) && mouseY>(kposY+2*gridSizef) && mouseY<(kposY+3*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX+1*gridSizef) , static_cast<float>(kposY+2*gridSizef));
                   moves--;
               }
                //bottom right
               else if(mouseX>(kposX+2*gridSizef) && mouseX<(kposX+3*gridSizef) && mouseY>(kposY+1*gridSizef) && mouseY<(kposY+2*gridSizef))
               {
                   knight.setPosition(static_cast<float>(kposX+2*gridSizef) , static_cast<float>(kposY+1*gridSizef));
                   moves--;
               }
            }
       }

       //track the present location of knight and princess
       fposX = knight.getPosition().x;
       fposY = knight.getPosition().y;
       fdestX = princess.getPosition().x;
       fdestY = princess.getPosition().y;

       //moves
       if (moves==0)
       {
           if(fposX==fdestX && fposY==fdestY)
           {
               gamewindow.close();
               YouWin(500 , 500);
           }
           else
           {
               gamewindow.close();
               gameOver(500 , 500);
           }
       }
       if (moves>0)
       {
           if(fposX==fdestX && fposY==fdestY)
           {
               gamewindow.close();
               YouWin(500 , 500);
           }
       }


        //implemented hint logic
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            hintX = hint.getPosition().x;
            hintY = hint.getPosition().y;

            int a = kposX/gridSizef;
            int b = kposY/gridSizef;
            cout<<a<<endl;
            cout<<b<<endl;

            int mX = event.mouseButton.x;
            int mY = event.mouseButton.y;

            if(mX>930 && mX<1010 && mY>300 && mY<350)
            {
                cout<<"hint is pressed"<<endl;
                if(valid(a-2,b+1))
                {
                    tileMap[a-2][b+1].setFillColor(sf::Color::Yellow);
                }
                if(valid(a-1,b+2))
                {
                    tileMap[a-1][b+2].setFillColor(sf::Color::Yellow);
                }
                if(valid(a+1,b+2))
                {
                    tileMap[a+1][b+2].setFillColor(sf::Color::Yellow);
                }
                if(valid(a+2,b+1))
                {
                    tileMap[a+2][b+1].setFillColor(sf::Color::Yellow);
                }
                if(valid(a+2,b-1))
                {
                    tileMap[a+2][b-1].setFillColor(sf::Color::Yellow);
                }
                if(valid(a+1,b-2))
                {
                    tileMap[a+1][b-2].setFillColor(sf::Color::Yellow);
                }
                if(valid(a-1,b-2))
                {
                    tileMap[a-1][b-2].setFillColor(sf::Color::Yellow);
                }
                if(valid(a-2,b-1))
                {
                    tileMap[a-2][b-1].setFillColor(sf::Color::Yellow);
                }


           }
        }


        //clears everything
        gamewindow.clear();
        gamewindow.draw(background);

        //displaying chessboard
        gamewindow.draw(shape);
        for(int x = 0 ; x< 8 ; x++)
        {
            for(int y = 0 ; y< 8; y++)
            {
                gamewindow.draw(tileMap[x][y]);
            }
         }
         gamewindow.draw(box);
         gamewindow.draw(display);



        //number of moves recorded
        move.setPosition(900, 80);
        move.setFillColor(sf::Color::Red);
        m.setPosition(930, 130);
        m.setFillColor(sf::Color::Red);
        gamewindow.draw(move);

        hint.setPosition(930 , 300);
        hint.setFillColor(sf::Color::Red);
        gamewindow.draw(hint);
        //to convert int to string
        stringstream ss ;

        ss << moves;
        m.setString(ss.str());
        gamewindow.draw(m);


       //displaying knight on chessboard
        gamewindow.draw(knight);
        gamewindow.draw(princess);
        //display everything on window
        gamewindow.display();
    }

  }
