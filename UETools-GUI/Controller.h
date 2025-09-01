#pragma once
#include "SDK\Engine_classes.hpp"






class Controller
{
public:
	static SDK::APlayerController* GetController(const int32_t& playerIndex = 0);
	static SDK::APawn* GetPawn(const int32_t& playerIndex = 0);
	static SDK::ACharacter* GetCharacter(const int32_t& playerIndex = 0);
	static SDK::UPlayer* GetPlayer(const int32_t& playerIndex = 0);
};

