#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
using namespace std;
typedef unsigned char Uint8;

class help
{
public:
    help(float width , float height);
    ~help(){//...
    }



private:
    sf::Font fonts;
	sf::Texture textures;
};
