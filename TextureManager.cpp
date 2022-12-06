#include "TextureManager.hpp"

TextureManager::TextureManager(){
    loadList();
    printList();
}


TextureManager::~TextureManager(){

}

sf::Texture* TextureManager::requestTexture(const std::string& texName){
    std::cout << "tman:requestTexture(): " << texName << std::endl;
    for(auto i = texInfo.begin(); i != texInfo.end(); ++i){
        // check if it exists
        // load if needed
        // add to tally
         if(texName == i->first){
            if(i->second.second.second == 0){
                loadTexture(i->second.first, i);
                i->second.second.second = 2;
            }else if(i->second.second.second == 1){
                // no load but set count to 2
                i->second.second.second = 2;
            }
//            std::cout << "request found for: " << texName << std::endl;
            return &(*(i->second.second.first));
        }
        //else error, file name not found
    }
    return nullptr; // change later
}


void TextureManager::loadList(){
    std::cout << "tman:loadList()" << std::endl;
    std::ifstream texList;
    texList.open("D:/Programming/C++/Projects/codebloks/bored/assets/textures/texturesList.txt");
    std::string line;
    std::string delim = "|";
    while(getline(texList, line)){
        std::size_t pos = line.find(delim, 0);
        std::string texName = line.substr(0, pos);
        std::string texPath = line.substr(pos + 1);
        if(texInfo.begin() == texInfo.end()){
            texData.first = texName;
            texData.second.first = texPath;
            texData.second.second.second = 0;
            texInfo.emplace_front(texData.first, texData.second);
//            texInfo.push_front(texData.first, texData.second);

            continue;
        }
        bool isContinue = false;
        for(auto i = texInfo.begin(); i != texInfo.end(); ++i){
            if(i->first == texName){
                // error, log error
                isContinue = true;
                break;
            }
        }
        if(isContinue){ continue;}
        texData.first = texName;
        texData.second.first = texPath;
        texData.second.second.second = 0;
        texInfo.push_front(texData);
    }
}

void TextureManager::loadTexture(const std::string& l_path, std::forward_list<std::pair<std::string, std::pair<std::string, std::pair<std::forward_list<sf::Texture>::iterator, int>>>>::iterator i){
    std::cout << "l_path is: " << l_path << std::endl;
    sf::Texture texture;
    texture.loadFromFile(l_path);
    texContainer.push_front(texture);
    i->second.second.first = texContainer.begin();
    auto test = texContainer.begin();
    ;
    // check if texture exists? already happened?
    // add texture to actual texture container
    // set pointer to this location

//    texture.loadFromFile(i->second.first);

}


void TextureManager::printList(){
    std::cout << "TEXTURE LIST __________________________" << std::endl;
    for(auto i = texInfo.begin(); i != texInfo.end(); ++i){
        std::cout << "Name---: " << i->first << std::endl;
        std::cout << "Path: " << i->second.first << std::endl;
        std::cout << "Count: " << i->second.second.second << std::endl;
    }
}


void TextureManager::printTextureCount(){
    int textureCount = 0;
    for(auto i = texContainer.begin(); i != texContainer.end(); ++i){
        textureCount++;
    }
    std::cout << "TextureCount: " << textureCount << std::endl;
}


void TextureManager::removeTexture(const std::string& texName){
    std::cout << "tman:removeTexture()" << std::endl;

    if(texContainer.empty()){ return;}

    for(auto i = texInfo.begin(); i != texInfo.end(); ++i){ // iterator for texInfo
        if(texName == i->first){
            auto texContainerIterator = (i->second.second.first); // iterator for texcontainer
            std::cout << "removing texture" << std::endl;
            auto prevIt = texContainer.begin();
            for(auto it = texContainer.begin(); it != texContainer.end(); ++it){
                if(it == texContainerIterator){
                    texContainer.erase_after(prevIt);
                    return;
                }else{
                    prevIt = it;
                }
            }
            break;
        }
    }
}


void TextureManager::cleanTextures(){
    std::cout << "tman:cleanTextures()" << std::endl;

    if(texContainer.empty()){ return;}

    for(auto i = texInfo.begin(); i != texInfo.end(); ++i){ // iterator for texInfo
//        if(i->second.second.second == 0 || i->second.second.second == 1){

        if(i->second.second.second == 1){
            auto texContainerIterator = (i->second.second.first); // iterator for texcontainer
            auto prevIt = texContainer.begin();
            for(auto it = texContainer.begin(); it != texContainer.end(); ++it){
                if(it == texContainerIterator){
                    std::cout << "removing texture: " << i->first << std::endl;
//                    if(i->second.second.first == texContainer.end()){
//                        continue;
//                    }
                    if(it == texContainer.begin()){
                        texContainer.pop_front();
//                        i->second.second.first = texContainer.end();
                    }else{
                        texContainer.erase_after(prevIt);
                        i->second.second.first = texContainer.end();
                    }
                    i->second.second.second = 0; // resets texture state to unloaded
                    break;
                }else{
                    prevIt = it;
                }
            }
            break;
        }
        else if(i->second.second.second == 2){
            i->second.second.second = 1;
        }
    }
}
