#include "Game.h"

sf::RenderWindow window(sf::VideoMode(1280,720),"Space",sf::Style::Close);

Game::Game(void)
{
    state = END;
    full = false;
    w = 1280,h = 720;
    loadcfg();

    if(!muzyka.openFromFile("Data/SFX/Under_song.wav"))
    {
        MessageBox(NULL,"Music not found","ERROR!",NULL);
        return;
    }
    muzyka.setVolume(poziommuzyki);
    muzyka.setLoop(true);
    muzyka.play();

    if(!font.loadFromFile("Data/Fonts/comicbd.ttf"))
    {
        MessageBox(NULL,"Fonts not found","ERROR!",NULL);
        return;
    }

    if(!icons.loadFromFile("Data/GFX/icon.png"))
    {
        MessageBox(NULL,"Sprite not found","ERROR!",NULL);
        return;
    }
    window.setIcon(32,32,icons.getPixelsPtr());

    if(!texture.loadFromFile("Data/GUI/Menu.png"))
    {
        MessageBox(NULL,"Title sprite not found","ERROR!",NULL);
        return;
    }
    else
    {
        sprite.setTexture(texture);
    }
    if(!option_t.loadFromFile("Data/GUI/Option.png"))
    {
        MessageBox(NULL,"Title sprite not found","ERROR!",NULL);
        return;
    }
    else
    {
        option_s.setTexture(option_t);
    }
    if(!typ_t.loadFromFile("Data/GUI/Typ.png"))
    {
        MessageBox(NULL,"Title sprite not found","ERROR!",NULL);
        return;
    }
    else
    {
        typ_s.setTexture(typ_t);
    }
    if(!inst_t.loadFromFile("Data/GUI/Control.png"))
    {
        MessageBox(NULL,"Title sprite not found","ERROR!",NULL);
        return;
    }
    else
    {
        inst_s.setTexture(inst_t);
    }
    if(!level_t.loadFromFile("Data/GUI/menu_level.png"))
    {
        MessageBox(NULL,"Title sprite not found","ERROR!",NULL);
        return;
    }
    else
    {
        level_s.setTexture(level_t);
    }
    engine.Load();
    window.setFramerateLimit(60);
    view = window.getDefaultView();
    window.setView(view);

    state = MENU;
}

Game::~Game(void)
{

}

void Game::runGame()
{
    engine.sound.stop();
    engine.swybuch.stop();
    while(state != END)
    {
        engine.soundpoziom = soundpoziom;
        switch(state)
        {
            case MENU:
                menu();
                break;
            case OPTION:
                option();
                break;
            case GAME:
                single();
                break;
            case TYP:
                typ();
                break;
            case SURVIVAL:
                survival();
                break;
            case INST:
                inst();
                break;
            case LEVEL:
                level();
                break;
        }
    }
}

void Game::menu()
{
    engine.sound.stop();
    engine.swybuch.stop();
    sf::Text title("Space",font,80);
    title.setStyle(sf::Text::Bold);
    title.setPosition(1280/2-title.getGlobalBounds().width/2,20);
    sprite.setPosition(0,0);
    const int ile = 3;

    sf::Text tekst[ile];
    std::string str[] = {"Start","Options","Exit"};

    for(int i = 0;i < ile;i++)
    {
        tekst[i].setFont(font);
        tekst[i].setCharacterSize(64);
        tekst[i].setString(str[i]);
        tekst[i].setPosition(20,250+i*120);
    }

while(state == MENU)
	{
		sf::Vector2i pixel(sf::Mouse::getPosition(window));
		sf::Vector2f mouse = window.mapPixelToCoords(pixel);
		sf::Event event;

		while(window.pollEvent(event))
		{
		if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Escape)
			state = END;

		else if(tekst[2].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			state = END;
			}
        else if(tekst[1].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			state = OPTION;
			}
        else if(tekst[0].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left
		|| event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
			state = TYP;
			}
		}
		for(int i=0;i<ile;i++)
			if(tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setColor(sf::Color::Red);
			else tekst[i].setColor(sf::Color::White);

		window.clear();
		window.draw(sprite);
		window.draw(title);
		for(int i=0;i<ile;i++)
		window.draw(tekst[i]);

		window.display();
	}
}

