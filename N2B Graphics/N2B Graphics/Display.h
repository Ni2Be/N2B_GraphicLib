#pragma once

// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

//STL
#include <iostream>
#include <string>

namespace NB
{
	class Display
	{
	public:
		Display(int width, int height, const std::string title);
		~Display();

		void clear();
		void update();

		GLFWwindow* operator&() const;
	private:
		GLFWwindow* window;
	};

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void error_callback(int error, const char* description);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void window_size_callback(GLFWwindow* window, int width, int height);
}