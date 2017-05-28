#include "NB_Light.h"


void NB::NB_Light::move_x(float delta)
{
	this->position.x += delta;
}

void NB::NB_Light::move_y(float delta)
{
	this->position.y += delta;
}

void NB::NB_Light::move_z(float delta)
{
	this->position.z += delta;
}

void NB::NB_Light::change_color(glm::vec4 color)
{
	this->type.color = color;
}
//


void NB::NB_Light_Cube::move_x(float delta)
{
	this->position.x += delta;
	this->cube.position.pos.x = this->position.x;
}

void NB::NB_Light_Cube::move_y(float delta)
{
	this->position.y += delta;
	this->cube.position.pos.y = this->position.y;
}

void NB::NB_Light_Cube::move_z(float delta)
{
	this->position.z += delta;
	this->cube.position.pos.z = this->position.z;
}

void NB::NB_Light_Cube::change_color(glm::vec4 color)
{
	this->cube.color = color;
	this->type.color = color;
}
