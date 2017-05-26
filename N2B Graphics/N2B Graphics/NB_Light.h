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
	struct NB_Light_Properties
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
			glm::vec4 color,
			float strength,
			float ambient_strength,
			float attenuation_const = 1.0f,
			float attenuation_lin = 0.09f,
			float attenuation_quad = 0.032f)
			:
			position(position),
			color(color),
			strength(strength),
			ambient_strength(ambient_strength),
			attenuation_const(attenuation_const),
			attenuation_lin(attenuation_lin),
			attenuation_quad(attenuation_quad){}
	public:
		virtual void move_x(float delta);
		virtual void move_y(float delta);
		virtual void move_z(float delta);

		float strength;
		float ambient_strength;
		glm::vec4 color;
		float attenuation_const;
		float attenuation_lin;
		float attenuation_quad;

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
			NB_Material light)
			:
			NB_Light(
				position,
				color,
				light.strength,
				light.ambient_strength),
			cube(
				position,
				color,
				width,
				height,
				depth,
				light) {}

		NB_Light_Cube(
			glm::vec3 position,
			glm::vec4 color,
			float width,
			float height,
			float depth,
			NB_Material light,
			float attenuation_const,
			float attenuation_lin,
			float attenuation_quad)
			:
			NB_Light(
				position,
				color,
				light.strength,
				light.ambient_strength,
				attenuation_const,
				attenuation_lin,
				attenuation_quad),
			cube(
				position,
				color,
				width,
				height,
				depth,
				light) {}

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
}
#endif
