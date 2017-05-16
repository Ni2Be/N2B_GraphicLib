//GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
//GLM
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

//STL
#include <vector>
#include <random>
#include <algorithm>
#include <thread>

//Project
#define NB_PRAGMA_ONCE_SUPPORT
//#define NB_DEBUG

#include "NB_Utility.h"
#include "NB_Display.h"
#include "NB_Utility.h"
#include "NB_Shader.h"
#include "NB_Mesh.h"
#include "NB_Texture.h"
#include "NB_Transformer.h"
#include "NB_Camera.h"

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


	std::random_device dev;
	std::mt19937 gen(dev());
	std::uniform_real_distribution<> z_dis(-200, 100);
	std::uniform_real_distribution<> xy_dis(-100, 100);

	std::vector<glm::vec3> cubePositions;
	int cubes = 90000;
	for (int i = 0; i < cubes; i++)
	{
		cubePositions.push_back(glm::vec3(xy_dis(gen), xy_dis(gen), z_dis(gen)));
	}

	/*
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
	};*/
	std::sort(std::begin(cubePositions), std::end(cubePositions), [](glm::vec3& lhs, glm::vec3& rhs) 
	{
		return lhs.z < rhs.z;
	});


	display.cam1.look_at(
		glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));
	//END TEST

	while (!glfwWindowShouldClose(&display))
	{
		glfwPollEvents();
		display.clear();
		display.camera_movement();

		//Cool stuff
		shader.use();
		
		texture1.bind(0);
		glUniform1i(glGetUniformLocation(shader.program, "texture1"), 0);
		texture2.bind(1);
		glUniform1i(glGetUniformLocation(shader.program, "texture2"), 1);



		float time = static_cast<float>(glfwGetTime());
		float sin_time = sin(time);

		for (auto& i : cubePositions)
		{
			trans1.pos = i;
			trans1.rot.y = sin_time;
			trans1.rot.x = sin_time;

			shader.update(trans1, display.cam1);
			cube.draw();
		}
		//shader.update(trans2);
		//triangle.draw();

		//

		display.update();
	}
	exit(EXIT_SUCCESS);
}
