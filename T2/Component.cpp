#include "./include/GameObject.h"
#include "./include/Component.h"

Component::Component(GameObject & a) : associated(a) {}

Component::~Component() = default;

void Component::Update(float dt) {}

void Component::Render() {}
