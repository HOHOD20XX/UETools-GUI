#include "Pawn.h"






SDK::APawn* GetPawn(const int32_t& playerIndex)
{
    SDK::UWorld* World = SDK::UWorld::GetWorld();
    if (World == nullptr)
        return nullptr;

    SDK::APawn* Pawn = SDK::UGameplayStatics::GetPlayerPawn(World, playerIndex);
    if (Pawn == nullptr)
        return nullptr;

    return Pawn;
}