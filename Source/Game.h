#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <string>
#include <fstream>
#include <sstream>

#include "Engine.h"

class Game
{
public:
    Game(void);
    ~Game(void);

    void runGame();
    bool full;
    int w,h;
    int ws,hs,f;

protected:
    enum GameState {MENU,GAME,GAME_OVER,END,OPTION,TYP,SURVIVAL,INST,LEVEL};
    GameState state;
private:
    sf::Font font;
    void menu();
    void option();
    void single();
    void typ();
    void survival();
    void inst();
    void level();
    void loadcfg();
    void savecfg();
    sf::Texture texture,option_t,typ_t,inst_t,level_t;
    sf::Sprite sprite,option_s,typ_s,inst_s,level_s;
    sf::Image icons;
    sf::View view;
    int poziom;
    int soundpoziom;
    int poziommuzyki;
    std::ostringstream ss;
    sf::Music muzyka;

    Engine engine;
};
