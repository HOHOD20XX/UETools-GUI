#pragma once
#include "SDK\Engine_classes.hpp"

#include "PlayerController.h"
#include "Object.h"






class Input
{
public:
	static SDK::UInputSettings* GetInputSettings(const bool& searchForDefaultObject = true);

	static std::vector<SDK::FKey> GetConsoleBindings();
	static bool CreateConsoleBindings();




private:
	static inline bool isInputDisabled = false;
	static inline SDK::APlayerController* initialPlayerController = nullptr;
	static inline bool initialIgnoreMoveInput = false;
	static inline bool initialIgnoreLookInput = false;
public:
	static bool GetIsInputDisabled()
	{
		return isInputDisabled;
	}
	static bool SetIsInputDisabled(const bool& newInputDisabled);
};

