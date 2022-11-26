#include "Event.hpp"

Event::Event(){
    l_state = CursorState;
}

Event::~Event(){

}

void Event::Update(Bus* m_bus){
    sf::Event event;
    while(m_bus->s_mainWindow->pollEvent(event)){
        State_Agnostic(m_bus, event);

        if(*(m_bus->s_state) == STATE_MENU){
            State_Menu(m_bus, event);

        }else if(*(m_bus->s_state) == STATE_GAME){
            State_Game(m_bus, event);

        }else if(*(m_bus->s_state) == STATE_ENDMENU){
            State_EndMenu(m_bus, event);
        }
    }
}

void Event::State_Agnostic(Bus* m_bus, sf::Event event){
    if (event.type == sf::Event::Closed){
        m_bus->s_mainWindow->close();
    }
}


void Event::State_Menu(Bus* m_bus, sf::Event event){

}


void Event::State_Game(Bus* m_bus, sf::Event event){
//  Close window : exit
    Logic logic(m_bus);
    if(event.type == sf::Event::KeyPressed){
        std::cout << "event type: " << event.type << std::endl;
        std::cout << "event key code: " << event.key.code << std::endl;
        std::cout << "alt pressed?: " << event.key.alt << std::endl;
        std::cout << "control pressed?: " << event.key.control << std::endl;
        std::cout << "shift pressed?: " << event.key.shift << std::endl;
        std::cout << "system pressed?: " << event.key.system << std::endl;

        if(l_state == CursorState){
            if(event.key.code == sf::Keyboard::W){
                int posx = m_bus->s_cursor->GetPosx();
                int posy = m_bus->s_cursor->GetPosy();
                if(logic.CursorCanMoveUp(posx, posy)){
                    m_bus->s_cursor->MoveUp();
                }
            }

            if(event.key.code == sf::Keyboard::S){
                int posx = m_bus->s_cursor->GetPosx();
                int posy = m_bus->s_cursor->GetPosy();
                if(logic.CursorCanMoveDown(posx, posy)){
                    m_bus->s_cursor->MoveDown();
                }
            }

            if(event.key.code == sf::Keyboard::A){
                int posx = m_bus->s_cursor->GetPosx();
                int posy = m_bus->s_cursor->GetPosy();
                if(logic.CursorCanMoveLeft(posx, posy)){
                    m_bus->s_cursor->MoveLeft();
                }
            }

            if(event.key.code == sf::Keyboard::D){
                int posx = m_bus->s_cursor->GetPosx();
                int posy = m_bus->s_cursor->GetPosy();
                if(logic.CursorCanMoveRight(posx, posy)){
                    m_bus->s_cursor->MoveRight();
                }
            }
        }


        if(l_state == CharState){

            if(event.key.code == sf::Keyboard::W){
                // Hardcoded for test.
                std::string charName = "Seras Victoria";
                // charName should be chosen by cursor action. I want a single point of entry
                // something like currentcharName or activecharName, or chosencharName.
                int index = m_bus->s_character->GetArrPos(charName);
                if(logic.CharCanMoveUp(index)){
                    m_bus->s_character->MoveUp(charName);
                }
            }

            if(event.key.code == sf::Keyboard::S){
                // Hardcoded for test.
                std::string charName = "Seras Victoria";
                int index = m_bus->s_character->GetArrPos(charName);
                if(logic.CharCanMoveDown(index)){
                    m_bus->s_character->MoveDown(charName);
                }
            }

            if(event.key.code == sf::Keyboard::A){
                // Hardcoded for test.
                std::string charName = "Seras Victoria";
                int index = m_bus->s_character->GetArrPos(charName);
                if(logic.CharCanMoveLeft(index)){
                    m_bus->s_character->MoveLeft(charName);
                }
            }

            if(event.key.code == sf::Keyboard::D){
                // Hardcoded for test.
                std::string charName = "Seras Victoria";
                int index = m_bus->s_character->GetArrPos(charName);
                if(logic.CharCanMoveRight(index)){
                    m_bus->s_character->MoveRight(charName);
                }
            }
        }

    }
}


void Event::State_EndMenu(Bus* m_bus, sf::Event event){

}


