#include "NB_Test_Shader.h"
#include <iostream>
#include "NB_Utility.h"

void NB::Test::Test_Shader_Texture::bind_uniforms()
{
	uni_transform = glGetUniformLocation(program, "transform");
	uni_view = glGetUniformLocation(program, "view");
	uni_projection = glGetUniformLocation(program, "projection");


	uni_attenuation_const = glGetUniformLocation(program, "light.attenuation_const");
	uni_attenuation_lin = glGetUniformLocation(program, "light.attenuation_lin");
	uni_attenuation_quad = glGetUniformLocation(program, "light.attenuation_quad");
	uni_light_pos = glGetUniformLocation(program, "light.position");
	uni_light_color = glGetUniformLocation(program, "light.color");
	uni_light_strength = glGetUniformLocation(program, "light.strength");

	uni_light_ambient_strength = glGetUniformLocation(program, "light.ambient_strength");

	uni_camera_pos = glGetUniformLocation(program, "camera_pos");

	uni_material_shininess = glGetUniformLocation(program, "material.shininess");
	uni_material_ambient = glGetUniformLocation(program, "material.ambient");
	uni_material_diffuse = glGetUniformLocation(program, "material.diffuse");
	uni_material_specular = glGetUniformLocation(program, "material.specular");


	uni_material_texture = glGetUniformLocation(program, "material.texture");
	uni_material_specular_map = glGetUniformLocation(program, "material.specular_map");
}

void NB::Test::Test_Shader_Texture::update(const NB::NB_Camera cam, NB::NB_Object& object, NB::NB_Ambient_light& ambient, NB::NB_Light_Cube& light)
{
	//Transformer
	glUniformMatrix4fv(uni_transform, 1, GL_FALSE, glm::value_ptr(object.position.get_model()));

	//Camera
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, glm::value_ptr(cam.get_view()));
	glUniformMatrix4fv(uni_projection, 1, GL_FALSE, glm::value_ptr(cam.get_projection()));
	glUniform3fv(uni_camera_pos, 1, glm::value_ptr(cam.get_camera_pos()));

	//Light
	glUniform1f(uni_attenuation_const, light.type.attenuation_const);
	glUniform1f(uni_attenuation_lin, light.type.attenuation_lin);
	glUniform1f(uni_attenuation_quad, light.type.attenuation_quad);
	glUniform1f(uni_light_ambient_strength, light.type.ambient_strength);

	glUniform3f(uni_light_pos, light.position.x, light.position.y, light.position.z);
	glUniform3f(uni_light_color, light.type.color.r, light.type.color.g, light.type.color.b);
	glUniform1f(uni_light_strength, light.type.strength);
	//Material
	glUniform1f(uni_material_shininess, object.material.shininess * 128);
	glUniform3f(uni_material_ambient, object.material.ambient.r, object.material.ambient.g, object.material.ambient.b);
	glUniform3f(uni_material_diffuse, object.material.diffuse.r, object.material.diffuse.g, object.material.diffuse.b);
	glUniform3f(uni_material_specular, object.material.specular.r, object.material.specular.g, object.material.specular.b);

	//Texture
#ifdef NB_DEBUG
	if (object.material.texture == nullptr)
	{
		error_log("NB::Test::Test_Shader_Texture::update", "No texture");
		exit(EXIT_FAILURE);
	}
#endif // NB_DEBUG

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, object.material.texture->id);
	glUniform1i(uni_material_texture, 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, object.material.specular_map->id);
	glUniform1i(uni_material_specular_map, 1);
}
//


void NB::Test::Test_Shader_Color::bind_uniforms()
{
	uni_transform = glGetUniformLocation(program, "transform");
	uni_view = glGetUniformLocation(program, "view");
	uni_projection = glGetUniformLocation(program, "projection");

	uni_light_color = glGetUniformLocation(program, "light_color");
}

void  NB::Test::Test_Shader_Color::update(const NB::NB_Camera cam, NB::NB_Light_Cube& light)
{
	//Transformer
	glUniformMatrix4fv(uni_transform, 1, GL_FALSE, glm::value_ptr(light.cube.position.get_model()));

	//Camera
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, glm::value_ptr(cam.get_view()));
	glUniformMatrix4fv(uni_projection, 1, GL_FALSE, glm::value_ptr(cam.get_projection()));

	//
	glUniform3f(uni_light_color, light.type.color.r, light.type.color.g, light.type.color.b);
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
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, glm::value_ptr(cam.get_view()));
	glUniformMatrix4fv(uni_projection, 1, GL_FALSE, glm::value_ptr(cam.get_projection()));
	glUniform3fv(uni_camera_pos, 1, glm::value_ptr(cam.get_camera_pos()));

	//Light
	glUniform3f(uni_ambient_color, ambient.light_color.r, ambient.light_color.g, ambient.light_color.b);
	glUniform1f(uni_ambient_strength, ambient.strength);

	glUniform3f(uni_light_pos, light.position.x, light.position.y, light.position.z);
	glUniform3f(uni_light_color, light.type.color.r, light.type.color.g, light.type.color.b);
	glUniform1f(uni_light_strength, light.type.strength);

	//Material
	glUniform1f(uni_material_shininess, object.material.shininess * 128);
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
