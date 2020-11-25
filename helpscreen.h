#pragma once

#include "SFML/Graphics.hpp"
#include<iostream>

using namespace std;

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
