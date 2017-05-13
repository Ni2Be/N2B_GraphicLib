#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texture_coo;

out vec4 vertex_color;
out vec2 vertex_texture_coo;

uniform float horizontal_offset;

void main()
{
	gl_Position = vec4(position.x + horizontal_offset, position.y, position.z, 1.0f);

	vertex_color = color;
	vertex_texture_coo = texture_coo;
}