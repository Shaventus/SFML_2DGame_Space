#include "Enemy_meneger.h"
Enemy_menager& Enemy_menager::getInstance()
{
    static Enemy_menager en;
    return en;
}
Enemy_menager::Enemy_menager()
{

}

Enemy_menager::~Enemy_menager()
{

}

void Enemy_menager::draw(sf::RenderWindow &win)
{
    for(int i = 0;i < en.size();++i)
    {
        en[i].col.x = en[i].x;
        en[i].col.y = en[i].y;
        en[i].y += en[i].move;
        ////                                             BOSS 1
        if(en[i].name == "Boss")
        {
            if(en[i].y >= en[i].block)
            {
                en[i].y = en[i].block;
                en[i].blo = true;
                //bossc.restart();
                t_b = 0;
            }
            if(en[i].blo == true)
            {
                bosst = bossc.getElapsedTime();
                t_b = bosst.asSeconds();
                if(en[i].x <= 10)
                {
                    en[i].ra = true;
                }
                else if(en[i].x + en[i].col.w >= 1270)
                {
                    en[i].ra = false;
                }
                if(en[i].ra == true)
                {
                    en[i].x += 6;
                }
                else
                {
                    en[i].x -= 6;
                }
                //std::cout << t_b << std::endl;
                if(t_b >= 3)
                {

                    bossc.restart();
                    t_b = 0;
                        add("sr",100,-200);
                        add("sr",200,-200);
                        add("sr",300,-200);
                        add("sr",400,-200);
                        add("sr",500,-200);
                        add("sr",600,-200);
                        add("sr",700,-200);
                        add("sr",800,-200);
                        add("sr",900,-200);
                        add("sr",1000,-200);
                        add("sr",1100,-200);
                        add("sr",1200,-200);
                }
            }
        }
        ////                  MASKA BOSS
        if(en[i].name == "Maskaboss")
        {
            if(en[i].y >= en[i].block)
            {
                en[i].y = en[i].block;
                en[i].blo = true;
                //bossc.restart();
                t_b = 0;
            }
            if(en[i].blo == true)
            {
                bosst = bossc.getElapsedTime();
                t_b = bosst.asSeconds();
                if(en[i].x <= 10)
                {
                    en[i].ra = true;
                }
                else if(en[i].x + en[i].col.w >= 1270)
                {
                    en[i].ra = false;
                }
                if(en[i].ra == true)
                {
                    en[i].x += 6;
                }
                else
                {
                    en[i].x -= 6;
                }
                if(t_b >= 3)
                {

                    bossc.restart();
                    t_b = 0;
                        add("dem",100,-200);
                        add("dem",200,-200);
                        add("dem",300,-200);
                        add("dem",400,-200);
                        add("dem",500,-200);
                        add("dem",600,-200);
                        add("dem",700,-200);
                        add("dem",800,-200);
                        add("dem",900,-200);
                        add("dem",1000,-200);
                        add("dem",1100,-200);
                        add("dem",1200,-200);
                }
                //std::cout << t_b << std::endl;
            }
        }
        //// Pixli
        if(en[i].name == "Pixil")
        {
            if(en[i].y >= en[i].block)
            {
                en[i].y = en[i].block;
                en[i].blo = true;
                //bossc.restart();
                t_b = 0;
            }
            if(en[i].blo == true)
            {
                bosst = bossc.getElapsedTime();
                t_b = bosst.asSeconds();
                if(en[i].x <= 10)
                {
                    en[i].ra = true;
                }
                else if(en[i].x + en[i].col.w >= 1270)
                {
                    en[i].ra = false;
                }
                if(en[i].ra == true)
                {
                    en[i].x += 6;
                }
                else
                {
                    en[i].x -= 6;
                }
                if(t_b >= 3)
                {

                    bossc.restart();
                    t_b = 0;
                        add("sr_p",100,-200);
                        add("sr_p",200,-200);
                        add("sr_p",300,-200);
                        add("sr_p",400,-200);
                        add("sr_p",500,-200);
                        add("sr_p",600,-200);
                        add("sr_p",700,-200);
                        add("sr_p",800,-200);
                        add("sr_p",900,-200);
                        add("sr_p",1000,-200);
                        add("sr_p",1100,-200);
                        add("sr_p",1200,-200);
                }
                //std::cout << t_b << std::endl;
            }
        }
        //// MASKI
        if(en[i].name == "Maskaa")
        {
            if(en[i].y >= en[i].block)
            {
                en[i].y = en[i].block;
                en[i].blo = true;
                //bossc.restart();
                t_b = 0;
            }
            if(en[i].blo == true)
            {
                if(en[i].x <= 10)
                {
                    en[i].ra = true;
                }
                else if(en[i].x + en[i].col.w >= 1270)
                {
                    en[i].ra = false;
                }
                if(en[i].ra == true)
                {
                    en[i].x += 6;
                }
                else
                {
                    en[i].x -= 6;
                }

                //std::cout << t_b << std::endl;
            }
        }
        if(en[i].name == "Maskab")
        {
            if(en[i].y >= en[i].block)
            {
                en[i].y = en[i].block;
                en[i].blo = true;
                //bossc.restart();
                t_b = 0;
            }
            if(en[i].blo == true)
            {
                if(en[i].x <= 10)
                {
                    en[i].ra = true;
                }
                else if(en[i].x + en[i].col.w >= 1270)
                {
                    en[i].ra = false;
                }
                if(en[i].ra == true)
                {
                    en[i].x += 6;
                }
                else
                {
                    en[i].x -= 6;
                }

                //std::cout << t_b << std::endl;
            }
        }
        ////
        if(en[i].y > 780)
        {
            en.erase(en.begin()+i);
        }
        if(en[i].y + en[i].col.h > 0 and en[i].y < 720)
        {
        if(en[i].name == "sr")
        {
            s.sprite.setTextureRect(sf::IntRect( 0, 0, 32,32));
        }
        else if(en[i].name == "sr_p")
        {
            s.sprite.setTextureRect(sf::IntRect( 0, 96, 32,32));
        }
        else if(en[i].name == "dem")
        {
            s.sprite.setTextureRect(sf::IntRect( 0, 128, 32,32));
        }
        else if(en[i].name == "kr")
        {
            s.sprite.setTextureRect(sf::IntRect( 32, 0, 64,64));
        }
        else if(en[i].name == "kr_p")
        {
            s.sprite.setTextureRect(sf::IntRect( 32, 64, 64,64));
        }
        else if(en[i].name == "as")
        {
            s.sprite.setTextureRect(sf::IntRect( 96, 0, 113,115));
        }
        else if(en[i].name == "Boss")
        {
            if(en[i].aktl == false)
            {
                s.sprite.setTextureRect(sf::IntRect( 209, 0, 256,128));
            }
            else
            {
                s.sprite.setTextureRect(sf::IntRect( 209, 128, 256,128));
            }
        }
        else if(en[i].name == "Pixil")
        {
            if(en[i].aktl == false)
            {
                s.sprite.setTextureRect(sf::IntRect( 784, 0, 640,300));
            }
            else
            {
                s.sprite.setTextureRect(sf::IntRect( 784, 300, 640,300));
            }
        }
        else if(en[i].name == "Maskaa")
        {
            if(en[i].aktl == false)
            {
                s.sprite.setTextureRect(sf::IntRect( 677, 0, 107,129));
            }
            else
            {
                s.sprite.setTextureRect(sf::IntRect( 677, 129, 107,129));
            }
        }
        else if(en[i].name == "Maskab")
        {
            if(en[i].aktl == false)
            {
                s.sprite.setTextureRect(sf::IntRect( 677, 0, 107,129));
            }
            else
            {
                s.sprite.setTextureRect(sf::IntRect( 677, 129, 107,129));
            }
        }
        else if(en[i].name == "kula")
        {
            s.sprite.setTextureRect(sf::IntRect( 0, 32, 32,32));
        }
        else if(en[i].name == "pixelkula")
        {
            s.sprite.setTextureRect(sf::IntRect( 0, 64, 32,32));
        }
        else if (en[i].name == "Maskaboss")
        {
            if(maska == true)
            {
                s.sprite.setTextureRect(sf::IntRect( 465, 0, 212,255));
            }
            else
            {
            if(en[i].aktl == false)
            {
                s.sprite.setTextureRect(sf::IntRect( 465, 255, 212,255));
            }
            else
            {
                s.sprite.setTextureRect(sf::IntRect( 465, 255 + 255, 212,255));
            }
            }
        }
        if(en[i].y + en[i].col.h > 0 or en[i].y < 720)
        {
            en[i].x += en[i].move_x;
            s.sprite.setPosition(en[i].x,en[i].y);
            win.draw(s.sprite);
        }
        }
    }
}

