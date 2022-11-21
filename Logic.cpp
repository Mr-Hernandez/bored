#include "Logic.hpp"


Logic::Logic(Bus* l_bus){
    m_bus = l_bus;
}

Logic::~Logic(){

}


// Game State Logic

bool Logic::CanMoveUp(int index){
    int posx = m_bus->s_character->GetPosx(index);
    int posy = m_bus->s_character->GetPosy(index);
    if(posx == -1 || posy == -1){ // -1 means
        //log error
        return false;
    }
    int mapBoundx = m_bus->s_map->GetTileLength();
    int mapBoundy = m_bus->s_map->GetTileHeight();

    // add a check for tile type later.
    if(posy == 0){
        return false;
    }else{
        return true;
    }
}

bool Logic::CanMoveDown(int index){
    int posx = m_bus->s_character->GetPosx(index);
    int posy = m_bus->s_character->GetPosy(index);
    if(posx == -1 || posy == -1){ // -1 means
        //log error
        return false;
    }
    int mapBoundx = m_bus->s_map->GetTileLength();
    int mapBoundy = m_bus->s_map->GetTileHeight();

    // add a check for tile type later.
    if(posy == mapBoundy - 1){
        return false;
    }else{
        return true;
    }
}

bool Logic::CanMoveLeft(int index){
    int posx = m_bus->s_character->GetPosx(index);
    int posy = m_bus->s_character->GetPosy(index);
    if(posx == -1 || posy == -1){ // -1 means
        //log error
        return false;
    }
    int mapBoundx = m_bus->s_map->GetTileLength();
    int mapBoundy = m_bus->s_map->GetTileHeight();

    // add a check for tile type later.
    if(posx == 0){
        return false;
    }else{
        return true;
    }
}

bool Logic::CanMoveRight(int index){
    int posx = m_bus->s_character->GetPosx(index);
    int posy = m_bus->s_character->GetPosy(index);
    if(posx == -1 || posy == -1){ // -1 means
        //log error
        return false;
    }
    int mapBoundx = m_bus->s_map->GetTileLength();
    int mapBoundy = m_bus->s_map->GetTileHeight();

    // add a check for tile type later.
    if(posx == mapBoundx - 1){
        return false;
    }else{
        return true;
    }
}
