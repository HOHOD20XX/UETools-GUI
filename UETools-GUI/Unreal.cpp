#include "Unreal.h"






SDK::UConsole* Unreal::Console::Get()
{
	SDK::UGameViewportClient* GameViewportClient = GameViewportClient::Get();
	if (GameViewportClient == nullptr || GameViewportClient->ViewportConsole == nullptr)
		return nullptr;

	return GameViewportClient->ViewportConsole;
}

bool Unreal::Console::Construct(const bool& ignorePresence)
{
	SDK::UGameViewportClient* GameViewportClient = GameViewportClient::Get();
	if (GameViewportClient == nullptr)
		return false;

	if (ignorePresence == false && GameViewportClient->ViewportConsole) // If presence shouldn't be ignored, we're looking up if Console already exist.
		return false;

	/*
		If Engine is present, the Console Class defined in it will be used.
		Otherwise, the default Console Class will serve as a fallback.

		Before assigning Console to the Game Viewport Client, ensure that SpawnObject() returned a valid pointer.
	*/
	SDK::UEngine* Engine = Engine::Get();
	if (SDK::UObject* objectReference = SDK::UGameplayStatics::SpawnObject(Engine ? Engine->ConsoleClass : SDK::TSubclassOf<SDK::UConsole>(SDK::UConsole::StaticClass()), GameViewportClient))
	{
		GameViewportClient->ViewportConsole = static_cast<SDK::UConsole*>(objectReference); // Clarify that newly spawned Object is of class Console.
		return true;
	}
	else
		return false;
}


bool Unreal::Console::Print(const std::wstring& wideString)
{
	const wchar_t* wCharString = wideString.c_str();
	wprintf(L"%ls\n", wCharString); // Print to std::cout (if present).

	if (SDK::APlayerController* playerController = PlayerController::Get())
	{
		playerController->ClientMessage(SDK::FString(wCharString), SDK::UKismetStringLibrary::Conv_StringToName(L"None"), 0);
		return true;
	}
	else
		return false;
}
bool Unreal::Console::Print(const std::string& string)
{
	return Print(std::wstring(string.begin(), string.end()));
}

bool Unreal::Console::Print(const int32_t& integer)
{
	return Print(std::to_wstring(integer));
}
bool Unreal::Console::Print(const uint32_t& unsignedInteger)
{
	return Print(std::to_wstring(unsignedInteger));
}

bool Unreal::Console::Print(const SDK::FVector& vector)
{
	return Print(SDK::UKismetStringLibrary::Conv_VectorToString(vector).ToWString());
}
bool Unreal::Console::Print(const SDK::FRotator& rotator)
{
	return Print(SDK::UKismetStringLibrary::Conv_RotatorToString(rotator).ToWString());
}

bool Unreal::Console::Print(SDK::UObject* objectReference)
{
	return Print(SDK::UKismetStringLibrary::Conv_ObjectToString(objectReference).ToWString());
}

bool Unreal::Console::Print()
{
	return Print(L" ");
}


bool Unreal::Console::Clear()
{
	static const std::wstring emptyLines = L" \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n ";
	return Print(emptyLines);
}






SDK::UInputSettings* Unreal::InputSettings::Get()
{
	SDK::UInputSettings* InputSettings = SDK::UInputSettings::GetDefaultObj();
	return InputSettings ? InputSettings : nullptr;
}


bool Unreal::InputSettings::AssignConsoleBindings()
{
	SDK::UInputSettings* InputSettings = InputSettings::Get();
	if (InputSettings == nullptr)
		return false;

	int32_t bindingsNum = InputSettings->ConsoleKeys.Num();
	if (bindingsNum > 0)
		InputSettings->ConsoleKeys[0].KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"Tilde");
	if (bindingsNum > 1)
		InputSettings->ConsoleKeys[1].KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"F10");
	if (bindingsNum > 2)
		InputSettings->ConsoleKeys[2].KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"¸");

	return true;
}






SDK::UGameViewportClient* Unreal::GameViewportClient::Get()
{
	SDK::UEngine* Engine = Engine::Get();
	if (Engine == nullptr || Engine->GameViewport == nullptr)
		return nullptr;

	return Engine->GameViewport;
}






