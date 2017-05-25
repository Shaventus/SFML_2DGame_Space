#include "Hud.h"

void Hud::Load()
{
    cd.load("Data/GUI/atalscd.png");
    itarczy.load("Data/GUI/tarczaikona.png");
    shotg.load("Data/GUI/shotgun.png");
    cd1.load("Data/GUI/atalscd.png");
    pasek.load("Data/GUI/pasek.png");
    pasek.sprite.setPosition(0,670);
    cdp = 17;
    cdp_shotg = 17;
    end_t = true;
    b_shotg = true;
    if(!font.loadFromFile("Data/Fonts/comicbd.ttf"))
    {
        MessageBox(NULL,"Fonts not found","ERROR!",NULL);
        return;
    }
    te_tarczy.setPosition(608,688);
    te_tarczy.setCharacterSize(16);
    te_tarczy.setFont(font);

    te_shotg.setPosition(641,688);
    te_shotg.setCharacterSize(16);
    te_shotg.setFont(font);

    hp_t.setPosition(0,688);
    hp_t.setCharacterSize(32);
    hp_t.setFont(font);
}

void Hud::Draw(sf::RenderWindow &win)
{
    win.draw(pasek.sprite);
    itarczy.sprite.setPosition(600,680);
    cd.sprite.setPosition(600,680);
    shotg.sprite.setPosition(633,680);
    cd1.sprite.setPosition(633,680);
    win.draw(itarczy.sprite);
    win.draw(shotg.sprite);
    cd.sprite.setTextureRect(sf::IntRect( 0 + 32*cdp, 0, 32,32));
    cd1.sprite.setTextureRect(sf::IntRect(0+32*cdp_shotg,0,32,32));
    win.draw(cd.sprite);
    win.draw(cd1.sprite);
    if(cdp != 17)
    {
        win.draw(te_tarczy);
    }
    if(cdp_shotg != 17)
    {
        win.draw(te_shotg);
    }
    win.draw(hp_t);
}

void Hud::Update(bool &ac)
{
    if(ac == false)
    {
        t_cd = tarcz.getElapsedTime();
        t = t_cd.asSeconds();
       // std::cout << t << std::endl;
    }
    else
    {
        tarcz.restart();
    }
    if(t < 34)
    {
        cdp = t/2;
        ss.str(std::string());
        ss.clear();
        ss << 34-t;
        te_tarczy.setString(ss.str());
    }
    else
    {
        cdp = 17;
        ac = true;
    }

}

void Hud::Update_shotgun(bool &ac)
{
    if(ac == false)
    {
        ac = false;
        t_shotg = c_shotg.getElapsedTime();
        t_s = t_shotg.asSeconds();
       // std::cout << t << std::endl;
    }
    else
    {
        c_shotg.restart();
    }
    if(t_s < 5)
    {
        cdp_shotg = t_s*3;
        ss.str(std::string());
        ss.clear();
        ss << 5-t_s;
        te_shotg.setString(ss.str());
    }
    else
    {
        cdp_shotg = 17;
        ac = true;
    }

}

void Hud::start()
{
    t_s = 6;
    t = 34;
}

void Hud::hp(int hp)
{
        ss.str(std::string());
        ss.clear();
        if(hp >= 0)
        {
            ss << "HP: " <<hp;
        }
        else
        {
            ss << "HP: " <<0;
        }
        hp_t.setString(ss.str());
}
