#include "Field.h"
#include <assert.h>
#include "Camera.h"
#include"Player.h"
#include "Bird.h"
#include "Engine/CsvReader.h"

Field::Field(GameObject* scene) : GameObject(scene)
{
	hImage = LoadGraph("Assets/bgchar.png");
	assert(hImage > 0);

}

Field::~Field()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
	if (Map != nullptr)
	{
		delete[] Map;//Mapは動的配列なので[]をつける
	}
}

void Field::Reset()
{
	if (Map != nullptr) {
		delete[] Map;
		Map = nullptr;
	}
	CsvReader csv;
	bool ret = csv.Load("Assets/stage1.csv");
	assert(ret);
	width = csv.GetWidth();
	height = 22;//csv.GetHeight();
	Map = new int[width * height];

	//for (int h = 0; h < height; h++) {
	//	for (int w = 0; w < width; w++) {
	//		Map[h*width+w] = csv.GetInt(w, h);
	//	}
	//}

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			switch (csv.GetInt(w, h))
			{
			case 0: //Player
			{
				Player* pPlayer = GetParent()->FindGameObject<Player>();
				pPlayer->SetPosition(w * 32, h * 32);
				break;
			}
			case 1: //Bird
			{
				Bird* pBird = GetParent()->FindGameObject<Bird>();
				pBird->SetPosition(w * 32, h * 32);
				break;
			}
			case 4:
			{

			}
			}
			Map[h * width + w] = csv.GetValue(w, h);
		}
	}
}

void Field::Update()
{
	/*if (CheckHitKey(KEY_INPUT_R)) {
		Reset();
	}*/
}

void Field::Draw()
{
	int scroll = 0;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		scroll = cam->GetValue(); // カメラのスクロール値を取得
	}
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int chip = Map[y * width + x];
			DrawRectGraph(x * 32 - scroll, y * 32, 32 * (chip % 16), 32 * (chip / 16), 32, 32, hImage, TRUE);//0
		}
	}
}

int Field::CollisionRight(int x, int y)
{
	if (IsWallBlock(x, y)) 
		return x % 32 + 1;
	return 0;
}

int Field::CollisionLeft(int x, int y)
{
	if (IsWallBlock(x, y))
		return x % 14 + 1;
	return 0;
}

int Field::CollisionDown(int x, int y)
{
	if (IsWallBlock(x, y))
		return y % 32 + 1;
	return 0;
}

int Field::CollisionUp(int x, int y)
{
	return 0;
}

bool Field::IsWallBlock(int x, int y)
{
	int chipX = x / 32;
	int chipY = y / 32;
	switch (Map[chipY * width + chipX]) {
	case 16:
	case 17:
	case 18:
	case 19:
	case 32:
	case 33:
	case 34:
	case 35:
		return true;
	}
	return false;

}
