#include "Pathfinder.hpp"


Pathfinder::Pathfinder(){

}

Pathfinder::~Pathfinder(){

}


void Pathfinder::AddPathPos(sf::Vector2i pos){
    m_pathContainer.push_back(pos);
}

void Pathfinder::ClearPath(){
    m_pathContainer.clear();
//    while(!m_pathContainer.empty()){
//        m_pathContainer.pop_back();
//    }
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

void Pathfinder::CheckPathOverlap(){
    int lastIndex = GetContainerSize();
//    if(lastIndex < 2 || m_pathContainer.empty()){ return;}
    if((lastIndex < 2)){ return;}
    for(int i = 0; i < lastIndex; i++){
        if(m_pathContainer[i] == m_pathContainer[lastIndex]){
//            if(i == 0){
//                sf::Vector2i charPos = m_pathContainer[0];
//                ClearPath();
//                AddPathPos(charPos);
//                return;
//            }
            std::cout << "index: " << i << "|lastindex: --------------" << lastIndex << std::endl;
            std::vector<sf::Vector2i>::iterator it1 = m_pathContainer.begin() + i + 1;
//            std::vector<sf::Vector2i>::iterator it2 = m_pathContainer.begin() + lastIndex;
            std::vector<sf::Vector2i>::iterator it2 = m_pathContainer.end() ;
            std::cout << "pathcontainer before erase: " << lastIndex << std::endl;
            m_pathContainer.erase(it1, it2);
            std::cout << "path container after erase: " << GetContainerSize() << std::endl;
            break;
        }
    }
}

