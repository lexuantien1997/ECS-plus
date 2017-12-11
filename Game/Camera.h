#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../DirectX/Vector2.h"

class Camera  // Camera shows things that we can see on the screen (view port)
{
private:
	Vector2i _camPosition;
public:
	Camera();
	Camera(Vector2i);
	Vector2i getCamPosition();
	void setCamPosition(Vector2i);
	~Camera();
};

#endif // !_CAMERA_H_


