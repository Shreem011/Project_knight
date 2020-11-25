#include "SFML/Graphics.hpp"
#include<SFML/System/Vector2.hpp>
#include <iostream>
#include "Menu.h"
#include "Game.h"
#include "include/helpscreen.h"


int main()
{
    //menu window
	sf::RenderWindow window(sf::VideoMode(1900, 1000), "Knight TRavial" , sf::Style::Default);
    Menu menu(window.getSize().x, window.getSize().y);

    //men background
	sf::Texture tex;

    if (!tex.loadFromFile("/home/shreem/Downloads/wallpaper.png"))
	{
		std::cout << "Error loading paddle texture :(" << std::endl;
	}
	sf::Sprite bck;
	bck.setTexture(tex);

	while (window.isOpen())
	{
	    //menu button pressed events
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
                        window.close();
                        gamescreen(1090 , 890);
                        break;

					case 1:
						std::cout << "Help button has been pressed" << std::endl;
						help(500,500);
						break;

					case 2:
						window.close();
						break;
					}

					break;
				}

				break;
			    case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();
		//display background
		window.draw(bck);
        menu.draw(window);
        //display windows content and window
        window.display();
	}
}
