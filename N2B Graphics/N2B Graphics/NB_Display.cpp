#include "NB_Display.h"
#include "NB_Utility.h"

#include <iostream>

NB::NB_Display::NB_Display(int width, int height, const std::string title = "window 1")
	: cam1(glm::radians(45.0f), (GLfloat)width / (GLfloat)height, 0.1f, 1000.0f),
	delta_time(0.0f),
	last_frame(0.0f),
	sensitivity(0.05f),
	x_offset(0.0f),
	y_offset(0.0f),
	yaw(-90.0f),
	pitch(0.0f)
{
	//set the window properties
	set_up_glfw(width, height, title);

	//set the openGL settings (openGL version is set in set_up_glfw())
	set_up_glew();

	//set up callbacks
	glfwSetWindowUserPointer(window, (void*)this);

	glfwSetFramebufferSizeCallback(window, cb_framebuffer_size);
	glfwSetWindowSizeCallback(window, cb_window_size);
	
	glfwSetKeyCallback(window, cb_key);
	glfwSetCursorPosCallback(window, cb_mouse_cursor);
	glfwSetMouseButtonCallback(window, cb_mouse_button);
	glfwSetScrollCallback(window, cb_scroll);
	
	glfwSetErrorCallback(cb_error);
}

NB::NB_Display::~NB_Display()
{
	glfwTerminate();
}

void NB::NB_Display::set_up_glfw(int width, int height, const std::string title)
{
	if (!glfwInit())
	{
		error_log("NB::NB_Display::NB_Display", "Failed to initiate GLFW");
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	this->window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (this->window == nullptr)
	{
		error_log("NB::NB_Display::NB_Display", "Failed to create GLFW window");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(this->window);
	glfwSwapInterval(1);
}

void NB::NB_Display::set_up_glew()
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		error_log("NB::NB_Display::NB_Display", "Failed to initialize GLFW");
		exit(EXIT_FAILURE);
	}

	//not screen width and height but pixels to ensure proper work on high res screens
	int w, h;
	glfwGetFramebufferSize(window, &w, &h);
	glViewport(0, 0, w, h);

	//z buffer
	glEnable(GL_DEPTH_TEST);

	//Enable alpha blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

GLFWwindow* NB::NB_Display::operator&() const
{
	return this->window;
}

void NB::cb_framebuffer_size(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void NB::cb_key(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	//get display
	NB::NB_Display* display = static_cast<NB::NB_Display*>(glfwGetWindowUserPointer(window));


	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	//Camera movement
	if (action == GLFW_PRESS)
	{
		display->keys[key] = true;
	}
	else if (action == GLFW_RELEASE)
	{
		display->keys[key] = false;
	}
}

void NB::cb_mouse_button(GLFWwindow* window, int button, int action, int mods)
{
	//get display
	NB::NB_Display* display = static_cast<NB::NB_Display*>(glfwGetWindowUserPointer(window));

	if (action == GLFW_PRESS)
		display->mouse_buttons[button] = true;
	else if (action == GLFW_RELEASE)
		display->mouse_buttons[button] = false;
}


void NB::cb_mouse_cursor(GLFWwindow* window, double xpos, double ypos)
{
	//get display
	NB::NB_Display* display = static_cast<NB::NB_Display*>(glfwGetWindowUserPointer(window));

	display->x_offset = xpos - display->last_x;
	display->y_offset = display->last_y - ypos;
	display->last_x = xpos;
	display->last_y = ypos;



	if (display->mouse_buttons[GLFW_MOUSE_BUTTON_MIDDLE])
	{
		GLfloat x_move = display->x_offset * display->sensitivity;
		GLfloat y_move = display->y_offset * display->sensitivity;

		display->yaw += x_move;
		display->pitch += y_move;

		if (display->pitch > 89.0f)
			display->pitch = 89.0f;
		if (display->pitch < -89.0f)
			display->pitch = -89.0f;

		glm::vec3 front;
		front.x = cos(glm::radians(display->pitch)) * cos(glm::radians(display->yaw));
		front.y = sin(glm::radians(display->pitch));
		front.z = cos(glm::radians(display->pitch)) * sin(glm::radians(display->yaw));
		display->cam1.camera_front = glm::normalize(front);
	}
}

void NB::cb_scroll(GLFWwindow* window, double xoffset, double yoffset)
{
	//get display
	NB::NB_Display* display = static_cast<NB::NB_Display*>(glfwGetWindowUserPointer(window));

	if (display->cam1.fov >= glm::radians(1.0f) && display->cam1.fov <= glm::radians(45.0f))
		display->cam1.fov -= glm::radians(yoffset);

	if (display->cam1.fov <= glm::radians(1.0f))
		display->cam1.fov = glm::radians(1.0f);
	if (display->cam1.fov >= glm::radians(45.0f))
		display->cam1.fov = glm::radians(45.0f);
}

void NB::NB_Display::camera_movement()
{
	GLfloat cameraSpeed = 5.0f * delta_time;
	if (keys[GLFW_KEY_W])
		cam1.camera_pos -= cameraSpeed * cam1.camera_pos;
	if (keys[GLFW_KEY_S])
		cam1.camera_pos += cameraSpeed * cam1.camera_pos;
	if (keys[GLFW_KEY_A])
		cam1.camera_pos -= glm::normalize(glm::cross(cam1.camera_front, cam1.camera_up)) * cameraSpeed;
	if (keys[GLFW_KEY_D])
		cam1.camera_pos += glm::normalize(glm::cross(cam1.camera_front, cam1.camera_up)) * cameraSpeed;
	if (keys[GLFW_KEY_LEFT_SHIFT])
		cam1.camera_pos.y += cameraSpeed;
	if (keys[GLFW_KEY_LEFT_CONTROL])
		cam1.camera_pos.y -= cameraSpeed;
	cam1.update();
}

void NB::cb_error(int error, const char* description)
{
	fputs(description, stderr);
}

void NB::cb_window_size(GLFWwindow* window, int width, int height)
{
	int w, h;
	glfwGetFramebufferSize(window, &w, &h);
	glViewport(0, 0, w, h);
}