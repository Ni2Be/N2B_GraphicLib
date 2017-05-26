#version 330 core

struct Material 
{
	sampler2D texture;
	sampler2D specular_map;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float shininess;
};
uniform Material material;

struct Light 
{
    vec3 position;
	
	float attenuation_const;
	float attenuation_lin;
	float attenuation_quad;
  
    vec3 color;
	float strength;
	float ambient_strength;
};
uniform Light light;

//Sun
const vec3 sun_light_direction = vec3(0.3f, -1.0f, 0.2f);
const float sun_light_strength = 0.02f;

uniform float ambient_strength;
uniform vec3 ambient_color;

uniform vec3 camera_pos;

in vec4 vertex_color;
in vec3 vertex_normal;
in vec3 vertex_pos;
in vec2 vertex_texture_coo;

out vec4 color;


void main()
{
	//Ambient
	vec3 ambient_light = light.ambient_strength * light.color * vec3(texture(material.texture, vertex_texture_coo));

	//Diffuse
	vec3 vertex_direction = normalize(vertex_normal);
	vec3 light_direction = normalize(light.position - vertex_pos);
	float diffuse_strength = max(dot(vertex_direction, light_direction), 0.0f);
	vec3 diffuse_light = light.strength * diffuse_strength * light.color * vec3(texture(material.texture, vertex_texture_coo));

	//Specular	
	vec3 view_direction = normalize(camera_pos - vertex_pos);
	vec3 reflect_direction = reflect(-light_direction, vertex_direction); 
	float specular_strength = pow(max(dot(view_direction, reflect_direction), 0.0), material.shininess);
	vec3 specular_light = light.strength * specular_strength * light.color * vec3(texture(material.specular_map, vertex_texture_coo));
	
	//Sun
	vec3 sun_light = max(dot(vertex_direction, -sun_light_direction), 0.0f) * sun_light_strength * vec3(texture(material.texture, vertex_texture_coo));

	//Attenuation
	float distance = length(light.position - vertex_pos);
	float attenuation = 1.0f / (light.attenuation_const + light.attenuation_lin * distance + light.attenuation_quad * pow(distance, 2));   

	//SUM
	vec3 light_sum = ambient_light * attenuation + diffuse_light * attenuation + specular_light * attenuation + sun_light;
    color = vec4(light_sum, 1.0f) * vertex_color;
}
