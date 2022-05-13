#ifndef COMPONENT_H_
#define COMPONENT_H_

class Component;

#include "GameObject.h"
#include <string>

class Component {
public:
    GameObject &associated;

    explicit Component(GameObject & a);
    virtual ~Component();

    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual bool Is(std::string type) = 0;
};

#endif