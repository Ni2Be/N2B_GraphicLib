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
	
	NB::NB_Display display{ 1200, 700, "Window" };

	const int LIGHT_COUNT = 50;

	NB::Test::Test_Shader_Texture texture_shader{ LIGHT_COUNT };
	NB::Test::Test_Shader_Color color_shader{ "./res/shader/color_shader" };
	NB::Test::Test_Shader_Light light_shader{ "./res/shader/light_shader" };

	NB::NB_Texture texture1{ "./res/textures/container2.png" };
	NB::NB_Texture texture2{ "./res/textures/container2_specular.png" };
	
	NB::NB_Transformer trans1, trans2;


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
		cubes[i].material.add_Texture(texture1, texture2);
		cubes[i].position.pos.x = i - cubes.size() / 2;
	}
	std::vector<std::vector<NB::NB_Cube>> ground;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis1_2(1, 2);
	std::uniform_real_distribution<float> dis0_1(0.1, 0.9);
	std::uniform_real_distribution<float> dis1_20(1, 20);
	for (int i = 0; i < cubes.size(); i++)
	{
		for (auto& cube : cubes)
		{
			cube.position.pos.z = i;
			cube.position.pos.y = dis1_20(gen);
		}
		ground.push_back(cubes);
	}

	//DIR Light
	NB::NB_Directional_Light sun = { glm::vec3{ 1.0f, 1.0f, 1.0f }, glm::vec3 { 0.3f, -1.0f, 0.2f }, 0.1f };
	display.set_background_color(glm::vec4{ 0.02f, 0.02f, 0.02f, 1.0f });


	//Point lights
	std::vector<NB::NB_Light_Cube*> lights;
	lights.push_back(display.light_cube_one);
	for (int i = 1; i < LIGHT_COUNT; i++)
	{
		lights.push_back(new NB::NB_Light_Cube{ 
			glm::vec3( dis1_20(gen), dis1_20(gen), dis1_20(gen)),
			glm::vec4{ 0.3f, 1.0f, 1.0f, 1.0f }, 
			0.5f, 0.5f, 0.5f, 
			NB::NB_LIGHT_WHITE });
		lights[i]->change_color(glm::vec4{ dis0_1(gen), dis0_1(gen), dis0_1(gen), 1.0f });
	}

	while (!glfwWindowShouldClose(&display))
	{
		glfwPollEvents();
		display.clear();

		//Cool stuff
		float time = static_cast<float>(glfwGetTime());

		texture_shader.use();
		for (int i = 0; i < ground.size(); i++)
		{
			for (int n = 0; n < ground[i].size(); n++)
			{
				texture_shader.update(display.cam1, ground[i][n], sun, lights);
				ground[i][n].draw();
			}
		}

		for (int i = 1; i < LIGHT_COUNT; i++)
		{
			lights[i]->move_y(0.1f * cos(time) * pow(-1, i));
			lights[i]->move_z(0.7f * cos(time) * pow(-1, i));
		}
		
		for (int i = 0; i < LIGHT_COUNT; i++)
		{
			color_shader.use();
			color_shader.update(display.cam1, lights[i]);
			lights[i]->cube.draw();
		}

		display.update();
	}
	exit(EXIT_SUCCESS);
}
