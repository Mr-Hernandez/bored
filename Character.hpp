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

    bool IsIndex(int index);

    //GETTERS
    int GetArrSize();
    int GetArrPos(const std::string l_charName);
    int GetStat(int index);
    int GetPosx(int index);
    int GetPosy(int index);
    const std::string GetCharName(int index);
    const std::string GetTexName(int index);
    sf::Texture* GetTexturePointer(int index);
    int GetIndexFromPos(int posx, int posy);
    int GetCurrentChar();
    void SetCurrentChar(int currentCharacterIndex);

    //SETTERS
//    sf::Texture* SetTexturePointer(int index);
    void SetPosx(int index, float x);
    void SetPosy(int index, float y);

    //GAME LOGIC
    void MoveUp(const std::string charName);
    void MoveDown(const std::string charName);
    void MoveLeft(const std::string charName);
    void MoveRight(const std::string charName);

private:
    struct Characters{
    std::string charName;
    int baseHP;
    int baseATK;
    int baseDEF;
    int baseSPD;
    int baseMOV;

    int currentHP;
    int currentATK;
    int currentDEF;
    int currentSPD;
    int currentMOV;

    int posx, posy;
    std::string texName;
    sf::Texture* texture;
    };

    int array_size;
    int currentCharacter;
    Characters charactersArr[NO_OF_CHARACTERS];

    void loadCharactersList();

    //movement



};

#endif // CHARACTER_H
