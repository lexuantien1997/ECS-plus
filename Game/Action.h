#ifndef ACTION_H_
#define ACTION_H_

#include <vector>
#include "../DirectX/Rect.h"

using namespace std;

// 1 action có nhiều bức hình
class Action
{
private:

	string name; // tên của trạng thái

	string spritePath; // vị trí bức hình lưu trạng thái action này

	vector<Rect> action_rect; // danh sách cách vị trí của các bức hình

	float duration;

	int action_size;

	int current_rect;

public:

	Action(string name, string path, vector<Rect> rects, float duration);

	Action() {}

	string getName();

	string getSpritePath();

	vector<Rect> getActionRect();

	float getFrameDuration() {
		return duration;
	}

	int getCurrentRect() { return current_rect; }

	void setCurrentRect(float offset) { current_rect = offset; }

	void increasing() { current_rect += 1; }

	int getAction_Size() { return action_size; }

	void setName(string name) { this->name = name; }


	~Action();
};


#endif // !STATE_H_


