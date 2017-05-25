#include "Map.h"

void CMap::draw(sf::RenderWindow &win)
{
    for(int i = 0;i < part.size();++i)
    {
        if(part[i].y > 720 + 64 * part[i].size)
        {
            int r =rand()%100;
            part[i].x = rand()%1270;
            part[i].size = (rand()%10 + 3) * 0.25;
            part[i].y = -part[i].size;
            part[i].rot = rand()%180;
            if(r > 10)
            {
                part[i].typ = 0;
                part[i].r = rand()%192 + 64;
                part[i].g = rand()%192 + 64;
                part[i].b = rand()%192 + 64;
            }
            else
            {
                part[i].typ = 1;
                part[i].r = rand()%8;
                part[i].g = rand()%16 + 4;
                part[i].b = rand()%32 + 4;
                part[i].size = rand()%7 + 5;
                part[i].y = -64 * part[i].size;
            }
        }
        if(part[i].typ == 0)
        {
            part[i].y = part[i].size * 0.5 + part[i].y;
        }
        else
        {
            part[i].y = part[i].size * 0.1 + part[i].y;
        }

        /*sprite.setPosition(part[i].x,part[i].y);
        sprite.setRotation(part[i].rot);
        sprite.setScale(part[i].size,part[i].size);
        win.draw(sprite);*/
        if(part[i].typ == 0)
        {
            shape.setFillColor(sf::Color(part[i].r,part[i].g,part[i].b));
            shape.setPosition(part[i].x,part[i].y);
            shape.setRadius(part[i].size);
            win.draw(shape);
        }
        else
        {

            sprite.setPosition(part[i].x,part[i].y);
            sprite.setRotation(part[i].rot);
            sprite.setScale(part[i].size,part[i].size);
            sprite.setColor(sf::Color(part[i].r,part[i].g,part[i].b));
            win.draw(sprite);
        }
    }
}

void CMap::logic()
{

}

void CMap::start()
{
    size = 200;
    part.clear();
    while(part.size() < size)
    {
        int r = rand()%100;
        if(pyl == false or r > 10)
        {
            part.push_back(Praticle(rand()%1280,rand()%720,(rand()%10 + 3) * 0.25,rand()%180,rand()%192 + 64,rand()%192 + 64,rand()%192 + 64,0));
        }
        else
        {
            part.push_back(Praticle(rand()%1280,rand()%720,rand()%7 + 5,rand()%180,rand()%8,rand()%16 + 5,rand()%32 + 4,1));
        }
    }
}
