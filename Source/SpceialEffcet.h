#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "SpriteLoader.h"
#include "Help_class.h"

class SpecialEffect
{
public:
    void Init();
    void Draw(sf::RenderWindow &win);
    void Logic();
    void addEks(float x,float y);
    void addEks(float x,float y,float scale);
    void Load();
    void start();

    SpriteLoader sp;
    std::vector<Klatka>klatka;
    Klatka z;
private:
};