SDK::UEngine* Unreal::Engine::Get()
{
	SDK::UEngine* Engine = SDK::UEngine::GetEngine();
	return Engine ? Engine : nullptr;
}






SDK::UGameInstance* Unreal::GameInstance::Get()
{
	SDK::UWorld* World = World::Get();
	if (World == nullptr)
		return nullptr;

	SDK::UGameInstance* GameInstance = SDK::UGameplayStatics::GetGameInstance(World);
	if (GameInstance == nullptr)
		return nullptr;

	return GameInstance;
}






SDK::AGameModeBase* Unreal::GameMode::Get()
{
	SDK::UWorld* World = World::Get();
	if (World == nullptr)
		return nullptr;

	SDK::AGameModeBase* GameMode = SDK::UGameplayStatics::GetGameMode(World);
	if (GameMode == nullptr)
		return nullptr;

	return GameMode;
}







SDK::AGameStateBase* Unreal::GameState::Get()
{
	SDK::UWorld* World = World::Get();
	if (World == nullptr)
		return nullptr;

	SDK::AGameStateBase* GameState = SDK::UGameplayStatics::GetGameState(World);
	if (GameState == nullptr)
		return nullptr;

	return GameState;
}






bool Unreal::LevelStreaming::LoadLevelInstance(const SDK::FString& levelPath, const SDK::FVector& locationOffset, const SDK::FRotator& rotationOffset)
{
	SDK::UWorld* world = Unreal::World::Get();
	if (world == nullptr)
		return false;

	bool outSuccess;
#ifdef UE5
	static const SDK::FString optionalLevelNameOverride;
	static SDK::TSubclassOf<SDK::ULevelStreamingDynamic> optionalLevelStreamingClass;
	SDK::ULevelStreamingDynamic::LoadLevelInstance(world, levelPath, locationOffset, rotationOffset, &outSuccess, optionalLevelNameOverride, optionalLevelStreamingClass, false);
#else
	static const SDK::FString optionalLevelNameOverride;
	SDK::ULevelStreamingDynamic::LoadLevelInstance(world, levelPath, locationOffset, rotationOffset, &outSuccess, optionalLevelNameOverride);
#endif

	return outSuccess;
}






SDK::UWorld* Unreal::World::Get()
{
	SDK::UWorld* World = SDK::UWorld::GetWorld();
	return World ? World : nullptr;
}






SDK::APawn* Unreal::Pawn::Get(const int32_t& playerIndex)
{
	SDK::UWorld* World = World::Get();
	if (World == nullptr)
		return nullptr;

	SDK::APawn* Pawn = SDK::UGameplayStatics::GetPlayerPawn(World, playerIndex);
	if (Pawn == nullptr)
		return nullptr;

	return Pawn;
}






bool Unreal::CheatManager::Construct(const bool& ignorePresence)
{
	SDK::APlayerController* PlayerController = PlayerController::Get();
	if (PlayerController == nullptr)
		return false;

	if (ignorePresence == false && PlayerController->CheatManager) // If presence shouldn't be ignored, we're looking up if Cheat Manager already exist.
		return false;

	if (PlayerController->CheatClass == nullptr) // If Player Controller has no cheating class specified, fallback to default Cheat Manager class.
		PlayerController->CheatClass = SDK::UCheatManager::StaticClass();

	/* Before assigning Cheat Manager to the Player Controller, ensure that SpawnObject() returned a valid pointer. */
	if (SDK::UObject* objectReference = SDK::UGameplayStatics::SpawnObject(PlayerController->CheatClass, PlayerController))
	{
		PlayerController->CheatManager = static_cast<SDK::UCheatManager*>(objectReference); // Clarify that newly spawned Object is of class Cheat Manager.
		return true;
	}
	else
		return false;
}






SDK::APlayerController* Unreal::PlayerController::Get(const int32_t& playerIndex)
{
	SDK::UWorld* World = World::Get();
	if (World == nullptr)
		return nullptr;

	SDK::APlayerController* PlayerController = SDK::UGameplayStatics::GetPlayerController(World, playerIndex);
	if (PlayerController == nullptr)
		return nullptr;

	return PlayerController;
}






