#include "Timer.hpp"

Timer::Timer() : m_ShowFrame(true), m_Frame(0) {
    m_clock.restart();
    m_framerate = sf::seconds(1.0f / 60.0f);
}

Timer::~Timer(){

}

void Timer::Update(){
    m_time += m_clock.restart();
}

bool Timer::getTick(){
//    m_time += m_clock.restart();
    if(m_time >= m_framerate){
        m_time = sf::microseconds(m_time.asMicroseconds() - m_framerate.asMicroseconds());
        m_Frame++;
        if(m_Frame > 60){ m_Frame = 1;}
        if(!m_ShowFrame){
            std::cout << "frame: " << m_Frame << std::endl;
        }
        return true;
    }else{
        return false;
    }
}

// Testing
//void Timer::setFrameDisplay(){ m_ShowFrame = true;}
void Timer::setFrameDisplay(){ m_ShowFrame = !m_ShowFrame;}

