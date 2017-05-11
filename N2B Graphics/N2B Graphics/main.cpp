#include <GL/glew.h>
#include <GLFW/glfw3.h>

//STL
#include <iostream>

#include "Display.h"
#include "NB_Utility.h"
#include "Shader.h"

int main()
{
	NB::Display display(800, 600, "Window");

	NB::Shader shader("./res/shader/basic_shader");


	while (!glfwWindowShouldClose(&display))
	{
		glfwPollEvents();
		display.clear();


		display.update();
	}
	glfwTerminate();
	exit(EXIT_SUCCESS);
}


