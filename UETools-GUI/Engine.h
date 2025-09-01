#pragma once
#include "SDK\Engine_classes.hpp"






class Engine
{
public:
	static SDK::UEngine* GetEngine();




public:
	static SDK::UFont* GetTinyFont();
	static bool SetTinyFont(SDK::UFont* newFont);

	static bool GetTinyFontSoftPath(SDK::FSoftObjectPath* outPath);
	static bool SetTinyFontSoftPath(const SDK::FSoftObjectPath& newPath);


	static SDK::UFont* GetSmallFont();
	static bool SetSmallFont(SDK::UFont* newFont);

	static bool GetSmallFontSoftPath(SDK::FSoftObjectPath* outPath);
	static bool SetSmallFontSoftPath(const SDK::FSoftObjectPath& newPath);


	static SDK::UFont* GetMediumFont();
	static bool SetMediumFont(SDK::UFont* newFont);

	static bool GetMediumFontSoftPath(SDK::FSoftObjectPath* outPath);
	static bool SetMediumFontSoftPath(const SDK::FSoftObjectPath& newPath);


	static SDK::UFont* GetLargeFont();
	static bool SetLargeFont(SDK::UFont* newFont);
	static bool GetLargeFontSoftPath(SDK::FSoftObjectPath* outPath);
	static bool SetLargeFontSoftPath(const SDK::FSoftObjectPath& newPath);


	static SDK::UFont* GetSubtitleFont();
	static bool SetSubtitleFont(SDK::UFont* newFont);
	static bool GetSubtitleFontSoftPath(SDK::FSoftObjectPath* outPath);
	static bool SetSubtitleFontSoftPath(const SDK::FSoftObjectPath& newPath);




public:
	static SDK::TSubclassOf<SDK::UConsole> GetConsoleClass();
	static bool SetConsoleClass(const SDK::TSubclassOf<SDK::UConsole>& newConsoleClass);

	static bool GetConsoleSoftPath(SDK::FSoftClassPath* outPath);
	static bool SetConsoleSoftPath(const SDK::FSoftClassPath& newPath);




public:
	static SDK::UGameViewportClient* GetGameViewport();
	static bool SetGameViewport(SDK::UGameViewportClient* newViewport);

	static SDK::TSubclassOf<SDK::UGameViewportClient> GetGameViewportClass();
	static bool SetGameViewportClass(const SDK::TSubclassOf<SDK::UGameViewportClient>& newGameViewportClass);

	static bool GetGameViewportSoftPath(SDK::FSoftClassPath* outPath);
	static bool SetGameViewportSoftPath(const SDK::FSoftClassPath& newPath);
};

