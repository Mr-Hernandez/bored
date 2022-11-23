#ifndef DRAW_H
#define DRAW_H

#include "Bus.hpp"
#include "SFML/Graphics.hpp"

class Draw{
public:
    Draw();
    ~Draw();

    void drawMap(Bus* m_bus);
    void drawCharacter(const std::string drawThisChar, Bus* m_bus);
    void drawCursor(Bus* m_bus);

private:
    sf::Vector2f pos2Orig(int posx, int posy, Bus* m_bus);
};

#endif // DRAW_H


