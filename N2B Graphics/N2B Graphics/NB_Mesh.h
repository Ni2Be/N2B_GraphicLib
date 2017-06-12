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
		friend class NB_Mesh;
		friend class NB_EMesh;
	public:
		NB_Vertex(
			const glm::vec3& pos,
			const glm::vec4& color = glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f },
			const glm::vec2& texture = glm::vec2{ -1.0f, -1.0f },
			const glm::vec3& normal =  glm::vec3{ 0.0f, 0.0f, 0.0f })
			:pos(pos), 
			color(color), 
			texture(texture), 
			normal(normal) {}

		NB_Vertex(
			const glm::vec3& pos, 
			GLfloat alpha = 1.0f, 
			const glm::vec2& texture = glm::vec2{ 1.0f, 1.0f },
			const glm::vec3& normal = glm::vec3{ 0.0f, 0.0f, 0.0f })
			:pos(pos), 
			color(glm::vec4{ 1.0f, 1.0f, 1.0f, alpha }), 
			texture(texture), 
			normal(normal) {}
	private:
		glm::vec3 pos;
		glm::vec4 color;
		glm::vec2 texture;
		glm::vec3 normal;
	};

	class NB_Mesh
	{
	public:
		explicit NB_Mesh(const std::vector<NB_Vertex>& vertices);
		
		void draw();

		~NB_Mesh();
	private:
		GLuint vertex_Array_Object;
		GLuint vertex_Buffer_Object;
		GLuint draw_count;
	};

	//Element Mesh
	class NB_EMesh
	{
	public:
		NB_EMesh(
			const std::vector<NB_Vertex>& vertices,
			const std::vector<GLuint>& indices);

		void draw();

		~NB_EMesh();
	private:
		GLuint element_buffer_object;
		GLuint vertex_Array_Object;
		GLuint vertex_Buffer_Object;
		GLuint draw_count;
	};
}
#endif