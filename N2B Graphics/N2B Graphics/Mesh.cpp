#include "Mesh.h"


Mesh::Mesh(Vertex* vertices, unsigned int num_vertices)
{
	draw_count = num_vertices;

	glGenVertexArrays(1, &vertex_array_object);
	glBindVertexArray(vertex_array_object);

	//transform into pos and texturepos
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texture_coordinates;
	positions.reserve(num_vertices);
	texture_coordinates.reserve(num_vertices);

	unsigned int pos_offset;
	unsigned int texture_offset;

	for (unsigned int i = 0; i < num_vertices; i++)
	{
		positions.push_back(vertices[i].pos);
		texture_coordinates.push_back(vertices[i].texture_coordinate);
	}

	glGenBuffers(NUM_BUFFERS, vertex_array_buffers);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_array_buffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, num_vertices * sizeof(positions[0]),
		&positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);


	glGenBuffers(NUM_BUFFERS, vertex_array_buffers);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_array_buffers[TEXTURE_COORDINATE_VB]);
	glBufferData(GL_ARRAY_BUFFER, num_vertices * sizeof(texture_coordinates[0]),
		&texture_coordinates[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glBindVertexArray(0);
}

void Mesh::draw()
{
	glBindVertexArray(vertex_array_object);

	glDrawArrays(GL_TRIANGLES, 0, draw_count);

	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vertex_array_object);
}
