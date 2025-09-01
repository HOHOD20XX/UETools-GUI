#pragma once
#include "SDK\Engine_classes.hpp"






class Character
{
public:
	static SDK::ACharacter* GetCharacter(const int32_t& playerIndex = 0);
	static SDK::UCharacterMovementComponent* GetMovementComponent(const int32_t& playerIndex = 0);




public:
	static int32_t GetJumpMaxCount(const int32_t& playerIndex = 0);
	static bool SetJumpMaxCount(const int32_t& newMaxCount, const int32_t& playerIndex = 0);

	static float GetJumpVelocity(const int32_t& playerIndex = 0);
	static bool SetJumpVelocity(const float& newVelocity, const int32_t& playerIndex = 0);

	static bool Jump(const int32_t& playerIndex = 0);
	static bool Launch(const SDK::FVector& launchVelocity, const bool& overrideHorizontalVelocity = false, const bool& overrideVerticalVelocity = false, const int32_t& playerIndex = 0);




public:
	static bool GetIsCheatFlying(const int32_t& playerIndex = 0);
	static bool SetIsCheatFlying(const bool& newCheatFlying, const int32_t& playerIndex = 0);

	static bool Walk(const int32_t& playerIndex = 0);
	static bool Fly(const int32_t& playerIndex = 0);
	static bool Ghost(const int32_t& playerIndex = 0);
};

