#include "./include/GameObject.h"
#include <iostream>
#include <algorithm>

GameObject::GameObject() {
    isDead = false;
}

GameObject::~GameObject() {
    components.clear();
}

void GameObject::Update(float dt) {
    for (auto &c: components) {
        c->Update(dt);
    }
}

void GameObject::Render() {
    for (auto &c: components) {
        c->Render();
    }
}

bool GameObject::IsDead() {
    return isDead;
}

void GameObject::RequestDelete() {
    isDead = true;
}

void GameObject::AddComponent(Component* cpt) {
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt) {
    std::vector <Component*>::iterator p = std::find(components.begin(), components.end(), cpt);
    if (p != components.end())
        components.erase(p);
}

Component * GameObject::GetComponent(std::string type) {
    for (auto &c: components) {
        if (c->Is(type)) {
            return c;
        }
    }
    return nullptr;
}