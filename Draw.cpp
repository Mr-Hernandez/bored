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

    sf::Texture* pPathVertical, *pPathHorizontal, *pPathArrow, *pPathTurn;
    pPathVertical = m_bus->s_texMan->requestTexture("pathLine");
    pPathHorizontal = m_bus->s_texMan->requestTexture("pathLine");
    pPathArrow = m_bus->s_texMan->requestTexture("pathArrow");
    pPathTurn = m_bus->s_texMan->requestTexture("pathTurn");
    if(pPathArrow == nullptr || pPathVertical == nullptr || pPathHorizontal == nullptr || pPathTurn == nullptr){ return;} // log error
    sf::Sprite vertSprite, horizSprite, arrowSprite, turnSprite;
    vertSprite.setTexture(*pPathVertical);
    horizSprite.setTexture(*pPathHorizontal);
    arrowSprite.setTexture(*pPathArrow);
    turnSprite.setTexture(*pPathTurn);

    bool firstFlag = true;
    for(int i = pathConSize; i > 0; i--){ // pathconsize returns valid index value
        // next
        sf::Vector2i current = m_bus->s_pathFinder->GetPos(i);
        sf::Vector2i previous = m_bus->s_pathFinder->GetPos(i-1);
        sf::Vector2i previous2;
        if(i >= 2 && i != pathConSize){ previous2 = m_bus->s_pathFinder->GetPos(i+1);}
        else{ previous2 = sf::Vector2i(-1,-1);}
//        m_bus->s_pathFinder->PrintPath();
        if(firstFlag){
            // logic for direction of arrow
            pathRotator(current, previous, &arrowSprite, m_bus);
            firstFlag = false;
        }else if(current.x != previous.x){
            // if turntrue then turnRotator, else pathRotator
            if(IsTurn(current, previous, previous2)){
                turnRotator(current, previous, previous2, &turnSprite, m_bus);
            }else{
                pathRotator(current, previous, &horizSprite, m_bus);
            }
        }else if(current.y != previous.y){
            if(IsTurn(current, previous, previous2)){
                turnRotator(current, previous, previous2, &turnSprite, m_bus);
            }else{
                pathRotator(current, previous, &vertSprite, m_bus);
            }
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

float Draw::degRotation(sf::Vector2i currentPos, sf::Vector2i previousPos){
//    if(currentPos.x != previousPos.x){
        if(currentPos.y < previousPos.y){
            return 0.f;
        }else if(currentPos.y > previousPos.y){
            return 180.f;
        }
//    }
//    if(currentPos.y != previousPos.y){
        if(currentPos.x < previousPos.x){
            return 270.f;
        }else if(currentPos.x > previousPos.x){
            return 90.f;
        }
//    }
    return 0.f;
}

void Draw::pathRotator(sf::Vector2i current, sf::Vector2i previous, sf::Sprite* sprite, Bus* m_bus){
    sf::Vector2f normalOrigin = sf::Vector2f(0.f,0.f);
    sf::Vector2f rotateOrigin = sf::Vector2f(64.f,64.f);
    float rotation = degRotation(current, previous);
    sprite->setOrigin(rotateOrigin);
    sprite->setRotation(rotation);
    if(rotation == 0.f){ sprite->setOrigin(normalOrigin);}
    else if(rotation == 90.f){ sprite->setOrigin(normalOrigin.x, normalOrigin.y + 128.f);}
    else if(rotation == 180.f){ sprite->setOrigin(normalOrigin.x + 128.f, normalOrigin.y + 128.f);}
    else if(rotation == 270.f){ sprite->setOrigin(normalOrigin.x + 128.f, normalOrigin.y);}
    sprite->setPosition(pos2Orig(current.x, current.y, m_bus));
    m_bus->s_mainWindow->draw(*sprite);
}

void Draw::turnRotator(sf::Vector2i current, sf::Vector2i previous, sf::Vector2i previous2, sf::Sprite* sprite, Bus* m_bus){
    sf::Vector2f rotateOrigin = sf::Vector2f(64.f,64.f);
    sprite->setOrigin(rotateOrigin);
    if((previous.x < previous2.x) && (previous.x < current.x)){
        //config 1
        if(previous2.y < current.y){
            //180 deg
            sprite->setRotation(180.f);
            sprite->setOrigin(normOrigin(180));
        }else if(previous2.y > current.y){
            //90 deg
            sprite->setRotation(90.f);
            sprite->setOrigin(normOrigin(90));
        }
    }
    if((previous.x > previous2.x) && (previous.x > current.x)){
        // config 2
        if(previous2.y > current.y){
            //0 deg
            sprite->setRotation(0.f);
            sprite->setOrigin(normOrigin(0));
        }else if(previous2.y < current.y){
            //270 deg
            sprite->setRotation(270.f);
            sprite->setOrigin(normOrigin(270));
        }
    }
    if((previous.y < previous2.y) && (previous.y < current.y)){
        // config 3
        if(previous2.x < current.x){
            //180
            sprite->setRotation(180.f);
            sprite->setOrigin(normOrigin(180));
        }else if(previous2.x > current.x){
            //270
            sprite->setRotation(270.f);
            sprite->setOrigin(normOrigin(270));
        }
    }
    if((previous.y > previous2.y) && (previous.y > current.y)){
        // config 4
        if(previous2.x < current.x){
            //90 deg
            sprite->setRotation(90.f);
            sprite->setOrigin(normOrigin(90));
        }else if(previous2.x > current.x){
            //0 deg
            sprite->setRotation(0.f);
            sprite->setOrigin(normOrigin(0));
        }
    }
    sprite->setPosition(pos2Orig(current.x, current.y, m_bus));
    m_bus->s_mainWindow->draw(*sprite);
}

bool Draw::IsTurn(sf::Vector2i current, sf::Vector2i previous, sf::Vector2i previous2){
    if(previous2.x == -1 || previous2.y == -1){ return false;}
    if((previous2.x != previous.x) && (previous2.y != previous.y)){ return true;}
    return false;
}

sf::Vector2f Draw::normOrigin(int degreesTurned){
    if(degreesTurned == 90){ return sf::Vector2f(0.f, 128.f);}
    else if(degreesTurned == 180){ return sf::Vector2f(128.f, 128.f);}
    else if(degreesTurned == 270){ return sf::Vector2f(128.f, 0.f);}
    else return sf::Vector2f(0.f, 0.f);


}



