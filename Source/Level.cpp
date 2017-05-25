#include "Level.h"

Level::Level()
{

}

Level::~Level()
{

}

void Level::Load()
{
    sp.load("Data/GFX/tlo.png");
}

void Level::start(int levels,Enemy_menager &enm)
{
    if(levels == 0)
    {
        level0(enm);
    }
    else if(levels == 1)
    {
        level1(enm);
    }
    else if(levels == 2)
    {
        level2(enm);
    }
}

void Level::Draw(sf::RenderWindow &win)
{
    for(int i = 0;i < to.size();++i)
    {
        to[i].x += to[i].movex;
        to[i].y += to[i].movey;
        if(to[i].y + to[i].h * to[i].scale> 0 and to[i].y - to[i].h * to[i].scale <720 and to[i].x + to[i].w* to[i].scale > 0 and to[i].x < 1280)
        {
            if(to[i].name == "asteroida")
            {
                sp.sprite.setTextureRect(sf::IntRect(0,0,64,64));
            }
            else if(to[i].name == "stacja1")
            {
                sp.sprite.setTextureRect(sf::IntRect(64,0,64,64));
            }
            else if(to[i].name == "stacja2")
            {
                sp.sprite.setTextureRect(sf::IntRect(128,0,64,64));
            }
            else if(to[i].name == "Ars2")
            {
                sp.sprite.setTextureRect(sf::IntRect(192,0,64,64));
            }
            else if(to[i].name == "Ars1")
            {
                sp.sprite.setTextureRect(sf::IntRect(256,0,64,64));
            }
            else if(to[i].name == "satelita")
            {
                sp.sprite.setTextureRect(sf::IntRect(320,0,64,64));
            }
            else if(to[i].name == "watroba")
            {
                sp.sprite.setTextureRect(sf::IntRect(0,64,64,64));
            }
            else if(to[i].name == "maskaa")
            {
                sp.sprite.setTextureRect(sf::IntRect(64,64,64,64));
            }
            else if(to[i].name == "maskab")
            {
                sp.sprite.setTextureRect(sf::IntRect(128,64,64,64));
            }
            else if(to[i].name == "kloceka")
            {
                sp.sprite.setTextureRect(sf::IntRect(0,128,64,64));
            }
            else if(to[i].name == "klocekb")
            {
                sp.sprite.setTextureRect(sf::IntRect(64,128,64,64));
            }
            else if(to[i].name == "klocekc")
            {
                sp.sprite.setTextureRect(sf::IntRect(128,128,64,64));
            }
        sp.sprite.setScale(to[i].scale,to[i].scale);
        sp.sprite.setRotation(to[i].rot);
        sp.sprite.setPosition(to[i].x,to[i].y);
        win.draw(sp.sprite);
        }
    }
}

void Level::add(float x,float y,float movex,float movey,int rot,std::string name,float scale)
{
    o.x = x;
    o.y = y;
    o.movex = movex;
    o.movey = movey;
    o.rot = rot;
    o.name = name;
    o.scale = scale;
    o.h = 64;
    o.w = 64;
    to.push_back(o);
}

