﻿#include "Camera.h"



Camera::Camera() // set tọa độ mặc định cho camera là (0, 0)
{
	
}

Camera::Camera(Vector2i a, Vector2i s)
{
	_camPosition = a;
	_size = s;
}

Vector2i Camera::getCamPosition()
{
	return _camPosition;
}

Vector2i Camera::getSize()
{
	return _size;
}

void Camera::setCamPosition(Vector2i a)
{
	_camPosition = a;
}

Camera::~Camera()
{
}