void Enemy_menager::load(std::string filename)
{
    s.load(filename);
   // s.name_sprite = nam;
    std::cout <<"dodano sprita\n";
}

void Enemy_menager::start()
{
    en.clear();
    for(int i = 0;i < 6;i++)
    {
        a.x = rand()%1200;
        a.y = -1* rand()%200 + 60;
        a.move = 6;
        a.name = "as";
        a.hp = 12;
        a.col.w = 113;
        a.col.h = 115;
        en.push_back(a);
    }
}

void Enemy_menager::init()
{
    sp.reserve(16);
}

void Enemy_menager::draw_survival(sf::RenderWindow &win)
{
    for(int i = 0;i < en.size();++i)
    {
        en[i].col.x = en[i].x;
        en[i].col.y = en[i].y;
        en[i].y += en[i].move;
        if(en[i].y > 780)
        {
            if(en[i].hp <= 0)
            {
                r = rand()%3;
            if(r == 0)
                   {
                    a.x = rand()%1200;
                    a.y = -1* (rand()%400 + 120);
                    a.move = 6;
                    a.name = "as";
                    a.hp = 12;
                    a.col.w = 113;
                    a.col.h = 115;
                }
            else if(r == 1)
                {
                    a.x = rand()%1200;
                    a.y = -1* (rand()%400 + 120);
                    a.move = 8;
                    a.name = "kr";
                    a.hp = 8;
                    a.col.w = 64;
                    a.col.h = 64;
                }
            else if(r == 2)
            {
                    a.x = rand()%1200;
                    a.y = -1* (rand()%400 + 120);
                    a.move = 12;
                    a.name = "sr";
                    a.hp = 2;
                    a.col.w = 32;
                    a.col.h = 32;
            }
                en.push_back(a);
            }
            en[i].x = rand()%1200;
            en[i].y = -1 * (rand()%400 + 80 );
            en[i].hp = 12;
        }
        if(en[i].y + en[i].col.h > 0 and en[i].y < 720)
        {
        if(en[i].name == "sr")
        {
            s.sprite.setTextureRect(sf::IntRect( 0, 0, 32,32));
        }
        else if(en[i].name == "sr_p")
        {
            s.sprite.setTextureRect(sf::IntRect( 0, 96, 32,32));
        }
        else if(en[i].name == "dem")
        {
            s.sprite.setTextureRect(sf::IntRect( 0, 128, 32,32));
        }
        else if(en[i].name == "kr")
        {
            s.sprite.setTextureRect(sf::IntRect( 32, 0, 64,64));
        }
        else if(en[i].name == "kr_p")
        {
            s.sprite.setTextureRect(sf::IntRect( 32, 64, 64,64));
        }
        else if(en[i].name == "as")
        {
            s.sprite.setTextureRect(sf::IntRect( 96, 0, 113,115));
        }
        else if(en[i].name == "Boss")
        {
            s.sprite.setTextureRect(sf::IntRect( 209, 0, 256,128));
        }
        if(en[i].y + en[i].col.h > 0 or en[i].y < 720)
        {
            s.sprite.setPosition(en[i].x,en[i].y);
            win.draw(s.sprite);
        }
        }
    }
}

