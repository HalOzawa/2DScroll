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
	void Update() override;
	void Draw() override;

	int CollisionRight(int x, int y);

	int CollisionDown(int x, int y);

private:
	int hImage;
};