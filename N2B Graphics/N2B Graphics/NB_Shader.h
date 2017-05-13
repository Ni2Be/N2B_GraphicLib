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

namespace NB
{
	class NB_Shader
	{
	public:
		NB_Shader(const std::string& fileName);
		~NB_Shader();

		void use();
		GLuint uni_horizontal_offset;
		GLuint program;
	private:
		//no copy
		NB_Shader(const NB_Shader&) {}
		NB_Shader& operator=(const NB_Shader&) {}
		//

		GLuint create_shader(const std::string& text, const GLenum sader_type);

		void error_check(GLuint shader, GLuint flag, bool isProgram,
			const std::string& errorMessage, const std::string& file_name);

	};
}

#endif //NB_SHADER_H_INCLUDED