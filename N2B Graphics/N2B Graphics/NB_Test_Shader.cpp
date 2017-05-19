#include "NB_Test_Shader.h"
#include <iostream>

void NB::Test::Test_Shader_Texture::bind_uniforms()
{
	uni_transform = glGetUniformLocation(program, "transform");
	uni_view = glGetUniformLocation(program, "view");
	uni_projection = glGetUniformLocation(program, "projection");
}

void  NB::Test::Test_Shader_Texture::update(const NB::NB_Transformer& trans, const NB::NB_Camera cam)
{
	//Transformer
	glUniformMatrix4fv(uni_transform, 1, GL_FALSE, glm::value_ptr(trans.get_model()));

	//Camera
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, glm::value_ptr(cam.view));
	glUniformMatrix4fv(uni_projection, 1, GL_FALSE, glm::value_ptr(cam.projection));
}
//


void NB::Test::Test_Shader_Color::bind_uniforms()
{
	uni_transform = glGetUniformLocation(program, "transform");
	uni_view = glGetUniformLocation(program, "view");
	uni_projection = glGetUniformLocation(program, "projection");
}

void  NB::Test::Test_Shader_Color::update(const NB::NB_Camera cam, NB::NB_Object& object)
{
	//Transformer
	glUniformMatrix4fv(uni_transform, 1, GL_FALSE, glm::value_ptr(object.position.get_model()));

	//Camera
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, glm::value_ptr(cam.view));
	glUniformMatrix4fv(uni_projection, 1, GL_FALSE, glm::value_ptr(cam.projection));
}
//



void NB::Test::Test_Shader_Light::bind_uniforms()
{
	uni_transform = glGetUniformLocation(program, "transform");
	uni_view = glGetUniformLocation(program, "view");
	uni_projection = glGetUniformLocation(program, "projection");
	uni_diffuse_pos = glGetUniformLocation(program, "diffuse_pos");
	uni_diffuse_color = glGetUniformLocation(program, "diffuse_color");
	uni_ambient_strength = glGetUniformLocation(program, "ambient_strength");
	uni_ambient_color = glGetUniformLocation(program, "ambient_color");
}

void NB::Test::Test_Shader_Light::update(const NB::NB_Camera cam, NB::NB_Object& object, NB::NB_Ambient_light& ambient, NB::NB_Light_Cube& diffuse_light)
{
	//Transformer
	glUniformMatrix4fv(uni_transform, 1, GL_FALSE, glm::value_ptr(object.position.get_model()));

	//Camera
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, glm::value_ptr(cam.view));
	glUniformMatrix4fv(uni_projection, 1, GL_FALSE, glm::value_ptr(cam.projection));

	//Light
	glUniform3f(uni_diffuse_pos, diffuse_light.position.pos.x, diffuse_light.position.pos.y, diffuse_light.position.pos.z);
	glUniform3f(uni_diffuse_color, diffuse_light.color.r, diffuse_light.color.g, diffuse_light.color.b);
	glUniform3f(uni_ambient_color, ambient.light_color.r, ambient.light_color.g, ambient.light_color.b);
	glUniform1f(uni_ambient_strength, ambient.strength);
}


void NB::Test::Test_Shader_Light::draw_objects(std::vector<NB::NB_Object*>& objects) const
{
	for (auto& i : objects)
	{
		//Transformer
		glUniformMatrix4fv(uni_transform, 1, GL_FALSE, glm::value_ptr(i->position.get_model()));
		i->draw();
	}
}
