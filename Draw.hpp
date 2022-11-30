#ifndef DRAW_H
#define DRAW_H

#include "Bus.hpp"
#include "SFML/Graphics.hpp"

class Draw{
public:
    Draw();
    Draw(int l_winH, int l_winW);
    ~Draw();

    void drawMap(Bus* m_bus);
    void drawCharacter(const std::string drawThisChar, Bus* m_bus);
    void drawCursor(Bus* m_bus);
    void drawPath(Bus* m_bus);

private:
    sf::Vector2f pos2Orig(int posx, int posy, Bus* m_bus);
    float degRotation(sf::Vector2i currentPos, sf::Vector2i previousPos);
    void pathRotator(sf::Vector2i current, sf::Vector2i previous, sf::Sprite* sprite, Bus* m_bus);
    void turnRotator(sf::Vector2i current, sf::Vector2i previous, sf::Vector2i previous2, sf::Sprite* sprite, Bus* m_bus);
    bool IsTurn(sf::Vector2i current, sf::Vector2i previous, sf::Vector2i previous2);
    sf::Vector2f normOrigin(int degreesTurned);
    int m_winH, m_winW;
};

#endif // DRAW_H


