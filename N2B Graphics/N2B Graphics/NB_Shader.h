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
		virtual void update(const NB_Transformer& trans, const NB::NB_Camera cam) {}
	protected:
		explicit NB_Shader(const std::string& fileName);
		~NB_Shader();


		virtual void bind_uniforms() {}
		GLuint program;


		GLuint create_shader(const std::string& text, const GLenum sader_type);

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