void Enemy_menager::start_survival()
{
    l_s = 4;
    en.clear();
    for(int i = 0;i < l_s;i++)
    {
        r = rand()%3;
        if(r == 0)
        {
            add("as",rand()%1200,-1* rand()%200 + 60);
        }
        else if(r == 1)
        {
            add("kr",rand()%1200,-1* rand()%200 + 60);
        }
        else if(r == 2)
        {
            add("sr",rand()%1200,-1* rand()%200 + 60);
        }
        en.push_back(a);
    }
}

void Enemy_menager::add(std::string name,float x,float y)
{
    if(name == "kr" or name == "kr_p")
    {
            a.x = x;
            a.y = y;
            a.move_x = 0;
            a.move = 8;
            a.name = name;
            a.hp = 16;
            a.max_hp = a.hp;
            a.col.w = 64;
            a.col.h = 64;
    }
    else if(name == "sr" or name == "sr_p" or name == "dem")
    {
            a.x = x;
            a.y = y;
            a.move_x = 0;
            a.move = 12;
            a.name = name;
            a.hp = 2;
            a.max_hp = a.hp;
            a.col.w = 32;
            a.col.h = 32;
    }
    else if(name == "as")
    {
            a.x = x;
            a.y = y;
            a.move = 6;
            a.move_x = 0;
            a.name = name;
            a.hp = 12;
            a.max_hp = a.hp;
            a.col.w = 113;
            a.col.h = 115;
    }
    else if(name == "Boss")
    {
            a.x = x;
            a.y = y;
            a.move = 6;
            a.move_x = 0;
            a.name = "Boss";
            a.hp = 2540;
            a.max_hp = a.hp;
            a.col.w = 256;
            a.col.h = 120;
            a.blo = false;
            a.block = 60;
            a.ra = true;
            a.aktl = false;
            b_de = false;
    }
    else if(name == "Pixil")
    {
            a.x = x;
            a.y = y;
            a.move = 6;
            a.move_x = 0;
            a.name = "Pixil";
            a.hp = 6000;
            a.max_hp = a.hp;
            a.col.w = 640;
            a.col.h = 300;
            a.blo = false;
            a.block = -10;
            a.ra = true;
            a.aktl = false;
            b_de = false;
    }
    else if(name == "kula")
    {
            a.x = x;
            a.y = y;
            a.move = 4;
            a.move_x = 0;
            a.name = "kula";
            a.hp = 2540;
            a.max_hp = a.hp;
            a.col.w = 28;
            a.col.h = 28;
            a.blo = false;
            a.block = 60;
            a.ra = true;
            a.aktl = false;
            b_de = false;
    }
    else if(name == "pixelkula")
    {
            a.x = x;
            a.y = y;
            a.move = 4 + rand()%2;
            a.move_x = 0;
            a.name = "pixelkula";
            a.hp = 2540;
            a.max_hp = a.hp;
            a.col.w = 28;
            a.col.h = 28;
            a.blo = false;
            a.block = 60;
            a.ra = true;
            a.aktl = false;
            b_de = false;
    }
    else if(name == "Maskaboss")
    {
            a.x = x;
            a.y = y;
            a.move = 6;
            a.move_x = 0;
            a.name = "Maskaboss";
            a.hp = 2540;
            a.max_hp = a.hp;
            a.col.w = 212;
            a.col.h = 255;
            a.blo = false;
            a.block = 10;
            a.ra = true;
            a.aktl = false;
            b_de = false;
            en.push_back(a);

            // maska 1
            a.x = x - 120;
            a.y = y + 80;
            a.move = 6;
            a.move_x = 0;
            a.name = "Maskaa";
            a.hp = 1000;
            a.max_hp = a.hp;
            a.col.w = 108;
            a.col.h = 129;
            a.blo = false;
            a.block = 60;
            a.ra = true;
            a.aktl = false;
            b_de = false;
            en.push_back(a);

            // maska 2
            a.x = x + 120 + 212;
            a.y = y + 80;
            a.move = 6;
            a.move_x = 0;
            a.name = "Maskab";
            a.hp = 1000;
            a.max_hp = a.hp;
            a.col.w = 108;
            a.col.h = 129;
            a.blo = false;
            a.block = 60;
            a.ra = false;
            a.aktl = false;
            b_de = false;
    }
    en.push_back(a);
}