void Game::single()
{;
    engine.soundpoziom = soundpoziom;
    engine.sound.stop();
    engine.swybuch.stop();
    engine.levels = poziom;
    engine.run(window);
    if(engine.exit == true)
    {
        state = END;
    }
    else
    {
        state = MENU;
    }
}

void Game::survival()
{
    engine.soundpoziom = soundpoziom;
    engine.sound.stop();
    engine.swybuch.stop();
    engine.run_survival(window);
    if(engine.exit == true)
    {
        state = END;
    }
    else
    {
        state = MENU;
    }
}

void Game::loadcfg()
{
    std::fstream plik;
    plik.open("Data/Stat/config.cfg");
    if(plik.good() == true)
    {
        plik >> ws;
        plik >> hs;
        plik >> f;
        plik >> soundpoziom;
        plik >> poziommuzyki;
        if(ws != 0 and hs != 0)
        {
       // std::cout << ws << std::endl;
       // std::cout << hs << std::endl;
       // std::cout << f << std::endl;
        if(f == 0)
            {
                window.create(sf::VideoMode(1280,720),"Space",sf::Style::Close);
                window.setSize(sf::Vector2u(ws,hs));
            }
            else
            {
                window.create(sf::VideoMode(1280,720),"Space",sf::Style::Fullscreen);
                full = true;
            }
        }

    }
    else
    {
        //std::cout << "Nie udalo sie otworzyc pliku config.cfg" << std::endl;
    }
    plik.close();
}

void Game::savecfg()
{
    std::fstream plik;
    plik.open("Data/Stat/config.cfg");
    if(plik.good() == true)
    {
        plik.clear();
        plik << ws;
        plik << " ";
        plik << hs;
        plik << " ";
        plik << f;
        plik << " ";
        plik << soundpoziom;
        plik << " ";
        plik << poziommuzyki;
    }
    else
    {
        //std::cout << "Nie udalo sie otworzyc pliku heightscore" << std::endl;
    }
    plik.close();
}

