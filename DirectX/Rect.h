#ifndef __RECT_H_
#define __RECT_H_

#include "Vector2.h"

// Dùng `Rect` mình tự tạo ra bởi vì: 
//	+ Hàm RECT của directX không cho chúng ta truyền dữ liệu thông qua constructor
//  + Lúc dùng cái `SpriteCow.com` để cắt từng bức hình nó trả về left-top với lại kích cỡ của bức hình
//    Nên dùng luôn cho nó lẹ, mất công tính toán left - top - right - bottom
struct Rect
{
public:
	Vector2f left_top; // left and top

	Vector2f size; // width and height

	Rect(Vector2f _left_top, Vector2f _size)
	{
		left_top = _left_top;
		size = _size;
	}

	Rect(float left, float top, float width, float height)
	{
		left_top = Vector2f(left, top);
		size = Vector2f(width, height);
	}

	Rect()
	{

	}
};


#endif // !_RECT_H_


