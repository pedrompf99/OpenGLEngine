#include "BaseObject.h"

const void BaseObject::AddChild(BaseObject* bo){
    this->children.push_back(bo);
}

const std::vector<BaseObject*> BaseObject::GetChildren(){
    return this->children;
}

const void BaseObject::AddComponent(Component* c){
    this->components.push_back(c);
}

const std::vector<Component*> BaseObject::GetComponents(){
    return this->components;
}