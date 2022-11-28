#ifndef EVENT_H
#define EVENT_H

#include <SFML/Graphics.hpp>
#include "Bus.hpp"
#include <iostream>
#include "SpriteDraw.hpp"
#include "Logic.hpp"



class Event{
public:
    Event();
    ~Event();

    void Update(Bus* m_bus);
    void State_Agnostic(Bus* m_bus, sf::Event event);
    void State_Menu(Bus* m_bus, sf::Event event);
    void State_Game(Bus* m_bus, sf::Event event);
    void State_EndMenu(Bus* m_bus, sf::Event event);

private:
    enum EventType{
        Closed, Resized, LostFocus, GainedFocus,
        TextEntered, KeyPressed, KeyReleased, MouseWheelMoved,
        MouseWheelScrolled, MouseButtonPressed, MouseButtonReleased, MouseMoved,
        MouseEntered, MouseLeft, JoystickButtonPressed, JoystickButtonReleased,
        JoystickMoved, JoystickConnected, JoystickDisconnected, TouchBegan,
        TouchMoved, TouchEnded, SensorChanged, Count
    };

    enum StateType{
        CursorState, CharState, PathState
    };

    StateType l_state;

};
#endif // EVENT_H

