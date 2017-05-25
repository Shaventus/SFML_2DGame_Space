#pragma once

#include "Help_class.h"
#include "SpriteLoader.h"
#include <string>

class col_box
{
    public:
    float x,y,w,h;
};

class Object
{
public:
    std::string name;
    float x,y,move,move_x,max_skret;
    int hp,r,g,b,max_hp;
    col_box col;
    int block;
    bool blo,ra,aktl;
};

class Object_UV
{
    public:
    std::string name;
    float x,y,move,move_x,max_skret;
    int hp,r;
    UV uv;
};

class tlo_object
{
public:
    float x,y,movex,movey,scale;
    int rot,w,h;
    std::string name;
};

class Klatka
{
public:
    float x,y,w,h,s;
    int kl,t,r;
};

bool AABB(col_box &a,col_box &b);
bool AABB(col_box &a,float x,float y,float size);
