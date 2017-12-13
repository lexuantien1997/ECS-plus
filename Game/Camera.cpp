#include "Camera.h"



Camera::Camera() // set tọa độ mặc định cho camera là (0, 0)
{

}

Camera::Camera(Vector2i a)
{
	_camPosition = a;
}

Vector2i Camera::getCamPosition()
{
	return _camPosition;
}

void Camera::setCamPosition(Vector2i a)
{
	_camPosition = a;
}

Camera::~Camera()
{
}
