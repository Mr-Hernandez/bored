#include "Draw.hpp"
#include "SFML/Graphics.hpp"

Draw::Draw(){

}


Draw::~Draw(){

}


void Draw::drawMap(Bus* m_bus){
    int mapLength = m_bus->s_map->GetTileLength();
    int mapHeight = m_bus->s_map->GetTileHeight();
    double windowLength = 800;
    double windowHeight = 800;
    int NoOfTiles = mapLength * mapHeight;
    double tileLength = windowLength / (double)mapLength;
    double tileHeight = windowHeight / (double)mapHeight;

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


sf::Vector2f Draw::pos2Orig(int posx, int posy, Bus* m_bus){
    double windowLength = 800;
    double windowHeight = 800;
    int mapLength = m_bus->s_map->GetTileLength();
    int mapHeight = m_bus->s_map->GetTileHeight();
    float tileLength = windowLength / (double)mapLength;
    float tileHeight = windowHeight / (double)mapHeight;
    float xOrigin = tileLength * posx;
    float yOrigin = tileHeight * posy;
    sf::Vector2f windowCoordinates = sf::Vector2f(xOrigin, yOrigin);
    return windowCoordinates;
}




