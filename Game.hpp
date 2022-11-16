#pragma once
#include "Enums.hpp"
#include "Timer.hpp"
#include "Window.hpp"
#include "Map.hpp"
#include "Event.hpp"
#include "Bus.hpp"
#include "Draw.hpp"
#include "TextureManager.hpp"

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
    Window m_mainWindow;
    Timer m_renderTimer;
    Map m_map;
    Event m_event;
    Bus m_bus;
    State state;
    Draw m_draw;
    TextureManager m_texMan;

};
