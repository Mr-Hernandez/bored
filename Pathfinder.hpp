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
    void CheckPathOverlap();
    void ClearPath();
    void PrintPath();
    void FindPath(sf::Vector2i startPos, sf::Vector2i targetPos);


private:
    sf::Vector2i m_targetPos;
    sf::Vector2i m_forkPos;

    std::vector<sf::Vector2i> m_pathContainer;
    std::vector<std::pair<sf::Vector2i, bool [4]>> finderContainer;

};
#endif // PATHFINDER_H
