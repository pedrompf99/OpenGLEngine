#include "Editor.h"

void Editor::BeginEditor(GLFWwindow* window){
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void Editor::EndEditor(){
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Editor::StartRender(){
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
}

void Editor::EndRender(){
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    ImGui::EndFrame();
}

void Editor::ShowSceneView(Scene* scene){
    ImGui::Begin("Scene View");
    Editor::IterateChildren(scene->GetRootObject());
    ImGui::End();
}

void Editor::IterateChildren(BaseObject* bo){
    for(auto boc : bo->GetChildren()){
        ImGuiTreeNodeFlags flag = ImGuiTreeNodeFlags_DefaultOpen;
        if (boc->GetChildren().size() == 0)
        {
            flag |= ImGuiTreeNodeFlags_Leaf;
        }
        if (ImGui::TreeNodeEx(boc->name.c_str(), flag))
        {
            Editor::IterateChildren(boc);
            ImGui::TreePop();
        } 
    }
}

void Editor::ShowMainMenuBar(){
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open", "CTRL+O")) {}
            if (ImGui::MenuItem("Save", "CTRL+S")) {}
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
            if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "CTRL+X")) {}
            if (ImGui::MenuItem("Copy", "CTRL+C")) {}
            if (ImGui::MenuItem("Paste", "CTRL+V")) {}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}