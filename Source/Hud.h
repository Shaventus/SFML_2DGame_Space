#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "SpriteLoader.h"

class Hud
{
public:
    void Load();
    void Draw(sf::RenderWindow &win);
    void Update(bool &ac);
    void Update_shotgun(bool &ac);
    void start();
    sf::Clock tarcz,c_shotg;
    sf::Time t_cd,t_shotg;
    SpriteLoader itarczy;
    SpriteLoader shotg;
    SpriteLoader cd,cd1;
    SpriteLoader pasek;
    float cdp,cdp_shotg;
    int t,t_s;
    bool end_t,b_shotg;

    void hp(int hp);
private:
    sf::Font font;
    sf::Text te_tarczy,te_shotg,hp_t;
    std::ostringstream ss;
};
