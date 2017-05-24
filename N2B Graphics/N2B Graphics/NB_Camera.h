/*
NB_Camera:
Attention:
Purpose:
Usage:
*/

#ifdef NB_PRAGMA_ONCE_SUPPORT
#pragma once
#endif
#ifndef NB_CAMERA_H_INCLUDED
#define NB_CAMERA_H_INCLUDED

//GLUE
#include <GL/glew.h>

//GLM
#include <glm.hpp>
#include <gtx/transform.hpp>
#include <gtc/type_ptr.hpp>

//
#include "NB_Shader.h"

namespace NB 
{
	class NB_Camera
	{
	public:
		NB_Camera(float fov, float aspect, float zNear, float zFar, float speed = 5.0f);
		
		inline void look_at(glm::vec3 pos, glm::vec3 front, glm::vec3 up)
		{
			camera_pos = pos;
			camera_front = front;
			camera_up = up;
			view = glm::lookAt(camera_pos, camera_pos + camera_front, camera_up);
		}

		float camera_speed;
		virtual void move_forward(float distance);
		virtual void move_backward(float distance);
		virtual void move_right(float distance);
		virtual void move_left(float distance);
		virtual void move_up(float distance);
		virtual void move_down(float distance);

		virtual void set_front(glm::vec3 front);
		void set_fov(GLfloat);

		GLfloat get_fov() const { return this->fov; }
		GLfloat get_aspect() const { return this->aspect; }
		GLfloat get_z_far() const { return this->z_far; }
		GLfloat get_z_near() const { return this->z_near; }
		glm::mat4 get_projection() const { return this->projection; }
		glm::mat4 get_view() const { return this->view; }
		glm::vec3 get_camera_pos() const { return this->camera_pos; }
		glm::vec3 get_camera_front() const { return this->camera_front; }
		glm::vec3 get_camera_up() const { return this->camera_up; }
	private:
		GLfloat fov;
		GLfloat aspect;
		GLfloat z_far;
		GLfloat z_near;
		glm::mat4 projection;
		glm::mat4 view;
		glm::vec3 camera_pos;
		glm::vec3 camera_front;
		glm::vec3 camera_up;
		void update();
	};
}
#endif
