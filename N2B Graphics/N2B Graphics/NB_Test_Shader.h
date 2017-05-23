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
		//
		class Test_Shader_Texture : public NB::NB_Shader
		{
		public:
			explicit Test_Shader_Texture(const std::string& fileName)
				:NB_Shader(fileName) 
			{
				this->bind_uniforms();
			}

			void update(const NB::NB_Transformer& trans, const NB::NB_Camera cam);
		private:
			void bind_uniforms();
			GLint uni_projection;
			GLint uni_view;
			GLint uni_transform;
		};

		class Test_Shader_Color : public NB::NB_Shader
		{
		public:
			explicit Test_Shader_Color(const std::string& fileName)
				:NB_Shader(fileName)
			{
				this->bind_uniforms();
			}

			void update(const NB::NB_Camera cam, NB::NB_Object& object);
		private:
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
			void update(const NB::NB_Camera cam, NB::NB_Object& object, NB::NB_Ambient_light& ambient, NB::NB_Light_Cube& diffuse_light);
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
