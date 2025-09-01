#include "Console.h"
#include "CheatManager.h"






bool Console::IsConsolePresent()
{
	return GetConsole();
}

SDK::UConsole* Console::GetConsole()
{
	SDK::UGameViewportClient* ViewportClient = Engine::GetGameViewport();
	if (ViewportClient == nullptr || ViewportClient->ViewportConsole == nullptr)
		return nullptr;

	return ViewportClient->ViewportConsole;
}

bool Console::SetConsole(SDK::UConsole* newConsole)
{
	SDK::UGameViewportClient* ViewportClient = Engine::GetGameViewport();
	if (ViewportClient == nullptr)
		return false;

	ViewportClient->ViewportConsole = newConsole;
	return true;
}

bool Console::ConstructConsole()
{
	SDK::UGameViewportClient* ViewportClient = Engine::GetGameViewport();
	if (ViewportClient == nullptr)
		return false;

	if (ViewportClient->ViewportConsole)
		return false;

	SDK::UObject* consoleObject = SDK::UGameplayStatics::SpawnObject(Engine::GetConsoleClass(), ViewportClient);
	if (consoleObject == nullptr)
		return false;

	ViewportClient->ViewportConsole = static_cast<SDK::UConsole*>(consoleObject);
	return true;
}




bool Console::Print(const std::wstring& wideString)
{
    const wchar_t* wCharString = wideString.c_str();
    wprintf(L"%ls\n", wCharString);

	if (SDK::APlayerController* controller = Controller::GetController())
	{
		SDK::FString fString = SDK::FString(wCharString);
		controller->ClientMessage(fString, SDK::UKismetStringLibrary::Conv_StringToName(L"None"), 0);
		return true;
	}
	else
		return false;
}


bool Console::Print(const std::string& string)
{
    return Print(StringUtilities::String_ToWString(string));
}


bool Console::Print(const SDK::int32& integer)
{
    return Print(SDK::UKismetStringLibrary::Conv_IntToString(integer).ToWString());
}


bool Console::Print(const SDK::FVector& vector)
{
    return Print(SDK::UKismetStringLibrary::Conv_VectorToString(vector).ToWString());
}


bool Console::Print(const SDK::FRotator& rotator)
{
    return Print(SDK::UKismetStringLibrary::Conv_RotatorToString(rotator).ToWString());
}


bool Console::Print(SDK::UObject* objectReference)
{
    return Print(SDK::UKismetStringLibrary::Conv_ObjectToString(objectReference).ToWString());
}


bool Console::Print()
{
    return Print(L" ");
}
