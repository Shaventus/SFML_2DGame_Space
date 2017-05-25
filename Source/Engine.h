#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <string>
#include <fstream>
#include <sstream>

#include "Object.h"
#include "Map.h"
#include "Enemy_meneger.h"
#include "Help_class.h"
#include "Hud.h"
#include "Level.h"
#include "SpceialEffcet.h"

#include "SpriteLoader.h"

class Engine
{
public:
    Engine(void);
    ~Engine(void);

    void run(sf::RenderWindow &win);
    void run_survival(sf::RenderWindow &win);
    void Load();
    void Logic();
    void Logic_survival();
    CMap cmap;
    bool exit;
    void load_stats(std::string filename);
    void colision();
    void colision_survival();
    void loadHS(); // load high score
    void rewriteHS();
    int highscore;
    bool end;
    int levels;
    sf::SoundBuffer buffer1,bwybuch;
    sf::Sound sound,swybuch;
    int soundpoziom;
private:
    int mkrew;
    float mk;
    Hud hu;
    SpecialEffect se;
    Gracz player;
    Bullet bullet;
    Bullet en_b;
    Enemy_menager em;
    Level level;
    int score;
    SpriteLoader mt;
    sf::Font font;
    sf::Text t_score,t_death,t_death1,hgs; // hgs high score
    std::ostringstream ss;
    std::string rand_e;
    int r;
};
