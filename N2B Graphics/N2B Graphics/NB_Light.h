/*
NB_Light:
Attention:
Purpose:
Usage:
*/

#ifdef NB_PRAGMA_ONCE_SUPPORT
#pragma once
#endif
#ifndef NB_LIGHT_H_INCLUDED
#define NB_LIGHT_H_INCLUDED


//GLM
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

//
#include "NB_Object.h"

namespace NB
{
	class NB_Light_Cube : public NB::NB_Cube
	{
	public:
		NB_Light_Cube(glm::vec3 pos, glm::vec4 color, float width, float height, float depth)
			:NB::NB_Cube(pos, color, width, height, depth) {}
		~NB_Light_Cube() {}
	};

	class NB_Ambient_light
	{
	public:
		NB_Ambient_light(glm::vec3 color, float strength)
			:light_color(color), strength(strength) {}
		glm::vec3 light_color;
		float strength;
	};
}
#endif
