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
        _shader.set_uniform("min_val", _color_palette.min_val);
        _shader.set_uniform("max_val", _color_palette.max_val);
        _shader.set_uniform("frequency", _color_palette.frequency);
        _shader.set_uniform("phase", _color_palette.phase);
        _renderer.render();
    }
    _renderer.end();
}

void App::ImGuiWindows()
{
    Cool::Log::ToUser::imgui_console_window();
    if (!Cool::RenderState::IsExporting()) {
        ImGui::Begin("Palette");
        ImGui::SliderFloat3("min_val", glm::value_ptr(_color_palette.min_val), 0.f, 1.f);
        ImGui::SliderFloat3("max_val", glm::value_ptr(_color_palette.max_val), 0.f, 1.f);
        ImGui::SliderFloat3("frequency", glm::value_ptr(_color_palette.frequency), 0.f, 4.f);
        ImGui::SliderFloat3("phase", glm::value_ptr(_color_palette.phase), 0.f, 1.f);
        if (ImGui::Button("Copy to clipboard")) {
            glfwSetClipboardString(_window.get(), _color_palette.to_string().c_str());
        }
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