#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class SpriteLoader
{
    public:
    std::string name_sprite;
    sf::Sprite sprite;
    sf::Texture texture;
    void load(std::string filename);
};

struct UV
{
    int x,y,w,h;
};
