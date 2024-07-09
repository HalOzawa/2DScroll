#pragma once
#include "Engine/GameObject.h"

/// <summary>
/// �n�ʁi�v���C�t�B�[���h�j
/// </summary>
class Field : public GameObject
{
public:
	Field(GameObject* scene);
	~Field();
	void Reset();
	void Update() override;
	void Draw() override;

	int CollisionRight(int x, int y);
	int CollisionLeft(int x, int y);
	int CollisionDown(int x, int y);
	int CollisionUp(int x, int y);

private:
	int hImage;
	
	bool IsWallBlock(int x, int y);
	int* Map;
	int width;
	int height;
};