void Level::level0(Enemy_menager &enm)
{
    to.clear();
    enm.en.clear();
    //Tlo
    add(1000,-600,0,1,0,"Ars2",4);
    add(800,-300,0,0.25,0,"Ars1",0.2);

    add(300,-400,0,1,40,"stacja1",0.5);
    add(700,-1200,0,1.5,10,"stacja2",1);
    add(823,-1120,0,1,120,"stacja2",0.7);


    add(400,-470,0,1,20,"asteroida",0.5);
    add(200,-450,0,1,90,"asteroida",0.5);
    add(450,-400,0,1,180,"asteroida",0.5);
    add(800,-700,0,3,60,"asteroida",1.0);
    add(100,-1400,0,6,260,"asteroida",1.5);
    add(900,-700,0,2,120,"asteroida",0.8);
    add(100,-900,0,2,80,"asteroida",0.9);
    add(1000,-820,0,2,10,"asteroida",0.7);
    add(400,-1600,0,2,57,"asteroida",0.8);
    add(200,-1200,0,2,230,"asteroida",0.9);
    add(500,-1400,0,2,300,"asteroida",0.7);
    add(486,-2500,0,6,160,"asteroida",1.5);
    add(1140,-1900,0,1.8,50,"asteroida",0.8);

    add(1100,-1870,0,1.7,250,"asteroida",0.7);
    add(1200,-1890,0,1.9,150,"asteroida",0.9);
    add(230,-2900,0,2,80,"asteroida",0.9);
    add(550,-3120,0,2,10,"asteroida",0.7);

    add(800,-3520,0,2,80,"satelita",1);

    add(800,-4700,0,3,60,"asteroida",1.0);
    add(100,-4400,0,6,260,"asteroida",1.5);
    add(900,-4200,0,2,20,"asteroida",0.8);
    add(100,-4900,0,2,180,"asteroida",0.9);
    add(1000,-4820,0,2,310,"asteroida",0.7);

    add(400,-5470,0,1,20,"asteroida",0.5);
    add(200,-5450,0,1,90,"asteroida",0.5);
    add(450,-5400,0,1,180,"asteroida",0.5);
    add(800,-5700,0,3,60,"asteroida",1.0);
    add(100,-51400,0,6,260,"asteroida",1.5);
    add(770,-6470,0,1,20,"asteroida",0.5);
    add(450,-6250,0,1,90,"asteroida",0.5);

    // Jednostki

    enm.add("as",400,-320);
    enm.add("as",500,-320);
    enm.add("as",600,-320);
    enm.add("as",700,-320);

    enm.add("as",400,-970);
    enm.add("as",500,-950);
    enm.add("as",600,-920);
    enm.add("as",700,-950);
    enm.add("as",800,-970);

    enm.add("kr",0,-1900,6);
    enm.add("kr",0,-1970,6);
    enm.add("kr",0,-2040,6);
    enm.add("kr",0,-2110,6);
    enm.add("kr",0,-2180,6);
    enm.add("kr",0,-2250,6);
    enm.add("kr",0,-2320,6);
    enm.add("kr",0,-2390,6);

    enm.add("kr",1216,-1900,-6);
    enm.add("kr",1216,-1970,-6);
    enm.add("kr",1216,-2040,-6);
    enm.add("kr",1216,-2110,-6);
    enm.add("kr",1216,-2180,-6);
    enm.add("kr",1216,-2250,-6);
    enm.add("kr",1216,-2320,-6);
    enm.add("kr",1216,-2390,-6);

    enm.add("sr",200,-5180);
    enm.add("sr",400,-5180);
    enm.add("sr",600,-5180);
    enm.add("sr",800,-5180);
    enm.add("sr",1000,-5180);

    enm.add("sr",300,-5480);
    enm.add("sr",500,-5480);
    enm.add("sr",700,-5480);
    enm.add("sr",900,-5480);
    enm.add("sr",1100,-5480);

    enm.add("sr",200,-5780);
    enm.add("sr",400,-5780);
    enm.add("sr",600,-5780);
    enm.add("sr",800,-5780);
    enm.add("sr",1000,-5780);

    enm.add("kr",832,-4400,-6);
    enm.add("kr",832,-4470,-6);
    enm.add("kr",832,-4540,-6);
    enm.add("kr",832,-4610,-6);
    enm.add("kr",832,-4680,-6);
    enm.add("kr",832,-4750,-6);
    enm.add("kr",832,-4820,-6);
    enm.add("kr",832,-4890,-6);

    enm.add("kr",448,-4400,6);
    enm.add("kr",448,-4470,6);
    enm.add("kr",448,-4540,6);
    enm.add("kr",448,-4610,6);
    enm.add("kr",448,-4680,6);
    enm.add("kr",448,-4750,6);
    enm.add("kr",448,-4820,6);
    enm.add("kr",448,-4890,6);

    enm.add("as",400,-5100);
    enm.add("as",500,-5050);
    enm.add("as",600,-5000);
    enm.add("as",700,-5050);
    enm.add("as",800,-5100);

    enm.add("sr",200,-8908);
    enm.add("sr",300,-8876);
    enm.add("sr",400,-8844);
    enm.add("sr",500,-8812);
    enm.add("sr",600,-8780);
    enm.add("sr",700,-8780);
    enm.add("sr",800,-8812);
    enm.add("sr",900,-8844);
    enm.add("sr",1000,-8876);
    enm.add("sr",1100,-8908);https://www.youtube.com/watch?v=npqpSF416-Q

    enm.add("as",100,-6980);
    enm.add("as",200,-6880);
    enm.add("as",400,-6780);
    enm.add("as",800,-6780);
    enm.add("as",1000,-6880);
    enm.add("as",1100,-6980);

    enm.add("as",100,-7480);
    enm.add("as",200,-7380);
    enm.add("as",400,-7280);
    enm.add("as",900,-7280);
    enm.add("as",1100,-7380);
    enm.add("as",1200,-7480);

    enm.add("as",100,-8980);
    enm.add("as",200,-8880);
    enm.add("as",400,-8780);
    enm.add("as",800,-8780);
    enm.add("as",1000,-8880);
    enm.add("as",1100,-8980);

}

