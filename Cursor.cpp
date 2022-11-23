#include "Cursor.hpp"

Cursor::Cursor(){
    Init();
}

Cursor::~Cursor(){

}

void Cursor::Init(){
    posx = 2;
    posy = 2;
    texName = "Cursor1";
    texture = nullptr;
}

int Cursor::GetPosx(){
    return posx;
}

int Cursor::GetPosy(){
    return posy;
}

std::string Cursor::GetTexName(){
    return texName;
}
