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

	uni_light_color = glGetUniformLocation(program, "light_color");
}

void  NB::Test::Test_Shader_Color::update(const NB::NB_Camera cam, NB::NB_Object& object)
{
	//Transformer
	glUniformMatrix4fv(uni_transform, 1, GL_FALSE, glm::value_ptr(object.position.get_model()));

	//Camera
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, glm::value_ptr(cam.view));
	glUniformMatrix4fv(uni_projection, 1, GL_FALSE, glm::value_ptr(cam.projection));

	//
	glUniform3f(uni_light_color, object.color.r, object.color.g, object.color.b);
}
//



void NB::Test::Test_Shader_Light::bind_uniforms()
{
	uni_transform = glGetUniformLocation(program, "transform");
	uni_view = glGetUniformLocation(program, "view");
	uni_projection = glGetUniformLocation(program, "projection");

	uni_light_pos = glGetUniformLocation(program, "light.position");
	uni_light_color = glGetUniformLocation(program, "light.color");
	uni_light_strength = glGetUniformLocation(program, "light.strength");

	uni_ambient_strength = glGetUniformLocation(program, "ambient_strength");
	uni_ambient_color = glGetUniformLocation(program, "ambient_color");

	uni_camera_pos = glGetUniformLocation(program, "camera_pos");

	uni_material_shininess = glGetUniformLocation(program, "material.shininess");
	uni_material_ambient = glGetUniformLocation(program, "material.ambient");
	uni_material_diffuse = glGetUniformLocation(program, "material.diffuse");
	uni_material_specular = glGetUniformLocation(program, "material.specular");
}

void NB::Test::Test_Shader_Light::update(const NB::NB_Camera cam, NB::NB_Object& object, NB::NB_Ambient_light& ambient, NB::NB_Light_Cube& light)
{
	//Transformer
	glUniformMatrix4fv(uni_transform, 1, GL_FALSE, glm::value_ptr(object.position.get_model()));

	//Camera
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, glm::value_ptr(cam.view));
	glUniformMatrix4fv(uni_projection, 1, GL_FALSE, glm::value_ptr(cam.projection));
	glUniform3f(uni_camera_pos, cam.camera_pos.x, cam.camera_pos.y, cam.camera_pos.z);
	
	//Light
	glUniform3f(uni_ambient_color, ambient.light_color.r, ambient.light_color.g, ambient.light_color.b);
	glUniform1f(uni_ambient_strength, ambient.strength);

	glUniform3f(uni_light_pos, light.position.pos.x, light.position.pos.y, light.position.pos.z);
	glUniform3f(uni_light_color, light.color.r, light.color.g, light.color.b);
	glUniform1f(uni_light_strength, light.material.shininess);

	//Material
	glUniform1f(uni_material_shininess, object.material.shininess);
	glUniform3f(uni_material_ambient, object.material.ambient.r, object.material.ambient.g, object.material.ambient.b);
	glUniform3f(uni_material_diffuse, object.material.diffuse.r, object.material.diffuse.g, object.material.diffuse.b);
	glUniform3f(uni_material_specular, object.material.specular.r, object.material.specular.g, object.material.specular.b);
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
