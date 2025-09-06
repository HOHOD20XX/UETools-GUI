#pragma once
#include "DirectWindow.h"
#include "imgui.h"

#include "Clipboard.h"
#include "Math.h"

#include <Windows.h>
#include <algorithm>

// #define UE5






namespace ImGui
{
	struct S_KeyBinding
	{
		ImGuiKey key = ImGuiKey_None;
		bool isDetermined = true;
		bool isInUse = false;
	};


	void TextBool(const char* label, const bool& inBool, const char* text_true, const char* text_false, const bool& useColoring, const ImU32& color_true, const ImU32& color_false);
	void TextBool(const char* label, const bool& inBool);
	void TextBoolColored(const char* label, const bool& status);
	void TextBoolPresence(const char* label, const bool& presence);
	void TextBoolPresenceColored(const char* label, const bool& presence);
	void TextBoolMultiplePresence(const char* label, const bool& presence);
	void TextBoolMultiplePresenceColored(const char* label, const bool& presence);


	void TextFloat(const char* label, const float& value, const bool& useColoring, const ImU32& color_positive, const ImU32& color_negative);
	void TextFloat(const char* label, const float& value);
	void TextFloatColored(const char* label, const float& value);


	void TextInt(const char* label, const int32_t& value, const bool& useColoring, const ImU32& color_positive, const ImU32& color_negative);
	void TextInt(const char* label, const int32_t& value);
	void TextIntColored(const char* label, const int32_t& value);


	void TextVector(const char* label, const SDK::FVector& value, const bool& useColoring, const ImU32& color_positive, const ImU32& color_negative);
	void TextVector(const char* label, const SDK::FVector& value);
	void TextVectorColored(const char* label, const SDK::FVector& value);


	void TextRotator(const char* label, const SDK::FRotator& value, const bool& useColoring, const ImU32& color_positive, const ImU32& color_negative);
	void TextRotator(const char* label, const SDK::FRotator& value);
	void TextRotatorColored(const char* label, const SDK::FRotator& value);


	void ReadOnlyInputText(const char* label, const char* text, const bool& showCopyButton);


	static int ImGuiKey_ToWinAPI(const ImGuiKey& key);
	bool KeyBindingInput(const char* label, S_KeyBinding* binding);
	bool IsKeyBindingPressed(S_KeyBinding* binding, const bool& waitForRelease = true);
	bool IsKeyBindingDown(S_KeyBinding* binding);
	bool IsKeyBindingReleased(S_KeyBinding* binding);


	static void SetFontScale(const float& fontScale)
	{
		SetWindowFontScale(fontScale);
	}
	static void SetFontSmall()
	{
		SetFontScale(0.5f);
	}
	static void SetFontRegular()
	{
		SetFontScale(1.0f);
	}
	static void SetFontBig()
	{
		SetFontScale(1.1f);
	}
	static void SetFontLarge()
	{
		SetFontScale(1.25f);
	}
	static void SetFontTitle()
	{
		SetFontScale(1.5f);
	}
}






class GUI
{
private:
	static inline bool isActive = true;
public:
	static bool GetIsActive()
	{
		return isActive;
	}
	static void SetIsActive(const bool& newIsActive)
	{
		isActive = newIsActive;
	}
	static void ToggleIsActive()
	{
		isActive = !isActive;
	}




private:
	static inline bool isInWaitMode = false;
	static inline double waitModeEndTime = 0.0;
public:
	static bool GetIsInWaitMode()
	{
		return isInWaitMode;
	}
	static void SetIsInWaitMode(const bool& newIsInWaitMode)
	{
		isInWaitMode = newIsInWaitMode;
	}

	static double GetWaitModeEndTime()
	{
		return waitModeEndTime;
	}
	static void SetWaitModeEndTime(const double& newWaitModeEndTime)
	{
		waitModeEndTime = newWaitModeEndTime;
	}

