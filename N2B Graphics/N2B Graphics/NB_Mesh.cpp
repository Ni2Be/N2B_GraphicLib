#include "NB_Mesh.h"
#include <vector>
#include <iostream>

NB::NB_Mesh::NB_Mesh(const std::vector<NB_Vertex>& vertices)
{
	draw_count = static_cast<GLuint>(vertices.size());

	//generate 1 vertex array object and bind it
	glGenVertexArrays(1, &vertex_Array_Object);
	glBindVertexArray(vertex_Array_Object);
	
	//generate 1 Buffer on the graphics card
	glGenBuffers(1, &vertex_Buffer_Object);

	//bind the buffer a Vertex_Buffer is of the type GL_ARRAY_BUFFER
	//bind means every call that is now made will accure to the binded buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertex_Buffer_Object);

	//allocate memory and save data
	//type of the target, size of the send data, pointer to the data, usage:
	//GL_STATIC_DRAW: the data will most likely not change at all or very rarely.
	//GL_DYNAMIC_DRAW : the data is likely to change a lot.
	//GL_STREAM_DRAW : the data will change every time it is drawn.
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STREAM_DRAW);


	//where is the vertex data is located that needs to be send to the shader
	//index, how many at all, what type are the single values, normalized?, 
	//how big is one vertex, offset
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		sizeof(NB_Vertex),
		(GLvoid*)offsetof(NB_Vertex, pos));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
		sizeof(NB_Vertex),
		(GLvoid*) offsetof(NB_Vertex, color));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
		sizeof(NB_Vertex),
		(GLvoid*)offsetof(NB_Vertex, texture));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE,
		sizeof(NB_Vertex),
		(GLvoid*)offsetof(NB_Vertex, normal));
	glEnableVertexAttribArray(3);

	//unbinde
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void NB::NB_Mesh::draw()
{     
	glBindVertexArray(vertex_Array_Object);
	glDrawArrays(GL_TRIANGLES, 0, draw_count);
	glBindVertexArray(0);
}

NB::NB_Mesh::~NB_Mesh()
{
	glDeleteVertexArrays(1, &vertex_Array_Object);
}

NB::NB_EMesh::NB_EMesh(
	const std::vector<NB_Vertex>& vertices,
	const std::vector<GLuint>& indices)
{
	draw_count = static_cast<GLuint>(indices.size());

	//generate 1 vertex array object and bind it
	glGenVertexArrays(1, &vertex_Array_Object);
	glBindVertexArray(vertex_Array_Object);

	//generate elemant buffer object and bind it
	glGenBuffers(1, &element_buffer_object);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_object);
	//send the data
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);


	//generate 1 Buffer on the graphics card
	glGenBuffers(1, &vertex_Buffer_Object);

	//bind the buffer a Vertex_Buffer is of the type GL_ARRAY_BUFFER
	//bind means every call that is now made will accure to the binded buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertex_Buffer_Object);

	//allocate memory and save data
	//type of the target, size of the send data, pointer to the data, usage:
	//GL_STATIC_DRAW: the data will most likely not change at all or very rarely.
	//GL_DYNAMIC_DRAW : the data is likely to change a lot.
	//GL_STREAM_DRAW : the data will change every time it is drawn.
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &(vertices[0]), GL_STREAM_DRAW);


	//where is the vertex data is located that needs to be send to the shader
	//index, how many at all, what type are the single values, normalized?, 
	//how big is one vertex, offset
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		sizeof(NB_Vertex),
		(GLvoid*)offsetof(NB_Vertex, pos));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
		sizeof(NB_Vertex),
		(GLvoid*)offsetof(NB_Vertex, color));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
		sizeof(NB_Vertex),
		(GLvoid*)offsetof(NB_Vertex, texture));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE,
		sizeof(NB_Vertex),
		(GLvoid*)offsetof(NB_Vertex, normal));
	glEnableVertexAttribArray(3);

	//unbinde
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void NB::NB_EMesh::draw()
{
	glBindVertexArray(vertex_Array_Object);
	glDrawElements(GL_TRIANGLES, draw_count, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

NB::NB_EMesh::~NB_EMesh()
{
	glDeleteVertexArrays(1, &vertex_Array_Object);
}
