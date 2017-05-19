/*
NB_Display:
Attention:
Purpose:
	Holds the window and anything that is 
	displayed on it (not at the moment)
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

//
#include "NB_Camera.h"
#include "NB_Light.h"

namespace NB
{
	class NB_Display
	{
	public:
		NB_Display(int width, int height, const std::string title);
		~NB_Display();

		inline void clear()
		{
			glClearColor(background_color.r, background_color.g, background_color.b, background_color.a);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		inline void update()
		{
			current_frame = glfwGetTime();
			delta_time = static_cast<GLfloat>(current_frame - last_frame);
			last_frame = current_frame;

			glfwSetWindowTitle(window, std::to_string(1 / delta_time).c_str());

			glfwSwapBuffers(this->window);
		}

		GLFWwindow* operator&() const;

		NB::NB_Camera cam1;
		void camera_movement();
		void set_background_color(glm::vec4& color);
		void set_background_color(NB::NB_Ambient_light& ambient);
	private:
		glm::vec4 background_color;

		//no copy
		NB_Display(const NB_Display&) 
			:cam1(45.0f, (GLfloat)1 / (GLfloat)1, 0.1f, 1000.0f){}
		NB_Display& operator=(const NB_Display&) {}
		//

		void set_up_glfw(int width, int height, const std::string title);
		void set_up_glew();

		//Movement / physics
		bool keys[1024];
		bool mouse_buttons[8];
		//time frames
		GLfloat delta_time;
		double current_frame;
		double last_frame;
		//mouse pos
		GLfloat last_x;
		GLfloat last_y;
		GLfloat sensitivity;
		GLfloat x_offset;
		GLfloat y_offset;
		//Cam
		GLfloat yaw;
		GLfloat pitch;
		//call backs
		friend static void cb_key(GLFWwindow* window, int key, int scancode, int action, int mode);
		friend static void cb_mouse_button(GLFWwindow* window, int button, int action, int mods);
		friend static void cb_mouse_cursor(GLFWwindow* window, double xpos, double ypos);
		friend static void cb_scroll(GLFWwindow* window, double xoffset, double yoffset);
		GLFWwindow* window;
	};

	static void cb_key(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void cb_mouse_cursor(GLFWwindow* window, double xpos, double ypos);
	static void cb_mouse_button(GLFWwindow* window, int button, int action, int mods);
	static void cb_scroll(GLFWwindow* window, double xoffset, double yoffset);

	static void cb_error(int error, const char* description);
	static void cb_framebuffer_size(GLFWwindow* window, int width, int height);
	static void cb_window_size(GLFWwindow* window, int width, int height);
}

#endif //NB_DISPLAY_H_INCLUDED