#pragma once
#include "SDK/Engine_classes.hpp"






class Math
{
public:
	static SDK::FVector NormalizeVector(const SDK::FVector& vector);
	static double NormalizeAngle(const double& angle);




public:
	static double InverseNormalizeAngle(const double& normalizedAngle);




public:
	static double Milliseconds_ToSeconds(const uint32_t& milliseconds);
	static uint32_t Seconds_ToMilliseconds(const double& seconds);
};

