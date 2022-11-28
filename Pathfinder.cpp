#include "Pathfinder.hpp"


Pathfinder::Pathfinder(){

}

Pathfinder::~Pathfinder(){

}


void Pathfinder::AddPathPos(sf::Vector2i pos){
    m_pathContainer.push_back(pos);
}

void Pathfinder::ClearPath(){
    while(!m_pathContainer.empty()){
        m_pathContainer.pop_back();
    }
}

int Pathfinder::GetContainerSize(){
    if(m_pathContainer.empty()){return -1;}
    return static_cast<int>(m_pathContainer.size() - 1);
}

sf::Vector2i Pathfinder::GetPos(int index){
    if(index < 0 || index > GetContainerSize()){ std::cout << "failed GetPos()"; exit(0);}//return sf::Vector2i(0,0);} // log error
    return m_pathContainer[index];
}

void Pathfinder::PrintPath(){
    for(size_t i = 0; i < m_pathContainer.size(); i++){
        std::cout << i << "|x: " << m_pathContainer[i].x << "|y: " << m_pathContainer[i].y << std::endl;
    }
}

