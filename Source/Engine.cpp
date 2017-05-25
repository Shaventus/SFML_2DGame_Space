#include "Engine.h"
Engine::Engine(void)
{

}

Engine::~Engine(void)
{

}

void Engine::run(sf::RenderWindow &win)
{
    end = false;
    bool menu = false;
    exit = false;
    bool start = true;
    mkrew = 0;
    mk = 0;

    t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,720/2-t_death.getGlobalBounds().height/2);
    t_death.setCharacterSize(64);
    t_death.setFont(font);
    t_death1.setPosition(1280/2-t_death.getGlobalBounds().width/2,720/2-t_death.getGlobalBounds().height/2 + 64);
    t_death1.setCharacterSize(64);
    t_death1.setFont(font);

	sf::Clock zegar;
	em.start();
	cmap.start();
    player.soundpoziom = soundpoziom;
    sound.setVolume(soundpoziom);
    swybuch.setVolume(soundpoziom);
	player.start();
	level.start(levels,em);
    player.hp = 20;
	hu.start();
    se.start();
    en_b.b.clear();
    bullet.b.clear();
    swybuch.stop();
    sound.stop();

	while(!menu)
	{
		sf::Event event;
		sf::Vector2i pixel(sf::Mouse::getPosition(win));
		sf::Vector2f mouse = win.mapPixelToCoords(pixel);

		while(win.pollEvent(event))
		{
			if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
            {
                menu = true;
            }
            if((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::R and player.hp <= 0)
               or (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::R and end == true))
            {
                em.start();
                cmap.start();
                player.start();
                level.start(levels,em);
                player.hp = 20;
                hu.start();
                se.start();
                en_b.b.clear();
                bullet.b.clear();
                mkrew = 0;
                mk = 0;
                start = true;
                end = false;
                sound.stop();
            }
            if(event.type == sf::Event::Closed)
            {
                exit = true;
                menu = true;
            }
          }
		Logic();
		hu.hp(player.hp);
		colision();
		win.clear();
		cmap.draw(win);
		level.Draw(win);
		bullet.draw(win);
		em.draw(win);
		se.Draw(win);
        en_b.draw(win);


        if(player.hp > 0)
        {
		player.draw(win);
        }
        else
        {
            end = false;
            ss.str(std::string());
            ss.clear();
            ss << "DEFEAT!";
            t_death.setString(ss.str());
            t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,720/2-t_death.getGlobalBounds().height/2);
            ss.str(std::string());
            ss.clear();
            ss << "Press R to Restart or";
            t_death1.setString(ss.str());
            t_death1.setPosition(1280/2-t_death.getGlobalBounds().width,720/2-t_death.getGlobalBounds().height/2 + 64);
            win.draw(t_death);
            win.draw(t_death1);
            ss.str(std::string());
            ss.clear();
            ss << "Esc to return to menu";
            t_death1.setString(ss.str());
            t_death1.setPosition(1280/2-t_death.getGlobalBounds().width,720/2-t_death.getGlobalBounds().height/2 + 128);
            win.draw(t_death1);
        }
        if(end == true)
        {
            if(levels == 0)
            {
                ss.str(std::string());
                ss.clear();
                ss << "Way hay, and up she rises";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,50);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "Way hay, and up she rises";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,100);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "Early in the morning!";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,150);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "VICTORY!";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,250);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "Press R to Restart or";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,300);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "Esc to return to menu";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,350);
                win.draw(t_death);
            }
            else if(levels == 1)
            {
                ss.str(std::string());
                ss.clear();
                ss << "Pixor will be pleased";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,50);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "And my pocket";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,100);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "PIXEL VICTORY!";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,250);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "Press R to Restart or";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,300);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "Esc to return to menu";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,350);
                win.draw(t_death);
            }
            else if(levels == 2)
            {
                ss.str(std::string());
                ss.clear();
                ss << "EPIC VICTORY!";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,250);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "It was a nightmare or reality";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,50);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "I do not know but I killed it";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,100);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "Press R to Restart or";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,300);
                win.draw(t_death);
                ss.str(std::string());
                ss.clear();
                ss << "Esc to return to menu";
                t_death.setString(ss.str());
                t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,350);
                win.draw(t_death);
            }
        }
        if(levels == 2 and em.maska == false)
        {
            if(mkrew <= 80)
            {
                mk += 0.5;
                mkrew = mk;
            }
            mt.sprite.setPosition(0,0);
            mt.sprite.setColor(sf::Color(255,255,255,mkrew));
            win.draw(mt.sprite);
        }
        if(em.maska == true)
        {
            sound.play();
        }
        hu.Draw(win);


		win.display();

		if(start == true)
        {
            se.start();
            player.start();
            if(levels == 0)
            {
                em.add("Boss",1280/2 - 128,-9880);
            }
            else if(levels == 1)
            {
                em.add("Pixil",1280/2 - (640/2),-7400);
            }
            else if(levels == 2)
            {
                em.add("Maskaboss",1280/2-108,-200);
            }
            start = false;
        }
	}
}

