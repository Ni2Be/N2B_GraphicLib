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

#include "NB_Shader.h"
#include "NB_Transformer.h"
#include "NB_Camera.h"

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


		class Test_Shader_Light : public NB::NB_Shader
		{
		public:
			explicit Test_Shader_Light(const std::string& fileName)
				:NB_Shader(fileName)
			{
				this->bind_uniforms();
			}

			void update(const NB::NB_Transformer& trans, const NB::NB_Camera cam, glm::vec4& light);
		private:
			void bind_uniforms();
			GLint uni_projection;
			GLint uni_view;
			GLint uni_transform;
			GLint uni_light_color;
		};
	}
}
#endif
