#include "TestScene.h"
#include "Player.h"
#include "Bird.h"
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
	Field* pField = Instantiate<Field>(this);
	pField->Reset();
	Instantiate<Camera>(this);
	Instantiate<Player>(this);
	Instantiate<Field>(this);
	
	Instantiate<Bird>(this);

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