void Game::option()
{
    engine.sound.stop();
    engine.swybuch.stop();
    sf::Text title("OPTION",font,80);
    title.setStyle(sf::Text::Bold);
    title.setPosition(1280/2-title.getGlobalBounds().width/2,20);
    option_s.setPosition(0,0);
    const int ile = 6;

    sf::Text tekst[ile];
    sf::Text save,plu,minu,pozioms,sounds;
    sf::Text plum,minum,poziomm,music;
    std::string str[] = {"FullScreen","800x600","1024x768","1280x720","1280x1024","BACK"};

    for(int i = 0;i < ile;i++)
    {
        tekst[i].setFont(font);
        tekst[i].setCharacterSize(64);
        tekst[i].setString(str[i]);
        tekst[i].setPosition(20,100+i*100);
    }
        sf::Text on_off("OFF",font,80);

        if(full == false)
        {
            on_off.setString("OFF");
        }
        else
        {
            on_off.setString("ON");
        }
        on_off.setStyle(sf::Text::Bold);
        on_off.setCharacterSize(64);
        on_off.setPosition(400,100);

        save.setFont(font);
        save.setCharacterSize(64);
        save.setString("Save");
        save.setPosition(1000,600);

        plu.setFont(font);
        plu.setCharacterSize(64);
        plu.setString("+");
        plu.setPosition(1100,200);

        minu.setFont(font);
        minu.setCharacterSize(64);
        minu.setString("-");
        minu.setPosition(1200,200);

        pozioms.setFont(font);
        pozioms.setCharacterSize(64);
        pozioms.setString("0");
        pozioms.setPosition(1000,200);

        sounds.setFont(font);
        sounds.setCharacterSize(64);
        sounds.setString("Sound: ");
        sounds.setPosition(800,200);

        plum.setFont(font);
        plum.setCharacterSize(64);
        plum.setString("+");
        plum.setPosition(1100,400);

        minum.setFont(font);
        minum.setCharacterSize(64);
        minum.setString("-");
        minum.setPosition(1200,400);

        poziomm.setFont(font);
        poziomm.setCharacterSize(64);
        poziomm.setString("0");
        poziomm.setPosition(1000,400);

        music.setFont(font);
        music.setCharacterSize(64);
        music.setString("Music: ");
        music.setPosition(800,400);

    while(state == OPTION)
	{
		sf::Vector2i pixel(sf::Mouse::getPosition(window));
		sf::Vector2f mouse = window.mapPixelToCoords(pixel);
		sf::Event event;

		while(window.pollEvent(event))
		{
		if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Escape)
			state = END;

		else if(tekst[5].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			state = MENU;
			}
        else if(save.getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			savecfg();
		//	std::cout << "Zapisano" << std::endl;
			}
        else if(plu.getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			soundpoziom += 5;
		//	std::cout << "Zapisano" << std::endl;
			}
        else if(minu.getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			soundpoziom -= 5;
		//	std::cout << "Zapisano" << std::endl;
			}
        else if(plum.getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			poziommuzyki += 5;
		//	std::cout << "Zapisano" << std::endl;
			}
        else if(minum.getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			poziommuzyki -= 5;
		//	std::cout << "Zapisano" << std::endl;
			}
        else if(tekst[1].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
            window.create(sf::VideoMode(1280,720),"Space",sf::Style::Close);
            window.setSize(sf::Vector2u(800,600));
            ws = 800;
            hs = 600;
            f = 0;
			}
        else if(tekst[2].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
            window.create(sf::VideoMode(1280,720),"Space",sf::Style::Close);
            window.setSize(sf::Vector2u(1024,768));
            ws = 1024;
            hs = 768;
            f = 0;
			}
        else if(tekst[3].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
            window.create(sf::VideoMode(1280,720),"Space",sf::Style::Close);
            window.setSize(sf::Vector2u(1280,720));
            ws = 1280;
            hs = 720;
            f = 0;
			}
        else if(tekst[4].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
            window.create(sf::VideoMode(1280,720),"Space",sf::Style::Close);
            window.setSize(sf::Vector2u(1280,1024));
            ws = 1280;
            hs = 1024;
            f = 0;
			}
        else if(tekst[0].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			    if(full == false)
                {
                window.create(sf::VideoMode(1280,720),"Space",sf::Style::Fullscreen);
                full = true;
                ws = 1280;
                hs = 720;
                f = 1;
                }
                else
                {
                window.create(sf::VideoMode(1280,720),"Space",sf::Style::Close);
                full = false;
                ws = 1280;
                hs = 720;
                f = 0;
                }
			}
		}

        ss.str(std::string());
        ss.clear();
        ss << soundpoziom;
        pozioms.setString(ss.str());
        ss.str(std::string());
        ss.clear();
        ss << poziommuzyki;
        poziomm.setString(ss.str());

		for(int i=0;i<ile;i++)
			if(tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setColor(sf::Color::Red);
			else tekst[i].setColor(sf::Color::White);

        if(save.getGlobalBounds().contains(mouse))
        {
            save.setColor(sf::Color::Red);
        }
        else save.setColor(sf::Color::White);

        if(plu.getGlobalBounds().contains(mouse))
        {
            plu.setColor(sf::Color::Red);
        }
        else plu.setColor(sf::Color::White);

        if(minu.getGlobalBounds().contains(mouse))
        {
            minu.setColor(sf::Color::Red);
        }
        else minu.setColor(sf::Color::White);

        if(plum.getGlobalBounds().contains(mouse))
        {
            plum.setColor(sf::Color::Red);
        }
        else plum.setColor(sf::Color::White);

        if(minum.getGlobalBounds().contains(mouse))
        {
            minum.setColor(sf::Color::Red);
        }
        else minum.setColor(sf::Color::White);

        muzyka.setVolume(poziommuzyki);

		window.clear();
		window.draw(option_s);
		window.draw(title);
		window.draw(on_off);
		window.draw(save);

		window.draw(plu);
		window.draw(minu);
		window.draw(pozioms);
		window.draw(sounds);

        window.draw(plum);
		window.draw(minum);
		window.draw(poziomm);
		window.draw(music);

		for(int i=0;i<ile;i++)
		window.draw(tekst[i]);

		window.display();
	}
}

