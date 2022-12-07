#include "Character.hpp"


Character::Character(){
    loadCharactersList();
}


Character::~Character(){

}


void Character::loadCharactersList(){
    std::fstream charList;
    charList.open("D:/Programming/C++/Projects/codebloks/bored/assets/textures/characterList.txt");
    std::string line;
    std::string delim = "|";
    int index = 0;
    while(getline(charList, line)){
        std::size_t pos = line.find(delim, 0);
        std::string charName = line.substr(pos+1);

        getline(charList, line);
        pos = line.find(delim, 0);
        std::string tmp = line.substr(pos+1);
        int baseHP = std::stoi(tmp);

        getline(charList, line);
        pos = line.find(delim, 0);
        tmp = line.substr(pos+1);
        int baseATK = std::stoi(tmp);

        getline(charList, line);
        pos = line.find(delim, 0);
        tmp = line.substr(pos+1);
        int baseDEF = std::stoi(tmp);

        getline(charList, line);
        pos = line.find(delim, 0);
        tmp = line.substr(pos+1);
        int baseSPD = std::stoi(tmp);

        getline(charList, line);
        pos = line.find(delim, 0);
        tmp = line.substr(pos+1);
        int baseMOV = std::stoi(tmp);

        getline(charList, line);
        pos = line.find(delim, 0);
        std::string texName = line.substr(pos+1);

        getline(charList, line); // clean up

        charactersArr[index].charName = charName;
        charactersArr[index].baseHP = baseHP;
        charactersArr[index].baseATK = baseATK;
        charactersArr[index].baseDEF = baseDEF;
        charactersArr[index].baseSPD = baseSPD;
        charactersArr[index].baseMOV = baseMOV;
        charactersArr[index].texName = texName;

        // initiate currentStats to base stats.
        // These must be changed from memory if different than baseStats.
        charactersArr[index].currentHP = charactersArr[index].baseHP;
        charactersArr[index].currentATK = charactersArr[index].baseATK;
        charactersArr[index].currentDEF = charactersArr[index].baseDEF;
        charactersArr[index].currentSPD = charactersArr[index].baseSPD;
        charactersArr[index].currentMOV = charactersArr[index].baseMOV;
        charactersArr[index].posx = 0;
        charactersArr[index].posy = 0;

        index++;
    }
    array_size = index + 1;
}


int Character::GetArrSize(){
    return array_size;
}

int Character::GetArrPos(const std::string l_charName){
    for(int i = 0; i < array_size; i++){
        if(charactersArr[i].charName == l_charName){
            return i;
        }
    }
    return -1;
}

const std::string Character::GetCharName(int index){
    if(!IsIndex(index)){ return "loadFailed";}
    return charactersArr[index].charName;
}

const std::string Character::GetTexName(int index){
    if(!IsIndex(index)){ return "loadFailed";} // log error
    return charactersArr[index].texName;
}

sf::Texture* Character::GetTexturePointer(int index){
    if(!IsIndex(index)){ return charactersArr[0].texture;} // log error
    return charactersArr[index].texture;
}

int Character::GetPosx(int index){
    if(!IsIndex(index)){ return -1;}
    return charactersArr[index].posx;
}

int Character::GetPosy(int index){
    if(!IsIndex(index)){ return -1;}
    return charactersArr[index].posy;
}


void Character::SetPosx(int index, float x){
    if(!IsIndex(index)){ return;}
    charactersArr[index].posx = x;
}

void Character::SetPosy(int index, float y){
    if(!IsIndex(index)){ return;}
    charactersArr[index].posy = y;
}

bool Character::IsIndex(int index){
    if( (index < 0 ) || (index >= array_size) ){
        return false;
    }else{
        return true;
    }
}


void Character::MoveUp(const std::string charName){
    // need logic on movement here.
    // I think the logic should be in another class
    // and then only call this one if it works out.
    for(int i = 0; i < array_size; i++){
        if(charactersArr[i].charName == charName){
//            std::cout << "before: (MOVEUP())" << charactersArr[i].posy << std::endl;
            charactersArr[i].posy--;
//            std::cout << "moved down (MOVEUP())" << charactersArr[i].posy << std::endl;
            break;
        }
    }
}

void Character::MoveDown(const std::string charName){
    for(int i = 0; i < array_size; i++){
        if(charactersArr[i].charName == charName){
//            std::cout << "before: (MOVEUP())" << charactersArr[i].posy << std::endl;
            charactersArr[i].posy++;
//            std::cout << "moved down (MOVEUP())" << charactersArr[i].posy << std::endl;
            break;
        }
    }
}

void Character::MoveLeft(const std::string charName){
    for(int i = 0; i < array_size; i++){
        if(charactersArr[i].charName == charName){
//            std::cout << "before: (MOVEUP())" << charactersArr[i].posy << std::endl;
            charactersArr[i].posx--;
//            std::cout << "moved down (MOVEUP())" << charactersArr[i].posy << std::endl;
            break;
        }
    }
}

void Character::MoveRight(const std::string charName){
    for(int i = 0; i < array_size; i++){
        if(charactersArr[i].charName == charName){
//            std::cout << "before: (MOVEUP())" << charactersArr[i].posy << std::endl;
            charactersArr[i].posx++;
//            std::cout << "moved down (MOVEUP())" << charactersArr[i].posy << std::endl;
            break;
        }
    }
}



int Character::GetIndexFromPos(int posx, int posy){
    for(int i = 0; i < array_size; i++){
        if(charactersArr[i].posx == posx && charactersArr[i].posy == posy){
            return i;
        }
    }
    return -1;
}

int Character::GetCurrentChar(){
    return currentCharacter;
}

void Character::SetCurrentChar(int currentCharacterIndex){
    if(currentCharacterIndex < 0){ return;}
    currentCharacter = currentCharacterIndex;
}

