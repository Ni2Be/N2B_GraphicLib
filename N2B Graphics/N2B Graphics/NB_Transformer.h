/*
NB_Transformer:
Attention:
Purpose:
Usage:
*/

#ifdef NB_PRAGMA_ONCE_SUPPORT
#pragma once
#endif
#ifndef NB_TRANSFORMER_H_INCLUDED
#define NB_TRANSFORMER_H_INCLUDED

//GLEW
#include <GL/glew.h>

//GLM
#include <glm.hpp>
#include <gtx/transform.hpp>

namespace NB {
	class NB_Transformer
	{
	public:
		NB_Transformer(
			const glm::vec3& pos = glm::vec3(),
			const glm::vec3& rot = glm::vec3(),
			const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f))
			:pos(pos), rot(rot), scale(scale) 
		{}

		virtual ~NB_Transformer() {}

		inline glm::mat4 get_model() const
		{
			glm::mat4 pos_mat = glm::translate(pos);
			glm::mat4 scale_mat = glm::scale(scale);

			glm::mat4 rot_x_mat = glm::rotate(rot.x, glm::vec3(1, 0, 0));
			glm::mat4 rot_y_mat = glm::rotate(rot.y, glm::vec3(0, 1, 0));
			glm::mat4 rot_z_mat = glm::rotate(rot.z, glm::vec3(0, 0, 1));

			glm::mat4 rot_mat = rot_z_mat * rot_y_mat * rot_x_mat;

			return pos_mat * rot_mat * scale_mat;
		}

		inline void set_scale(float vactor)
		{
			scale.x = vactor;
			scale.y = vactor;
			scale.z = vactor;
		}

		glm::vec3 pos;
		glm::vec3 rot;
		glm::vec3 scale;

	private:
		//no copy
		NB_Transformer(const NB_Transformer&) {}
		NB_Transformer& operator=(const NB_Transformer&) {}
		//
	};
}
#endif