void Enemy_menager::add(std::string name,float x,float y,float move_x)
{
    if(name == "kr" or name == "kr_p")
    {
            a.x = x;
            a.y = y;
            a.move_x = move_x;
            a.move = 8;
            a.name = name;
            a.hp = 16;
            a.max_hp = a.hp;
            a.col.w = 64;
            a.col.h = 64;
    }
    else if(name == "sr" or name == "sr_p" or name == "dem")
    {
            a.x = x;
            a.y = y;
            a.move_x = move_x;
            a.move = 12;
            a.name = name;
            a.hp = 2;
            a.max_hp = a.hp;
            a.col.w = 32;
            a.col.h = 32;
    }
    else if(name == "as")
    {
            a.x = x;
            a.y = y;
            a.move = 6;
            a.move_x = move_x;
            a.name = "as";
            a.hp = 40;
            a.max_hp = a.hp;
            a.col.w = 113;
            a.col.h = 115;
    }
    else if(name == "Boss")
    {
            a.x = x;
            a.y = y;
            a.move = 6;
            a.move_x = move_x;
            a.name = "Boss";
            a.hp = 2540;
            a.max_hp = a.hp;
            a.col.w = 256;
            a.col.h = 120;
            a.blo = false;
            a.block = 60;
            a.ra = true;
            a.aktl = false;
            b_de = false;
    }
    else if(name == "Pixil")
    {
            a.x = x;
            a.y = y;
            a.move = 6;
            a.move_x = move_x;
            a.name = "Pixil";
            a.hp = 6000;
            a.max_hp = a.hp;
            a.col.w = 640;
            a.col.h = 300;
            a.blo = false;
            a.block = -10;
            a.ra = true;
            a.aktl = false;
            b_de = false;
    }
    else if(name == "kula")
    {
            a.x = x;
            a.y = y;
            a.move = 4;
            a.move_x = move_x;
            a.name = "kula";
            a.hp = 2540;
            a.max_hp = a.hp;
            a.col.w = 28;
            a.col.h = 28;
            a.blo = false;
            a.block = 60;
            a.ra = true;
            a.aktl = false;
            b_de = false;
    }
    else if(name == "pixelkula")
    {
            a.x = x;
            a.y = y;
            a.move = 4 + rand()%2;
            a.move_x = move_x;
            a.name = "pixelkula";
            a.hp = 2540;
            a.max_hp = a.hp;
            a.col.w = 28;
            a.col.h = 28;
            a.blo = false;
            a.block = 60;
            a.ra = true;
            a.aktl = false;
            b_de = false;
    }
    else if(name == "Maskaboss")
    {
            a.x = x;
            a.y = y;
            a.move = 6;
            a.move_x = move_x;
            a.name = "Maskaboss";
            a.hp = 2540;
            a.max_hp = a.hp;
            a.col.w = 212;
            a.col.h = 255;
            a.blo = false;
            a.block = 10;
            a.ra = true;
            a.aktl = false;
            b_de = false;
            en.push_back(a);

            // maska 1
            a.x = x - 120;
            a.y = y + 80;
            a.move = 6;
            a.move_x = move_x;
            a.name = "Maskaa";
            a.hp = 1000;
            a.max_hp = a.hp;
            a.col.w = 108;
            a.col.h = 129;
            a.blo = false;
            a.block = 60;
            a.ra = true;
            a.aktl = false;
            b_de = false;
            en.push_back(a);

            // maska 2
            a.x = x + 120 + 212;
            a.y = y + 80;
            a.move = 6;
            a.move_x = move_x;
            a.name = "Maskab";
            a.hp = 1000;
            a.max_hp = a.hp;
            a.col.w = 108;
            a.col.h = 129;
            a.blo = false;
            a.block = 60;
            a.ra = false;
            a.aktl = false;
            b_de = false;
    }
    en.push_back(a);
}

