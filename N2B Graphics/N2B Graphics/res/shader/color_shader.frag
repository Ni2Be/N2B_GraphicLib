#version 330 core

uniform sampler2D texture1;
uniform sampler2D texture2;

in vec4 vertex_color;

out vec4 color;



void main()
{
	color = vertex_color;
}
