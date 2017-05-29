/*
NB_Draw_Container:
Attention:
Purpose:
Usage:
*/

#ifdef NB_PRAGMA_ONCE_SUPPORT
#pragma once
#endif
#ifndef NB_DRAW_CONTAINER_H_INCLUDED
#define NB_DRAW_CONTAINER_H_INCLUDED

#include <vector>

#include "NB_Camera.h"
#include "NB_Object.h"
#include "NB_Light.h"
#include "NB_Shader.h"

namespace NB
{
	template <class Shader>
	class NB_Draw_Container
	{
	public:
		NB_Draw_Container(
			Shader& shader,
			NB_Camera& camera)
			:shader(&shader),
			camera(&camera)
		{}

		void attach(NB_Light_Cube& light);
		void attach(NB_Object& object);
		void draw();
	private:
		Shader* shader;
		NB_Camera* camera;
		NB_Directional_Light* sun;
		std::vector<NB_Light_Cube*> lights;
		std::vector<NB_Object*> objects;
	};
}

template <class Shader>
void NB::NB_Draw_Container<Shader>::attach(NB_Light_Cube& light)
{
	this->lights.push_back(&light);
}

template <class Shader>
void NB::NB_Draw_Container<Shader>::attach(NB_Object& object)
{
	this->objects.push_back(&object);
}

template <class Shader>
void NB::NB_Draw_Container<Shader>::draw()
{
	for (auto object : objects)
	{
		shader->update(*camera, *object, *sun, lights);
		object.draw();
	}
}
#endif
