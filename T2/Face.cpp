#include "./include/Face.h"
#include "./include/Sound.h"
#include <iostream>


Face::Face(GameObject & associated) : Component(associated) {
    hitpoints = 30;
}

void Face::Damage(int damage) {
    hitpoints -= damage;
    
    if(hitpoints <= 0) {
        associated.RequestDelete();
        Component *c = associated.GetComponent("Sound");
        if (c) {
            auto *sound = dynamic_cast<Sound *>(c);
            sound->Play(1);
        }
    }
}

void Face::Update(float dt) {

}

void Face::Render() {

}

bool Face::Is(std::string type) {
    return type == "Face";
}