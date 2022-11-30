#include "Game.hpp"

Game::Game() : m_winW(1920),
               m_winH(1080),
               m_mainWindow(m_winH, m_winW),
               m_draw(m_winH, m_winW){
               // add here whatever other objects need the screen size or add it to bus?
               // need a set size update?
    state = STATE_GAME;
//    m_renderTimer.setFrameDisplay();
    init_bus();
    m_viewer.SetSize(2);
//    m_viewer.SetCenter(sf::Vector2f(m_winW/2.f, 800.f));
//    m_view.reset(sf::FloatRect(100,100,400,200));
//    m_view.setSize(640, 512);
//    m_view.setCenter(320,256);
//    m_view.setViewport(sf::FloatRect(0.0f, 0.0f, 0.1f, 0.1f));
}

Game::~Game(){}

void Game::Update(){
    m_renderTimer.Update(); // gets new time
//    m_mainWindow.getWindow()->setView(m_view);
    m_mainWindow.getWindow()->setView(*m_viewer.GetView());
    m_mainWindow.Update();  // does nothing
    m_event.Update(&m_bus); // reads inputs // game logic layer between input and result.
    m_draw.drawMap(&m_bus); // should draw appropriate map
    m_draw.drawCharacter("Seras Victoria", &m_bus); // draw characters from list
    m_draw.drawCursor(&m_bus);
    m_draw.drawPath(&m_bus);
    m_viewer.SetCenter(sf::Vector2f(m_cursor.GetPosx() * 128, m_cursor.GetPosy() * 128));


//    sf::Texture* pTexture;
//    pTexture = m_texMan.requestTexture("fireTile");
//    sf::Sprite sprite;
//    sprite.setTexture(*pTexture);
//    sprite.setPosition(425, 425);
//    m_mainWindow.getWindow()->draw(sprite);

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
    m_bus.s_pathFinder = &m_pathFinder;
}

