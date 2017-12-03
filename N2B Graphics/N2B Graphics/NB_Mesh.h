/*
NB_Mesh:
Attention:
Purpose:
Usage:
*/

#include "NB_Utility.h"

#ifdef NB_PRAGMA_ONCE_SUPPORT
#pragma once
#endif
#ifndef NB_MESH_H_INCLUDED
#define NB_MESH_H_INCLUDED

//Ogl math
#include <glm.hpp>
//GLEW
#include <GL/glew.h>

//STL
#include <vector>


//

#include "NB_Texture.h"

namespace NB 
{
	class NB_Vertex
	{
		friend class old_NB_Mesh;
		friend class NB_Mesh;
	public:
		NB_Vertex(
			const glm::vec3& pos,
			const glm::vec4& color   = glm::vec4{  1.0f,  1.0f, 1.0f, 1.0f },
			const glm::vec2& texture = glm::vec2{ -1.0f, -1.0f },
			const glm::vec3& normal  = glm::vec3{  0.0f,  0.0f, 0.0f })
			:
			pos		(pos), 
			color	(color), 
			texture	(texture), 
			normal	(normal) 
		{}
	private:
		glm::vec3 pos;
		glm::vec4 color;
		glm::vec2 texture;
		glm::vec3 normal;
	};

	//class old_NB_Mesh
	//{
	//public:
	//	explicit old_NB_Mesh(const std::vector<NB_Vertex>& vertices);
	//	
	//	void draw();

	//	~old_NB_Mesh();
	//private:
	//	GLuint vertex_Array_Object;
	//	GLuint vertex_Buffer_Object;
	//	GLuint draw_count;
	//};

	//Mesh
	class NB_Mesh
	{
	public:
		explicit NB_Mesh(const std::vector<NB_Vertex>& vertices);


		NB_Mesh(
			const std::vector<NB_Vertex>&	vertices,
			const std::vector<GLuint>&		indices,
			const std::vector<NB_Texture>&  textures);

		void setup_mesh();
		void draw();

		~NB_Mesh();


		std::vector<NB_Vertex>		m_vertices;
		std::vector<unsigned int>	m_indices;
		std::vector<NB_Texture>		m_textures;
	private:
		GLuint m_EBO;
		GLuint m_VAO;
		GLuint m_VBO;
		GLuint m_draw_count;
	};
}
#endif