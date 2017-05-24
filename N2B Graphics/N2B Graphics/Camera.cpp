#include "NB_Camera.h"
#include <glm.hpp>

NB::NB_Camera::NB_Camera(float fov, float aspect, float z_near, float z_far, float speed)
	:fov(fov),
	aspect(aspect),
	z_near(z_near),
	z_far(z_far),
	camera_speed(speed)
{
	projection = glm::perspective(fov, aspect, z_near, z_far);
}

void NB::NB_Camera::update()
{
	view = glm::lookAt(camera_pos, camera_pos + camera_front, camera_up);
	projection = glm::perspective(fov, aspect, z_near, z_far);
}

void NB::NB_Camera::move_forward(float distance)
{
	this->camera_pos -= distance * camera_speed * this->camera_pos * 0.1f;
	this->update();
}

void NB::NB_Camera::move_backward(float distance)
{
	this->camera_pos += distance * camera_speed * this->camera_pos * 0.1f;
	this->update();
}

void NB::NB_Camera::move_right(float distance)
{
	this->camera_pos += distance * camera_speed * glm::normalize(glm::cross(this->camera_front, this->camera_up));
	this->update();
}

void NB::NB_Camera::move_left(float distance)
{
	this->camera_pos -= distance * camera_speed * glm::normalize(glm::cross(this->camera_front, this->camera_up));
	this->update();
}

void NB::NB_Camera::move_up(float distance)
{
	this->camera_pos.y += distance * camera_speed;
	this->update();
}

void NB::NB_Camera::move_down(float distance)
{
	this->camera_pos.y -= distance * camera_speed;
	this->update();
}

void NB::NB_Camera::set_front(glm::vec3 front)
{
	this->camera_front = front;
	this->update();
}

void NB::NB_Camera::set_fov(GLfloat fov)
{
	this->fov = fov;
	this->update();
}