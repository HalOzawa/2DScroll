#include "TestScene.h"
#include "Player.h"
#include "Bird.h"
#include "Wolf.h"
#include "Field.h"
#include "Camera.h"

//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//������
void TestScene::Initialize()
{
	Instantiate<Camera>(this);
	Field* pField = Instantiate<Field>(this);
	Instantiate<Bird>(this);
	Instantiate<Wolf>(this);
	Instantiate<Player>(this);
	pField->Reset();
	
}

//�X�V
void TestScene::Update()
{
}

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}
