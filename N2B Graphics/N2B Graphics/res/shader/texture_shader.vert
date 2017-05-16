#version 330 core


uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;


layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texture_coo;

out vec4 vertex_color;
out vec2 vertex_texture_coo;

void main()
{
	gl_Position = projection * view * transform * vec4(position.x, position.y, position.z, 1.0f);

	vertex_color = color;
	vertex_texture_coo = texture_coo;
}