SDK::ACharacter* Unreal::Character::Get(const int32_t& playerIndex)
{
	SDK::UWorld* World = World::Get();
	if (World == nullptr)
		return nullptr;

	SDK::ACharacter* Character = SDK::UGameplayStatics::GetPlayerCharacter(World, playerIndex);
	if (Character == nullptr)
		return nullptr;

	return Character;
}


int32_t Unreal::Character::GetJumpMaxCount(SDK::ACharacter* characterReference)
{
	return characterReference ? characterReference->JumpMaxCount : 0;
}
int32_t Unreal::Character::GetJumpMaxCount(const int32_t& playerIndex)
{
	return GetJumpMaxCount(Character::Get(playerIndex));
}


bool Unreal::Character::SetJumpMaxCount(SDK::ACharacter* characterReference, const int32_t& value)
{
	if (characterReference)
	{
		characterReference->JumpMaxCount = value;
		return true;
	}
	else
		return false;
}
bool Unreal::Character::SetJumpMaxCount(const int32_t& playerIndex, const int32_t& value)
{
	return SetJumpMaxCount(Character::Get(playerIndex), value);
}


float Unreal::Character::GetJumpVelocity(SDK::ACharacter* characterReference)
{
	if (characterReference == nullptr || characterReference->CharacterMovement == nullptr)
		return 0.0f;

	return characterReference->CharacterMovement->JumpZVelocity;
}
float Unreal::Character::GetJumpVelocity(const int32_t& playerIndex)
{
	return GetJumpVelocity(Character::Get(playerIndex));
}

bool Unreal::Character::SetJumpVelocity(SDK::ACharacter* characterReference, const float& value)
{
	if (characterReference == nullptr || characterReference->CharacterMovement == nullptr)
		return false;

	characterReference->CharacterMovement->JumpZVelocity = value;
}
bool Unreal::Character::SetJumpVelocity(const int32_t& playerIndex, const float& value)
{
	return SetJumpVelocity(Character::Get(playerIndex), value);
}


bool Unreal::Character::Jump(SDK::ACharacter* characterReference)
{
	if (characterReference == nullptr)
		return false;

	bool canJump = characterReference->CanJump();
	if (canJump)
		characterReference->Jump();

	return canJump;
}
bool Unreal::Character::Jump(const int32_t& playerIndex)
{
	SDK::ACharacter* Character = Character::Get(playerIndex);

	if (Character == nullptr)
		return false;

	bool canJump = Character->CanJump();
	if (canJump)
		Character->Jump();

	return canJump;
}


bool Unreal::Character::Launch(SDK::ACharacter* characterReference, const SDK::FVector& launchVelocity, const bool& overrideHorizontalVelocity, const bool& overrideVerticalVelocity)
{
	if (characterReference == nullptr || characterReference->CharacterMovement == nullptr
									  || characterReference->CharacterMovement->bCheatFlying == true
									  || characterReference->CharacterMovement->MovementMode == SDK::EMovementMode::MOVE_None
									  || characterReference->CharacterMovement->IsActive() == false)
		return false;

	SDK::FVector finalVelocity = launchVelocity;
	const SDK::FVector characterVelocity = characterReference->GetVelocity();

	if (overrideHorizontalVelocity == false)
	{
		finalVelocity.X += characterVelocity.X;
		finalVelocity.Y += characterVelocity.Y;
	}

	if (overrideVerticalVelocity == false)
	{
		finalVelocity.Z += characterVelocity.Z;
	}

	characterReference->CharacterMovement->PendingLaunchVelocity = finalVelocity;
	characterReference->OnLaunched(finalVelocity, overrideHorizontalVelocity, overrideVerticalVelocity);

	if (characterReference->CharacterMovement->bCheatFlying)
	{
		characterReference->SetActorEnableCollision(true);
		characterReference->CharacterMovement->bCheatFlying = false;
		characterReference->CharacterMovement->SetMovementMode(SDK::EMovementMode::MOVE_Walking, 0);
	}

	return true;
}
bool Unreal::Character::Launch(const int32_t& playerIndex, const SDK::FVector& launchVelocity, const bool& overrideHorizontalVelocity, const bool& overrideVerticalVelocity)
{
	return Launch(Character::Get(playerIndex), launchVelocity, overrideHorizontalVelocity, overrideVerticalVelocity);
}


