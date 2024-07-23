#include "Random.h"

Random::Random(GameObject* scene)
{
	number = 0;
	RandMax = 100;
	
}

Random::~Random()
{
}

void Random::Update()
{
	//number = GetRand(RandMax);
}

void Random::Draw()
{
}

bool Random::CollideCircle(float x, float y, float r)
{
	return false;
}

void Random::SetPosition(int x, int y)
{
	
}
