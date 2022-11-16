#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteDraw.hpp"
#include "Shape.hpp"


class Window{

public:
    Window();
    ~Window();

    void Update();

    sf::RenderWindow* getWindow();

private:
    sf::RenderWindow m_mainWindow;
    SpriteDraw m_SpriteDraw;


};
