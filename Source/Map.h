#pragma once

#include "SpriteLoader.h"

struct Praticle
{
    sf::Color col;
    float x,y,size;
    short r,g,b,typ;
    int rot;

    Praticle()
    {

    }

    Praticle(float x,float y,float size,int rot)
    :x(x),
    y(y),
    size(size),
    rot(rot)
    {

    }

    Praticle(float x,float y,float size,int rot,sf::Color col)
    :x(x),
    y(y),
    size(size),
    rot(rot),
    col(col)
    {

    }

    Praticle(float x,float y,float size,int rot,short r,short g,short b)
    :x(x),
    y(y),
    size(size),
    rot(rot),
    r(r),
    g(g),
    b(b)
    {

    }

    Praticle(float x,float y,float size,int rot,short r,short g,short b,short typ)
    :x(x),
    y(y),
    size(size),
    rot(rot),
    r(r),
    g(g),
    b(b),
    typ(typ)
    {

    }
};

class CMap :public SpriteLoader
{
public:
    void draw(sf::RenderWindow &win);
    void logic();
    void start();
    std::vector<Praticle>part;
    int size;
    sf::CircleShape shape;
    bool pyl;
};
