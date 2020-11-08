#include "SFML/Graphics.hpp"
#include<SFML/System/Vector2.hpp>
#include <iostream>

#include "Menu.h"
#include "Game.h"
#include "include/helpscreen.h"


int main()
{

	sf::RenderWindow window(sf::VideoMode(1900, 1000), "Knight TRavial" , sf::Style::Default);
    Menu menu(window.getSize().x, window.getSize().y);
    //gamescreen game(window.getSize().x, window.getSize().y);

	//sf::Texture texture;

    //if (!texture.loadFromFile("/home/shreem/Downloads/whiteKnight.png"))
	//{
		//std::cout << "Error loading paddle texture :(" << std::endl;
	//}
	//sf::Sprite sprite;
	//sprite.setTexture(texture);

	while (window.isOpen())
	{
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
						//window.clear();
                        window.close();
                        gamescreen(1090 , 890);
                        //window.close();
						break;
					case 1:
						std::cout << "Help button has been pressed" << std::endl;
						//Help();
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
		//window.draw(sprite);
        menu.draw(window);

        window.display();
	}
}
