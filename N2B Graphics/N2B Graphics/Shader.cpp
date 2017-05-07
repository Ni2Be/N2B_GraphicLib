#include "Shader.h"
#include "NB_Utility.h"

Shader::Shader(const std::string& fileName)
{
	m_program = glCreateProgram();
	m_shaders[0] = create_shader(fileName + ".vert", GL_VERTEX_SHADER);
	m_shaders[1] = create_shader(fileName + ".frag", GL_FRAGMENT_SHADER);

	for (unsigned int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(m_program, m_shaders[i]);


	glBindAttribLocation(m_program, 0, "position");
	glBindAttribLocation(m_program, 1, "texture_coordinate");


	glLinkProgram(m_program);
	error_check(m_program, GL_LINK_STATUS, true, "Shader linking fail: ", fileName);

	glValidateProgram(m_program);
	error_check(m_program, GL_VALIDATE_STATUS, true, "Program is invalid: ", fileName);

	m_uniforms[TRANSFORM_U] = glGetUniformLocation(m_program, "transform");
}

Shader::~Shader()
{
	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}
	glDeleteProgram(m_program);
}

void Shader::use()
{
	glUseProgram(m_program);
}


GLuint Shader::create_shader(const std::string& file_name, const GLenum shader_type)
{
	GLuint shader = glCreateShader(shader_type);
	if (shader == 0)
		error_log(__func__, "Shader creation failed");

	std::string file_content = load_file_to_string(file_name).c_str();
	const GLchar* shader_code = static_cast<const GLchar*>(file_content.c_str());

	glShaderSource(shader, 1, &shader_code, NULL);
	glCompileShader(shader);

	error_check(shader, GL_COMPILE_STATUS, false, "Shader compilation fail: ", file_name);

	return shader;
}





void Shader::error_check(GLuint get_checked, GLuint flag, bool is_program, const std::string& error_message, const std::string& file_name)
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

		std::string send_error = "Error in " + file_name + "\n" + error_message;
		error_log(__func__, send_error + error);
	}
}