#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	sf::Sprite sprite;

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Texture texture;
	//sf::Sprite sprite;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
//home/shreem/Downloads/PngItem_71553.png
