/*
NB_Display:
Attention:
Purpose:
Usage:
*/

#ifdef NB_PRAGMA_ONCE_SUPPORT
#pragma once
#endif
#ifndef NB_DISPLAY_H_INCLUDED
#define NB_DISPLAY_H_INCLUDED


// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

//STL
#include <string>

namespace NB
{
	class NB_Display
	{
	public:
		NB_Display(int width, int height, const std::string title);
		~NB_Display();

		inline void clear()
		{
			glClearColor(0.41f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		inline void update()
		{
			glfwSwapBuffers(this->window);
		}

		GLFWwindow* operator&() const;
	private:
		//no copy
		NB_Display(const NB_Display&) {}
		NB_Display& operator=(const NB_Display&) {}
		//

		void set_up_glfw(int width, int height, const std::string title);
		void set_up_glew();

		GLFWwindow* window;
	};

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void error_callback(int error, const char* description);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void window_size_callback(GLFWwindow* window, int width, int height);
}

#endif //NB_DISPLAY_H_INCLUDED