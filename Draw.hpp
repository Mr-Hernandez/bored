#ifndef DRAW_H
#define DRAW_H

#include "Bus.hpp"

class Draw{
public:
    Draw();
    ~Draw();

    void drawMap(Bus* m_bus);
    void drawCharacter(Bus* m_bus);

private:

};

#endif // DRAW_H


