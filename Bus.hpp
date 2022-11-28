#ifndef BUS_H
#define BUS_H

#include "SFML/Graphics.hpp"
#include "Enums.hpp"
#include "Timer.hpp"
#include "Map.hpp"
#include "TextureManager.hpp"
#include "Character.hpp"
#include "Cursor.hpp"
#include "Pathfinder.hpp"


struct Bus{
    State* s_state = nullptr;
    sf::RenderWindow* s_mainWindow = nullptr;
    Timer* s_timer = nullptr;
    Map* s_map = nullptr;
    TextureManager* s_texMan = nullptr;
    Character* s_character = nullptr;
    Cursor* s_cursor = nullptr;
    Pathfinder* s_pathFinder = nullptr;

};

#endif // BUS_H


