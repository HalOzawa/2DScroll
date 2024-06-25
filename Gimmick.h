#pragma once
#include "Engine/GameObject.h"
class Gimmick :
    public GameObject
{
    int number;
    int RandMax;
    int count;
    int Color;
    float pPos;
public:
    Gimmick(GameObject* Scene);
    ~Gimmick();
    void Update() override;
    void Draw() override;
};

