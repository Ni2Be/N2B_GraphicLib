#version 330 core

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec3 light_color;

in vec4 vertex_color;

out vec4 color;



void main()
{
	color = vec4(light_color, 1.0f);
}
