//GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

//STL
#include <vector>

//Project
#define NB_PRAGMA_ONCE_SUPPORT
#include "NB_Display.h"
#include "NB_Utility.h"
#include "NB_Shader.h"
#include "NB_Mesh.h"
#include "NB_Texture.h"

int main()
{
	NB::NB_Display display{800, 600, "Window"};

	NB::NB_Shader shader{ "./res/shader/basic_shader" };

	NB::NB_Texture texture1{ "./res/textures/awesomeface.png" };
	NB::NB_Texture texture2{ "./res/textures/wall.jpg" };

	//TEST
	std::vector<NB::NB_Vertex> tri_vertices
	{	
		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f, 0.0f }, glm::vec4{ 1.0f, 0.0f, 0.0f, 1.0f}, glm::vec2{ 0.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{  0.5f, -0.5f, 0.0f }, glm::vec4{ 0.0f, 1.0f, 0.0f, 1.0f}, glm::vec2{ 1.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{  0.0f,  0.5f, 0.0f }, glm::vec4{ 0.0f, 0.0f, 1.0f, 1.0f}, glm::vec2{ 0.5f, 1.0f } }
	};
	NB::NB_Mesh triangle{ tri_vertices };
	
	std::vector<NB::NB_Vertex> sqr_vertices
	{
		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f, 0.0f }, glm::vec4{ 1.0f, 0.0f, 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f, 0.0f }, glm::vec4{ 1.0f, 1.0f, 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{-0.5f, -0.5f, 0.0f }, glm::vec4{ 1.0f, 0.0f, 1.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{-0.5f,  0.5f, 0.0f }, glm::vec4{ 0.0f, 1.0f, 1.0f, 1.0f } }
	};
	std::vector<GLuint> sqr_indices { 0, 1, 3, 1, 2, 3 };
	NB::NB_EMesh square{ sqr_vertices, sqr_indices };
	////
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//END TEST

	while (!glfwWindowShouldClose(&display))
	{
		glfwPollEvents();
		display.clear();
		
		//Cool stuff
		shader.use();

		texture1.bind(0);
		glUniform1i(glGetUniformLocation(shader.program, "texture1"), 0);
		texture2.bind(1);
		glUniform1i(glGetUniformLocation(shader.program, "texture2"), 1);

		float time = glfwGetTime();
		glUniform1f(shader.uni_horizontal_offset, sin(time));


		square.draw();
		triangle.draw();

		//

		display.update();
	}
	exit(EXIT_SUCCESS);
}
