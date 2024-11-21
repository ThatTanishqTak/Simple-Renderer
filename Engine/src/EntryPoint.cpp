#include "EntryPoint.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow* window;

void EntryPoint::Init()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1080, 720, "Simple Renderer", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
}

void EntryPoint::Run()
{
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.8f, 0.3f, 0.2f, 1.0f);
		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}

void EntryPoint::Shutdown()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}