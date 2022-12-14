#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteDraw.hpp"
#include "Shape.hpp"


class Window{

public:
    Window();
    Window(int l_winH, int l_winW);
    ~Window();

    void Update();

    sf::RenderWindow* getWindow();

private:
//    int winH, winW;
    sf::RenderWindow m_mainWindow;
    SpriteDraw m_SpriteDraw;


};
