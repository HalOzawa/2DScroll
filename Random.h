#pragma once
#include "Engine/GameObject.h"

class Random : public GameObject
{
	int hImage;
	int Color;
	int number;
	int RandMax;
public:
	Random(GameObject* scene);
	~Random();
	void Update() override;
	void Draw() override;

	bool CollideCircle(float x, float y, float r);
	void SetPosition(int x, int y);
};

