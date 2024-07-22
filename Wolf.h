#pragma once
#include "Engine/GameObject.h"
class Wolf :
    public GameObject
{
    int hImage;
public:
	Wolf(GameObject* scene);
	~Wolf();
	void Update() override;
	void Draw() override;

	bool CollideCircle(float x, float y, float r);
	void SetPosition(int x, int y);
};

