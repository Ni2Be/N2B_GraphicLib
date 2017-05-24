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
#define NB_DEBUG

#include "NB_Utility.h"
#include "NB_Display.h"
#include "NB_Utility.h"
#include "NB_Shader.h"
#include "NB_Mesh.h"
#include "NB_Texture.h"
#include "NB_Transformer.h"
#include "NB_Camera.h"
#include "NB_Object.h"
#include "NB_Light.h"
#include "NB_Material.h"
//
#include "NB_Test_Shader.h"

int main()
{
	NB::NB_Display display{ 800, 600, "Window" };

	NB::Test::Test_Shader_Texture texture_shader{ "./res/shader/texture_shader" };
	NB::Test::Test_Shader_Color color_shader{ "./res/shader/color_shader" };
	NB::Test::Test_Shader_Light light_shader{ "./res/shader/light_shader" };

	NB::NB_Texture texture1{ "./res/textures/awesomeface.png" };
	NB::NB_Texture texture2{ "./res/textures/wall.jpg" };
	
	NB::NB_Transformer trans1, trans2;


	//TEST

	/*
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

	NB::NB_EMesh square{ sqr_vertices, sqr_indices };*/
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);





	display.cam1.look_at(
		glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));
	//END TEST

	std::vector<NB::NB_Cube> cubes
	{
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_EMERALD),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_JADE),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_OBSIDIAN),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_PEARL),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_RUBY),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_TURQUOISE),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_BRASS),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_BONZE),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_CHROME),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_COPPER),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_SILVER),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_GOLD),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_PLASTIC_BLACK),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_PLASTIC_CYAN),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_PLASTIC_GREEN),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_PLASTIC_RED),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_PLASTIC_WHITE),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_PLASTIC_YELLOW),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_RUBBER_BLACK),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_RUBBER_CYAN),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_RUBBER_GREEN),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_RUBBER_RED),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_RUBBER_WHITE),
		NB::NB_Cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f, 1.0f, NB::NB_RUBBER_YELLOW)
	};

	for (int i = 0; i < cubes.size(); i++)
	{
		cubes[i].position.pos.x = i - cubes.size() / 2;
	}
	std::vector<std::vector<NB::NB_Cube>> ground;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(1, 2);
	for (int i = 0; i < cubes.size(); i++)
	{
		for (auto& cube : cubes)
		{
			cube.position.pos.z = i;
			cube.position.pos.y = static_cast<float>(dis(gen));
		}
		ground.push_back(cubes);
	}


	NB::NB_Ambient_light ambient = { glm::vec3{ 1.0f, 1.0f, 1.0f }, 0.1f };
	display.set_background_color(ambient);


	while (!glfwWindowShouldClose(&display))
	{
		glfwPollEvents();
		display.clear();

		//Cool stuff
		float time = static_cast<float>(glfwGetTime());
		light_shader.use();
		//texture_shader.use();
		//for (auto& cube : cubes)
		//{
		//	//texture_shader.update(display.cam1, *cube, texture1, texture2);
		//	light_shader.update(display.cam1, cube, ambient, *display.light_cube_one);
		//	cube.draw();
		//}

		for (int i = 0; i < ground.size(); i++)
		{
			for (int n = 0; n < ground[i].size(); n++)
			{
				light_shader.update(display.cam1, ground[i][n], ambient, *display.light_cube_one);
				ground[i][n].draw();
			}
		}


		color_shader.use();
		color_shader.update(display.cam1, *display.light_cube_one);
		display.light_cube_one->draw();
		//

		display.update();
	}
	exit(EXIT_SUCCESS);
}
