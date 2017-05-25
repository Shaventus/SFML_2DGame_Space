#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <SFML/Audio.hpp>

#include "SpriteLoader.h"
#include "Help_class.h"

class Bullet: public SpriteLoader
{
public:
    void Init();
    void draw(sf::RenderWindow &win);
    void add();
    void add(float x,float y);
    void add(float x,float y,float move);
    void add(float x,float y,float move,std::string name);
    void add(float x,float y,float move,std::string name,UV uvz);
    void add(float x,float y,float move,std::string name,UV uvz,float move_x);
    void add(float x,float y,float move,std::string name,UV uvz,float move_x,int r);
    void logic();
    void clear();
    void setFillColor(int r,int b,int g);
    void setRadious(float r);
    Object_UV o;
    std::vector<Object_UV>b;
private:
    sf::CircleShape shape;
};

class Gracz: public Object , public SpriteLoader
{
    public:
        UV uv;
        UV uv_pocisk;
        void draw(sf::RenderWindow &win);
        void load_player_stat(std::string filename);
        void load_tarcza();
        void start();
        void clear();
        void logic(Bullet &bl);
        void fire(Bullet &bl);
        bool firep;
        bool tarcza_k,tarcza_a;
        bool shotg_k,shotg_a;
        SpriteLoader tarcza;
        int t_p;
        bool god_mod;
        void pocisktime();
        float t;
        int soundpoziom;
    private:
        void ogranicznik();
        sf::SoundBuffer bpocisk;
        sf::Sound spocisk;
        sf::Clock clock;
        sf::Time time;
};
