#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Log.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);

int main()
{
	// Initialise GLFW
	if (glfwInit() == GL_FALSE)
	{
		ERROR("Failed to init GLFW");
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create the window
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
	if (window == NULL)
	{
		ERROR("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialise GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ERROR("Failed to initialise GLAD");
		return -1;
	}

	// Initliase the OpenGL viewport to the same size as the window
	// that was created by GLFW
	glViewport(0, 0, 800, 600);

	// Override the default callback function for all window
	// resize events
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Render loop
	while (!glfwWindowShouldClose(window))
	{
		// Handle user input
		process_input(window);

		// Rendering
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Check and call events and swap the buffers
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	// Cleanup GLFW
	glfwTerminate();

	return 0;
}

// Custom callback that just resizes the OpenGL viewport to
// the new window size.
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	std::cout << "Resizing OpenGL viewport to " << width << "x" << height << std::endl;
	glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}