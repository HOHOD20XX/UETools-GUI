#include "GameState.h"






SDK::AGameStateBase* GameState::GetGameState()
{
    SDK::UWorld* World = SDK::UWorld::GetWorld();
    if (World == nullptr)
        return nullptr;

    SDK::AGameStateBase* GameState = SDK::UGameplayStatics::GetGameState(World);
    if (GameState == nullptr)
        return nullptr;

    return GameState;
}
