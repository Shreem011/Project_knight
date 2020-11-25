#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
using namespace std;

class gameOver
{
public:
    gameOver(float width , float height);
    ~gameOver(){//...
    }

private:
    sf::Font fontss;
	sf::Texture texturess;
};

