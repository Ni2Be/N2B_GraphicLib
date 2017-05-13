#include "NB_Display.h"
#include "NB_Utility.h"


NB::NB_Display::NB_Display(int width, int height, const std::string title = "window 1")
{
	//set the window properties
	set_up_glfw(width, height, title);

	//set the openGL settings (openGL version is set in set_up_glfw())
	set_up_glew();

	//set up callbacks
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);
	glfwSetKeyCallback(this->window, key_callback);
	glfwSetErrorCallback(error_callback);
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

}

GLFWwindow* NB::NB_Display::operator&() const
{
	return this->window;
}

void NB::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void NB::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void NB::error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

void NB::window_size_callback(GLFWwindow* window, int width, int height)
{
	int w, h;
	glfwGetFramebufferSize(window, &w, &h);
	glViewport(0, 0, w, h);
}