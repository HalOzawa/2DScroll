#include "Player.h"
#include <DxLib.h>
#include <assert.h>
#include"Camera.h"
#include "Bird.h"
#include "Wolf.h"
#include "Field.h"

namespace
{
	const float MOVE_SPEED = 3.5f;
	//const float PLAYER_XPOSITION = 10.0f;
	const float GROUND = 600.0f;
	const float JUMP_HEIGHT = 64.0f * 3.5f;
	const float GRAVITY = 9.8f / 60.0f;

};
Player::Player(GameObject* parent) : GameObject(sceneTop)
{
	hImage = LoadGraph("Assets/aoi.png");
	assert(hImage > 0);
	transform_.position_.x = 100.0f;
	transform_.position_.y = GROUND;
	onGround = true;
	flameCounter = 0;
	animType = 0;
	animFrame = 0;
	state = S_WaIk;
	
	number = 0;
	RandMax = 100;
	count = 0;
	Color = GetColor(255, 255, 255);

	/*cameraX = 50;*/
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
	//if (transform_.position_.x >= 400 && transform_.position_.x <= 900) {
	//	if (count < 1) {
	//		number = GetRand(RandMax);
	//		count++;
	//	}

	//	if (number == 1) {
	//		DrawString(100, 250, "���C�t��", Color);
	//		ScreenFlip();
	//	}
	//	else if (number > 1 && number <= 65) {
	//		DrawString(100, 250, "�����I�I", Color);
	//		ScreenFlip();
	//		if (CheckHitKey(KEY_INPUT_D))
	//		{
	//			transform_.position_.x += MOVE_SPEED * 3.0f;
	//			if (++flameCounter >= 8)
	//			{
	//				animFrame = (animFrame + 1) % 4;//if�����g��Ȃ��œK��
	//				flameCounter = 0;
	//			}
	//		}
	//	}
	//	else if (number > 65 && number <= 99) {
	//		DrawString(100, 250, "�����N���Ȃ�����", Color);
	//		ScreenFlip();
	//	}
	//	else if (number == 100) {
	//		KillMe();
	//	}
	//}

	//if (transform_.position_.x >= 1000 && transform_.position_.x <= 1200) {
	//	if (count < 2) {
	//		number = GetRand(RandMax);
	//		count++;
	//	}

	//	if (number == 1 && number <= 60) {
	//		DrawString(100, 250, "�A�C�e���Q�b�g", Color);
	//		ScreenFlip();
	//	}
	//	else if (number > 60 && number <= 99) {
	//		DrawString(100, 250, "�G�ǉ�", Color);
	//		ScreenFlip();
	//	}
	//	else if (number == 100) {
	//		KillMe();
	//	}
	//}

	//if (transform_.position_.x >= 1350 && transform_.position_.x <= 1800) {
	//	if (count < 3) {
	//		number = GetRand(RandMax);
	//		count++;
	//	}

	//	if (number == 1) {
	//	}
	//	else if (number > 1 && number <= 70) {
	//		DrawString(100, 250, "�����N���Ȃ�����", Color);
	//		ScreenFlip();
	//	}
	//	else if (number > 70 && number <= 99) {
	//		DrawString(100, 250, "����...", Color);
	//		ScreenFlip();
	//		if (CheckHitKey(KEY_INPUT_D))
	//		{
	//			transform_.position_.x += MOVE_SPEED / -3.0f;
	//			if (++flameCounter >= 8)
	//			{
	//				animFrame = (animFrame + 1) % 4;//if�����g��Ȃ��œK��
	//				flameCounter = 0;
	//			}
	//		}
	//	}
	//	else if (number == 100) {
	//		KillMe();
	//	}
	//}

	//if (transform_.position_.x >= 2050 && transform_.position_.x <= 2940) {
	//	if (count < 4) {
	//		number = GetRand(RandMax);
	//		count++;
	//	}

	//	if (number == 1) {
	//		DrawString(100, 250, "���C�t��", Color);
	//		ScreenFlip();
	//	}
	//	else if (number > 1 && number <= 50) {
	//		DrawString(100, 250, "�����I�I", Color);
	//		ScreenFlip();
	//		if (CheckHitKey(KEY_INPUT_D))
	//		{
	//			transform_.position_.x += MOVE_SPEED * 2.0f;
	//			if (++flameCounter >= 8)
	//			{
	//				animFrame = (animFrame + 1) % 4;//if�����g��Ȃ��œK��
	//				flameCounter = 0;
	//			}
	//		}
	//	}
	//	else if (number > 50 && number <= 99) {
	//		DrawString(100, 250, "����...", Color);
	//		ScreenFlip();
	//		if (CheckHitKey(KEY_INPUT_D))
	//		{
	//			transform_.position_.x += MOVE_SPEED / -3.0f;
	//			if (++flameCounter >= 8)
	//			{
	//				animFrame = (animFrame + 1) % 4;//if�����g��Ȃ��œK��
	//				flameCounter = 0;
	//			}
	//		}
	//	}
	//	else if (number == 100) {
	//		KillMe();
	//	}
	//}

	Field* pField = GetParent()->FindGameObject<Field>();

	if (CheckHitKey(KEY_INPUT_D))
	{
		transform_.position_.x += MOVE_SPEED;
		if (++flameCounter >= 8)
		{
			animFrame = (animFrame + 1) % 4;//if�����g��Ȃ��œK��
			flameCounter = 0;
		}

		int hitX = transform_.position_.x + 50;
		int hitY = transform_.position_.y + 63;

		if (pField != nullptr) {
			int push = pField->CollisionRight(hitX, hitY);//�ǂɂ߂肱�񂾕���Ԃ��i����ȏ�i�߂Ȃ�����j
			transform_.position_.x -= push;
		}
	}
	else if (CheckHitKey(KEY_INPUT_A))
	{
		transform_.position_.x -= MOVE_SPEED;
		if (++flameCounter >= 8)
		{
			animFrame = (animFrame + 1) % 4;//if�����g��Ȃ��œK��
			flameCounter = 0;
		}

		int hitX = transform_.position_.x + 15;
		int hitY = transform_.position_.y + 63;
		if (pField != nullptr) {
			int push = pField->CollisionLeft(hitX, hitY);//�ǂɂ߂肱�񂾕���Ԃ��i����ȏ�i�߂Ȃ�����j
			transform_.position_.x += push;
		}
	}
	else
	{
		animFrame = 0;
		flameCounter = 0;
	}

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		PictFlame = 80;

		//animFrame = (animFrame + 1) % 4;
		if (prevSpaceKey == false)
		{
			if (onGround)
			{
				Jump_P = -sqrtf(2 * GRAVITY * JUMP_HEIGHT);
				onGround = false;
			}
		}
		prevSpaceKey = true;
	}
	else
	{
		prevSpaceKey = false;
	}

	//if (pField != nullptr && !onGround)
	//{
	//	int hitX = transform_.position_.x + 32;
	//	int hitY = transform_.position_.y;

	//	int push = pField->CollisionUp(hitX, hitY);
	//	if (push > 0)
	//	{
	//		Jump_P = 0.0f;
	//		transform_.position_.y += push;
	//	}
	//}

	Jump_P += GRAVITY; //���x += �����x
	transform_.position_.y += Jump_P; //���W += ���x

	if (pField != nullptr)
	{
		int pushR = pField->CollisionDown(transform_.position_.x + 50, transform_.position_.y + 64);
		int pushL = pField->CollisionDown(transform_.position_.x + 14, transform_.position_.y + 64);
		int push = max(pushR, pushL);

		if (push >= 1)
		{
			transform_.position_.y -= push - 1;
			Jump_P = 0.0f;
			onGround = true;
		}
		else
		{
			onGround = false;
		}
	}

	//if (transform_.position_.y >= 800)//�n�ʂɂ����瑬�x�����ɖ߂��A�߂��Ȃ��Ɗђʂ��鋰�ꂠ��
	{
		//KillMe();
		//transform_.position_.y = GROUND;
		//Jump_P = 0.0f;
		//onGround = true;
	}

	std::list<Bird*> eBird = GetParent()->FindGameObjects<Bird>();
	for (Bird* eBird : eBird)
	{
		if (eBird->CollideCircle(transform_.position_.x + 32.0f, transform_.position_.y + 32.0f, 20.0f))
		{
			//������������
			KillMe();
		}
	}

	std::list<Wolf*> pWolf = GetParent()->FindGameObjects<Wolf>();
	for (Wolf* pWolf : pWolf)
	{
		if (pWolf->CollideCircle(transform_.position_.x + 32.0f, transform_.position_.y + 64.0f, 20.0f))
		{
			//������������
			KillMe();
		}
	}

	//�J�����ʒu�̒���
	//�J��������
	Camera* cam = GetParent()->FindGameObject<Camera>();
	int xR = (int)transform_.position_.x - cam->GetValue();
	int xL = (int)transform_.position_.x + cam->GetValue();
	if (xR > 600)
	{
		xR = 600;
		cam->SetValue((int)transform_.position_.x - xR);
	}

	if (xL > 600)
	{
		xL = 600;
		cam->SetValue((int)transform_.position_.x - xL);
	}
}

void Player::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	
	Camera* cam = GetParent()->FindGameObject<Camera>();
	//int z = (int)transform_.position_.x - cam->GetValue();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	DrawRectGraph(x, y, animFrame * 64, animType * 64, 64, 64, hImage, TRUE);
	DrawCircle(x + 32.0f, y + 32.0f, 24.0f, GetColor(255, 0, 0), 0);
	//DrawFormatString(0, 0, Color, "������ %d", number);
}

bool Player::CollideCircle(float x, float y, float r)
{
	float myCenterX = transform_.position_.x + 32.0f;
	float myCenterY = transform_.position_.y + 32.0f;
	float myR = 24.0f;

	(myCenterX - x)* (myCenterY - y);

	float dx = myCenterX - x;
	float dy = myCenterY - y;
	if (sqrt(dx * dx + dy * dy) < (r + myR) * (r + myR))
		return true;
	return false;
}

void Player::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

