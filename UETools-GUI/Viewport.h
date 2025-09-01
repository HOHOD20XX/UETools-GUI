#pragma once
#include "SDK.hpp"






class Viewport
{
public:
	static SDK::UGameViewportClient* GetGameViewport();
	static SDK::TSubclassOf<SDK::UGameViewportClient> GetGameViewportClass();
};

