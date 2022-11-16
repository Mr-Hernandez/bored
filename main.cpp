#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main()
{
    Game game;

    while(game.getWindow()->isOpen()){
        game.Update();
        game.Render();
    }
}
