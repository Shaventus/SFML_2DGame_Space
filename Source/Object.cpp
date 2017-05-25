#include "Object.h"

void Gracz::draw(sf::RenderWindow &win)
{
    sprite.setPosition(x,y);
    col.x = x;
    col.y = y;
    win.draw(sprite);
    if(tarcza_a == true)
    {
        tarcza.sprite.setColor(sf::Color(255, 255, 255, t_p));
        tarcza.sprite.setPosition(x,y);
        win.draw(tarcza.sprite);
    }
}

void Gracz::load_player_stat(std::string filename)
{
    std::fstream plik;
    plik.open(filename.c_str());
    if(plik.is_open() == true)
    {
        std::string s,pom;
        while(!plik.eof())
        {
            plik >> s;
            if(s == "#name")
            {
                plik >> name;
            }
            if(s == "#Texture")
            {
                plik >> pom;
                load(pom);
            }
            if(s == "#width")
            {
                plik >> uv.w;
            }
            if(s == "#height")
            {
                plik >> uv.h;
            }
            if(s == "#x")
            {
                plik >> uv.x;
            }
            if(s == "#y")
            {
                plik >> uv.y;
            }
            if(s == "#move")
            {
                plik >> move;
            }
           // std::cout << s << std::endl;
        }

    }
    else
    {
        MessageBox(NULL,filename.c_str(),"ERROR",NULL);
    }
    bpocisk.loadFromFile("Data/SFX/pocisk.wav");
    spocisk.setBuffer(bpocisk);
    spocisk.setVolume(soundpoziom/5);
    spocisk.setLoop(false);
}

void Gracz::clear()
{

}

void Gracz::pocisktime()
{
    time = clock.getElapsedTime();
    t = time.asSeconds();
    if(t > 0.25 and firep == true)
    {
        t = 0;
        clock.restart();
        spocisk.play();
        firep = false;
    }

}

void Gracz::start()
{
    x = 1280/2 - uv.w/2;
    y = 720 - 30 - uv.h;
    hp = 20;
    col.w = uv.w;
    col.h = uv.h;
    tarcza_a = false;
    tarcza_k = true;
    shotg_k = true;
    god_mod = false;
    firep = false;
    spocisk.setVolume(soundpoziom/5);
}

void Gracz::ogranicznik()
{
    if(x < 0)
    {
        x = 0;
    }
    if(x + uv.w > 1280)
    {
        x = 1280 - uv.w;
    }
    if(y < 0)
    {
        y = 0;
    }
    if(y + uv.h > 720)
    {
        y = 720 - uv.h;
    }
}

void Gracz::logic(Bullet &bl)
{
    sprite.setColor(sf::Color(255,255,255,255));
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::A ) or sf::Keyboard::isKeyPressed( sf::Keyboard::Left ))
    {
        x -= move;
    }
    else if(sf::Keyboard::isKeyPressed( sf::Keyboard::D ) or sf::Keyboard::isKeyPressed( sf::Keyboard::Right ))
    {

        x += move;
    }
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::S ) or sf::Keyboard::isKeyPressed( sf::Keyboard::Down ))
    {
        y += move;
    }
    else if(sf::Keyboard::isKeyPressed( sf::Keyboard::W ) or sf::Keyboard::isKeyPressed( sf::Keyboard::Up ))
    {
        y -= move;
    }
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::Q ) and tarcza_k == true)
    {
        tarcza_k = false;
        tarcza_a = true;
        t_p = 255;
    }
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::E ) and shotg_k == true)
    {
                bl.add(x + uv.w/2 - 6,y,-40,"P",uv_pocisk,-4);
                bl.add(x + uv.w/2 + 5,y,-40,"P",uv_pocisk,-3);
                bl.add(x + uv.w/2 - 4,y,-40,"P",uv_pocisk,-2);
                bl.add(x + uv.w/2 - 2,y,-40,"P",uv_pocisk,-1);
                bl.add(x + uv.w/2,y,-40,"P",uv_pocisk,0);
                bl.add(x + uv.w/2 + 2,y,-40,"P",uv_pocisk,1);
                bl.add(x + uv.w/2 + 4,y,-40,"P",uv_pocisk,2);
                bl.add(x + uv.w/2 + 5,y,-40,"P",uv_pocisk,3);
                bl.add(x + uv.w/2 + 6,y,-40,"P",uv_pocisk,4);
                shotg_k = false;
                //spocisk.play();
                firep = true;
    }
    if(t_p <= 4)
    {
        t_p = 4;
        tarcza_a = false;
        god_mod = false;
    }
    if(tarcza_a == true)
    {
        t_p-=2;
        god_mod = true;
    }
    ogranicznik();
    pocisktime();
   // spocisk.stop();
    firep = false;
}

