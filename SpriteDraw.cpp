#include "SpriteDraw.hpp"

SpriteDraw::SpriteDraw(){}

SpriteDraw::~SpriteDraw(){}

void SpriteDraw::drawRandomCircle(sf::RenderWindow* l_window){
    // Providing a seed value
	srand((unsigned) time(NULL));
    int random = (rand() % 801);
    srand((unsigned) time(NULL));
    int random2 = (rand() % 601);
//    int random = 300;
//    int random2 = 300;

    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp")){
        //exit
    }
    static float posx = 0;
    static float posy = 0;
    sf::Sprite sprite(texture);
//    sprite.setPosition((float)random, (float)random2);
    sprite.setPosition(posx, posy);
    l_window->draw(sprite);
    posx += 0.2;
    posy += 0.2;
    if(posx > 800){ posx = 0;}
    if(posy > 600){ posy = 0;}
}
