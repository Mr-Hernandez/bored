#ifndef VIEWER_H
#define VIEWER_H

#include "SFML/Graphics.hpp"

class Viewer{
public:
    Viewer();
    ~Viewer();

    sf::View* GetView();
    void SetCenter(sf::Vector2f l_center);
    void SetSize(int sizeNum);


private:
    sf::View m_view;
    sf::Vector2f m_close, m_medium, m_far;
    sf::Vector2f m_center;
    sf::Vector2f currentCenter;





};
#endif // VIEWER_H
