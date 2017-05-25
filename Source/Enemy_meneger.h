#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <iostream>

#include "SpriteLoader.h"
#include "Help_class.h"
#include "Object.h"

class Enemy_menager
{
    public:
        static Enemy_menager& getInstance();
        Enemy_menager();
        ~Enemy_menager();
        void draw(sf::RenderWindow &win);
        std::vector<SpriteLoader> sp;
        std::vector<Object>en;
        void load(std::string filename);
        void init(void);
        SpriteLoader s;
        void start();
        Object a;

        void add(std::string name,float x,float y);
        void add(std::string name,float x,float y,float move_x);

        void fire(Bullet &bul);

        void start_survival();
        void draw_survival(sf::RenderWindow &win);
        int l_s; // Liczba obiektów w tyrbie survial
        short int r; // Typ statku który się wylosuje

        UV uv_pocisk;
        sf::Clock bossc;
        sf::Time bosst;
        int t_b;
        bool b_de;
        bool maska;
};
