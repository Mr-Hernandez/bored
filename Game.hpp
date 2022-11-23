#pragma once
#include "Enums.hpp"
#include "Timer.hpp"
#include "Window.hpp"
#include "Map.hpp"
#include "Event.hpp"
#include "Bus.hpp"
#include "Draw.hpp"
#include "TextureManager.hpp"
#include "Character.hpp"
#include "Cursor.hpp"

class Game{

public:
//    Bus m_bus;

    Game();
    ~Game();
    sf::RenderWindow* getWindow();

    void Update();
    void Render();

    void init_bus();



//    Bus m_bus;


private:
    unsigned int m_winH;
    unsigned int m_winW;

    Window m_mainWindow;
    Timer m_renderTimer;
    Map m_map;
    Event m_event;
    Bus m_bus;
    State state;
    Draw m_draw;
    TextureManager m_texMan;
    Character m_character;
    Cursor m_cursor;

};
