#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include "../Scene/Scene.h"

class Editor {
    public:
        static void BeginEditor(GLFWwindow* window);
        static void EndEditor();
        static void StartRender();
        static void EndRender();
        static void ShowMainMenuBar();
        static void ShowSceneView(Scene* scene);
    private:
        static void IterateChildren(BaseObject* bo);
};