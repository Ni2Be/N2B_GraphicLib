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

//GLEW
#include <GL/glew.h>

//GLM
#include <glm.hpp>

//STL
#include <string>
#include <fstream>
#include <iostream>

//
#include "NB_Transformer.h"
#include "NB_Camera.h"

namespace NB
{
	class NB_Shader
	{
	public:
		void use();
		GLuint program;
	protected:
		NB_Shader() {}
		explicit NB_Shader(const std::string& file_name);
		~NB_Shader();


		virtual void bind_uniforms() {}


		GLuint create_shader(const std::string& text, const GLenum sader_type);

		void build_program(const std::string& file_name);

		void error_check(GLuint shader, GLuint flag, bool isProgram,
			const std::string& errorMessage, const std::string& file_name);
	private:
		//no copy
		NB_Shader(const NB_Shader&) {}
		NB_Shader& operator=(const NB_Shader&) {}
		//
	};
}

#endif //NB_SHADER_H_INCLUDED