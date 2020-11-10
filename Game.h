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
    bool valid(int x , int y);
    bool validknightpos();
    //void knight();


private:
    //sf::Event event;
    sf::Font fonts;
	sf::Texture texknight ;
	sf::Sprite knight;
	float gridSizef = 110;
	//int box[8][8];
    int posX=3 ,posY=3; //destX=,destY=;
    float kposX , kposY;
    int moves=60;
};

