#include "CheatManager.h"






bool CheatManager::IsCheatManagerPresent()
{
	return GetCheatManager();
}

SDK::UCheatManager* CheatManager::GetCheatManager()
{
	SDK::APlayerController* Controller = PlayerController::GetPlayerController();
	if (Controller == nullptr || Controller->CheatManager == nullptr)
		return nullptr;

	return Controller->CheatManager;
}

bool CheatManager::SetCheatManager(SDK::UCheatManager* newCheatManager)
{
	SDK::APlayerController* Controller = PlayerController::GetPlayerController();
	if (Controller == nullptr)
		return false;

	Controller->CheatManager = newCheatManager;
	return true;
}

bool CheatManager::ConstructCheatManager()
{
	SDK::APlayerController* Controller = PlayerController::GetPlayerController();
	if (Controller == nullptr)
		return false;

	if (Controller->CheatManager)
		return false;

	SDK::UObject* cheatManagerObject = nullptr;
	if (Controller->CheatClass == nullptr)
		Controller->CheatClass = SDK::UCheatManager::StaticClass();

	cheatManagerObject = SDK::UGameplayStatics::SpawnObject(Controller->CheatClass, Controller);
	if (cheatManagerObject == nullptr)
		return false;

	Controller->CheatManager = static_cast<SDK::UCheatManager*>(cheatManagerObject);
	return true;
}





SDK::TSubclassOf<SDK::UCheatManager> CheatManager::GetCheatManagerClass()
{
	SDK::APlayerController* Controller = PlayerController::GetPlayerController();
	if (Controller == nullptr || Controller->CheatClass == nullptr)
		return nullptr;

	return Controller->CheatClass;
}

bool CheatManager::SetCheatManagerClass(const SDK::TSubclassOf<SDK::UCheatManager>& newCheatManagerClass)
{
	SDK::APlayerController* Controller = PlayerController::GetPlayerController();
	if (Controller == nullptr)
		return false;

	Controller->CheatClass = newCheatManagerClass;
	return true;
}