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
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		i = GetRand(RandMax);
	}
	if (i >= 90) {
		transform_.position_.x = 800;
	}
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
	DrawFormatString(0, 0, Color, "óêêîÇÕ %d", i);
}
