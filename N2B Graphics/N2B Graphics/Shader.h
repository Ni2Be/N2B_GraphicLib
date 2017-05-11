#pragma once
#include <string>
#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <glm.hpp>

namespace NB
{
	class Shader
	{
	public:
		Shader(const std::string& fileName);
		~Shader();

		void use();
	private:
		//no copy
		Shader(const Shader&) {}
		Shader& operator=(const Shader&) {}
		//

		GLuint create_shader(const std::string& text, const GLenum sader_type);

		void error_check(GLuint shader, GLuint flag, bool isProgram,
			const std::string& errorMessage, const std::string& file_name);

		enum
		{
			TRANSFORM_U,
			NUM_UNIFORMS,
			NUM_SHADERS = 2
		};

		GLuint program;
		GLuint m_uniforms[NUM_UNIFORMS];
	};
}