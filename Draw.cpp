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
    double windowHeight = 600;
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


void Draw::drawCharacter(Bus* m_bus){

    // Who chooses which characters should be drawn?
    // Who assigns the characters their textures?
    // Who chooses character's default location?

    int array_size = m_bus->s_character->GetArrSize();

    // Hardcoded for test.
    std::string drawThisChar = "Seras Victoria";

    // Here we find the corresponding name and texture but
    // hardcode the texturerequest which should be done elsewhere.
    // Maybe even just in another function that is called first.
    for(int i = 0; i < array_size; i++){
        if(drawThisChar == m_bus->s_character->GetCharName(i)){
            std::cout << "Gettexname: " << m_bus->s_character->GetTexName(i) << std::endl;
            sf::Texture* char1 = m_bus->s_texMan->requestTexture(m_bus->s_character->GetTexName(i));
            sf::Sprite serasVictoriaSprite;
            serasVictoriaSprite.setTexture(*char1); // I can check if nullptr here
            m_bus->s_mainWindow->draw(serasVictoriaSprite);
            break;
        }
    }

}



