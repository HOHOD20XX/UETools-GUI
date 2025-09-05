#pragma once
#include "DirectWindow.h"
#include "imgui.h"

#include "Clipboard.h"
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
		struct S_Console
		{
			SDK::UConsole* consoleReference;
			std::string consoleClass;
			std::string consoleObject;
		};

		struct S_ViewportClient
		{
			SDK::UGameViewportClient* viewportClientReference;
			std::string viewportClientClass;
			std::string viewportClientObject;

			S_Console console;
		};

		struct S_Engine
		{
			SDK::UEngine* engineReference;
			std::string engineClass;
			std::string engineObject;

			S_ViewportClient viewportClient;

			bool fixedFrameRateEnabled;
			double fixedFrameRate;

			bool smoothFrameRateEnabled;
			SDK::FFloatRange smoothFrameRateRange;

			bool subtitlesEnabled;
			bool subtitlesForcedOff;

			bool pauseOnLossOfFocus;
		};

		struct S_OnlineSession
		{
			SDK::UOnlineSession* onlineSessionReference;
			std::string onlineSessionClass;
			std::string onlineSessionObject;
		};

		struct S_GameInstance
		{
			SDK::UGameInstance* gameInstanceReference;
			std::string gameInstanceClass;
			std::string gameInstanceObject;

			S_OnlineSession onlineSession;
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

		struct S_GameState
		{
			SDK::AGameStateBase* gameStateReference;
			std::string gameStateClass;
			std::string gameStateObject;
		};

		struct S_NetDriver
		{
			SDK::UNetDriver* netDriverReference;
			std::string netDriverClass;
			std::string netDriverObject;
		};

		struct S_DemoNetDriver
		{
			SDK::UNetDriver* demoNetDriverReference;
			std::string demoNetDriverClass;
			std::string demoNetDriverObject;
		};

		struct S_World
		{
			SDK::UWorld* worldReference;
			std::string worldClass;
			std::string worldObject;

			S_GameState gameState;

			S_NetDriver netDriver;
			S_DemoNetDriver demoNetDriver;

			S_Level persistentLevel;

			std::vector<S_StreamingLevel> streamingLevels;

			double gameTimeInSeconds;

			bool isServer;
			bool isDedicatedServer;
			bool isSplitScreen;
			bool isStandalone;
		};

		struct S_Player
		{
			SDK::UPlayer* playerReference;
			std::string playerClass;
			std::string playerObject;
		};

		struct S_Pawn
		{
			SDK::APawn* pawnReference;
			std::string pawnClass;
			std::string pawnObject;

			SDK::FVector location;
			SDK::FRotator rotation;
			SDK::FVector scale;

			bool isControlled;
			bool isPawnControlled;
			bool isPlayerControlled;
			bool isLocallyControlled;
			bool isBotControlled;
		};

		struct S_CameraManager
		{
			SDK::APlayerCameraManager* cameraManagerReference;
			std::string cameraManagerClass;
			std::string cameraManagerObject;

			SDK::FVector location;
			SDK::FRotator rotation;
			SDK::FVector scale;
		};

		struct S_CheatManager
		{
			SDK::UCheatManager* cheatManagerReference;
			std::string cheatManagerClass;
			std::string cheatManagerObject;
		};

		struct S_PlayerController
		{
			SDK::APlayerController* playerControllerReference;
			std::string playerControllerClass;
			std::string playerControllerObject;

			S_Player player;

			S_Pawn pawn;

			S_CameraManager cameraManager;

			S_CheatManager cheatManager;
		};

		struct S_ActorComponent
		{
			SDK::UActorComponent* actorComponentReference;
			std::string actorComponentClass;
			std::string actorComponentObject;

			bool isActive;
			bool autoActivate;
			bool editorOnly;

			bool netAddressible;
			bool replicates;

			SDK::EComponentCreationMethod creationMethod;
		};

		struct S_Actor
		{
			SDK::AActor* actorReference;
			std::string actorClass;
			std::string actorObject;

			SDK::FVector location;
			SDK::FRotator rotation;
			SDK::FVector scale;

			std::vector<S_ActorComponent> components;
		};




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