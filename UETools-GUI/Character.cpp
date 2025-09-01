#include "Character.h"






SDK::ACharacter* Character::GetCharacter(const int32_t& playerIndex)
{
    SDK::UWorld* World = SDK::UWorld::GetWorld();
    if (World == nullptr)
        return nullptr;
    
    SDK::ACharacter* Character = SDK::UGameplayStatics::GetPlayerCharacter(World, playerIndex);
    if (Character == nullptr)
        return nullptr;

    return Character;
}

SDK::UCharacterMovementComponent* Character::GetMovementComponent(const int32_t& playerIndex)
{
    SDK::ACharacter* Character = GetCharacter(playerIndex);
    if (Character == nullptr || Character->CharacterMovement == nullptr)
        return nullptr;

    return Character->CharacterMovement;
}




int32_t Character::GetJumpMaxCount(const int32_t& playerIndex)
{
    SDK::ACharacter* Character = GetCharacter(playerIndex);
    if (Character == nullptr)
        return 0;

    return Character->JumpMaxCount;
}

bool Character::SetJumpMaxCount(const int32_t& newMaxCount, const int32_t& playerIndex)
{
    SDK::ACharacter* Character = GetCharacter(playerIndex);
    if (Character == nullptr)
        return false;

    Character->JumpMaxCount = newMaxCount;
    return true;
}


float Character::GetJumpVelocity(const int32_t& playerIndex)
{
    SDK::UCharacterMovementComponent* MovementComponent = GetMovementComponent(playerIndex);
    if (MovementComponent == nullptr)
        return 0.0f;

    return MovementComponent->JumpZVelocity;
}

bool Character::SetJumpVelocity(const float& newVelocity, const int32_t& playerIndex)
{
    SDK::UCharacterMovementComponent* MovementComponent = GetMovementComponent(playerIndex);
    if (MovementComponent == nullptr)
        return false;

    MovementComponent->JumpZVelocity = newVelocity;
    return true;
}


bool Character::Jump(const int32_t& playerIndex)
{
    SDK::ACharacter* Character = GetCharacter(playerIndex);
    if (Character == nullptr)
        return false;

    bool canJump = Character->CanJump();
    if (canJump)
        Character->Jump();

    return canJump;
}




bool Character::Launch(const SDK::FVector& launchVelocity, const bool& overrideHorizontalVelocity, const bool& overrideVerticalVelocity, const int32_t& playerIndex)
{
    SDK::ACharacter* Character = GetCharacter(playerIndex);
    if (Character == nullptr || Character->CharacterMovement == nullptr
                             || Character->CharacterMovement->bCheatFlying == true
                             || Character->CharacterMovement->MovementMode == SDK::EMovementMode::MOVE_None
                             || Character->CharacterMovement->IsActive() == false)
        return false;

    SDK::FVector finalVelocity = launchVelocity;
    const SDK::FVector characterVelocity = Character->GetVelocity();

    if (overrideHorizontalVelocity == false)
    {
        finalVelocity.X += characterVelocity.X;
        finalVelocity.Y += characterVelocity.Y;
    }

    if (overrideVerticalVelocity == false)
    {
        finalVelocity.Z += characterVelocity.Z;
    }

    Character->CharacterMovement->PendingLaunchVelocity = finalVelocity;
    Character->OnLaunched(finalVelocity, overrideHorizontalVelocity, overrideVerticalVelocity);
    
    if (Character->CharacterMovement->bCheatFlying)
    {
        Character->SetActorEnableCollision(true);
        Character->CharacterMovement->bCheatFlying = false;
        Character->CharacterMovement->SetMovementMode(SDK::EMovementMode::MOVE_Walking, 0);
    }

    return true;
}




bool Character::GetIsCheatFlying(const int32_t& playerIndex)
{
    SDK::UCharacterMovementComponent* MovementComponent = GetMovementComponent(playerIndex);
    if (MovementComponent == nullptr)
        return false;

    return MovementComponent->bCheatFlying;
}

bool Character::SetIsCheatFlying(const bool& newCheatFlying, const int32_t& playerIndex)
{
    SDK::UCharacterMovementComponent* MovementComponent = GetMovementComponent(playerIndex);
    if (MovementComponent == nullptr)
        return false;

    MovementComponent->bCheatFlying = newCheatFlying;
    return true;
}


bool Character::Walk(const int32_t& playerIndex)
{
    SDK::ACharacter* Character = GetCharacter(playerIndex);
    if (Character == nullptr || Character->CharacterMovement == nullptr)
        return false;

    Character->SetActorEnableCollision(true);

    Character->CharacterMovement->bCheatFlying = false;
    Character->CharacterMovement->SetMovementMode(SDK::EMovementMode::MOVE_Walking, 0);
    return true;
}

bool Character::Fly(const int32_t& playerIndex)
{
    SDK::ACharacter* Character = GetCharacter(playerIndex);
    if (Character == nullptr || Character->CharacterMovement == nullptr)
        return false;

    Character->SetActorEnableCollision(true);

    Character->CharacterMovement->bCheatFlying = true;
    Character->CharacterMovement->SetMovementMode(SDK::EMovementMode::MOVE_Flying, 0);
    return true;
}

bool Character::Ghost(const int32_t& playerIndex)
{
    SDK::ACharacter* Character = GetCharacter(playerIndex);
    if (Character == nullptr || Character->CharacterMovement == nullptr)
        return false;

    Character->SetActorEnableCollision(false);

    Character->CharacterMovement->bCheatFlying = true;
    Character->CharacterMovement->SetMovementMode(SDK::EMovementMode::MOVE_Flying, 0);
    return true;
}
