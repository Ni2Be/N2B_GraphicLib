

#version 330 core


uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;


layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 3) in vec3 normal;

out vec4 vertex_color;
out vec3 vertex_normal;
out vec3 vertex_pos;

void main()
{
	gl_Position = projection * view * transform * vec4(position.x, position.y, position.z, 1.0f);

	vertex_color = color;
	vertex_normal = normal;
	vertex_pos = vec3(transform * vec4(position.x, position.y, position.z, 1.0f));
}