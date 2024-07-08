#pragma once
#include "Engine/GameObject.h"
class Camera :
    public GameObject
{
public:
	Camera(GameObject* parent) :GameObject(parent) { value_ = 0; }
	~Camera() {};
	void SetValue(int v) { value_ = v; }
	int GetValue() { return value_; }
private:
	int value_;
};

