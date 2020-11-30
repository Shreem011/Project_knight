#include <SFML/Audio.hpp>
#include "SFML/Graphics.hpp"
#include<SFML/System/Vector2.hpp>

#include <iostream>
using namespace std;


int main()
{
    //const float desired_ratio = 1.77777778f;

    sf::RenderWindow window(sf::VideoMode(1920,1080) , "GAME-OVER");
    window.setView(sf::View(sf::FloatRect(0.0f , 0.0f , 1920.0f , 1080.0f)));

    ///home/shreem/Downloads/audio.ogg
    sf::Texture splashtexture;
    if(!splashtexture.loadFromFile("/home/shreem/Downloads/gameover.png"))
    {
        //...
    }

    sf::Sprite splashsprite;
    splashsprite.setTexture(splashtexture);

    sf::Font fontss;
    fontss.loadFromFile("/home/shreem/ProjectFiles/KNIGHT/cmake-3.18.4/arial.ttf");
    sf::Text overtext("MAIN MENU", fontss);
    overtext.setCharacterSize(50);
    overtext.setColor(sf::Color::Red);
    overtext.setPosition(900,700);
    sf::Text overtextt("EXIT", fontss);
    overtextt.setCharacterSize(50);
    overtextt.setColor(sf::Color::Red);
    overtextt.setPosition(950,800);


    /*sf::Music splashmusic;
    if(!splashmusic.openFromFile("/home/shreem/Downloads/audio.ogg"))
    {
        //...
    }

    splashmusic.play();
    splashmusic.setLoop(true);
    */

    while (window.isOpen())
    {
        sf::Clock clock;

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

             else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {

               //tracks the location where mouse button is pressed
               int mouseX = event.mouseButton.x ;
               int mouseY = event.mouseButton.y ;

               //cout<<mouseX;
               cout<<endl;
               cout<<mouseY;

               if(mouseX > 900 && mouseX < 1190 && mouseY > 665 && mouseY < 700)
               {
                   cout<<"main menu is pressed:";
               }
               else if(mouseX > 945 && mouseX < 1065 && mouseY > 760 && mouseY < 800)
               {
                   cout<<"exit is pressed:";
                   window.close();
               }

            }

        }

        if(window.isOpen())
        {
            //window.clear(sf::Color(0,126,3,255));
            window.draw(splashsprite);
            window.draw(overtext);
            window.draw(overtextt);
            window.display();


        }

    }

    return 0;
}

