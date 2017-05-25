#include "SpceialEffcet.h"

void SpecialEffect::Init()
{

}

void SpecialEffect::Draw(sf::RenderWindow &win)
{
    for(int i = 0;i < klatka.size();++i)
    {
        sp.sprite.setScale(klatka[i].s,klatka[i].s);
        sp.sprite.setOrigin(sf::Vector2f(71/2, 50));
        sp.sprite.setRotation(klatka[i].r);
        sp.sprite.setTextureRect(sf::IntRect( 0 + klatka[i].w * klatka[i].kl, 0, klatka[i].w,klatka[i].h));
        sp.sprite.setPosition(klatka[i].x,klatka[i].y);
        win.draw(sp.sprite);
    }

}

void SpecialEffect::Logic()
{
    for(int i = 0;i < klatka.size();++i)
    {
        if(klatka[i].kl >=18)
        {
            klatka.erase(klatka.begin() + i);
        }
        klatka[i].t++;
        klatka[i].kl = klatka[i].t/4;
       // std::cout << klatka[i].kl << std::endl;
    }
}

void SpecialEffect::addEks(float x,float y)
{
    z.x = x;
    z.y = y;
    z.w = 71;
    z.h = 100;
    z.kl = 0;
    z.t = 0;
    z.r = rand()%359;
    z.s = (rand()%10+20)/10;
    klatka.push_back(z);
}

void SpecialEffect::addEks(float x,float y,float scale)
{
    z.x = x;
    z.y = y;
    z.w = 71;
    z.h = 100;
    z.kl = 0;
    z.t = 0;
    z.r = rand()%359;
    z.s = scale;
    klatka.push_back(z);
}

void SpecialEffect::Load()
{
    sp.load("Data/GFX/ekspolzja.png");
}

void SpecialEffect::start()
{
    klatka.clear();
}

