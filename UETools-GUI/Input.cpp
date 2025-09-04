#include "Input.h"






SDK::UInputSettings* Input::GetInputSettings(const bool& searchForDefaultObject)
{
	SDK::UInputSettings* InputSettings = nullptr;
	if (searchForDefaultObject)
	{
		InputSettings = SDK::UInputSettings::GetDefaultObj();
		if (InputSettings == nullptr)
			return nullptr;
	}
	else
	{
		SDK::UObject* foundObject = Object::GetObjectOfClass(SDK::UInputSettings::StaticClass());
		if (foundObject == nullptr)
			return nullptr;

		InputSettings = static_cast<SDK::UInputSettings*>(foundObject);
	}

	return InputSettings;
}




std::vector<SDK::FKey> Input::GetConsoleBindings()
{
	std::vector<SDK::FKey> outputArray;

	SDK::UInputSettings* InputSettings = GetInputSettings();
	if (InputSettings == nullptr)
		return outputArray;

	int32_t bindingsNum = InputSettings->ConsoleKeys.Num();
	for (int i = 0; i < bindingsNum; i++)
		outputArray.push_back(InputSettings->ConsoleKeys[i]);

	return outputArray;
}

bool Input::CreateConsoleBindings()
{
	SDK::UInputSettings* InputSettings = GetInputSettings();
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




bool Input::SetIsInputDisabled(const bool& newInputDisabled)
{
	if (newInputDisabled)
	{
		SDK::APlayerController* Controller = PlayerController::GetPlayerController();
		if (Controller == nullptr)
			return false;

		initialPlayerController = Controller;

		initialIgnoreMoveInput = Controller->IsMoveInputIgnored();
		initialIgnoreLookInput = Controller->IsLookInputIgnored();

		Controller->SetIgnoreMoveInput(true);
		Controller->SetIgnoreLookInput(true);
		return true;
	}
	else
	{
		if (initialPlayerController == nullptr)
			return false;

		initialPlayerController->SetIgnoreMoveInput(initialIgnoreMoveInput);
		initialPlayerController->SetIgnoreLookInput(initialIgnoreLookInput);

		initialIgnoreMoveInput = false;
		initialIgnoreLookInput = false;
		initialPlayerController = nullptr;

		return false;
	}
}
