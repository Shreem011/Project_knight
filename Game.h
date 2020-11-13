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
	sf::Texture texknight , texprincess;
	sf::Sprite knight , princess;
	float gridSizef = 110;
	//int box[8][8];
    int posX=0 ,posY=0 , destX=7 ,destY=6 ;
    float kposX , kposY;
    int moves=5;
};

