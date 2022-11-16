#include "Draw.hpp"
#include "SFML/Graphics.hpp"

Draw::Draw(){

}


Draw::~Draw(){

}


void Draw::drawMap(Bus* m_bus){
    int mapLength = m_bus->s_map->GetTileLength();
    int mapHeight = m_bus->s_map->GetTileHeight();
//    double windowLength = m_bus->s_mainWindow->getSize().x;
//    double windowHeight = m_bus->s_mainWindow->getSize().y;
    double windowLength = 800;
    double windowHeight = 600;

    int NoOfTiles = mapLength * mapHeight;
    double tileLength = windowLength / (double)mapLength;
    double tileHeight = windowHeight / (double)mapHeight;

    // set origin positions on window
//    sf::Texture fireTexture;
    static bool g = true;

    m_bus->s_texMan->printTextureCount();
    sf::Texture* fireTexture = m_bus->s_texMan->requestTexture("fireTile");
    m_bus->s_texMan->printTextureCount();

    if(g){
        sf::Texture* dirtTexture = m_bus->s_texMan->requestTexture("dirtTile");
        m_bus->s_texMan->printTextureCount();
        g = false;
    }


    sf::Texture* grassTexture = m_bus->s_texMan->requestTexture("grassTile");
    m_bus->s_texMan->printTextureCount();

//    m_bus->s_texMan->removeTexture("dirtTile");



    sf::Sprite fireSprite;
    sf::Sprite grassSprite;
    fireSprite.setTexture(*fireTexture);
    grassSprite.setTexture(*grassTexture);
//    grassSprite.setTextureRect(sf::IntRect(xOrigin, yOrigin, tileLength, tileHeight));

    for(int y = 0; y < mapHeight; y++){
        for(int x = 0; x < mapLength; x++){
            int index = y * mapLength + x;
            int windowX, windowY;
            double xOrigin = tileLength * x;
            double yOrigin = tileHeight * y;

            char tileType = m_bus->s_map->GetTileType(x, y);

            // spritecreation here
            fireSprite.setTextureRect(sf::IntRect(12, 50, tileLength, tileHeight));

            fireSprite.setPosition(xOrigin, yOrigin);
            grassSprite.setPosition(xOrigin, yOrigin);
            if(tileType == '0'){
                m_bus->s_mainWindow->draw(fireSprite);
            }else if(tileType == '1'){
                m_bus->s_mainWindow->draw(grassSprite);
            }
//            sf::RectangleShape rectangle;
//            rectangle.setSize(sf::Vector2f(tileLength, tileHeight));
//            rectangle.setPosition(sf::Vector2f(xOrigin, yOrigin));
//            rectangle.setOutlineColor(sf::Color::Black);
//            rectangle.setOutlineThickness(5);
//            if(tileType == '0'){
//                rectangle.setFillColor(sf::Color::Red);
//            }else if(tileType == '1'){
//                rectangle.setFillColor(sf::Color::Blue);
//            }
//            m_bus->s_mainWindow->draw(rectangle);
        }
    }
}



