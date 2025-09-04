#include "PlayerController.h"






SDK::APlayerController* PlayerController::GetPlayerController(const int32_t& playerIndex)
{
    SDK::UWorld* World = SDK::UWorld::GetWorld();
    if (World == nullptr)
        return nullptr;

    SDK::APlayerController* Controller = SDK::UGameplayStatics::GetPlayerController(World, playerIndex);
    if (Controller == nullptr)
        return nullptr;

    return Controller;
}

SDK::APawn* PlayerController::GetPawn(const int32_t& playerIndex)
{
    SDK::APlayerController* Controller = GetPlayerController(playerIndex);
    if (Controller == nullptr || Controller->AcknowledgedPawn == nullptr)
        return nullptr;

    return Controller->AcknowledgedPawn;
}

SDK::ACharacter* PlayerController::GetCharacter(const int32_t& playerIndex)
{
    SDK::APlayerController* Controller = GetPlayerController(playerIndex);
    if (Controller == nullptr || Controller->Character == nullptr)
        return nullptr;

    return Controller->Character;
}

SDK::UPlayer* PlayerController::GetPlayer(const int32_t& playerIndex)
{
    SDK::APlayerController* Controller = GetPlayerController(playerIndex);
    if (Controller == nullptr || Controller->Player == nullptr)
        return nullptr;

    return Controller->Player;
}
