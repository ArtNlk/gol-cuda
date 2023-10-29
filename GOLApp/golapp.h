#ifndef GOLAPP_H
#define GOLAPP_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "golcpu.h"

class GOLApp
{
public:
    GOLApp(size_t width, size_t height);
    ~GOLApp();

    int run();
protected:
    void renderGui();

    void updateTexture();

    GOLCpu m_gol;

    GLuint m_texture;

    size_t m_width;
    size_t m_height;
    ImGuiIO* m_io;
    GLFWwindow* m_window;
};

#endif // GOLAPP_H
