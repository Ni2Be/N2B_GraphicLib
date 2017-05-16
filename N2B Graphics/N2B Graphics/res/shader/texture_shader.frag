#version 330 core

uniform sampler2D texture1;
uniform sampler2D texture2;

in vec4 vertex_color;
in vec2 vertex_texture_coo;

out vec4 color;



void main()
{
		color = mix(texture(texture1, vertex_texture_coo), texture(texture2, vertex_texture_coo), 0.5) * vertex_color;
}