void Enemy_menager::fire(Bullet &bul)
{
    for(int i = 0;i < en.size();++i)
    {
            if(en[i].y + en[i].col.h > 0 and en[i].y < 720)
            {
                if(en[i].name == "as" or en[i].name == "kr" or en[i].name == "kr_p")
                {
                r = rand()%1000;
                if(r < 10)
                {
                    bul.add(en[i].x + en[i].col.w/2,en[i].y + en[i].col.h,12,"E",uv_pocisk,0);
                }
                }
                else if(en[i].name == "Boss")
                {
                    int r1 = rand()%4;
                    r = rand()%1000;
                    if(r < 100)
                    {
                        if(r1 == 0)
                        {
                            bul.add(en[i].x + en[i].col.w/2 + 32,en[i].y + en[i].col.h,12,"E",uv_pocisk,0);
                        }
                        else if(r1 == 1)
                        {
                            bul.add(en[i].x + en[i].col.w/2 + 64,en[i].y + en[i].col.h,12,"E",uv_pocisk,0);
                        }
                        else if(r1 == 2)
                        {
                            bul.add(en[i].x + en[i].col.w/2 - 32,en[i].y + en[i].col.h,12,"E",uv_pocisk,0);
                        }
                        else if(r1 == 3)
                        {
                            bul.add(en[i].x + en[i].col.w/2 - 64,en[i].y + en[i].col.h,12,"E",uv_pocisk,0);
                        }
                    }
                }
                else if (en[i].name == "Maskaa" or en[i].name == "Maskab")
                {
                    r = rand()%1000;
                    int k = 0;
                    int r1 = rand()%4;
                    if(r <= 20 and r1 == 1)
                    {
                        add("kula",en[i].x + 53,en[i].y + 90,-2);
                        add("kula",en[i].x + 53,en[i].y + 90);
                        add("kula",en[i].x + 53,en[i].y + 90,2);
                    }
                }
                else if (en[i].name == "Maskaboss")
                {
                    r = rand()%1000;
                    int k = 0;
                    int r1 = rand()%4;
                    if(r <= 20 and r1 == 1)
                    {
                        add("kula",en[i].x + 53,en[i].y + 90,-4);
                        add("kula",en[i].x + 53,en[i].y + 90,-2);
                        add("kula",en[i].x + 53,en[i].y + 90);
                        add("kula",en[i].x + 53,en[i].y + 90,2);
                        add("kula",en[i].x + 53,en[i].y + 90,4);
                    }
                    if(maska == false and r > 990)
                    {
                        add("kula",en[i].x + 53,en[i].y + 90,-8);
                        add("kula",en[i].x + 53,en[i].y + 90,-6);
                        add("kula",en[i].x + 53,en[i].y + 90,-4);
                        add("kula",en[i].x + 53,en[i].y + 90,-2);
                        add("kula",en[i].x + 53,en[i].y + 90);
                        add("kula",en[i].x + 53,en[i].y + 90,2);
                        add("kula",en[i].x + 53,en[i].y + 90,4);
                        add("kula",en[i].x + 53,en[i].y + 90,6);
                        add("kula",en[i].x + 53,en[i].y + 90,8);
                    }
                }
                else if (en[i].name == "Pixil")
                {
                    r = rand()%1000;
                    int k = 0;
                    int r1 = rand()%4;
                    if(r <= 5 and r1 == 1)
                    {
                        add("pixelkula",en[i].x + 38,en[i].y + 242 - 10,0); //3

                        add("pixelkula",en[i].x + 131,en[i].y + 266 - 10,0);

                        add("pixelkula",en[i].x + 240,en[i].y + 283 -10 ,0);

                        add("pixelkula",en[i].x + 312,en[i].y + 300 -10,0);
                        add("pixelkula",en[i].x + 324,en[i].y + 300 -10,0);

                        add("pixelkula",en[i].x + 400,en[i].y + 283 -10,0);

                        add("pixelkula",en[i].x + 509,en[i].y + 266 -10,0);

                        add("pixelkula",en[i].x + 594,en[i].y + 242 -10,0);
                    }
                    else if(r <= 5 and r1 == 2)
                    {
                        add("pixelkula",en[i].x + 43,en[i].y + 242 -10,0);

                        add("pixelkula",en[i].x + 131,en[i].y + 266 -10,0);

                        add("pixelkula",en[i].x + 240,en[i].y + 283 -10,0);
                    }
                    else if(r <= 5 and r1 == 3)
                    {

                        add("pixelkula",en[i].x + 400,en[i].y + 283 -10,0);

                        add("pixelkula",en[i].x + 509,en[i].y + 266 -10,0);

                        add("pixelkula",en[i].x + 594,en[i].y + 242 -10,0);
                    }
                    else if(r <= 5 and r1 == 0)
                    {

                        add("pixelkula",en[i].x + 312,en[i].y + 300 -10,0);
                        add("pixelkula",en[i].x + 324,en[i].y + 300 -10,0);
                    }
                    if(r > 20 and r < 30)
                    {
                        add("pixelkula",en[i].x + 43,en[i].y + 242 -10,0);
                    }
                    else if(r >= 31 and r < 40)
                    {
                        add("pixelkula",en[i].x + 131,en[i].y + 266 -10,0);
                    }
                    else if(r > 41 and r < 50)
                    {
                        add("pixelkula",en[i].x + 240,en[i].y + 283 -10,0);
                    }
                    else if(r > 51 and r < 60)
                    {
                        add("pixelkula",en[i].x + 400,en[i].y + 283 -10,0);
                    }
                    else if(r > 61 and r < 70)
                    {
                        add("pixelkula",en[i].x + 509,en[i].y + 266 -10,0);
                    }
                    else if(r > 71 and r < 80)
                    {
                        add("pixelkula",en[i].x + 594,en[i].y + 242 -10,0);
                    }
                    if(r > 980)
                    {
                        if(r1 == 0)
                        {
                            bul.add(en[i].x + en[i].col.w/2 + 32,en[i].y + en[i].col.h,12,"E",uv_pocisk,2);
                        }
                        else if(r1 == 1)
                        {
                            bul.add(en[i].x + en[i].col.w/2 + 64,en[i].y + en[i].col.h,12,"E",uv_pocisk,4);
                        }
                        else if(r1 == 2)
                        {
                            bul.add(en[i].x + en[i].col.w/2 - 32,en[i].y + en[i].col.h,12,"E",uv_pocisk,-2);
                        }
                        else if(r1 == 3)
                        {
                            bul.add(en[i].x + en[i].col.w/2 - 64,en[i].y + en[i].col.h,12,"E",uv_pocisk,-4);
                        }
                    }

                }
            }
    }
}
