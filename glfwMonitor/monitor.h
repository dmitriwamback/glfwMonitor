#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow* window;
bool isRetinaDisplay;
int viewportMultipler;
int WINDOWSIZE_X;
int WINDOWSIZE_Y;

void Init() {

    if (!glfwInit()) throw std::runtime_error("Couldn't initialize GLFW");
    /*
        Initialize window here
        ...
        ...
    */
}

void SetViewportSize() {

    //glfwViewport();
}

void SetFramebufferSize() {

    /*
        // Bind Framebuffer
        ...
        ...
        ===>>>> glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, WINDOWSIZE_X*multiplier, WINDOWSIZE_Y*multiplier, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        ===>>>> glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, WINDOWSIZE_X*multiplier, WINDOWSIZE_Y*multiplier);
        ...

        // Unbind Framebuffer
    */
}

void Loop() {

    while (!glfwWindowShouldClose(window)) {

        int count;
        int monitorxPosition, xWindowPosition;
        int monitoryPosition, yWindowPosition;
        GLFWmonitor** monitors = glfwGetMonitors(&count);
        GLFWmonitor* focusedMonitor;

        for (int i = 0; i < count; i++) {
            glfwGetMonitorPos(monitors[i], &monitorxPosition, &monitoryPosition);
            glfwGetWindowPos(doaWindow, &xWindowPosition, &yWindowPosition);

            if (xWindowPosition > monitorxPosition - 100) focusedMonitor = monitors[i];
        }
        const char* name = glfwGetMonitorName(focusedMonitor);
        isRetinaDisplay = std::string(name).find("Retina") != std::string::npos ? true : false;
        multipler = isRetinaDisplay == true ? 2 : 1;

        glfwGetWindowSize(window, &WINDOWSIZE_X, &WINDOWSIZE_Y);
        SetFramebufferSize();
    }
}