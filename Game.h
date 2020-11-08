#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
using namespace std;
typedef unsigned char Uint8;

class gamescreen
{
public:
    gamescreen(float width , float height);
    ~gamescreen(){//...
    }



private:
    sf::Font fonts;
	sf::Texture textures;
};