void Engine::run_survival(sf::RenderWindow &win)
{
    swybuch.stop();
    sound.stop();
    end = false;
    bool menu = false;
    exit = false;
    bool start = true;

	sf::Clock zegar;
    em.start_survival();
    cmap.start();

    loadHS();

    score = 0;

    t_score.setPosition(0,0);
    t_score.setCharacterSize(32);
    t_score.setFont(font);

    hgs.setCharacterSize(32);
    hgs.setFont(font);

    ss.str(std::string());
    ss.clear();
    ss << "High score: " << highscore;

    hgs.setString(ss.str());
    hgs.setPosition(900,0);

    t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,720/2-t_death.getGlobalBounds().height/2);
    t_death.setCharacterSize(64);
    t_death.setFont(font);
    t_death1.setPosition(1280/2-t_death.getGlobalBounds().width/2,720/2-t_death.getGlobalBounds().height/2 + 64);
    t_death1.setCharacterSize(64);
    t_death1.setFont(font);

    player.soundpoziom = soundpoziom;
    sound.setVolume(soundpoziom);
    swybuch.setVolume(soundpoziom);
    player.start();
    hu.start();
    se.start();
    en_b.b.clear();
    bullet.b.clear();
    hu.start();
    player.hp = 20;


	while(!menu)
	{
		sf::Event event;
		sf::Vector2i pixel(sf::Mouse::getPosition(win));
		sf::Vector2f mouse = win.mapPixelToCoords(pixel);

		while(win.pollEvent(event))
		{
			if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
            {
                menu = true;
            }
            else if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return and player.hp < 0)
            {
                menu = true;
            }
            if(event.type == sf::Event::Closed)
            {
                exit = true;
                menu = true;
            }
          }

        ss.str(std::string());
		ss.clear();
		Logic_survival();
		colision_survival();
		ss << "SCORE: " << score;
        t_score.setString(ss.str());
		win.clear();
		cmap.draw(win);
		bullet.draw(win);
		em.draw_survival(win);
		se.Draw(win);
		if(player.hp < 0)
        {

        if(score > highscore)
        {
            rewriteHS();
        }

		ss.str(std::string());
		ss.clear();
		ss << "DEFEAT! YOUR SCORE IS : " << score;
		t_death.setString(ss.str());
        t_death.setPosition(1280/2-t_death.getGlobalBounds().width/2,720/2-t_death.getGlobalBounds().height/2);
        ss.str(std::string());
		ss.clear();
		ss << "Press ENTER to END";
		t_death1.setString(ss.str());
        t_death1.setPosition(1280/2-t_death.getGlobalBounds().width/2,720/2-t_death.getGlobalBounds().height/2 + 64);
        win.draw(t_death);
		win.draw(t_death1);
        }
        else
        {
            player.draw(win);
            win.draw(t_score);
        }
        hu.Draw(win);
        win.draw(hgs);
		win.display();
        if(start == true)
        {
            se.start();
            player.start();
            start = false;
        }
	}
}

