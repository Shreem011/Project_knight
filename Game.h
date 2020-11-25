#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>

#include<functional>
#include<math.h>
#include<float.h>
#include<vector>
#include<set>
#include<string.h>
#include<string>
#include<sstream>

using namespace std;

class gamescreen
{
public:
    gamescreen(float width , float height);
    ~gamescreen(){//...
    }
    bool valid(int x , int y);

private:
    sf::Font fonts;
	sf::Texture texknight , texprincess , texback;
	sf::Sprite knight , princess , background;
	float gridSizef = 110;
    int posX=0 ,posY=0 , destX=4 ,destY=5 ;
    float kposX , kposY , fposX , fposY , fdestX , fdestY , hintX , hintY;
    int moves=25, score;
};

