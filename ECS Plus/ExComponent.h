#ifndef _EXAM_COMPONENT_H_
#define _EXAM_COMPONENT_H_

#include "_ECS_Header.h"

using namespace ECS;

struct IVector2f
{
	float x, y;
	IVector2f(){}
	IVector2f(float _x,float _y):x(_x),y(_y){}
};

struct IImage
{
	string source;
};

// Class giữ các trạng thái của Entity 
class TTransform :public ECS::Component
{
private:
	int a;
	IVector2f position; // vị trí của bức hình

					   // độ phóng đại của bức hình, mặc định là (1,1)
					   // giá trị âm sẽ lật bức hình lại
	IVector2f scale;

	// góc xoay từ 0-360
	float rotation;

	IVector2f origin; // tâm xoay, co dãn

public:

	TTransform(string name,int _a) :Component{ name } ,a(_a)
	{ 

	}
	/**
	* + Position : the position of entity
	* + Origin : origin of scale, position
	* + Scale : zoom (-) or (+)
	* + Rotation : the angle
	**/
	void initTransform(IVector2f position, IVector2f origin, IVector2f scale, float  rotation)
	{
		this->position = position;
		this->origin = origin;
		this->rotation = rotation;
		this->scale = scale;
	}

	IVector2f getPosition() { return position; }

	void setPosition(float x,float y)
	{
		position.x = x;
		position.y = y;
	}

	void move(float offSetX, float offSetY)
	{
		setPosition(position.x + offSetX, position.y + offSetY);
	}

};

// Vận tốc của 1 entity
class TVelocity :public ECS::Component
{
private:
	IVector2f velocity;
public:
	TVelocity(string name) :Component{ name }
	{

	}
	void initVelocity(IVector2f velocity)
	{
		this->velocity = velocity;
	}

	float getVelocityX() { return velocity.x; }
	float getVelocityY() { return velocity.y; }

	void set(IVector2f gravity)
	{
		this->velocity.x = gravity.x;
		this->velocity.y = gravity.y;
	}
};

// Trọng lực của entity
// Kiểm tra vật có nhảy dc hay không
class TGravity :public ECS::Component
{
private:
	// Hằng số NewTon
	float g;
	bool canJump;
public:
	TGravity(string name) :Component{ name }
	{

	}
	void initGraviry(float g=10,bool canJump=false)
	{
		this->g = g;
		this->canJump = canJump;
	}

	void active() { canJump = true; }

	void deActive() { canJump = false; }

	bool getCanJump() { return canJump; }
	
};

// Bức hình
class TSprite :public ECS::Component
{
private:
	IImage image;
public:
	TSprite(string name) :Component{ name }
	{

	}
	void initSprite(string source)
	{
		image.source = source;
	}

	void draw(IVector2f position)
	{
		// do something
	}
};

#endif // !EXAM_COMPONENT_H_