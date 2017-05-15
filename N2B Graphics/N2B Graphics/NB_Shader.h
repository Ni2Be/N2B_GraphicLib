/*
NB_Shader:
	Attention:
	Purpose:
	Usage:
*/

#ifdef NB_PRAGMA_ONCE_SUPPORT
#pragma once
#endif
#ifndef NB_SHADER_H_INCLUDED
#define NB_SHADER_H_INCLUDED

#include <string>
#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <glm.hpp>

#include "NB_Transformer.h"
#include "NB_Camera.h"

namespace NB
{
	class NB_Shader
	{
	public:
		NB_Shader(const std::string& fileName);
		~NB_Shader();

		void use();
		void update(const NB_Transformer& trans, const NB::NB_Camera cam);

		GLuint program;
	private:
		//no copy
		NB_Shader(const NB_Shader&) {}
		NB_Shader& operator=(const NB_Shader&) {}
		//


		//uniforms
		GLint uni_projection;
		GLint uni_view;
		GLint uni_transform;
		void bind_uniforms();

		GLuint create_shader(const std::string& text, const GLenum sader_type);

		void error_check(GLuint shader, GLuint flag, bool isProgram,
			const std::string& errorMessage, const std::string& file_name);

	};
}

#endif //NB_SHADER_H_INCLUDED