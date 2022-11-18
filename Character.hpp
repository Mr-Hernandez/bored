#ifndef CHARACTER_H
#define CHARACTER_H

#define NO_OF_CHARACTERS 50

#include "SFML/Graphics.hpp"
//#include "Bus.hpp" cause circular logic do not add.
#include <fstream>
#include <iostream>
#include <string>

class Character{

public:
    Character();
    ~Character();

    //GETTERS
    int GetArrSize();
    int GetStat(int index);
    int GetPosx(int index);
    int GetPosy(int index);
    const std::string GetCharName(int index);
    const std::string GetTexName(int index);
    sf::Texture* GetTexturePointer(int index);

    //SETTERS
//    sf::Texture* SetTexturePointer(int index);

private:
    struct Characters{
    std::string charName;
    int baseHP;
    int baseATK;
    int baseDEF;
    int baseSPD;

    int currentHP;
    int currentATK;
    int currentDEF;
    int currentSPD;

    int posx, posy;
    std::string texName;
    sf::Texture* texture;
    };

    int array_size;
    Characters charactersArr[NO_OF_CHARACTERS];

    void loadCharactersList();


};

#endif // CHARACTER_H
