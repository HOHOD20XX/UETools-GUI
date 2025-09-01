#pragma once
#include "SDK\Engine_classes.hpp"
#include "CranchyLib.h"

#include "Engine.h"






class Console
{
public:
	static bool IsConsolePresent();
	static SDK::UConsole* GetConsole();
	static bool SetConsole(SDK::UConsole* newConsole);
	static bool ConstructConsole();


public:
	static bool Print(const std::wstring& wideString);
	static bool Print(const std::string& string);
	static bool Print(const SDK::int32& integer);
	static bool Print(const SDK::FVector& vector);
	static bool Print(const SDK::FRotator& rotator);
	static bool Print(SDK::UObject* objectReference);
	static bool Print();
};

