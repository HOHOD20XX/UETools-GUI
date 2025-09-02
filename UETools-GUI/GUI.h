#pragma once
#include "DirectWindow.h"
#include "imgui.h"

#include "CranchyLib.h"
#include "Math.h"

#include "Input.h"
#include "Console.h"
#include "CheatManager.h"
#include "GameInstance.h"
#include "GameMode.h"
#include "GameState.h"
#include "Character.h"

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


	static int ImGuiKey_ToWinAPI(const ImGuiKey& key);


	bool KeyBindingInput(const char* label, S_KeyBinding* binding);
	bool IsKeyBindingPressed(S_KeyBinding* binding, const bool& waitForRelease = true);
	bool IsKeyBindingDown(S_KeyBinding* binding);
	bool IsKeyBindingReleased(S_KeyBinding* binding);
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
		static void UpdateDebugInformation();

	public:
		static void ProcessKeybindings();
	};






	class SharedData
	{
	public:
		struct S_Engine
		{
			SDK::UEngine* engineReference;
			std::string engineClass;
			std::string engineObject;

			bool fixedFrameRateEnabled;
			double fixedFrameRate;

			bool smoothFrameRateEnabled;
			double smoothFrameRateLowerBound;
			double smoothFrameRateUpperBound;

			bool subtitlesEnabled;
			bool subtitlesForcedOff;

			bool pauseOnLossOfFocus;
		};

		struct S_GameSession
		{
			SDK::AGameSession* gameSessionReference;
			std::string gameSessionClass;
			std::string gameSessionObject;

			int32_t maxPlayers;
			int32_t maxSpectators;
			int32_t maxPartySize;
			int8_t maxSplitScreensPerConnection;

			std::string sessionName;
		};

		struct S_GameMode
		{
			SDK::AGameModeBase* gameModeReference;
			std::string gameModeClass;
			std::string gameModeObject;

			S_GameSession gameSession;

			int32_t playersCount;
			int32_t spectatorsCount;

			bool startPlayersAsSpectators;
			std::string defaultPlayerName;

			bool useSeamlessTravel;

			std::string options;
			bool isPausable;
		};




	public:
		struct S_WorldSettings
		{
			SDK::AWorldSettings* worldSettingsReference;

			std::string worldSettingsClass;
			std::string worldSettingsObject;

			bool worldHighPriorityLoading;
			bool worldLocalHighPriorityLoading;

			double worldToMeters;
		};

		struct S_Level
		{
			SDK::ULevel* levelReference;

			std::string levelClass;
			std::string levelObject;
			std::string levelName;

			bool isLevelVisible;

			S_WorldSettings worldSettings;
		};

		struct S_StreamingLevel
		{
			SDK::ULevelStreaming* streamingLevelReference;
			std::string streamingLevelPath;
			SDK::FLinearColor streamingLevelColor;

			S_Level level;
		};




	public:
		struct S_DebugInformation
		{
			bool isActive;
			bool autoUpdate;

			double lastUpdateTime;

			S_Engine engine;

			bool isGameInstancePresent;
			std::string gameInstanceClass;
			std::string gameInstanceObject;

			S_GameMode gameMode;

			bool isGameStatePresent;
			std::string gameStateClass;
			std::string gameStateObject;

			bool isConsolePresent;
			std::string consoleClass;
			std::string consoleObject;

			bool isCheatManagerPresent;
			std::string cheatManagerClass;
			std::string cheatManagerObject;

			bool isControllerPresent;
			std::string controllerClass;
			std::string controllerObject;

				bool isPlayerPresent;
				std::string playerClass;
				std::string playerObject;

				bool isPawnPresent;
				std::string pawnClass;
				std::string pawnObject;
				std::string pawnLocation;
				std::string pawnRotation;
				std::string pawnScale;
				bool isPawnControlled;
				bool isPawnPawnControlled;
				bool isPawnPlayerControlled;
				bool isPawnLocallyControlled;
				bool isPawnBotControlled;

				bool isCameraManagerPresent;
				std::string cameraManagerClass;
				std::string cameraManagerObject;
				std::string cameraManagerLocation;
				std::string cameraManagerRotation;
				std::string cameraManagerScale;

			bool isViewportClientPresent;
			std::string viewportClientClass;
			std::string viewportClientObject;

			bool isWorldPresent;
			std::string worldClass;
			std::string worldObject;

				S_Level persistentLevel;

				bool areStreamingLevelsPresent;
				std::vector<S_StreamingLevel> streamingLevels;

				double gameTimeInSeconds;

				bool isServer;
				bool isDedicatedServer;
				bool isSplitScreen;
				bool isStandalone;

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
		struct S_FeaturesInformation
		{
			bool isDirectionalMovementEnabled;
			double directionalMovementStep = 45.0;
			double directionalMovementDelay = 0.1;

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
				: menuOpenClose{ ImGuiKey_Insert },
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