#pragma once
#include "Engine/GameObject.h"
#include "Player.h"
class Camera :
    public GameObject
{
public:
	Camera(GameObject* parent) :GameObject(parent) { value_ = 0; }
	~Camera() {};
	void GetPlayerPos(Player* _player) { player_ = _player; }
	void Update();
	void SetValue(int v) { value_ = v; }
	int GetValue() { return value_; }
private:
	Player* player_;
	int value_;
};

