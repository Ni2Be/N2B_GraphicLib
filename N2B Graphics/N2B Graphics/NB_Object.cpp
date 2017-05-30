#include "NB_Object.h"
#include <assimp/postprocess.h>

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

void NB::NB_Model::draw() const
{
	for (auto& m : meshes)
	{
		m->draw();
	}
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


NB::NB_EMesh* NB::NB_Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<NB_Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<NB_Texture> textures;


	//TEST
	textures.push_back(*material.texture);
	textures.push_back(*material.specular_map);
	//ENDTEST

	
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
	// Process indices
	for (GLuint i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (GLuint j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}

	return new NB_EMesh(vertices, indices, textures);
}

std::vector<NB::NB_Texture> NB::NB_Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type,
	std::string typeName)
{

}