#include "Game.hpp"

Game::Game(){
    state = STATE_GAME;
    m_renderTimer.setFrameDisplay();
    init_bus();
}

Game::~Game(){}

void Game::Update(){
    m_renderTimer.Update();
    m_mainWindow.Update();
    m_event.Update(&m_bus);
    m_draw.drawMap(&m_bus);

    sf::Texture* texture;
    texture = m_bus.s_texMan->requestTexture("char1");
    sf::Sprite char1Sprite;
    char1Sprite.setTexture(*texture);
    char1Sprite.setPosition(100.0, 200.0);
    m_bus.s_mainWindow->draw(char1Sprite);



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
}

