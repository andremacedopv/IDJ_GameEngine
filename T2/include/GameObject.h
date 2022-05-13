#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject;

#include <string>
#include <vector>
#include "Component.h"
#include "Rect.h"

class GameObject {
private:
    bool isDead;

public:
    std::vector <Component*> components;
    Rect box;

    GameObject();
    ~GameObject();

    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    Component * GetComponent(std::string type);

};

#endif