void Level::level1(Enemy_menager &enm)
{
    to.clear();
    enm.en.clear();
    // TŁO
    add(800,-700,0,1,0,"kloceka",2);
    add(200,-2000,0,0.5,120,"klocekb",3);

    add(100,-600,0,1,40,"klocekc",1);
    add(300,-1100,0,1.5,10,"kloceka",1);
    add(223,-1420,0,1,120,"kloceka",2);

    add(960,-1800,0,1,20,"klocekc",2);
    add(1230,-800,0,1.5,10,"klocekb",1.5);
    add(1200,-1620,0,1,120,"kloceka",1);

    // ENEMY
    enm.add("kr_p",400,-320);
    enm.add("kr_p",500,-320);
    enm.add("kr_p",600,-320);
    enm.add("kr_p",700,-320);

    enm.add("kr_p",400,-970);
    enm.add("kr_p",500,-950);
    enm.add("kr_p",600,-920);
    enm.add("kr_p",700,-950);
    enm.add("kr_p",800,-970);

    enm.add("sr_p",1200,-2400,-8);
    enm.add("sr_p",1200,-2470,-8);
    enm.add("sr_p",1200,-2540,-8);
    enm.add("sr_p",1200,-2610,-8);
    enm.add("sr_p",1200,-2680,-8);
    enm.add("sr_p",1200,-2750,-8);
    enm.add("sr_p",1200,-2820,-8);
    enm.add("sr_p",1200,-2890,-8);

    enm.add("sr_p",60,-3400,8);
    enm.add("sr_p",60,-3470,8);
    enm.add("sr_p",60,-3540,8);
    enm.add("sr_p",60,-3610,8);
    enm.add("sr_p",60,-3680,8);
    enm.add("sr_p",60,-3750,8);
    enm.add("sr_p",60,-3820,8);
    enm.add("sr_p",60,-3890,8);

    enm.add("kr_p",200,-3970,6);
    enm.add("kr_p",300,-3950,6);
    enm.add("kr_p",400,-3920,6);
    enm.add("kr_p",500,-3950,6);
    enm.add("kr_p",600,-3970,6);

    enm.add("kr_p",1200,-4970,-6);
    enm.add("kr_p",1100,-4950,-6);
    enm.add("kr_p",1000,-4920,-6);
    enm.add("kr_p",900,-4950,-6);
    enm.add("kr_p",800,-4970,-6);

    enm.add("sr_p",100,-5400,0);
    enm.add("sr_p",200,-5400,0);
    enm.add("sr_p",300,-5400,0);
    enm.add("sr_p",400,-5400,0);
    enm.add("sr_p",500,-5400,0);
    enm.add("sr_p",600,-5400,0);
    enm.add("sr_p",700,-5400,0);
    enm.add("sr_p",800,-5400,0);
    enm.add("sr_p",900,-5400,0);
    enm.add("sr_p",1000,-5400,0);
    enm.add("sr_p",1100,-5400,0);
    enm.add("sr_p",1200,-5400,0);

    enm.add("kr_p",400,-5970);
    enm.add("kr_p",500,-5950);
    enm.add("kr_p",600,-5920);
    enm.add("kr_p",700,-5950);
    enm.add("kr_p",800,-5970);

    enm.add("kr_p",200,-6970,6);
    enm.add("kr_p",300,-6950,6);
    enm.add("kr_p",400,-6920,6);
    enm.add("kr_p",500,-6950,6);
    enm.add("kr_p",600,-6970,6);

    enm.add("kr_p",1200,-7970,-6);
    enm.add("kr_p",1100,-7950,-6);
    enm.add("kr_p",1000,-7920,-6);
    enm.add("kr_p",900,-7950,-6);
    enm.add("kr_p",800,-7970,-6);

    enm.add("sr_p",100,-9400,0);
    enm.add("sr_p",200,-9400,0);
    enm.add("sr_p",300,-9400,0);
    enm.add("sr_p",400,-9400,0);
    enm.add("sr_p",500,-9400,0);
    enm.add("sr_p",600,-9400,0);
    enm.add("sr_p",700,-9400,0);
    enm.add("sr_p",800,-9400,0);
    enm.add("sr_p",900,-9400,0);
    enm.add("sr_p",1000,-9400,0);
    enm.add("sr_p",1100,-9400,0);
    enm.add("sr_p",1200,-9400,0);
}

void Level::level2(Enemy_menager &enm)
{
    to.clear();
    enm.en.clear();
    //// TLO
    add(600,-600,0,1,90,"maskaa",1);
    add(300,-1800,0,1.5,20,"maskaa",1);
    add(1000,-700,0,1,180,"maskaa",1);
    add(123,-400,0,1,240,"maskab",1);
    add(700,-1600,0,1,10,"maskab",2);

    add(500,-980,0,1,10,"maskaa",0.5);
    add(900,-1700,0,1,240,"maskab",1);
    add(436,-2000,0,1,110,"maskab",2);

    add(223,-3420,0,1,260,"maskab",1.5);
    add(1000,-3400,0,1,310,"watroba",2);

    add(823,-4400,0,1,240,"maskab",1);
    add(400,-4600,0,1,10,"maskab",2);


    add(400,-5470,0,1,20,"maskab",0.5);
    add(200,-5450,0,1,90,"maskab",0.5);
    add(450,-5400,0,1,180,"maskaa",0.5);
    add(800,-5700,0,3,60,"maskab",1.0);
}