bool Unreal::Character::Walk(SDK::ACharacter* characterReference)
{
	if (characterReference == nullptr || characterReference->CharacterMovement == nullptr)
		return false;

	characterReference->SetActorEnableCollision(true);

	characterReference->CharacterMovement->bCheatFlying = false;
	characterReference->CharacterMovement->SetMovementMode(SDK::EMovementMode::MOVE_Walking, 0);

	return true;
}
bool Unreal::Character::Walk(const int32_t& playerIndex)
{
	return Walk(Character::Get(playerIndex));
}

bool Unreal::Character::Fly(SDK::ACharacter* characterReference)
{
	if (characterReference == nullptr || characterReference->CharacterMovement == nullptr)
		return false;

	characterReference->SetActorEnableCollision(true);

	characterReference->CharacterMovement->bCheatFlying = true;
	characterReference->CharacterMovement->SetMovementMode(SDK::EMovementMode::MOVE_Flying, 0);

	return true;
}
bool Unreal::Character::Fly(const int32_t& playerIndex)
{
	return Fly(Character::Get(playerIndex));
}

bool Unreal::Character::Ghost(SDK::ACharacter* characterReference)
{
	if (characterReference == nullptr || characterReference->CharacterMovement == nullptr)
		return false;

	characterReference->SetActorEnableCollision(false);

	characterReference->CharacterMovement->bCheatFlying = true;
	characterReference->CharacterMovement->SetMovementMode(SDK::EMovementMode::MOVE_Flying, 0);

	return true;
}
bool Unreal::Character::Ghost(const int32_t& playerIndex)
{
	return Ghost(Character::Get(playerIndex));
}






std::vector<SDK::AActor*> Unreal::Actor::GetAllDefaultOfClass(const SDK::TSubclassOf<SDK::AActor>& actorClass)
{
	std::vector<SDK::AActor*> outCollection;

	int32_t objectsNum = SDK::UObject::GObjects->Num();
	for (int i = 0; i < objectsNum; i++)
	{
		SDK::UObject* objectReference = SDK::UObject::GObjects->GetByIndex(i);

		if (objectReference == nullptr || objectReference->IsDefaultObject() == false)
			continue;

		if (objectReference->IsA(actorClass))
			outCollection.push_back(static_cast<SDK::AActor*>(objectReference)); // Clarify that found Object is of class Actor.
	}

	return outCollection;
}
std::vector<SDK::AActor*> Unreal::Actor::GetAllOfClass(const SDK::TSubclassOf<SDK::AActor>& actorClass)
{
	std::vector<SDK::AActor*> outCollection;

	int32_t objectsNum = SDK::UObject::GObjects->Num();
	for (int i = 0; i < objectsNum; i++)
	{
		SDK::UObject* objectReference = SDK::UObject::GObjects->GetByIndex(i);

		if (objectReference == nullptr || objectReference->IsDefaultObject())
			continue;

		if (objectReference->IsA(actorClass))
			outCollection.push_back(static_cast<SDK::AActor*>(objectReference)); // Clarify that found Object is of class Actor.
	}

	return outCollection;
}


SDK::AActor* Unreal::Actor::Summon(const SDK::TSubclassOf<SDK::AActor>& actorClass, const Unreal::Transform& transform)
{
	SDK::UWorld* world = Unreal::World::Get();
	if (world == nullptr)
		return nullptr;

	static const SDK::FTransform dummyTransform = SDK::FTransform();
#ifdef UE5
	SDK::AActor* actorReference = SDK::UGameplayStatics::BeginDeferredActorSpawnFromClass(world, actorClass, dummyTransform, SDK::ESpawnActorCollisionHandlingMethod::AlwaysSpawn, nullptr, SDK::ESpawnActorScaleMethod::SelectDefaultAtRuntime);
#else
	SDK::AActor* actorReference = SDK::UGameplayStatics::BeginDeferredActorSpawnFromClass(world, actorClass, dummyTransform, SDK::ESpawnActorCollisionHandlingMethod::AlwaysSpawn, nullptr);
#endif
	if (actorReference == nullptr)
		return nullptr;

#ifdef UE5
	SDK::UGameplayStatics::FinishSpawningActor(actorReference, dummyTransform, SDK::ESpawnActorScaleMethod::SelectDefaultAtRuntime);
#else
	SDK::UGameplayStatics::FinishSpawningActor(actorReference, dummyTransform);
#endif
	actorReference->K2_TeleportTo(transform.location, transform.rotation);
	actorReference->SetActorScale3D(transform.scale);

	return actorReference;
}


