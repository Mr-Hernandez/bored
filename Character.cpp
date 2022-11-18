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
        std::string texName = line.substr(pos+1);

        getline(charList, line); // clean up

        charactersArr[index].charName = charName;
        charactersArr[index].baseHP = baseHP;
        charactersArr[index].baseATK = baseATK;
        charactersArr[index].baseDEF = baseDEF;
        charactersArr[index].baseSPD = baseSPD;
        charactersArr[index].texName = texName;

        // initiate currentStats to base stats.
        // These must be changed from memory if different than baseStats.
        charactersArr[index].currentHP = charactersArr[index].baseHP;
        charactersArr[index].currentATK = charactersArr[index].baseATK;
        charactersArr[index].currentDEF = charactersArr[index].baseDEF;
        charactersArr[index].currentSPD = charactersArr[index].baseSPD;
        charactersArr[index].posx = 0;
        charactersArr[index].posy = 0;

        index++;
    }
    array_size = index + 1;
}


int Character::GetArrSize(){
    return array_size;
}

const std::string Character::GetCharName(int index){
    if(index > array_size){ return 0;}
    return charactersArr[index].charName;
}

const std::string Character::GetTexName(int index){
    if(index > array_size){ return 0;}
    return charactersArr[index].texName;
}

sf::Texture* Character::GetTexturePointer(int index){
    if(index > array_size){ return 0;}
    return charactersArr[index].texture;
}

int Character::GetPosx(int index){
    if(index > array_size){ return 0;}
    return charactersArr[index].posx;
}

int Character::GetPosy(int index){
    if(index > array_size){ return 0;}
    return charactersArr[index].posy;
}



