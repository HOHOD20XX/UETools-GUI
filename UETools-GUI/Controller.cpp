#include "Controller.h"






SDK::APlayerController* Controller::GetController(const int32_t& playerIndex)
{
    SDK::UWorld* World = SDK::UWorld::GetWorld();
    if (World == nullptr)
        return nullptr;

    SDK::APlayerController* Controller = SDK::UGameplayStatics::GetPlayerController(World, playerIndex);
    if (Controller == nullptr)
        return nullptr;

    return Controller;
}

SDK::APawn* Controller::GetPawn(const int32_t& playerIndex)
{
    SDK::APlayerController* Controller = GetController(playerIndex);
    if (Controller == nullptr || Controller->AcknowledgedPawn == nullptr)
        return nullptr;

    return Controller->AcknowledgedPawn;
}

SDK::ACharacter* Controller::GetCharacter(const int32_t& playerIndex)
{
    SDK::APlayerController* Controller = GetController(playerIndex);
    if (Controller == nullptr || Controller->Character == nullptr)
        return nullptr;

    return Controller->Character;
}

SDK::UPlayer* Controller::GetPlayer(const int32_t& playerIndex)
{
    SDK::APlayerController* Controller = GetController(playerIndex);
    if (Controller == nullptr || Controller->Player == nullptr)
        return nullptr;

    return Controller->Player;
}
