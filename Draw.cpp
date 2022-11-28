#include "Draw.hpp"
#include "SFML/Graphics.hpp"

Draw::Draw(){

}

Draw::Draw(int l_winH, int l_winW) : m_winH(l_winH), m_winW(l_winW){

}


Draw::~Draw(){

}


void Draw::drawMap(Bus* m_bus){
    int mapLength = m_bus->s_map->GetTileLength();
    int mapHeight = m_bus->s_map->GetTileHeight();
//    double windowLength = 800;
//    double windowHeight = 800;
    double windowLength = (double)m_winW;
    double windowHeight = (double)m_winH;
//    int NoOfTiles = mapLength * mapHeight;
    double tileLength = windowLength / (double)mapLength;
    double tileHeight = windowHeight / (double)mapHeight;
//    std::cout << "windowLength: " << windowLength << "|mapLength: " << mapLength << std::endl;

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

    sf::Sprite fireSprite;
    sf::Sprite grassSprite;
    fireSprite.setTexture(*fireTexture);
    grassSprite.setTexture(*grassTexture);

    for(int y = 0; y < mapHeight; y++){
        for(int x = 0; x < mapLength; x++){
//            int index = y * mapLength + x;
//            int windowX, windowY;
            double xOrigin = tileLength * x;
            double yOrigin = tileHeight * y;
            xOrigin = 128 * x;
            yOrigin = 128 * y; // hardcode test
//            std::cout << "x: " << xOrigin << "|y: " << yOrigin << std::endl;

            char tileType = m_bus->s_map->GetTileType(x, y);

            // spritecreation here
//            fireSprite.setTextureRect(sf::IntRect(12, 50, tileLength, tileHeight));

//            fireSprite.setPosition(xOrigin, yOrigin);
//            grassSprite.setPosition(xOrigin, yOrigin);
            fireSprite.setPosition(pos2Orig(x, y, m_bus));
            grassSprite.setPosition(pos2Orig(x, y, m_bus));
            if(tileType == '0'){
                m_bus->s_mainWindow->draw(fireSprite);
            }else if(tileType == '1'){
                m_bus->s_mainWindow->draw(grassSprite);
            }
        }
    }
}


void Draw::drawCharacter(const std::string drawThisChar, Bus* m_bus){

    // Who chooses which characters should be drawn?
    // Who assigns the characters their textures?
    // Who chooses character's default location?

    int array_size = m_bus->s_character->GetArrSize();
    if(array_size == 0){ return;}

//    // Hardcoded for test.
//    std::string drawThisChar = "Seras Victoria";

    // Here we find the corresponding name and texture but
    // hardcode the texturerequest which should be done elsewhere.
    // Maybe even just in another function that is called first.
    for(int i = 0; i < array_size; i++){
        if(drawThisChar == m_bus->s_character->GetCharName(i)){
//            std::cout << "Gettexname: " << m_bus->s_character->GetTexName(i) << std::endl;
            sf::Texture* char1 = m_bus->s_texMan->requestTexture(m_bus->s_character->GetTexName(i));
            if(char1 == nullptr){ return;} // log failure here
            int posx = m_bus->s_character->GetPosx(i);
            int posy = m_bus->s_character->GetPosy(i);
            sf::Sprite sprite;
            sprite.setTexture(*char1);
            sprite.setPosition(pos2Orig(posx, posy, m_bus));
            m_bus->s_mainWindow->draw(sprite);
            break;
        }
    }
}


void Draw::drawCursor(Bus* m_bus){
    sf::Texture* pCursorTexture = m_bus->s_texMan->requestTexture(m_bus->s_cursor->GetTexName());
    if(pCursorTexture == nullptr){ std::cout << "drawCursor Error\n"; return;} // log error
    int posx = m_bus->s_cursor->GetPosx();
    int posy = m_bus->s_cursor->GetPosy();
    sf::Sprite cursorSprite;
    cursorSprite.setTexture(*pCursorTexture);
    cursorSprite.setPosition(pos2Orig(posx, posy, m_bus));
    m_bus->s_mainWindow->draw(cursorSprite);
}


void Draw::drawPath(Bus* m_bus){
    int pathConSize = m_bus->s_pathFinder->GetContainerSize();
//    std::cout << "Pos Container Size: " << pathConSize << std::endl;
    if(pathConSize <= 1){ return;}

    sf::Texture* pPathVertical, *pPathHorizontal, *pPathArrow;
    pPathVertical = m_bus->s_texMan->requestTexture("pathLine");
    pPathHorizontal = m_bus->s_texMan->requestTexture("pathLine");
    pPathArrow = m_bus->s_texMan->requestTexture("pathArrow");
    if(pPathArrow == nullptr || pPathVertical == nullptr || pPathHorizontal == nullptr){ return;} // log error
    sf::Sprite vertSprite, horizSprite, arrowSprite;
    vertSprite.setTexture(*pPathVertical);
    horizSprite.setTexture(*pPathHorizontal);
    arrowSprite.setTexture(*pPathArrow);

    bool firstFlag = true;
    for(int i = pathConSize; i > 0; i--){
        // next
        sf::Vector2i current = m_bus->s_pathFinder->GetPos(i);
        sf::Vector2i previous = m_bus->s_pathFinder->GetPos(i-1);
//        m_bus->s_pathFinder->PrintPath();
        if(firstFlag){
            // logic for direction of arrow
            arrowSprite.setPosition(pos2Orig(current.x, current.y, m_bus));
            m_bus->s_mainWindow->draw(arrowSprite);
            firstFlag = false;
        }else if(current.x != previous.x){
            horizSprite.setPosition(pos2Orig(current.x, current.y, m_bus));
            m_bus->s_mainWindow->draw(horizSprite);
        }else if(current.y != previous.y){
            vertSprite.setPosition(pos2Orig(current.x, current.y, m_bus));
            m_bus->s_mainWindow->draw(vertSprite);
        }
    }
}


sf::Vector2f Draw::pos2Orig(int posx, int posy, Bus* m_bus){
//    double windowLength = 800;
//    double windowHeight = 800;
    float pxWidth = 128;
    float pxHeight = 128;
    double windowLength = (double)m_winW;
    double windowHeight = (double)m_winH;
    int mapLength = m_bus->s_map->GetTileLength();
    int mapHeight = m_bus->s_map->GetTileHeight();
    float tileLength = windowLength / (double)mapLength;
    float tileHeight = windowHeight / (double)mapHeight;
//    float xOrigin = tileLength * posx;
//    float yOrigin = tileHeight * posy;
    float xOrigin = pxWidth * posx;
    float yOrigin = pxHeight * posy;
    sf::Vector2f windowCoordinates = sf::Vector2f(xOrigin, yOrigin);
    return windowCoordinates;
}




