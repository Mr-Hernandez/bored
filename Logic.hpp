#ifndef LOGIC_H
#define LOGIC_H

#include "Bus.hpp"


class Logic{
public:
    Logic(Bus* l_bus);
    ~Logic();
    //Game State Logic
    bool CharCanMoveUp(int index);
    bool CharCanMoveDown(int index);
    bool CharCanMoveLeft(int index);
    bool CharCanMoveRight(int index);

    bool CursorCanMoveUp(int posx, int posy);
    bool CursorCanMoveDown(int posx, int posy);
    bool CursorCanMoveLeft(int posx, int posy);
    bool CursorCanMoveRight(int posx, int posy);



private:
    Bus* m_bus;

};

#endif // LOGIC_H
