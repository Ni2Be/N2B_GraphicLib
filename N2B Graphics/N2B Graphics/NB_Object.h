/*
NB_OBJECT:
Attention:
Purpose:
Usage:
*/

#ifdef NB_PRAGMA_ONCE_SUPPORT
#pragma once
#endif
#ifndef NB_NB_OBJECT_H_INCLUDED
#define NB_NB_OBJECT_H_INCLUDED

#include "NB_Mesh.h"
#include "NB_Transformer.h"
#include "NB_Shader.h"
#include "NB_Display.h"

namespace NB
{
	class NB_Object
	{
	public:
		NB_Object() {}
		~NB_Object()
		{
			delete mesh;
		}

		std::vector<NB::NB_Vertex> vertices;
		NB::NB_Mesh* mesh;
		NB::NB_Transformer position;
		glm::vec4 color;

		inline void draw() const
		{
			mesh->draw();
		}
	};

	class NB_Cube : public NB_Object
	{
	public:
		NB_Cube(glm::vec3 pos, glm::vec4 color, float width, float height, float depth)
		{
			position.pos = pos;

			width /= 2;
			height /= 2;
			depth /= 2;

			NB_Object::vertices =
			{
				//Front
				NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ -width, -height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, -height, +depth }, color },

				NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, +height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, -height, +depth }, color },

				//Back/
				NB::NB_Vertex{ glm::vec3{ -width, +height, -depth }, color },
				NB::NB_Vertex{ glm::vec3{ -width, -height, -depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, -height, -depth }, color },

				NB::NB_Vertex{ glm::vec3{ -width, +height, -depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, +height, -depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, -height, -depth }, color },

				//Right
				NB::NB_Vertex{ glm::vec3{ +width, +height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, -height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, -height, -depth }, color },

				NB::NB_Vertex{ glm::vec3{ +width, +height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, +height, -depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, -height, -depth }, color },

				//Left/
				NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ -width, -height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ -width, -height, -depth }, color },

				NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ -width, +height, -depth }, color },
				NB::NB_Vertex{ glm::vec3{ -width, -height, -depth }, color },

				//Top
				NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, +height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, +height, -depth }, color },

				NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ -width, +height, -depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, +height, -depth }, color },

				//Bottom
				NB::NB_Vertex{ glm::vec3{ -width, -width, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, -width, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, -width, -depth }, color },

				NB::NB_Vertex{ glm::vec3{ -width, -width, +depth }, color },
				NB::NB_Vertex{ glm::vec3{ -width, -width, -depth }, color },
				NB::NB_Vertex{ glm::vec3{ +width, -width, -depth }, color },
			};

			NB_Object::mesh = new NB::NB_Mesh(NB_Object::vertices);
		}
	};
}
#endif
