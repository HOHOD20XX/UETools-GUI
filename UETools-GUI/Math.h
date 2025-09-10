#pragma once
#include "SDK/Engine_classes.hpp"






class Math
{
public:
	static SDK::FVector NormalizeVector(const SDK::FVector& vector);


public:
	static uint32_t Seconds_ToMilliseconds(const double& seconds);
};

