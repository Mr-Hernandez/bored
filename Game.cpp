#include "Game.hpp"

Game::Game() : m_winH((unsigned int)800),
               m_winW((unsigned int)800),
               m_mainWindow(m_winH, m_winW){
               // add here whatever other objects need the screen size or add it to bus?
               // need a set size update?
    state = STATE_GAME;
    m_renderTimer.setFrameDisplay();
    init_bus();
}

Game::~Game(){}

void Game::Update(){
    m_renderTimer.Update(); // gets new time
    m_mainWindow.Update();  // does nothing
    m_event.Update(&m_bus); // reads inputs // game logic layer between input and result.
    m_draw.drawMap(&m_bus); // should raw appropriate map
    m_draw.drawCharacter("Seras Victoria", &m_bus); // draw characters from list
    m_draw.drawCursor(&m_bus);

}

void Game::Render(){
    if(m_renderTimer.getTick()){
        m_texMan.cleanTextures();
        getWindow()->display();
        getWindow()->clear();
    }
}

sf::RenderWindow* Game::getWindow(){
    return m_mainWindow.getWindow();
}

void Game::init_bus(){
    m_bus.s_mainWindow = getWindow();
    m_bus.s_timer = &m_renderTimer;
    m_bus.s_map = &m_map;
    m_bus.s_state = &state;
    m_bus.s_texMan = &m_texMan;
    m_bus.s_character = &m_character;
    m_bus.s_cursor = &m_cursor;
}

