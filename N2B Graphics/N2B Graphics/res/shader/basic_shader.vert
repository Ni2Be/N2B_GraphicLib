#version 400

attribute vec3 position;
attribute vec2 texture_coordinate;

varying vec2 texture_coordinate0;

uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(position, 1.0);
	texture_coordinate0 = texture_coordinate;
}