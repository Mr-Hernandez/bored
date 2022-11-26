#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>

// Once this object is created m_mapsetup() is called in the constructor.
// This will read a file containing map data and store it.
// Though the idea is that a map name should be called in order to make
// choosing the map possible. Also must handle deallocating previous data.

class Map{
public:
    Map();
    ~Map();
    /*
    getTileType();
    getMapSize();
    getMapName();
    m_mapSetup(std::string& l_mapName);
    */
    char GetTileType(int posx, int posy);
    void m_setMap(std::string& mapName);
    int GetTileLength();
    int GetTileHeight();



private:
    int m_NoOfTiles;
    int m_length, m_height;
    std::string m_mapName;

    struct m_TileDef{
        char type;
        int posx;
        int posy;
        bool occupied;
    };

    void m_setMap();

    // Tools
    int m_pos2array(int posx, int posy); //return index for a tile in tile array

    // remember to deallocate when setting up new map.
public: m_TileDef* mapTileArr;

};
#endif // MAP_H
