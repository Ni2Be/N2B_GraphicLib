#include "NB_Object.h"
#include <assimp/postprocess.h>
#include <iostream>

NB::NB_Object::NB_Object(const NB_Object& lhs)
{
	this->color = lhs.color;
	this->material = lhs.material;
	this->position = lhs.position;
	this->vertices = lhs.vertices;
	this->mesh = new NB_Mesh(this->vertices);
}

void NB::NB_Object::draw() const
{
	mesh->draw();
}



void NB::NB_Model::loadModel(std::string path)
{
	Assimp::Importer import;
	const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);
	

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::string error = import.GetErrorString();
		NB::error_log("ERROR::ASSIMP::", error);
		return;
	}
	this->directory = path.substr(0, path.find_last_of('/'));

	this->processNode(scene->mRootNode, scene);
}

void NB::NB_Model::processNode(aiNode* node, const aiScene* scene)
{
	// Process all the node's meshes (if any)
	for (GLuint i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		this->meshes.push_back(this->processMesh(mesh, scene));
	}
	// Then do the same for each of its children
	for (GLuint i = 0; i < node->mNumChildren; i++)
	{
		this->processNode(node->mChildren[i], scene);
	}
}

NB::NB_Model::Material_Mesh* NB::NB_Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	//material
	NB::NB_Material material
	{
		glm::vec3{ 0.24725,	0.1995,	0.0745 },
		glm::vec3{ 0.75164, 0.60648, 0.22648 },
		glm::vec3{ 0.628281, 0.555802, 0.366065 },
		0.4f
	};

	std::cout << "Material count: " << scene->mNumMaterials << std::endl;
	std::cout << "Material index: " << mesh->mMaterialIndex << std::endl;

	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial *mat = scene->mMaterials[mesh->mMaterialIndex];
		
		aiString diffuse_dict;
		mat->GetTexture(aiTextureType_DIFFUSE, (unsigned int)0, &diffuse_dict);
		NB_Texture* diffuse = new NB_Texture(this->directory + "/" + diffuse_dict.C_Str());
		material.texture = diffuse;

		std::cout << "Texture path: " << this->directory + "/" + diffuse_dict.C_Str() << std::endl;
		std::cout << "Texture count: " << mat->GetTextureCount(aiTextureType_DIFFUSE) << std::endl;

		aiString specular_dict;
		mat->GetTexture(aiTextureType_SPECULAR, (unsigned int)0, &specular_dict);
		NB_Texture* specular = new NB_Texture(this->directory + "/" + specular_dict.C_Str());
		material.specular_map = specular;

		std::cout << "Texture path: " << this->directory + "/" + specular_dict.C_Str() << std::endl;
		std::cout << "Texture count: " << mat->GetTextureCount(aiTextureType_SPECULAR) << std::endl;
	}
	
	//verticies
	std::vector<NB_Vertex> vertices;
	for (GLuint i = 0; i < mesh->mNumVertices; i++)
	{
		vertices.push_back
			(
			NB::NB_Vertex{ 
				glm::vec3{ mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z },
				color, 
				glm::vec2{ mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y },
				glm::vec3{ mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z } }
			);
	}
	//indices
	std::vector<GLuint> indices;
	for (GLuint i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (GLuint j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}

	return new Material_Mesh(new NB_EMesh(vertices, indices), material);
}




void NB::NB_Model::draw(GLint uni_material_texture, GLint uni_material_specular_map)
{
	for (auto m : meshes)
	{
		m->draw(uni_material_texture, uni_material_specular_map);
	}
}

void NB::NB_Model::Material_Mesh::draw(GLint uni_material_texture, GLint uni_material_specular_map)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, material.texture->id);
	glUniform1i(uni_material_texture, 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, material.specular_map->id);
	glUniform1i(uni_material_specular_map, 1);

	mesh->draw();
}