Unreal::Transform Unreal::Actor::GetTransform(SDK::AActor* actorReference)
{
	if (actorReference == nullptr)
		return Transform();

	Unreal::Transform outTransform;
	outTransform.location = actorReference->K2_GetActorLocation();
	outTransform.rotation = actorReference->K2_GetActorRotation();
	outTransform.scale = actorReference->GetActorScale3D();

	return outTransform;
}


bool Unreal::Actor::IsValid(SDK::AActor* actorReference)
{
	try
	{
		/* 
			Need to figure out less demanding method!

			So far that's the only approach found capable of functioning on Garbage Collection,
			allowing to call it while moving between levels w/o high risk of getting game crash.
		*/
		if (actorReference)
		{
			int32_t objectsNum = SDK::UObject::GObjects->Num();
			for (int i = 0; i < objectsNum; i++)
			{
				SDK::UObject* objectReference = SDK::UObject::GObjects->GetByIndex(i);

				if (objectReference == actorReference)
					return SDK::UKismetSystemLibrary::IsValid(objectReference);
			}
		}
	}
	catch (...) { }

	return false;
}






std::vector<SDK::UObject*> Unreal::Object::GetAllDefaultOfClass(const SDK::TSubclassOf<SDK::UObject>& objectClass)
{
	std::vector<SDK::UObject*> outCollection;

	int32_t objectsNum = SDK::UObject::GObjects->Num();
	for (int i = 0; i < objectsNum; i++)
	{
		SDK::UObject* objectReference = SDK::UObject::GObjects->GetByIndex(i);

		if (objectReference == nullptr || objectReference->IsDefaultObject() == false)
			continue;

		if (objectReference->IsA(objectClass))
			outCollection.push_back(objectReference);
	}

	return outCollection;
}
std::vector<SDK::UObject*> Unreal::Object::GetAllOfClass(const SDK::TSubclassOf<SDK::UObject>& objectClass)
{
	std::vector<SDK::UObject*> outCollection;

	int32_t objectsNum = SDK::UObject::GObjects->Num();
	for (int i = 0; i < objectsNum; i++)
	{
		SDK::UObject* objectReference = SDK::UObject::GObjects->GetByIndex(i);

		if (objectReference == nullptr || objectReference->IsDefaultObject())
			continue;

		if (objectReference->IsA(objectClass))
			outCollection.push_back(objectReference);
	}

	return outCollection;
}






std::vector<SDK::FString> Unreal::String::Split(const std::wstring& wideString, const wchar_t& separator, const bool& removeSeparatorSpaces)
{
	std::vector<SDK::FString> outCollection;

	if (wideString.empty())
		return outCollection;

	size_t position = 0;
	while (true)
	{
		const size_t separatorPosition = wideString.find(separator, position);

		std::wstring token = (separatorPosition == std::wstring::npos)
							 ? wideString.substr(position)
							 : wideString.substr(position, separatorPosition - position);

		if (removeSeparatorSpaces)
		{
			size_t first = 0;
			while (first < token.size() && std::iswspace(token[first]))
				++first;

			size_t last = token.size();
			while (last > first && std::iswspace(token[last - 1]))
				--last;

			token = token.substr(first, last - first);
		}

		if (token.empty() == false)
			outCollection.push_back(SDK::FString(token.c_str()));

		if (separatorPosition == std::wstring::npos)
			break;

		position = separatorPosition + 1;
	}

	return outCollection;
}
