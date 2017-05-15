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

namespace NB 
{
	class NB_Camera
	{
	public:
		NB_Camera(float fov, float aspect, float zNear, float zFar);
		
		inline void look_at(glm::vec3 pos, glm::vec3 front, glm::vec3 up)
		{
			camera_pos = pos;
			camera_front = front;
			camera_up = up;
			view = glm::lookAt(camera_pos, camera_pos + camera_front, camera_up);
		}

		inline void update()
		{
			view = glm::lookAt(camera_pos, camera_pos + camera_front, camera_up);
			projection = glm::perspective(fov, aspect, z_near, z_far);
		}
		GLfloat fov;
		GLfloat aspect;
		GLfloat z_far;
		GLfloat z_near;
		glm::mat4 projection;
		glm::mat4 view;
		glm::vec3 camera_pos;
		glm::vec3 camera_front;
		glm::vec3 camera_up;
	private:
	};
}
#endif