void Engine::Load()
{
    buffer1.loadFromFile("Data/SFX/maska.wav");
    sound.setBuffer(buffer1);
    sound.setVolume(soundpoziom);
    sound.setLoop(false);

    bwybuch.loadFromFile("Data/SFX/wybuch.wav");
    swybuch.setBuffer(bwybuch);
    swybuch.setVolume(soundpoziom);
    swybuch.setLoop(false);

    mt.load("Data/GFX/tlomaska.png");
    em.init();
    em.load("Data/GFX/enemy_atlas.png");
    hu.Load();
    player.load_player_stat("Data/stat/Player.txt");
    player.load_tarcza();
    player.soundpoziom = soundpoziom;
    bullet.Init();
    en_b.Init();
    en_b.setFillColor(255,10,10);
    cmap.pyl = true;
    cmap.load("Data/GFX/tlo_pyl.png");
    se.Load();
    player.start();
    cmap.start();
    bullet.clear();
    if(!font.loadFromFile("Data/Fonts/comicbd.ttf"))
    {
        MessageBox(NULL,"Fonts not found","ERROR!",NULL);
        return;
    }
    em.start();
    level.Load();
}

void Engine::Logic()
{
    cmap.logic();
    bullet.logic();
    en_b.logic();
    em.fire(en_b);
    se.Logic();
    //std::cout << en_b.b.size() << std::endl;
    if(player.hp > 0)
    {
    player.logic(bullet);
    player.fire(bullet);
        hu.Update_shotgun(player.shotg_k);
        hu.Update(player.tarcza_k);
    }
}

void Engine::Logic_survival()
{
    cmap.logic();
    bullet.logic();
    en_b.logic();
    se.Logic();
    //std::cout << en_b.b.size() << std::endl;
    if(player.hp > 0)
    {
    player.logic(bullet);
    player.fire(bullet);
        hu.Update_shotgun(player.shotg_k);
        hu.Update(player.tarcza_k);
    }
}

void Engine::load_stats(std::string filename)
{
    std::fstream plik;
    plik.open(filename.c_str());
    if(plik.is_open() == true)
    {
        std::string line;
        while(!plik.eof())
        {
            plik >> line;
            if(line == "smoke_off")
            {
                cmap.pyl = false;
            }
            if(line == "smoke_on")
            {
                cmap.pyl = true;
            }
        }
    }
    else
    {
        MessageBox(NULL,"Nie mozna zaladowac poziomu","ERROR!",NULL);
        return;
    }
}

void Engine::colision()
{
    //std::cout << bullet.b.size() << std::endl;
    for(int j = 0;j < em.en.size();++j)
    {
        for(int i = 0;i < bullet.b.size();++i)
        {

            if(AABB(em.en[j].col,bullet.b[i].x,bullet.b[i].y,6) == true) // Kolizja obiektu enemy z pociskiem
            {
                if(em.en[j].name == "Maskaboss" and em.maska == true)
                {
                    bullet.b[i].hp = 0;
                }
                else
                {
                    em.en[j].hp -= 25;
                    bullet.b[i].hp = 0;
                }
            }
        }
        if(AABB(em.en[j].col,player.col) == true)
        {
            if(player.god_mod == true)
            {
                em.en[j].hp = -4;
                swybuch.play();
            }
            else
            {
                em.en[j].hp = -25;
                player.hp = -4;
                player.col.x = 2000;
                se.addEks(player.x,player.y);
            }
        }
        if(em.en[j].hp <= 0)
        {
            if(em.en[j].name == "Boss" or em.en[j].name == "Maskaboss" or em.en[j].name == "Pixil")
            {
                se.addEks(em.en[j].x + em.en[j].col.w/2,em.en[j].y + em.en[j].col.h/2,10);
                swybuch.play();
                end = true;
            }
            else
            {
                se.addEks(em.en[j].x + em.en[j].col.w/2,em.en[j].y + em.en[j].col.h/2);
                swybuch.play();
            }
            em.en.erase(em.en.begin() + j);
            //std::cout << score << std::endl;
        }
        if(em.en[j].name == "Boss" and em.en[j].hp <= em.en[j].max_hp/2 and em.en[j].aktl == false)
        {
            em.en[j].aktl = true;
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            swybuch.play();
            swybuch.play();
            swybuch.play();
        }
        if(em.en[j].name == "Pixil" and em.en[j].hp <= em.en[j].max_hp/2 and em.en[j].aktl == false)
        {
            em.en[j].aktl = true;
            se.addEks(em.en[j].x + 34,em.en[j].y + 186,4);
            se.addEks(em.en[j].x + 127,em.en[j].y + 142,4);
            se.addEks(em.en[j].x + 371,em.en[j].y + 275,3);
            se.addEks(em.en[j].x + 395,em.en[j].y + 114,2);
            se.addEks(em.en[j].x + 265,em.en[j].y + 60,2);
            swybuch.play();
        }
        if(em.en[j].name == "Maskaa" and em.en[j].hp <= em.en[j].max_hp/2 and em.en[j].aktl == false)
        {
            em.en[j].aktl = true;
            swybuch.play();
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
        }
        if(em.en[j].name == "Maskab" and em.en[j].hp <= em.en[j].max_hp/2 and em.en[j].aktl == false)
        {
            em.en[j].aktl = true;
            swybuch.play();
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
        }
        if(em.en[j].name == "Maskaboss" and em.en[j].hp <= em.en[j].max_hp/2 and em.en[j].aktl == false)
        {
            em.en[j].aktl = true;
            swybuch.play();
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
            se.addEks(em.en[j].x + em.en[j].col.w/2 + (rand()%80 - 40),em.en[j].y + em.en[j].col.h/2 + (rand()%80 - 40));
        }
        if(em.en[j].name == "Maskaboss")
        {
            em.maska = false;
        }
        if(em.en[j].name == "Maskaa")
        {
            em.maska = true;
        }
        if(em.en[j].name == "Maskab")
        {
            em.maska = true;
        }
    }
    if(player.god_mod != true)
    {
    for(int i = 0;i < en_b.b.size();++i)
    {
        if(AABB(player.col,en_b.b[i].x,en_b.b[i].y,en_b.b[i].r*2) == true)
        {
            player.sprite.setColor(sf::Color(10,10,10,255));
            en_b.b[i].hp = 0;
            player.hp -= 2;
            if(player.hp <= 0)
            {
                se.addEks(player.x,player.y);
            }
        }
    }
    }

}

