/*
NB_Test_Shader:
Attention:
Purpose:
Usage:
*/

#ifdef NB_PRAGMA_ONCE_SUPPORT
#pragma once
#endif
#ifndef NB_TEST_SHADER_H_INCLUDED
#define NB_TEST_SHADER_H_INCLUDED

//STL
#include <vector>

//
#include "NB_Shader.h"
#include "NB_Transformer.h"
#include "NB_Camera.h"
#include "NB_Object.h"
#include "NB_Light.h"

namespace NB
{
	namespace Test
	{

		class Test_Shader_Texture : public NB::NB_Shader
		{
		public:
			Test_Shader_Texture(int light_count)
				:
				NB_Shader(),
				shader_location("./res/shader/texture_shader"),
				light_count(light_count),
				uni_attenuation_const(light_count),
				uni_attenuation_lin(light_count),
				uni_attenuation_quad(light_count),
				uni_light_strength(light_count),
				uni_light_pos(light_count),
				uni_light_color(light_count),
				uni_light_ambient_strength(light_count)
			{
				change_light_count(light_count);
				this->bind_uniforms();
			}

			virtual void draw();
			
			void attach(NB::NB_Camera& camera);
			void attach(NB::NB_Directional_Light& dir_light);
			void attach(NB::NB_Light_Cube& light);
			void attach(std::vector<NB::NB_Light_Cube>& lights);
			void attach(NB_Object& object);
			void attach(std::vector<NB_Object>& object);

			void update(
				const NB::NB_Camera cam,
				NB::NB_Object& object,
				NB::NB_Directional_Light& ambient,
				std::vector<NB::NB_Light_Cube*>& lights);
		protected:
			NB::NB_Directional_Light* dir_light;
			std::vector<NB::NB_Light_Cube*> lights;
			std::vector<NB_Object*> objects;
			NB::NB_Camera* camera;

			std::string shader_location;

			void bind_uniforms();
			GLint uni_projection;
			GLint uni_view;
			GLint uni_transform;

			GLint uni_camera_pos;

			GLint uni_material_ambient;
			GLint uni_material_diffuse;
			GLint uni_material_specular;
			GLint uni_material_shininess;

			//should be called before gameloop
			//recompiling shader
			void change_light_count(int new_count);

			int light_count;
			std::vector<GLint> uni_attenuation_const;
			std::vector<GLint> uni_attenuation_lin;
			std::vector<GLint> uni_attenuation_quad;
			std::vector<GLint> uni_light_strength;
			std::vector<GLint> uni_light_pos;
			std::vector<GLint> uni_light_color;
			std::vector<GLint> uni_light_ambient_strength;

			GLint uni_dir_light_direction;
			GLint uni_dir_light_color;
			GLint uni_dir_light_strength;

			GLint uni_material_texture;
			GLint uni_material_specular_map;
		};

		class Test_Shader_Element : public Test_Shader_Texture
		{
		public:
			using Test_Shader_Texture::attach;

			Test_Shader_Element(int light_count)
				:Test_Shader_Texture(light_count)
			{}

			void update(
				const NB::NB_Camera cam,
				NB::NB_Model& model,
				NB::NB_Directional_Light& dir_light,
				std::vector<NB::NB_Light_Cube*>& lights);

			void attach(NB_Model& model);

			std::vector<NB_Model*> models;

			void draw();
		};

		class Test_Shader_Color : public NB::NB_Shader
		{
		public:
			explicit Test_Shader_Color(const std::string& fileName)
				:NB_Shader(fileName)
			{
				this->bind_uniforms();
			}


			void attach(NB::NB_Camera& camera);

			void update(const NB::NB_Camera cam, NB::NB_Light_Cube* light);
			void attach(NB::NB_Light_Cube& light);
			void draw();
		private:
			NB::NB_Camera* camera;
			std::vector<NB::NB_Light_Cube*> lights;
			void bind_uniforms();
			GLint uni_projection;
			GLint uni_view;
			GLint uni_transform;
			GLint uni_light_color;
		};


		class Test_Shader_Light : public NB::NB_Shader
		{
		public:
			explicit Test_Shader_Light(const std::string& fileName)
				:NB_Shader(fileName)
			{
				this->bind_uniforms();
			}

			void draw_objects(std::vector<NB::NB_Object*>& objects) const;
			void update(const NB::NB_Camera cam, NB::NB_Object& object, NB::NB_Directional_Light& ambient, NB::NB_Light_Cube& light);
		private:
			void bind_uniforms();
			GLint uni_projection;
			GLint uni_view;
			GLint uni_transform;

			GLint uni_camera_pos;

			GLint uni_material_ambient;
			GLint uni_material_diffuse;
			GLint uni_material_specular;
			GLint uni_material_shininess;

			GLint uni_light_strength;
			GLint uni_light_pos;
			GLint uni_light_color;
			GLint uni_ambient_strength;
			GLint uni_ambient_color;
		};
	}
}
#endif
