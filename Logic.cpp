#include "Logic.hpp"


Logic::Logic(Bus* l_bus){
    m_bus = l_bus;
}

Logic::~Logic(){

}


// Game State Logic

bool Logic::CharCanMoveUp(int index){
    int posx = m_bus->s_character->GetPosx(index);
    int posy = m_bus->s_character->GetPosy(index);
    if(posx == -1 || posy == -1){ // -1 means
        //log error
        return false;
    }
//    int mapBoundx = m_bus->s_map->GetTileLength();
//    int mapBoundy = m_bus->s_map->GetTileHeight();

    // add a check for tile type later.
    if(posy == 0){
        return false;
    }else{
        return true;
    }
}

bool Logic::CharCanMoveDown(int index){
    int posx = m_bus->s_character->GetPosx(index);
    int posy = m_bus->s_character->GetPosy(index);
    if(posx == -1 || posy == -1){ // -1 means
        //log error
        return false;
    }
//    int mapBoundx = m_bus->s_map->GetTileLength();
    int mapBoundy = m_bus->s_map->GetTileHeight();

    // add a check for tile type later.
    if(posy == mapBoundy - 1){
        return false;
    }else{
        return true;
    }
}

bool Logic::CharCanMoveLeft(int index){
    int posx = m_bus->s_character->GetPosx(index);
    int posy = m_bus->s_character->GetPosy(index);
    if(posx == -1 || posy == -1){ // -1 means
        //log error
        return false;
    }
//    int mapBoundx = m_bus->s_map->GetTileLength();
//    int mapBoundy = m_bus->s_map->GetTileHeight();

    // add a check for tile type later.
    if(posx == 0){
        return false;
    }else{
        return true;
    }
}

bool Logic::CharCanMoveRight(int index){
    int posx = m_bus->s_character->GetPosx(index);
    int posy = m_bus->s_character->GetPosy(index);
    if(posx == -1 || posy == -1){ // -1 means
        //log error
        return false;
    }
    int mapBoundx = m_bus->s_map->GetTileLength();
//    int mapBoundy = m_bus->s_map->GetTileHeight();

    // add a check for tile type later.
    if(posx == mapBoundx - 1){
        return false;
    }else{
        return true;
    }
}


bool Logic::CursorCanMoveUp(int posx, int posy){
    return true; //logic currently just in Cursor.cpp
}

bool Logic::CursorCanMoveDown(int posx, int posy){
    int mapBoundy = m_bus->s_map->GetTileHeight();
    if(posy >= mapBoundy - 1){ return false;}
    std::cout << posy << ":" << mapBoundy << std::endl;
    return true;
}

bool Logic::CursorCanMoveLeft(int posx, int posy){
    return true; //logic currently just in Cursor.cpp
}

bool Logic::CursorCanMoveRight(int posx, int posy){
    int mapBoundx = m_bus->s_map->GetTileLength();
    if(posx >= mapBoundx - 1){ return false;}
    return true;
}


bool Logic::CanSelectChar(){
    sf::Vector2i cursorPos;
    sf::Vector2i charPos;

    cursorPos = sf::Vector2i(m_bus->s_cursor->GetPosx(), m_bus->s_cursor->GetPosy());
    int index = m_bus->s_character->GetIndexFromPos(cursorPos.x, cursorPos.y);
    if(index < 0){ return false;}
    m_bus->s_character->SetCurrentChar(index);
    return true;
}
