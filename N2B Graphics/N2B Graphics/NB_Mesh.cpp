#include "NB_Mesh.h"
#include <vector>
#include <iostream>

//NB::old_NB_Mesh::old_NB_Mesh(const std::vector<NB_Vertex>& vertices)
//{
//	draw_count = static_cast<GLuint>(vertices.size());
//
//	//generate 1 vertex array object and bind it
//	glGenVertexArrays(1, &vertex_Array_Object);
//	glBindVertexArray(vertex_Array_Object);
//	
//	//generate 1 Buffer on the graphics card
//	glGenBuffers(1, &vertex_Buffer_Object);
//
//	//bind the buffer a Vertex_Buffer is of the type GL_ARRAY_BUFFER
//	//bind means every call that is now made will accure to the binded buffer
//	glBindBuffer(GL_ARRAY_BUFFER, vertex_Buffer_Object);
//
//	//allocate memory and save data
//	//type of the target, size of the send data, pointer to the data, usage:
//	//GL_STATIC_DRAW: the data will most likely not change at all or very rarely.
//	//GL_DYNAMIC_DRAW : the data is likely to change a lot.
//	//GL_STREAM_DRAW : the data will change every time it is drawn.
//	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STREAM_DRAW);
//
//
//	//where is the vertex data is located that needs to be send to the shader
//	//index, how many at all, what type are the single values, normalized?, 
//	//how big is one vertex, offset
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
//		sizeof(NB_Vertex),
//		(GLvoid*)offsetof(NB_Vertex, pos));
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
//		sizeof(NB_Vertex),
//		(GLvoid*) offsetof(NB_Vertex, color));
//	glEnableVertexAttribArray(1);
//
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
//		sizeof(NB_Vertex),
//		(GLvoid*)offsetof(NB_Vertex, texture));
//	glEnableVertexAttribArray(2);
//
//	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE,
//		sizeof(NB_Vertex),
//		(GLvoid*)offsetof(NB_Vertex, normal));
//	glEnableVertexAttribArray(3);
//
//	//unbinde
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//}
//
//void NB::old_NB_Mesh::draw()
//{     
//	glBindVertexArray(vertex_Array_Object);
//	glDrawArrays(GL_TRIANGLES, 0, draw_count);
//	glBindVertexArray(0);
//}
//
//NB::old_NB_Mesh::~old_NB_Mesh()
//{
//	glDeleteVertexArrays(1, &vertex_Array_Object);
//}


NB::NB_Mesh::NB_Mesh(const std::vector<NB_Vertex>& vertices)
	:
	m_vertices(vertices)
{
	for (int i = 0; i < m_vertices.size(); i++)
		m_indices.push_back(i);

	setup_mesh();
}


NB::NB_Mesh::NB_Mesh(
	const std::vector<NB_Vertex>&	vertices,
	const std::vector<GLuint>&		indices,
	const std::vector<NB_Texture>&  textures)
	:
	m_vertices(vertices),
	m_indices(indices),
	m_textures(textures)
{
	setup_mesh();
}

void NB::NB_Mesh::setup_mesh()
{
	m_draw_count = static_cast<GLuint>(m_indices.size());

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers	 (1, &m_VBO);
	glGenBuffers	 (1, &m_EBO);

	glBindVertexArray(m_VAO);

	//type of the target, size of the send data, pointer to the data, usage:
	//GL_STATIC_DRAW  : the data will most likely not change at all or very rarely.
	//GL_DYNAMIC_DRAW : the data is likely to change a lot.
	//GL_STREAM_DRAW  : the data will change every time it is drawn.
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(m_vertices[0]), &(m_vertices[0]), GL_STREAM_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(m_indices[0]), &m_indices[0], GL_STATIC_DRAW);

	//index, how many, what type are the single values, normalized?, 
	//how big is one vertex, offset
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		sizeof(NB_Vertex),
		(GLvoid*)offsetof(NB_Vertex, pos));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
		sizeof(NB_Vertex),
		(GLvoid*)offsetof(NB_Vertex, color));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
		sizeof(NB_Vertex),
		(GLvoid*)offsetof(NB_Vertex, texture));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE,
		sizeof(NB_Vertex),
		(GLvoid*)offsetof(NB_Vertex, normal));

	//unbinde
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void NB::NB_Mesh::draw()
{
	glBindVertexArray(m_VAO);
	glDrawElements	 (GL_TRIANGLES, m_draw_count, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

NB::NB_Mesh::~NB_Mesh()
{
	glDeleteVertexArrays(1, &m_VAO);
}
