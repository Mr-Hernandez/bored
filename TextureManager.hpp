#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <utility>
#include <forward_list>
#include <fstream>

/*ABOUT THE TEXTURE ALLOCATING AND DEALLOCATING
* When requestTexture() is called and the texName matches,
  then the count is examined.
  0 means load the texture and set count value to 2
  1 means don't load texture but set count value to 2

  The deallocating function, cleanTextures(), works as follows.
  It iterates through all the texInfo members and reads the count value
  0 means texture is not allocated and so no deallocation is needed
  1 means texture is allocated but was not requested in past frame so deallocate it
  2 means texture is allocated and was requested in previous frame,
    so do not deallocate and set count value to 1.

  This works because if texture is not requested, the count value 1 is not incremented to 2
  so the next pass around cleanTextures() will see the value 1 and deallocate the texture.
*/


class TextureManager{
public:
    TextureManager();
    ~TextureManager();

    sf::Texture* requestTexture(const std::string& texName);
    void removeTexture(const std::string& texName);

    void printTextureCount();
    void cleanTextures();

private:
    void loadList();
    void printList();
    void loadTexture(const std::string& l_path, std::forward_list<std::pair<std::string, std::pair<std::string, std::pair<std::forward_list<sf::Texture>::iterator, int>>>>::iterator i);

    sf::Texture* texTest;
    std::pair<std::string, std::pair<std::string, std::pair<std::forward_list<sf::Texture>::iterator, int>>> texData; // <name, <path, <texture, count>>>
    std::forward_list<std::pair<std::string, std::pair<std::string, std::pair<std::forward_list<sf::Texture>::iterator, int>>>> texInfo;
    std::forward_list<sf::Texture> texContainer;
};

#endif // TEXTUREMANAGER_H
