#ifndef LOGIC_H
#define LOGIC_H

#include "Bus.hpp"


class Logic{
public:
    Logic(Bus* l_bus);
    ~Logic();
    //Game State Logic
    bool CanMoveUp(int index);
    bool CanMoveDown(int index);
    bool CanMoveLeft(int index);
    bool CanMoveRight(int index);


private:
    Bus* m_bus;

};

#endif // LOGIC_H
