#pragma once
#include "SDK/Engine_classes.hpp"






class Math
{
public:
	static SDK::FVector Normalize(const SDK::FVector& vector);




public:
	static double Milliseconds_ToSeconds(const uint32_t& milliseconds);
	static uint32_t Seconds_ToMilliseconds(const double& seconds);
};

