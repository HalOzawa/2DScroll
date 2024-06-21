#include "Player.h"
#include <DxLib.h>
#include <assert.h>

Player::Player(GameObject* parent) : GameObject(sceneTop)
{
	hImage = LoadGraph("Assets/aoi.png");
	assert(hImage > 0);
	RandMax = 100;
	transform_.position_.x = 10.0f;
	transform_.position_.y = 577.0f;
	Color = GetColor(255, 255, 255);
}

Player::~Player()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void Player::Update()
{
	//if (CheckHitKey(KEY_INPUT_SPACE)) {
	//	Number = GetRand(RandMax);
	//}
	if (transform_.position_.x == 400) {
		Number = GetRand(RandMax);
	}

	if (Number == 1) {
		transform_.position_.x = 200;
	}
	else if (Number > 1 && Number <= 50) {
		transform_.position_.x = 500;
	}
	else if (Number > 50 && Number <= 99) {
		transform_.position_.y = 100;
	}
	else if(Number == 100) {
		transform_.position_.y = 577;
	}

	//switch (i)
	//{
	//case 0:
	//	transform_.position_.x = 800;
	//	break;
	//case 9:
	//	transform_.position_.x = 400;
	//	break;
	//default:
	//	break;
	//}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		transform_.position_.x += 3.0;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		transform_.position_.x -= 3.0;
	}

}

void Player::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	DrawRectGraph(x, y, 0, 0, 64, 64, hImage, TRUE);
	DrawFormatString(0, 0, Color, "—”‚Í %d", Number);
}
