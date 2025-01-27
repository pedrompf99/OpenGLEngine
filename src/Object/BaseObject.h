#include <vector>
#include <string>
#include "Component/Component.h"

class BaseObject{
    private:
        std::vector<BaseObject*> children;
        std::vector<Component*> components;
    public:
        const void AddChild(BaseObject* bo);
        const std::vector<BaseObject*> GetChildren();
        const void AddComponent(Component* c);
        const std::vector<Component*> GetComponents();
        std::string name;
};