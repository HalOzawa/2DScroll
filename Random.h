#pragma once
#include "Engine/GameObject.h"

class Random : public GameObject
{
	int number;
	int RandMax;
public:
	Random(GameObject* scene);
	void Update() override;
	void GetRand(int Number_);
};

