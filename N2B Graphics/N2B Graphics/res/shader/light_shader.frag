#version 330 core

uniform vec4 light_color;

in vec4 vertex_color;

out vec4 color;


void main()
{
    color = light_color * vertex_color;
}