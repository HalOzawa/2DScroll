#include "Random.h"

Random::Random(GameObject* scene)
{
	number = 0;
	RandMax = 100;
	
}

void Random::Update()
{
	number = GetRand(RandMax);
}

void Random::GetRand(int Number_)
{
	Number_ = number;
}