void Engine::colision_survival()
{
    //std::cout << bullet.b.size() << std::endl;
    for(int j = 0;j < em.en.size();++j)
    {
        for(int i = 0;i < bullet.b.size();++i)
        {

            if(AABB(em.en[j].col,bullet.b[i].x,bullet.b[i].y,6) == true) // Kolizja obiektu enemy z pociskiem
            {
                em.en[j].hp -= 4;
                bullet.b[i].hp = 0;
            }
        }
        if(AABB(em.en[j].col,player.col) == true)
        {
            if(player.god_mod == true)
            {
                em.en[j].hp = -4;
                swybuch.play();
            }
            else
            {
                em.en[j].hp = -4;
                player.hp = -4;
                player.col.x = 2000;
                se.addEks(player.x,player.y);
                swybuch.play();
            }
        }
        if(em.en[j].hp <= 0)
        {
            se.addEks(em.en[j].x + em.en[j].col.w/2,em.en[j].y + em.en[j].col.h/2);
            em.en.erase(em.en.begin() + j);
            swybuch.play();
            score += 5 + rand()%25;
            //std::cout << score << std::endl;
                r = rand()%3;
                if(r == 0)
                {
                    rand_e = "as";
                }
                else if(r == 1)
                {
                    rand_e = "kr";
                }
                else if(r == 2)
                {
                    rand_e = "sr";
                }
            em.add(rand_e,rand()%1200,-1* (rand()%400 + 120));
                r = rand()%3;
                if(r == 0)
                {
                    rand_e = "as";
                }
                else if(r == 1)
                {
                    rand_e = "kr";
                }
                else if(r == 2)
                {
                    rand_e = "sr";
                }
            em.add(rand_e,rand()%1200,-1* (rand()%400 + 120));
        }
    }
}

void Engine::loadHS()
{
    std::fstream plik;
    plik.open("Data/Stat/Heighscore.txt");
    if(plik.good() == true)
    {
        plik >> highscore;
        std::cout << highscore << std::endl;
    }
    else
    {
        highscore = 0;
        std::cout << "Nie udalo sie otworzyc pliku heightscore" << std::endl;
    }
    plik.close();
}

void Engine::rewriteHS()
{
    std::fstream plik;
    plik.open("Data/Stat/Heighscore.txt");
    if(plik.good() == true)
    {
        plik.clear();
        plik << score;
    }
    else
    {
        std::cout << "Nie udalo sie otworzyc pliku heightscore" << std::endl;
    }
    plik.close();
}
