#include "NB_Object.h"



NB::NB_Object::NB_Object(const NB_Object& lhs)
{
	this->color = lhs.color;
	this->material = lhs.material;
	this->position = lhs.position;
	this->vertices = lhs.vertices;
	this->mesh = new NB_Mesh(this->vertices);
}