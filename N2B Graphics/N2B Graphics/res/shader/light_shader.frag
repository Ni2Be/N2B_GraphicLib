#version 330 core

uniform vec3 diffuse_pos;
uniform vec3 diffuse_color;
uniform float ambient_strength;
uniform vec3 ambient_color;

in vec4 vertex_color;
in vec3 vertex_normal;
in vec3 vertex_pos;

out vec4 color;


void main()
{
	//Ambient
	vec3 ambient_light = ambient_strength * ambient_color;

	//Diffuse
	vec3 vertex_direction = normalize(vertex_normal);
	vec3 light_direction = normalize(diffuse_pos - vertex_pos);
	float diffuse_strength = max(dot(vertex_direction, light_direction), 0.0f);
	vec3 diffuse_light = diffuse_strength * diffuse_color;

	//
	vec3 light_sum = ambient_light + diffuse_light;
    color = vec4(light_sum, 1.0f) * vertex_color;
}