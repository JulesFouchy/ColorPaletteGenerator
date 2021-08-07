#include "App.h"
#include <Cool/App/Input.h>
#include <Cool/App/RenderState.h>
#include <Cool/Log/ToUser.h>
#include <Cool/Serialization/JsonFile.h>

App::App(Cool::Window& window)
    : _window{window}
{
    Cool::Serialization::from_json(*this, Cool::File::root_dir() + "/last-session-cache.json");
}

App::~App()
{
    Cool::Serialization::to_json(*this, Cool::File::root_dir() + "/last-session-cache.json", "App");
}

void App::update()
{
    render();
}

void App::render()
{
    _renderer.begin();
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    _renderer.end();
}

void App::ImGuiWindows()
{
    Cool::Log::ToUser::imgui_console_window();
    if (!Cool::RenderState::IsExporting()) {
#ifdef DEBUG
        if (_show_imgui_debug) {
            ImGui::Begin("Debug", &_show_imgui_debug);
            ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);
            ImGui::SameLine();
            bool cap_framerate = _window.isVSyncEnabled();
            if (ImGui::Checkbox("Cap framerate", &cap_framerate)) {
                if (cap_framerate) {
                    _window.enableVSync();
                }
                else {
                    _window.disableVSync();
                }
            }
            ImGui::Checkbox("Show Demo Window", &_show_imgui_demo);
            ImGui::End();
        }
        if (_show_imgui_demo) { // Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
            ImGui::ShowDemoWindow(&_show_imgui_demo);
        }
#endif
    }
}

void App::ImGuiMenus()
{
    if (ImGui::BeginMenu("Windows")) {
        Cool::Log::ToUser::imgui_toggle_console();
#ifdef DEBUG
        ImGui::Separator();
        ImGui::Checkbox("Debug", &_show_imgui_debug);
#endif
        ImGui::EndMenu();
    }
}

void App::onKeyboardEvent(int key, int scancode, int action, int mods)
{
    if (!Cool::RenderState::IsExporting() && !ImGui::GetIO().WantTextInput) {
    }
}

void App::onMouseButtonEvent(int button, int action, int mods)
{
    if (!Cool::RenderState::IsExporting() && !ImGui::GetIO().WantCaptureMouse) {
    }
}

void App::onScrollEvent(double xOffset, double yOffset)
{
    if (!Cool::RenderState::IsExporting() && !ImGui::GetIO().WantCaptureMouse) {
    }
}

void App::onMouseMoveEvent(double xpos, double ypos)
{
    if (!Cool::RenderState::IsExporting() && !ImGui::GetIO().WantCaptureMouse) {
    }
}