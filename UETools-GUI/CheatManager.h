#pragma once
#include "SDK\Engine_classes.hpp"

#include "PlayerController.h"






class CheatManager
{
public:
	static bool IsCheatManagerPresent();
	static SDK::UCheatManager* GetCheatManager();
	static bool SetCheatManager(SDK::UCheatManager* newCheatManager);
	static bool ConstructCheatManager();


	static SDK::TSubclassOf<SDK::UCheatManager> GetCheatManagerClass();
	static bool SetCheatManagerClass(const SDK::TSubclassOf<SDK::UCheatManager>& newCheatManagerClass);
};