void Game::typ()
{
    engine.sound.stop();
    engine.swybuch.stop();
    typ_s.setPosition(0,0);
    const int ile = 4;

    sf::Text tekst[ile];
    std::string str[] = {"Survival","Instruction","Campaign","Back"};

    for(int i = 0;i < ile;i++)
    {
        tekst[i].setFont(font);
        tekst[i].setCharacterSize(64);
        tekst[i].setString(str[i]);
        tekst[i].setPosition(20,250+i*120);
    }

while(state == TYP)
	{
		sf::Vector2i pixel(sf::Mouse::getPosition(window));
		sf::Vector2f mouse = window.mapPixelToCoords(pixel);
		sf::Event event;

		while(window.pollEvent(event))
		{
		if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Escape)
			state = END;

		else if(tekst[2].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			state = LEVEL;
			}
        else if(tekst[1].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			state = INST;
			}
        else if(tekst[0].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left
		|| event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
			state = SURVIVAL;
			}
        else if(tekst[3].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			state = MENU;
			}
		}
		for(int i=0;i<ile;i++)
			if(tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setColor(sf::Color::Red);
			else tekst[i].setColor(sf::Color::White);

		window.clear();
		window.draw(typ_s);
		for(int i=0;i<ile;i++)
		window.draw(tekst[i]);

		window.display();
	}
}

void Game::inst()
{
    engine.sound.stop();
    engine.swybuch.stop();
    inst_s.setPosition(0,0);
    const int ile = 2;

    sf::Text tekst[ile];
    std::string str[] = {"Survival","Back"};

    for(int i = 0;i < ile;i++)
    {
        tekst[i].setFont(font);
        tekst[i].setCharacterSize(64);
        tekst[i].setString(str[i]);
        tekst[i].setPosition(20,450+i*120);
    }

while(state == INST)
	{
		sf::Vector2i pixel(sf::Mouse::getPosition(window));
		sf::Vector2f mouse = window.mapPixelToCoords(pixel);
		sf::Event event;

		while(window.pollEvent(event))
		{
		if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Escape)
			state = END;

        else if(tekst[1].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			state = TYP;
			}
        else if(tekst[0].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left
		|| event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
			state = SURVIVAL;
			}
		}
		for(int i=0;i<ile;i++)
			if(tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setColor(sf::Color::Red);
			else tekst[i].setColor(sf::Color::White);

		window.clear();
		window.draw(inst_s);
		for(int i=0;i<ile;i++)
		window.draw(tekst[i]);

		window.display();
	}


}

void Game::level()
{
    engine.sound.stop();
    engine.swybuch.stop();
    level_s.setPosition(0,0);
    const int ile = 4;

    sf::Text tekst[ile];
    std::string str[] = {"Level 0","Level 1","Level 2","Back"};

    for(int i = 0;i < ile;i++)
    {
        tekst[i].setFont(font);
        tekst[i].setCharacterSize(64);
        tekst[i].setString(str[i]);
        tekst[i].setPosition(20,250+i*120);
    }

while(state == LEVEL)
	{
		sf::Vector2i pixel(sf::Mouse::getPosition(window));
		sf::Vector2f mouse = window.mapPixelToCoords(pixel);
		sf::Event event;

		while(window.pollEvent(event))
		{
		if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Escape)
			state = END;

		else if(tekst[2].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			state = GAME;
			poziom = 2;
			}
        else if(tekst[1].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			state = GAME;
			poziom = 1;
			}
        else if(tekst[0].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left
		|| event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
			state = GAME;
			poziom = 0;
			}
        else if(tekst[3].getGlobalBounds().contains(mouse) &&
		event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
			state = TYP;
			}
		}
		for(int i=0;i<ile;i++)
			if(tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setColor(sf::Color::Red);
			else tekst[i].setColor(sf::Color::White);

		window.clear();
		window.draw(level_s);
		for(int i=0;i<ile;i++)
		window.draw(tekst[i]);

		window.display();
	}
}
