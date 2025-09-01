#include "GameMode.h"






SDK::AGameModeBase* GameMode::GetGameMode()
{
    SDK::UWorld* World = SDK::UWorld::GetWorld();
    if (World == nullptr)
        return nullptr;

    SDK::AGameModeBase* GameMode = SDK::UGameplayStatics::GetGameMode(World);
    if (GameMode == nullptr)
        return nullptr;

    return GameMode;
}
