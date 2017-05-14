//GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
//GLM
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

//STL
#include <vector>

//Project
#define NB_PRAGMA_ONCE_SUPPORT
#include "NB_Display.h"
#include "NB_Utility.h"
#include "NB_Shader.h"
#include "NB_Mesh.h"
#include "NB_Texture.h"
#include "NB_Transformer.h"

int main()
{
	NB::NB_Display display{ 800, 600, "Window" };

	NB::NB_Shader shader{ "./res/shader/basic_shader" };

	NB::NB_Texture texture1{ "./res/textures/awesomeface.png" };
	NB::NB_Texture texture2{ "./res/textures/wall.jpg" };

	NB::NB_Transformer trans1, trans2;

	//TEST
	std::vector<NB::NB_Vertex> tri_vertices
	{
		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f, 0.0f }, 1.0f, glm::vec2{ 0.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f, 0.0f }, 1.0f, glm::vec2{ 1.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.0f,  0.5f, 0.0f }, 1.0f, glm::vec2{ 0.5f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f, 0.5f }, 1.0f, glm::vec2{ 0.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f, 0.5f }, 1.0f, glm::vec2{ 1.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.0f,  0.5f, 0.5f }, 1.0f, glm::vec2{ 0.5f, 1.0f } }
	};
	std::vector<GLuint> tri_indices{
		0, 1, 2,
		3, 4, 5 };
	NB::NB_EMesh triangle{ tri_vertices , tri_indices };

	std::vector<NB::NB_Vertex> sqr_vertices
	{
		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f, 0.0f }, glm::vec4{ 1.0f, 0.0f, 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f, 0.0f }, glm::vec4{ 1.0f, 1.0f, 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{-0.5f, -0.5f, 0.0f }, glm::vec4{ 1.0f, 0.0f, 1.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{-0.5f,  0.5f, 0.0f }, glm::vec4{ 0.0f, 1.0f, 1.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f, 1.0f }, glm::vec4{ 1.0f, 0.0f, 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f, 1.0f }, glm::vec4{ 1.0f, 1.0f, 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{-0.5f, -0.5f, 1.0f }, glm::vec4{ 1.0f, 0.0f, 1.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{-0.5f,  0.5f, 1.0f }, glm::vec4{ 0.0f, 1.0f, 1.0f, 1.0f } }
	};
	std::vector<GLuint> sqr_indices{
		0, 1, 3, 1, 2, 3,
		4, 5, 7, 5, 6, 7,
		1, 5, 2, 2, 5, 6,
		0, 4, 7, 0, 7, 3,
		0, 1, 4, 1, 4, 5,
		2, 3, 7, 2, 6, 7 };

	NB::NB_EMesh square{ sqr_vertices, sqr_indices };
	////
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	std::vector<NB::NB_Vertex> cube_vertices = 
	{
		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f, -0.5f}, 1.0f, glm::vec2{ 0.0f, 0.0f}},
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f, -0.5f},   1.0f, glm::vec2{ 1.0f, 0.0f} },
		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f, -0.5f},   1.0f, glm::vec2{ 1.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f, -0.5f},  1.0f, glm::vec2{ 1.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f,  0.5f, -0.5f},   1.0f, glm::vec2{ 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f, -0.5f},   1.0f, glm::vec2{ 0.0f, 0.0f } },

		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f,  0.5f},   1.0f, glm::vec2{ 0.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f,  0.5f }, 1.0f, glm::vec2{ 1.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f,  0.5f }, 1.0f, glm::vec2{ 1.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f,  0.5f }, 1.0f, glm::vec2{ 1.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f,  0.5f,  0.5f }, 1.0f, glm::vec2{ 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f,  0.5f }, 1.0f, glm::vec2{ 0.0f, 0.0f } },

		NB::NB_Vertex{ glm::vec3{ -0.5f,  0.5f,  0.5f }, 1.0f, glm::vec2{ 1.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f,  0.5f, -0.5f }, 1.0f, glm::vec2{ 1.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f, -0.5f }, 1.0f, glm::vec2{ 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f, -0.5f }, 1.0f, glm::vec2{ 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f,  0.5f }, 1.0f, glm::vec2{ 0.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f,  0.5f,  0.5f }, 1.0f, glm::vec2{ 1.0f, 0.0f } },

		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f,  0.5f }, 1.0f, glm::vec2{ 1.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f, -0.5f }, 1.0f, glm::vec2{ 1.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f, -0.5f }, 1.0f, glm::vec2{   0.0f, 1.0 } },
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f, -0.5f }, 1.0f, glm::vec2{ 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f,  0.5f }, 1.0f, glm::vec2{ 0.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f,  0.5f }, 1.0f, glm::vec2{ 1.0f, 0.0f } },

		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f, -0.5f }, 1.0f, glm::vec2{ 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f, -0.5f }, 1.0f, glm::vec2{ 1.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f,  0.5f }, 1.0f, glm::vec2{ 1.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f, -0.5f,  0.5f }, 1.0f, glm::vec2{ 1.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f,  0.5f }, 1.0f, glm::vec2{ 0.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f, -0.5f, -0.5f }, 1.0f, glm::vec2{ 0.0f, 1.0f } },

		NB::NB_Vertex{ glm::vec3{ -0.5f,  0.5f, -0.5f }, 1.0f, glm::vec2{ 0.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f, -0.5f }, 1.0f, glm::vec2{ 1.0f, 1.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f,  0.5f }, 1.0f, glm::vec2{ 1.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ 0.5f,  0.5f,  0.5f }, 1.0f, glm::vec2{ 1.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f,  0.5f,  0.5f }, 1.0f, glm::vec2{ 0.0f, 0.0f } },
		NB::NB_Vertex{ glm::vec3{ -0.5f,  0.5f, -0.5f }, 1.0f, glm::vec2{ 0.0f, 1.0f } }
	};
	NB::NB_Mesh cube(cube_vertices);

	std::vector<glm::vec3> cubePositions = 
	{
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};
	std::sort(std::begin(cubePositions), std::end(cubePositions), [](glm::vec3& lhs, glm::vec3& rhs) 
	{
		return lhs.z < rhs.z;
	});
	//END TEST



	glm::mat4 projection;

	projection = glm::perspective(45.0f, (GLfloat)800 / (GLfloat)600, 0.1f, 100.0f);
	GLint projLoc = glGetUniformLocation(shader.program, "projection");

	while (!glfwWindowShouldClose(&display))
	{
		glfwPollEvents();
		display.clear();

		//Cool stuff
		shader.use();
		shader.update(trans1);

		texture1.bind(0);
		glUniform1i(glGetUniformLocation(shader.program, "texture1"), 0);
		texture2.bind(1);
		glUniform1i(glGetUniformLocation(shader.program, "texture2"), 1);



		float time = static_cast<float>(glfwGetTime());

		//TEST
		// Create transformations
		glm::mat4 view;
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		// Get their uniform location
		GLint viewLoc = glGetUniformLocation(shader.program, "view");
		// Pass the matrices to the shader
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		//ENDTEST


		for (auto& i : cubePositions)
		{
			trans1.pos = i;
			trans1.rot.y = (sin(time));
			trans1.rot.x = (sin(time));

			shader.update(trans1);
			cube.draw();
		}



		//shader.update(trans2);
		//triangle.draw();

		//

		display.update();
	}
	exit(EXIT_SUCCESS);
}
