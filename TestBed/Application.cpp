#include "iostream"

#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"


#include <GL\glew.h>
#include <GLFW\glfw3.h>

int main(int, char**)
{
	// Init code to be abstracted -PC
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
	{
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // changed to Core over Compat, VAO`s added -PC

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // sets frame rate = refresh rate

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error!" << std::endl;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;
	{ // this scope exists to deal with the issue of GL`s error being infinite looped - TODO heap allocate so this dose not exist -PC


		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}
	glfwTerminate();

	return 0;
}