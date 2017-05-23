#version 330 core

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float shininess;//
};
uniform Material material;

struct Light {
    vec3 position;//
  
    vec3 color;//
	float strength;//
};
uniform Light light;  


uniform float ambient_strength;
uniform vec3 ambient_color;

uniform vec3 camera_pos;

in vec4 vertex_color;
in vec3 vertex_normal;
in vec3 vertex_pos;

out vec4 color;


void main()
{
	//Ambient
	vec3 ambient_light = ambient_strength * ambient_color * material.ambient;

	//Diffuse
	vec3 vertex_direction = normalize(vertex_normal);
	vec3 light_direction = normalize(light.position - vertex_pos);
	float diffuse_strength = max(dot(vertex_direction, light_direction), 0.0f);
	vec3 diffuse_light = light.strength * diffuse_strength * light.color * material.diffuse;

	//Specular	
	vec3 view_direction = normalize(camera_pos - vertex_pos);
	vec3 reflect_direction = reflect(-light_direction, vertex_direction); 
	float specular_strength = pow(max(dot(view_direction, reflect_direction), 0.0), material.shininess);
	vec3 specular_light = light.strength * specular_strength * light.color  * material.specular;  
	//
	vec3 light_sum = ambient_light + diffuse_light + specular_light;
    color = vec4(light_sum, 1.0f) * vertex_color;
}
