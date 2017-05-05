#include <GL/glew.h>
#include <GLFW/glfw3.h>

//STL
#include <iostream>

#include "Display.h"


int main()
{
	NB::Display display(800, 600, "Window");

	while (!glfwWindowShouldClose(&display))
	{
		glfwPollEvents();

		display.clear();

		glfwSwapBuffers(&display);
	}
	glfwTerminate();
	exit(EXIT_SUCCESS);
}


