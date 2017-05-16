#include "NB_Shader.h"
#include "NB_Utility.h"

#include <gtc/type_ptr.hpp>

NB::NB_Shader::NB_Shader(const std::string& fileName)
{
	//compile shaders
	GLuint vetex_shader = create_shader(fileName + ".vert", GL_VERTEX_SHADER);
	GLuint fragment_shader = create_shader(fileName + ".frag", GL_FRAGMENT_SHADER);

	//link to program
	program = glCreateProgram();
	glAttachShader(program, vetex_shader);
	glAttachShader(program, fragment_shader);
	
	glBindAttribLocation(program, 0, "position");

	glLinkProgram(program);
	error_check(program, GL_LINK_STATUS, true, "Shader linking fail: ", fileName);

	glValidateProgram(program);
	error_check(program, GL_VALIDATE_STATUS, true, "Program is invalid: ", fileName);

	bind_uniforms();

	glDeleteShader(vetex_shader);
	glDeleteShader(fragment_shader);
}

void NB::NB_Shader::bind_uniforms()
{
	uni_transform = glGetUniformLocation(program, "transform");
	uni_view = glGetUniformLocation(program, "view");
	uni_projection = glGetUniformLocation(program, "projection");
}

NB::NB_Shader::~NB_Shader()
{
	glDeleteProgram(program);
}

void NB::NB_Shader::use()
{
	glUseProgram(program);
}

void NB::NB_Shader::update(const NB_Transformer& trans, const NB::NB_Camera cam)
{
	//Transformer
	glUniformMatrix4fv(uni_transform, 1, GL_FALSE, glm::value_ptr(trans.get_model()));

	//Camera
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, glm::value_ptr(cam.view));
	glUniformMatrix4fv(uni_projection, 1, GL_FALSE, glm::value_ptr(cam.projection));
}

GLuint NB::NB_Shader::create_shader(const std::string& file_name, const GLenum shader_type)
{
	GLuint shader = glCreateShader(shader_type);
	if (shader == 0)
		error_log("NB::NB_Shader::create_shader", "Shader creation failed");

	std::string file_content = load_file_to_string(file_name).c_str();
	const GLchar* shader_code = static_cast<const GLchar*>(file_content.c_str());

	glShaderSource(shader, 1, &shader_code, NULL);
	glCompileShader(shader);

	error_check(shader, GL_COMPILE_STATUS, false, "Shader compilation fail: ", file_name);

	return shader;
}

void NB::NB_Shader::error_check(GLuint get_checked, GLuint flag, bool is_program, const std::string& error_message, const std::string& file_name)
{
	GLint success = 0;
	if (is_program)
		glGetProgramiv(get_checked, flag, &success);
	else
		glGetShaderiv(get_checked, flag, &success);

	if (success == GL_FALSE)
	{
		GLchar error[1024] = { 0 };
		if (is_program)
			glGetProgramInfoLog(get_checked, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(get_checked, sizeof(error), NULL, error);

		error_log("NB::NB_Shader::error_check\n", "Error in " + file_name + "\n" + error_message + error);
	}
}
