#include "iostream"

// GLM
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"

// Logger
#include "Logger\Logger.h"

// ImGui
#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"
#include "imgui\imgui_impl_opengl3.h"

// OpenGL
// extensions
#include <GL\glew.h>
// windowing and context
#include <GLFW\glfw3.h>

// Demos
#include "Demos\DemoManager.h"
#include "Demos\BSTDemo.h"
#include "Demos\QuadTreeDemo.h"
#include "Demos\TrammelDemo.h"

// Timer
#include "Timer\LPTimer.h"

// Box2D
#include "Box2D\Box2D.h"


int main(int, char**)
{
	Logger::Init(); // init logger -PC
	Logger::GetAppLogger()->info("LOGGER initialized!");

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
	window = glfwCreateWindow(960, 540, "Test Bed", NULL, NULL);
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


		const double MS_PER_UPDATE = 0.008; // Nystrom Pattern: Game Loop


		ImGui::CreateContext();
		ImGui_ImplOpenGL3_Init("#version 330"); // explicit version statement - PC
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui::StyleColorsDark();

		Demo* currentDemo = nullptr;
		DemoManager* demoManager = new DemoManager(currentDemo);
		currentDemo = demoManager;


		demoManager->RegisterDemo<QuadTreeDemo>("QuadTree Demo");
		demoManager->RegisterDemo<BSTDemo>("BinarySearchTree Demo");
		demoManager->RegisterDemo<TrammelDemo>("Trammel of Archimedes Demo");

		// Timer -PC
		LPTimer timer;
		double previousTime = timer.getTime();
		double lag = 0;
		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			// game loop pattern, times -PC
			double currentTime = timer.getTime();
			double elapsedTime = currentTime - previousTime;
			previousTime = currentTime;
			lag += elapsedTime;

			glClearColor(0.3f, 0.3f, 0.3f, 1.0f); // cheap can be removed later -PC
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				
			// UI
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
			if (currentDemo)
			{
				while (lag >= MS_PER_UPDATE)
				{
					currentDemo->Update(MS_PER_UPDATE);
					lag -= MS_PER_UPDATE;
				}
				// Game Loop, Pattern used for decoupling -PC, -Robert Nystrom GPP
				glEnable(GL_DEPTH_TEST);
				currentDemo->Render();
				glDisable(GL_DEPTH_TEST);
				ImGui::Begin("TestBed Demos");
				if (currentDemo != demoManager && ImGui::Button("<-"))
				{
					delete currentDemo;
					currentDemo = demoManager;
				}
				currentDemo->ImGuiRender();
				ImGui::End();
			}

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
		// clean up demos
		delete currentDemo;
		if (currentDemo != demoManager)
		{
			delete demoManager;
		}

	}

	// clean up in general
	ImGui_ImplOpenGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();

	return 0;
}