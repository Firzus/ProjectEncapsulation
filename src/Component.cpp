#include "Component.h"

void Component::createEntity(std::string label, Entity* entity)
{
    if (entities.find(label) != entities.end()) {
        return;
    }
}

void Component::deleteEntity(const std::string& label)
{
    std::unordered_map<std::string, Entity*>::iterator it = entities.find(label);
    if (it != entities.end()) {
        delete it->second;
        entities.erase(it);
    }
}