	static void StartWaitMode(const double& duration)
	{
		waitModeEndTime = ImGui::GetTime() + duration;
		isInWaitMode = true;
	}




private:
	static inline bool isForeground = true;
public:
	static bool GetIsForeground()
	{
		return isForeground;
	}
	static void SetIsForeground(const bool& newIsForeground)
	{
		isForeground = newIsForeground;
	}




public:
	static void Create(const HMODULE& applicationModule);
	static void Draw();




public:
	enum class E_Sound
	{
		BUTTON_PRESS,
		BUTTON_CANCEL,
		ACTION_SUCCESS,
		ACTION_ERROR
	};
	static void PlaySound(const E_Sound& soundToPlay);
	static void PlayActionSound(const bool& wasSuccessfull)
	{
		PlaySound(wasSuccessfull ? E_Sound::ACTION_SUCCESS : E_Sound::ACTION_ERROR);
	}






	class SharedWorkers
	{
	private:
		static inline HANDLE userInterfaceThread = nullptr;
	public:
		static HANDLE GetUserInterfaceThread()
		{
			return userInterfaceThread;
		}
		static void SetUserInterfaceThread(const HANDLE& newUserInterfaceThread)
		{
			userInterfaceThread = newUserInterfaceThread;
		}


	private:
		static inline HANDLE featuresThread = nullptr;
	public:
		static HANDLE GetFeaturesThread()
		{
			return featuresThread;
		}
		static void SetFeaturesThread(const HANDLE& newFeaturesThread)
		{
			featuresThread = newFeaturesThread;
		}
		static void FeaturesWorker();
	};






	class SharedCalls
	{
	public:
		static void GatherDebugInformation();


	public:
		static void GatherActors();


	public:
		static void ProcessKeybindings();
	};






	class SharedData
	{
	public:
		struct S_GatherActorsFeature
		{
			bool enabled;

			char filterBuffer[255];
			size_t filterBufferSize = 255;
			bool filterCaseSensitive = true;

			char componentsFilterBuffer[255];
			size_t componentsFilterBufferSize = 255;
			bool componentsFilterCaseSensitive = true;

			std::vector<S_Actor> actors;
		};




	public:
		struct S_DebugInformation
		{
			bool isActive;

			double lastUpdateTime;

			bool autoUpdate;
			float autoUpdateDelay = 0.01f;

			S_Engine engine;

			S_GameInstance gameInstance;

			S_GameMode gameMode;

			S_PlayerController playerController;

			S_World world;

			S_GatherActorsFeature gatherActorsFeature;

			bool wasProjectNameObtained;
			std::string projectName;

			bool wasProjectPlatformObtained;
			std::string projectPlatform;

			bool wasProjectEngineVersionObtained;
			std::string projectEngineVersion;

			bool wasUsernameObtained;
			std::string username;

			bool wasCommandLineObtained;
			std::string commandLine;
		};
		static inline S_DebugInformation debugInfo = {};




	public:
		struct S_ObjectsInformation
		{
			SDK::APlayerController* controller;
			SDK::ACharacter* character;
			SDK::UCharacterMovementComponent* movementComponent;
		};
		static inline S_ObjectsInformation objectsInfo = {};




	public:
		struct S_DirectionalMovement
		{
			bool enabled;
			double movementStep = 45.0;
			double movementDelay = 0.05;
		};

		struct S_FeaturesInformation
		{
			S_DirectionalMovement directionalMovement;

			float launchVelocity[3] = { 0.0f, 0.0f, 1325.0f };

			double dashStrength = 3375.0;
		};
		static inline S_FeaturesInformation featuresInfo = {};




	public:
		struct S_KeybindingsInformation
		{
			ImGui::S_KeyBinding menuOpenClose;

			ImGui::S_KeyBinding ghost;
			ImGui::S_KeyBinding fly;
			ImGui::S_KeyBinding walk;

			ImGui::S_KeyBinding jump;

			ImGui::S_KeyBinding launch;
			ImGui::S_KeyBinding dash;

			S_KeybindingsInformation()
				: menuOpenClose { ImGuiKey_Insert },
				  ghost{ ImGuiKey_Keypad7 },
				  fly{ ImGuiKey_Keypad8 },
				  walk{ ImGuiKey_Keypad9 }
			{
			}
		};
		static inline S_KeybindingsInformation keybindingsInfo = {};
	};






	class SharedFunctions
	{
	public:
		static void Ghost();
		static void Fly();
		static void Walk();


	public:
		static void Jump();


	public:
		static void Launch();
		static void Dash();
	};
};