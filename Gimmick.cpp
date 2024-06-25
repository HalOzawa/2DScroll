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
		DrawString(100, 250, "アイテムゲット", Color);
		ScreenFlip();
	}
	else if (number > 50 && number <= 99) {
		DrawString(100, 250, "何も起きなかった", Color);
		ScreenFlip();
	}
	else if (number == 100) {
		KillMe();
	}
}

void Gimmick::Draw()
{
	DrawFormatString(0, 0, Color, "乱数は %d", number);
}