void Gracz::fire(Bullet &bl)
{
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::Space ))
    {
           bl.add(x + uv.w/2,y,-40,"P",uv_pocisk,0);
          // spocisk.play();
           firep = true;
       // std::cout << "Strzal" << std::endl;
    }
    pocisktime();
}

void Gracz::load_tarcza()
{
    tarcza.load("Data/GFX/polegracz.png");
}

void Bullet::draw(sf::RenderWindow &win)
{
    if(b.size() != 0)
    {
        for(int i = 0;i < b.size();++i)
        {
            b[i].y += b[i].move;
            b[i].x += b[i].move_x;
            if(b[i].y < 0 or b[i].hp <= 0 or b[i].y > 720)
            {
                b.erase(b.begin() + i);
            }
            shape.setPosition(b[i].x,b[i].y);
            win.draw(shape);
        }
    }
}

void Bullet::add()
{
    o.x = 0;
    o.y = 0;
    o.move = 1;
    o.hp = 1;
    b.push_back(o);
}

void Bullet::add(float x,float y)
{
    o.x = x;
    o.y = y;
    o.move = 1;
    o.hp = 1;
    o.r = 3;
    b.push_back(o);
}

void Bullet::add(float x,float y,float move)
{
    o.x = x;
    o.y = y;
    o.move = move;
    o.hp = 1;
    o.r = 3;
    b.push_back(o);

}

void Bullet::add(float x,float y,float move,std::string name)
{
    o.x = x;
    o.y = y;
    o.move = move;
    o.name = name;
    o.hp = 1;
    o.r = 3;
    b.push_back(o);
}

void Bullet::add(float x,float y,float move,std::string name,UV uvz)
{
    o.x = x;
    o.y = y;
    o.move = move;
    o.name = name;
    o.uv.x = uvz.x;
    o.uv.y = uvz.y;
    o.uv.w = uvz.w;
    o.uv.h = uvz.h;
    o.hp = 1;
    o.r = 3;
    b.push_back(o);
}

void Bullet::add(float x,float y,float move,std::string name,UV uvz,float move_x)
{
    o.x = x;
    o.y = y;
    o.move = move;
    o.name = name;
    o.uv.x = uvz.x;
    o.uv.y = uvz.y;
    o.uv.w = uvz.w;
    o.uv.h = uvz.h;
    o.hp = 1;
    o.r = 3;
    o.move_x = move_x;
    b.push_back(o);
}

void Bullet::add(float x,float y,float move,std::string name,UV uvz,float move_x,int r)
{
    o.x = x;
    o.y = y;
    o.move = move;
    o.name = name;
    o.uv.x = uvz.x;
    o.uv.y = uvz.y;
    o.uv.w = uvz.w;
    o.uv.h = uvz.h;
    o.hp = 1;
    o.r = r;
    o.move_x = move_x;
    b.push_back(o);
}

void Bullet::logic()
{
    /*for(int i = 0;i < b.size();++i)
    {
        b[i].y += b[i].move;
        if(b[i].y < 0)
        {
            b.erase(b.begin() + i);
        }
        std::cout << b.size() << std::endl;
    }*/
}

void Bullet::clear()
{
    b.clear();
}

void Bullet::Init()
{
    shape.setRadius(3);
    shape.setFillColor(sf::Color(200,200,5));
}

void Bullet::setFillColor(int r,int b,int g)
{
    shape.setFillColor(sf::Color(r,b,g,255));
}

void Bullet::setRadious(float r)
{
    shape.setRadius(r);
}
