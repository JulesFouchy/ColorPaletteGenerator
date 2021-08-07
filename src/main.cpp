
#include <Cool/App/AppManager.h>
#include <Cool/App/WindowFactory.h>
#include <Cool/Core/initialize.h>
#include "App.h"

void main()
{
    Cool::initialize();
    // Init Glfw and set OpenGL version
#if defined(__APPLE__)
    Cool::WindowFactory window_factory(
        3, 3); // OpenGL > 3.3 is not supported on MacOS
#else
    Cool::WindowFactory window_factory(4, 3);
#endif
    // Create the main window and init OpenGL
    Cool::Window& window = window_factory.create("Palette Generator", 1280, 720);
    glfwMaximizeWindow(window.get());
    // App
    App              app(window);
    Cool::AppManager appManager(window, app);
    appManager.run();
}