#include "GameInstance.h"






SDK::UGameInstance* GameInstance::GetGameInstance()
{
    SDK::UWorld* World = SDK::UWorld::GetWorld();
    if (World == nullptr)
        return nullptr;

    SDK::UGameInstance* GameInstance = SDK::UGameplayStatics::GetGameInstance(World);
    if (GameInstance == nullptr)
        return nullptr;

    return GameInstance;
}
