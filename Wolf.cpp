#include "Wolf.h"
#include "Camera.h"
#include <assert.h>

namespace {
    static const int SCREEN_WIDTH = 1280;
	const float Ground = 600.0f;
}

Wolf::Wolf(GameObject* scene)
{
	hImage = LoadGraph("Assets/Wolf2.png");
	assert(hImage > 0);
	transform_.position_.x = 600.0f;
	transform_.position_.y = Ground;
}

Wolf::~Wolf()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void Wolf::Update()
{
	int x = (int)transform_.position_.x;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	if (x > SCREEN_WIDTH)
		return;
	else if (x < -64) {
		KillMe();
		return;
	}
	transform_.position_.x -= 1.0f;
}

void Wolf::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y-16;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	DrawRectGraph(x, y, 0, 0, 128, 83, hImage, TRUE);
	DrawCircle(x + 64.0f, y + 40.0f, 30.0f, GetColor(255, 0, 0), 0);
}

bool Wolf::CollideCircle(float x, float y, float r)
{
	//x,y,r‚ª‘Šè‚Ì‰~‚Ìî•ñ
	//©•ª‚Ì‰~‚Ìî•ñ
	float myCenterX = transform_.position_.x + 32.0f;
	float myCenterY = transform_.position_.y + 64.0f;
	float dx = myCenterX - x;
	float dy = myCenterY - y;
	float dSqrts = dx * dx + dy * dy;
	//float dSqrts =sqrt(dx * dx + dy * dy);

	float myR = 20.0f + r;
	float rSqrt = myR * myR;
	//float rSqrt = sqrt(myR * myR);
	if (dSqrts <= rSqrt)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Wolf::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}
