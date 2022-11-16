#include <iostream>
#include <SFML/Graphics.hpp>

int main(){
    sf::Clock m_clock;
    sf::Time m_time = sf::seconds(1.1f / 60.0f);
    sf::Time frametime = sf::seconds(1.0f / 60.0f);

    std::cout << "m_time: " << m_time.asMicroseconds() << std::endl;
    std::cout << "frametime: " << frametime.asMicroseconds() << std::endl;
    m_time =- frametime;
    std::cout << "m_time2: " << m_time.asMicroseconds() << std::endl;

    m_time = sf::seconds(1.1f / 60.0f);
    frametime = sf::seconds(1.0f / 60.0f);

    std::cout << "m_time: " << m_time.asMicroseconds() << std::endl;
    std::cout << "frametime: " << frametime.asMicroseconds() << std::endl;
    m_time = sf::microseconds(m_time.asMicroseconds() - frametime.asMicroseconds());
    std::cout << "m_time2: " << m_time.asMicroseconds() << std::endl;
    return 0;
}
