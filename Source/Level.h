#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <SFML/Audio.hpp>

#include "SpriteLoader.h"
#include "Enemy_meneger.h"
#include "Help_class.h"

class Level
{
public:
    Level();
    ~Level();
    void level0(Enemy_menager &enm);
    void level1(Enemy_menager &enm);
    void level2(Enemy_menager &enm);
    void Load();
    void Draw(sf::RenderWindow &win);
    bool asteroida,stacja1,stacja2;
    std::vector<tlo_object>to;
    tlo_object o;
    void add(float x,float y,float movex,float movey,int rot,std::string name,float scale);
    void start(int levels,Enemy_menager &enm);

private:
    sf::Clock clock;
    sf::Time time;
    SpriteLoader sp;
};
