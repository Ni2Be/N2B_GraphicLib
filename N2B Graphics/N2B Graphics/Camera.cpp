#include "NB_Camera.h"

NB::NB_Camera::NB_Camera(float fov, float aspect, float z_near, float z_far)
	:fov(fov),
	aspect(aspect),
	z_near(z_near),
	z_far(z_far)
{
	projection = glm::perspective(fov, aspect, z_near, z_far);
}
