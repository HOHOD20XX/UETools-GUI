#pragma once
#include "SDK\Engine_classes.hpp"






class PlayerController
{
public:
	static SDK::APlayerController* GetPlayerController(const int32_t& playerIndex = 0);
	static SDK::APawn* GetPawn(const int32_t& playerIndex = 0);
	static SDK::ACharacter* GetCharacter(const int32_t& playerIndex = 0);
	static SDK::UPlayer* GetPlayer(const int32_t& playerIndex = 0);
};

