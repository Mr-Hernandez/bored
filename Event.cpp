#include "Event.hpp"

Event::Event(){

}

Event::~Event(){

}

void Event::Update(Bus* m_bus){
    sf::Event event;
        while(m_bus->s_mainWindow->pollEvent(event)){
            if (event.type == sf::Event::Closed)
                m_bus->s_mainWindow->close();

            if(*(m_bus->s_state) == STATE_MENU){
                State_Menu(m_bus, event);

            }else if(*(m_bus->s_state) == STATE_GAME){
                State_Game(m_bus, event);

            }else if(*(m_bus->s_state) == STATE_ENDMENU){
                State_EndMenu(m_bus, event);
            }
        }
}

void Event::State_Menu(Bus* m_bus, sf::Event event){

}


void Event::State_Game(Bus* m_bus, sf::Event event){
//  Close window : exit
    if (event.type == sf::Event::Closed)
        m_bus->s_mainWindow->close();

    if (event.type == sf::Event::KeyPressed){
        if (event.key.code == sf::Keyboard::Escape){
            std::cout << "the escape key was pressed" << std::endl;
            std::cout << "event key code is: " << event.key.code << std::endl;
            m_bus->s_timer->setFrameDisplay();
//                    s_Rectangle s_rectangle;
//                    s_rectangle.print();
        }
    }

    if (event.type == sf::Event::KeyPressed){
        if (event.key.code == sf::Keyboard::A){
            std::cout << "the A key was pressed" << std::endl;
            std::cout << "event key code is: " << event.key.code << std::endl;
            SpriteDraw spritedraw;
            spritedraw.drawRandomCircle((m_bus->s_mainWindow));
//                    s_Circle s_circle;
//                    s_circle.print();
        }
    }
}


void Event::State_EndMenu(Bus* m_bus, sf::Event event){

}
