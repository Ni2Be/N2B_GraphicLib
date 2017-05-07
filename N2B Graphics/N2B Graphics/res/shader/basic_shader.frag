#version 400

uniform sampler2D diffuse;

varying vec2 texture_coordinate0;

void main()
{
	gl_FragColor = texture2D(diffuse, texture_coordinate0);
}
