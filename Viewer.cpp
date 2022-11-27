#include "Viewer.hpp"


Viewer::Viewer(){
    m_close = sf::Vector2f(720, 405);
    m_medium = sf::Vector2f(1280, 720);
    m_far = sf::Vector2f(1920, 1080);
    m_view.setSize(m_far);
    m_view.setCenter(m_far / 2.f);

}

Viewer::~Viewer(){

}


sf::View* Viewer::GetView(){
    return &m_view;
}


void Viewer::SetCenter(sf::Vector2f l_center){
    static sf::Vector2f currentCenter = sf::Vector2f(0.f, 0.f);
    float cursorSpeed = 0.9f;
//    if(currentCenter != l_center){
        if(currentCenter.x < l_center.x){
            currentCenter.x += cursorSpeed;
        }
        if(currentCenter.x > l_center.x){
            currentCenter.x -= cursorSpeed;
        }
        if(currentCenter.y < l_center.y){
            currentCenter.y += cursorSpeed;
        }
        if(currentCenter.y > l_center.y){
            currentCenter.y -= cursorSpeed;
        }
//    }
    m_view.setCenter(currentCenter);
}


void Viewer::SetSize(int sizeNum){
    if(sizeNum == 0){ m_view.setSize(m_close);}
    else if(sizeNum == 1){ m_view.setSize(m_medium);}
    else if(sizeNum == 2){ m_view.setSize(m_far);}
}

