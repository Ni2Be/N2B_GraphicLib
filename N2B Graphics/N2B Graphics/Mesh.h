#pragma once
#include <vector>

#include <glm.hpp>
#include <GL/glew.h>

class Vertex
{
	friend class Mesh;
public:
	Vertex(const glm::vec3& pos, const glm::vec2& text_Coordinate)
		:pos(pos), texture_coordinate(text_Coordinate) {}
private:
	glm::vec3 pos;
	glm::vec2 texture_coordinate;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int num_vertices);

	void draw();

	~Mesh();
private:
	enum
	{
		POSITION_VB,
		TEXTURE_COORDINATE_VB,
		NUM_BUFFERS
	};

	GLuint vertex_array_object;
	GLuint vertex_array_buffers[NUM_BUFFERS];
	unsigned int draw_count;
};

