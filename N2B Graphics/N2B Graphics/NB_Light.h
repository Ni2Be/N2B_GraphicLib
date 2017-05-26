/*
NB_Light:
Attention:
Purpose:
Usage:
*/

#include "NB_Utility.h"
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
#include "NB_Material.h"

namespace NB
{
	struct NB_Light_Properties : public NB_Material
	{
		NB_Light_Properties(
			glm::vec4 color,
			float strength,
			float ambient_strength,
			float attenuation_const = 1.0f,
			float attenuation_lin = 0.09f,
			float attenuation_quad = 0.032f)
			:
			color(color),
			strength(strength),
			ambient_strength(ambient_strength),
			attenuation_const(attenuation_const),
			attenuation_lin(attenuation_lin),
			attenuation_quad(attenuation_quad) {}

		float strength;
		float ambient_strength;
		glm::vec4 color;
		float attenuation_const;
		float attenuation_lin;
		float attenuation_quad;
	};

	class NB_Light
	{
	protected:
		NB_Light(
			glm::vec3 position,
			NB_Light_Properties type)
			:
			position(position),
			type(type){}
	public:
		virtual void move_x(float delta);
		virtual void move_y(float delta);
		virtual void move_z(float delta);

		NB_Light_Properties type;

		glm::vec3 position;
	};

	class NB_Light_Cube : public NB::NB_Light
	{
	public:
		NB_Light_Cube(
			glm::vec3 position,
			glm::vec4 color,
			float width,
			float height,
			float depth,
			NB_Light_Properties type)
			:
			NB_Light(
				position,
				type),
			cube(
				position,
				color,
				width,
				height,
				depth,
				type) {}

		~NB_Light_Cube() {}

		NB_Cube cube;

		void move_x(float delta);
		void move_y(float delta);
		void move_z(float delta);
	};


	class NB_Ambient_light
	{
	public:
		NB_Ambient_light(glm::vec3 color, float strength)
			:light_color(color), strength(strength) {}
		glm::vec3 light_color;
		float strength;
	};



	//Light
	const NB_Light_Properties NB_LIGHT_WHITE
	{
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
		1.0f,
		0.2f
	};
}
#endif
