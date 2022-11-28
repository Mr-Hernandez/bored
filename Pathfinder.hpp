#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdlib.h>

class Pathfinder{
public:
    Pathfinder();
    ~Pathfinder();

    int GetContainerSize();
    sf::Vector2i GetPos(int index);

    void AddPathPos(sf::Vector2i pos);
    void ClearPath();
    void PrintPath();


private:
    sf::Vector2i m_targetPos;
    sf::Vector2i m_forkPos;

    std::vector<sf::Vector2i> m_pathContainer;

};
#endif // PATHFINDER_H
