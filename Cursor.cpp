#include "Cursor.hpp"

Cursor::Cursor(){
    Init();
}

Cursor::~Cursor(){

}

void Cursor::Init(){
    posx = 0;
    posy = 0;
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


void Cursor::MoveUp(){
    posy--;
    if(posy < 0){ posy = 0;}
}

void Cursor::MoveDown(){
    posy++;
    // logic taken care of outside of this
}

void Cursor::MoveLeft(){
    posx--;
    if(posx < 0){ posx = 0;}
}

void Cursor::MoveRight(){
    posx++; // logic for this is outside
}
