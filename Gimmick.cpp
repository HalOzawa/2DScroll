#include "Gimmick.h"
#include "Player.h"

Gimmick::Gimmick(GameObject* scene)
{
	number = 0;
	RandMax = 100;
	count = 0;
	Color = GetColor(255, 255, 255);
}

Gimmick::~Gimmick()
{
}

void Gimmick::Update()
{
	Player* pPlayer = GetParent()->FindGameObject<Player>();
	

	if (pPlayer->GetPosition().x == 400) {
		number = GetRand(RandMax);
		count++;
	}
	if (number == 1) {

	}
	else if (number > 1 && number <= 50) {
		DrawString(100, 250, "�A�C�e���Q�b�g", Color);
		ScreenFlip();
	}
	else if (number > 50 && number <= 99) {
		DrawString(100, 250, "�����N���Ȃ�����", Color);
		ScreenFlip();
	}
	else if (number == 100) {
		KillMe();
	}
}

void Gimmick::Draw()
{
	DrawFormatString(0, 0, Color, "������ %d", number);
}
