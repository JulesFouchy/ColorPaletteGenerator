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
        _shader.bind();
        _shader.set_uniform("aspect_ratio", Cool::RenderState::Size().aspectRatio());
        _shader.set_uniform("a", _color_palette.a);
        _shader.set_uniform("b", _color_palette.b);
        _shader.set_uniform("c", _color_palette.c);
        _shader.set_uniform("d", _color_palette.d);
        _renderer.render();
    }
    _renderer.end();
}

void App::ImGuiWindows()
{
    Cool::Log::ToUser::imgui_console_window();
    if (!Cool::RenderState::IsExporting()) {
        ImGui::Begin("Palette");
        ImGui::SliderFloat3("a", glm::value_ptr(_color_palette.a), 0.f, 2.f);
        ImGui::SliderFloat3("b", glm::value_ptr(_color_palette.b), 0.f, 2.f);
        ImGui::SliderFloat3("c", glm::value_ptr(_color_palette.c), 0.f, 2.f);
        ImGui::SliderFloat3("d", glm::value_ptr(_color_palette.d), 0.f, 2.f);
        ImGui::InputText("yo", &_color_palette.to_string());
        ImGui::End();
    }
}

void App::ImGuiMenus()
{
    if (ImGui::BeginMenu("Windows")) {
        Cool::Log::ToUser::imgui_toggle_console();
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