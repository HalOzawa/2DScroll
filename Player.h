#pragma once
#include "Engine/GameObject.h"

/// <summary>
/// プレイヤーキャラ
/// </summary>
class Player : public GameObject
{
public:
	Player(GameObject* scene);
	~Player();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	int i;
	int RandMax;
	unsigned int Color;
	GameObject* sceneTop;
	bool prevSpaceKey;
};