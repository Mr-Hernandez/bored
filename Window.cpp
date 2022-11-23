#include "Window.hpp"


Window::Window() : m_mainWindow(sf::VideoMode(800, 800), "SFML window"){

}

Window::Window(unsigned int l_winH, unsigned int l_winW) : m_mainWindow(sf::VideoMode(l_winH, l_winW), "SFML window2"){

}

Window::~Window(){

}

sf::RenderWindow* Window::getWindow(){
    return &m_mainWindow;
    }

void Window::Update(){
//    sf::Event event;
//    while(m_mainWindow.pollEvent(event)){
//        // Close window : exit
//        if (event.type == sf::Event::Closed)
//            m_mainWindow.close();
//
//        if (event.type == sf::Event::KeyPressed){
//            if (event.key.code == sf::Keyboard::Escape){
//                std::cout << "the escape key was pressed" << std::endl;
//                std::cout << "event key code is: " << event.key.code << std::endl;
//                s_Rectangle s_rectangle;
//                s_rectangle.print();
//            }
//        }
//
//        if (event.type == sf::Event::KeyPressed){
//            if (event.key.code == sf::Keyboard::A){
//                std::cout << "the A key was pressed" << std::endl;
//                std::cout << "event key code is: " << event.key.code << std::endl;
//                s_Circle s_circle;
//                s_circle.print();
//            }
//        }

//        if(event.type == sf::Event::LostFocus){
//            m_isFocused = false;
//            m_eventManager.SetFocus(false);
//        }
//        else if(event.type == sf::Event::GainedFocus){
//            m_isFocused = true;
//            m_eventManager.SetFocus(true);
//        }
//    }
//    m_SpriteDraw.drawRandomCircle(&m_mainWindow);
}
