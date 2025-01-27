#include "Scene.h"

void Scene::SetRootObject(BaseObject* bo){
    this->rootObject = bo;
}

BaseObject* Scene::GetRootObject(){
    return this->rootObject;
}