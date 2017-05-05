#include "Display.h"



NB::Display::Display(int width, int height, const std::string title = "window 1")
{

	if (!glfwInit())
	{
		std::cerr << "Failed to initiate GLFW" << std::endl;
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	this->window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (this->window == nullptr)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(this->window);

	//GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}

	//not width and height to ensure proper work on high res screens
	int w, h;
	glfwGetFramebufferSize(window, &w, &h);
	glViewport(0, 0, w, h);

	//set up callback
	glfwSetKeyCallback(this->window, key_callback);
	glfwSetErrorCallback(error_callback);
}


NB::Display::~Display()
{
}

GLFWwindow* NB::Display::operator&() const
{
	return this->window;
}

void NB::Display::clear()
{
	glClearColor(0.41f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
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