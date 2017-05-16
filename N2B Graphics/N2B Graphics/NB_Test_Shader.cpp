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

void NB::Test::Test_Shader_Light::bind_uniforms()
{
	uni_transform = glGetUniformLocation(program, "transform");
	uni_view = glGetUniformLocation(program, "view");
	uni_projection = glGetUniformLocation(program, "projection");
	uni_light_color = glGetUniformLocation(program, "light_color");
}

void  NB::Test::Test_Shader_Light::update(const NB::NB_Transformer& trans, const NB::NB_Camera cam, glm::vec4& light)
{
	//Transformer
	glUniformMatrix4fv(uni_transform, 1, GL_FALSE, glm::value_ptr(trans.get_model()));

	//Camera
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, glm::value_ptr(cam.view));
	glUniformMatrix4fv(uni_projection, 1, GL_FALSE, glm::value_ptr(cam.projection));

	//Light
	glUniform4f(uni_light_color, light.x, light.y, light.z, light.a);
}