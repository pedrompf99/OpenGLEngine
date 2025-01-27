#pragma once
#include "../Object/BaseObject.h"
class Scene{
    private:
        BaseObject* rootObject;
    public:
        void SetRootObject(BaseObject* bo);
        BaseObject* GetRootObject();
};
