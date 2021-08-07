#pragma once

#include <Cool/App/IApp.h>
#include <Cool/App/Window.h>
#include <Cool/OpenGL/Shader.h>
#include <Cool/Renderer_Fullscreen/Renderer_Fullscreen.h>
#include "ColorPalette/ColorPalette.h"

class App : public Cool::IApp {
public:
    App(Cool::Window& window);
    ~App();

    void update() override;
    void ImGuiWindows() override;
    void ImGuiMenus() override;
    void onKeyboardEvent(int key, int scancode, int action, int mods) override;
    void onMouseButtonEvent(int button, int action, int mods) override;
    void onScrollEvent(double xOffset, double yOffset) override;
    void onMouseMoveEvent(double xPos, double yPos) override;

private:
    void render();

private:
    Cool::Window&             _window;
    Cool::Renderer_Fullscreen _renderer;
    ColorPalette              _color_palette;
    Cool::Shader              _shader{"Cool/res/shaders/fullscreen.vert", "shaders/color_palette.frag"};

private:
    // Serialization
    friend class cereal::access;
    template<class Archive>
    void serialize(Archive& archive)
    {
        archive(cereal::make_nvp("Color Palette", _color_palette));
    }
};