#ifndef CURSOR_H
#define CURSOR_H

#include "SFML/Graphics.hpp"

class Cursor{
public:
    Cursor();
    ~Cursor();

    int GetPosx();
    int GetPosy();
    std::string GetTexName();

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

private:
    int posx;
    int posy;
    std::string texName;

    sf::Texture* texture;
    void Init();

};
#endif // CURSOR_H
