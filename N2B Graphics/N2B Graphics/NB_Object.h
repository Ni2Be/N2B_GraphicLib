/*
NB_OBJECT:
Attention:
Purpose:
Usage:
*/

#ifdef NB_PRAGMA_ONCE_SUPPORT
#pragma once
#endif
#ifndef NB_OBJECT_H_INCLUDED
#define NB_OBJECT_H_INCLUDED

//
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

//
#include "NB_Mesh.h"
#include "NB_Transformer.h"
#include "NB_Material.h"
#include "NB_Texture.h"

namespace NB
{
	class NB_Object
	{
	public:
		NB_Object(glm::vec4 color, NB_Material material)
		:color(color), material(material){}
		~NB_Object()
		{
			delete mesh;
		}

		NB_Object(const NB_Object& lhs);

		std::vector<NB::NB_Vertex> vertices;
		NB::NB_Mesh* mesh;
		NB::NB_EMesh* e_mesh;
		NB::NB_Transformer position;
		glm::vec4 color;
		NB::NB_Material material;

		virtual void draw() const;
	};

	class NB_Cube : public NB_Object
	{
	public:
		void transform(float width, float height, float depth)
		{
			width /= 2;
			height /= 2;
			depth /= 2;
			NB_Object::vertices =
			{
			//Front
			NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f, 1.0f } },
			NB::NB_Vertex{ glm::vec3{ -width, -height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f, 1.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, -height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f, 1.0f } },

			NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f, 1.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, +height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f, 1.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, -height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f, 1.0f } },

			//Back/
			NB::NB_Vertex{ glm::vec3{ -width, +height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f,-1.0f } },
			NB::NB_Vertex{ glm::vec3{ -width, -height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f,-1.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, -height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f,-1.0f } },

			NB::NB_Vertex{ glm::vec3{ -width, +height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f,-1.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, +height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f,-1.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, -height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f,-1.0f } },

			//Right
			NB::NB_Vertex{ glm::vec3{ +width, +height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 1.0f, 0.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, -height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 1.0f, 0.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, -height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 1.0f, 0.0f, 0.0f } },

			NB::NB_Vertex{ glm::vec3{ +width, +height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 1.0f, 0.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, +height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 1.0f, 0.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, -height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 1.0f, 0.0f, 0.0f } },

			//Left/
			NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ -1.0f, 0.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ -width, -height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ -1.0f, 0.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ -width, -height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ -1.0f, 0.0f, 0.0f } },

			NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ -1.0f, 0.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ -width, +height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ -1.0f, 0.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ -width, -height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ -1.0f, 0.0f, 0.0f } },

			//Top
			NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, +height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, +height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f } },

			NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ -width, +height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, +height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f } },

			//Bottom
			NB::NB_Vertex{ glm::vec3{ -width, -width, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f,-1.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, -width, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f,-1.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, -width, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f,-1.0f, 0.0f } },

			NB::NB_Vertex{ glm::vec3{ -width, -width, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f,-1.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ -width, -width, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f,-1.0f, 0.0f } },
			NB::NB_Vertex{ glm::vec3{ +width, -width, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f,-1.0f, 0.0f } },
		};
		delete mesh;
		mesh = new NB::NB_Mesh(NB_Object::vertices);
		}

		NB_Cube(glm::vec3 pos, glm::vec4 color, float width, float height, float depth, NB_Material material)
			:NB_Object(color, material)
		{
			position.pos = pos;

			width /= 2;
			height /= 2;
			depth /= 2;

			NB_Object::vertices =
			{
				//Front
				NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color, glm::vec2{ 0.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f, 1.0f } },
				NB::NB_Vertex{ glm::vec3{ -width, -height, +depth }, color, glm::vec2{ 0.0f, 0.0f }, glm::vec3{ 0.0f, 0.0f, 1.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, -height, +depth }, color, glm::vec2{ 1.0f, 0.0f }, glm::vec3{ 0.0f, 0.0f, 1.0f } },

				NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color, glm::vec2{ 0.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f, 1.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, +height, +depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f, 1.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, -height, +depth }, color, glm::vec2{ 1.0f, 0.0f }, glm::vec3{ 0.0f, 0.0f, 1.0f } },

				//Back/
				NB::NB_Vertex{ glm::vec3{ -width, +height, -depth }, color, glm::vec2{ 0.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f,-1.0f } },
				NB::NB_Vertex{ glm::vec3{ -width, -height, -depth }, color, glm::vec2{ 0.0f, 0.0f }, glm::vec3{ 0.0f, 0.0f,-1.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, -height, -depth }, color, glm::vec2{ 1.0f, 0.0f }, glm::vec3{ 0.0f, 0.0f,-1.0f } },

				NB::NB_Vertex{ glm::vec3{ -width, +height, -depth }, color, glm::vec2{ 0.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f,-1.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, +height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 0.0f,-1.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, -height, -depth }, color, glm::vec2{ 1.0f, 0.0f }, glm::vec3{ 0.0f, 0.0f,-1.0f } },

				//Right
				NB::NB_Vertex{ glm::vec3{ +width, +height, +depth }, color, glm::vec2{ 0.0f, 1.0f }, glm::vec3{ 1.0f, 0.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, -height, +depth }, color, glm::vec2{ 0.0f, 0.0f }, glm::vec3{ 1.0f, 0.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, -height, -depth }, color, glm::vec2{ 1.0f, 0.0f }, glm::vec3{ 1.0f, 0.0f, 0.0f } },

				NB::NB_Vertex{ glm::vec3{ +width, +height, +depth }, color, glm::vec2{ 0.0f, 1.0f }, glm::vec3{ 1.0f, 0.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, +height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 1.0f, 0.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, -height, -depth }, color, glm::vec2{ 1.0f, 0.0f }, glm::vec3{ 1.0f, 0.0f, 0.0f } },

				//Left/
				NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color, glm::vec2{ 0.0f, 1.0f }, glm::vec3{ -1.0f, 0.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ -width, -height, +depth }, color, glm::vec2{ 0.0f, 0.0f }, glm::vec3{ -1.0f, 0.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ -width, -height, -depth }, color, glm::vec2{ 1.0f, 0.0f }, glm::vec3{ -1.0f, 0.0f, 0.0f } },

				NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color, glm::vec2{ 0.0f, 1.0f }, glm::vec3{ -1.0f, 0.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ -width, +height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ -1.0f, 0.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ -width, -height, -depth }, color, glm::vec2{ 1.0f, 0.0f }, glm::vec3{-1.0f, 0.0f, 0.0f } },

				//Top
				NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color, glm::vec2{ 0.0f, 1.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, +height, +depth }, color, glm::vec2{ 0.0f, 0.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, +height, -depth }, color, glm::vec2{ 1.0f, 0.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f } },

				NB::NB_Vertex{ glm::vec3{ -width, +height, +depth }, color, glm::vec2{ 0.0f, 1.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ -width, +height, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, +height, -depth }, color, glm::vec2{ 1.0f, 0.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f } },

				//Bottom
				NB::NB_Vertex{ glm::vec3{ -width, -width, +depth }, color, glm::vec2{ 0.0f, 1.0f }, glm::vec3{ 0.0f,-1.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, -width, +depth }, color, glm::vec2{ 0.0f, 0.0f }, glm::vec3{ 0.0f,-1.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, -width, -depth }, color, glm::vec2{ 1.0f, 0.0f }, glm::vec3{ 0.0f,-1.0f, 0.0f } },

				NB::NB_Vertex{ glm::vec3{ -width, -width, +depth }, color, glm::vec2{ 0.0f, 1.0f }, glm::vec3{ 0.0f,-1.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ -width, -width, -depth }, color, glm::vec2{ 1.0f, 1.0f }, glm::vec3{ 0.0f,-1.0f, 0.0f } },
				NB::NB_Vertex{ glm::vec3{ +width, -width, -depth }, color, glm::vec2{ 1.0f, 0.0f }, glm::vec3{ 0.0f,-1.0f, 0.0f } },
			};

			NB_Object::mesh = new NB::NB_Mesh(NB_Object::vertices);
		}
	};

	class NB_Model : public NB_Object
	{
	public:
		explicit NB_Model(const std::string& path, glm::vec4 color, NB_Material material)
			:NB_Object(color, material)
		{
			this->loadModel(path);
		}

		void NB::NB_Model::draw() const;
	private:
		std::vector<NB_EMesh*> meshes;
		std::string directory;
		
		
		void loadModel(std::string path);
		void processNode(aiNode* node, const aiScene* scene);
		NB_EMesh* processMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<NB_Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
			std::string typeName);
	};
}
#endif
