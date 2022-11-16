#ifndef TIMER_H
#define TIMER_H

#include <SFML/Graphics.hpp>

//Testing
#include <iostream>

class Timer{

public:
    Timer();
    ~Timer();

    bool getTick();

    void Update();

    //Testing Purposes
    void setFrameDisplay();

private:
    sf::Clock m_clock;
    sf::Time m_time;
    sf::Time m_framerate;

    //Testing
    bool m_ShowFrame;
    int m_Frame;


};

#endif // TIMER_H

