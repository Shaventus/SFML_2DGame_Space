// Copyright (C) 2015, Maciej "Shaventus" Ciosk

#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand( time( NULL ) );
    Game game;
    game.runGame();
    return 0;
}
