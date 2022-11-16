#include "Map.hpp"

Map::Map() : mapTileArr(nullptr){
    m_setMap();
}


Map::~Map(){

}

void Map::m_setMap(){
    free(mapTileArr); //free does not throw exceptions?
    std::string l_mapName = "Map 2";
    m_setMap(l_mapName);
}

void Map::m_setMap(std::string& l_mapName){
    std::cout << "in m_mapSetup" << std::endl;
    std::ifstream mapfile;
    mapfile.open("D:/Programming/C++/Projects/codebloks/bored/assets/maps/maps.txt", std::ifstream::in);
    std::string line;
    std::string delim = "|";
    while(getline(mapfile, line)){
        //search map by name
        if(line.find("MapName|", 0) != std::string::npos){
            std::string mapName = line.substr(8);
            if(mapName != l_mapName){ continue;}
            getline(mapfile, line);
            std::size_t place1 = line.find(delim, 0);
            std::size_t place2 = line.find(delim, place1 + 1);
            std::cout << "place1:" << place1 << "---place2:" << place2 << std::endl;
            std::string length = line.substr(place1 + 1, (place2 - 1) - place1);
            std::string height = line.substr(place2 + 1);
            int i_length = std::stoi(length);
            int i_height = std::stoi(height);
            std::cout << "length:" << i_length << std::endl;
            std::cout << "height:" << i_height << std::endl;
            mapTileArr = (m_TileDef*)calloc(i_length * i_height, sizeof(*mapTileArr));

            // once everything checks out
            m_length = i_length;
            m_height = i_height;
            m_NoOfTiles = m_length * m_height;

            // Writing tile type and positions to tile array.
            getline(mapfile, line); // skip line that say MapLayout
            for(int i = 0; i < m_height; i++){
                getline(mapfile, line);
                for(int j = 0; j < m_length; j++){
                    mapTileArr[(i*m_length) + j].type = line[j];
                    mapTileArr[(i*m_length) + j].posx = j;
                    mapTileArr[(i*m_length) + j].posy = i;
                    std::cout << "type: " << mapTileArr[(i*m_length) + j].type << " posx: " << mapTileArr[(i*m_length) + j].posx << " posy: " << mapTileArr[(i*m_length) + j].posy << std::endl;
                }
            }
            break;
        }

    }
}



int Map::m_pos2array(int posx, int posy){
    int arrIndex = (posy * m_length) + posx;
    if(arrIndex > m_NoOfTiles){
        return 0;
    }
    return arrIndex;
}

char Map::GetTileType(int posx, int posy){
    int index = m_pos2array(posx, posy);
    return mapTileArr[index].type;
}

int Map::GetTileLength(){ return m_length;}
int Map::GetTileHeight(){ return m_height;}
