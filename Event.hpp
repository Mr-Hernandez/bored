#ifndef EVENT_H
#define EVENT_H

#include <SFML/Graphics.hpp>
#include "Bus.hpp"
#include <iostream>
#include "SpriteDraw.hpp"

class Event{
public:
    Event();
    ~Event();

    void Update(Bus* m_bus);
    void State_Menu(Bus* m_bus, sf::Event event);
    void State_Game(Bus* m_bus, sf::Event event);
    void State_EndMenu(Bus* m_bus, sf::Event event);

private:



};
#endif // EVENT_H

