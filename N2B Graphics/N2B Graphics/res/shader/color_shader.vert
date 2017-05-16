#version 330 core


uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;


layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

out vec4 vertex_color;

void main()
{
	gl_Position = projection * view * transform * vec4(position.x, position.y, position.z, 1.0f);

	vertex_color = color;
}