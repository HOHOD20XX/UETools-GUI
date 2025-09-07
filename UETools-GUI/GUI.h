#pragma once
#include "DirectWindow.h"
#include "imgui.h"

#include "Unreal.h"
#include "Clipboard.h"
#include "Math.h"

#include <Windows.h>
#include <algorithm>

/*
	#define UE5

	When targeting Unreal Engine 5 based titles, it's recommended to uncomment that define;
	In many cases that action alone would be enough to adapt entirity of solution for newer engine.
*/

/* 
	#define ACTOR_TRACE 

	The way Line Tracing work often differ from Engine to Engine (e.g. 4.25 -> 4.27),
	it's disabled by default in order to avoid a potential set of compilation errors. 
*/
#define ACTOR_TRACE 





namespace ImGui
{
	struct KeyBinding
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
	bool KeyBindingInput(const char* label, KeyBinding* binding);
	bool IsKeyBindingPressed(KeyBinding* binding, const bool& waitForRelease = true);
	bool IsKeyBindingDown(KeyBinding* binding);
	bool IsKeyBindingReleased(KeyBinding* binding);


	static void SetFontScale(const float& fontScale)
	{
		SetWindowFontScale(fontScale);
	}
	static void SetFontTiny()
	{
		SetFontScale(0.5f);
	}
	static void SetFontLittle()
	{
		SetFontScale(0.75f);
	}
	static void SetFontSmall()
	{
		SetFontScale(0.9f);
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
};






class GUI
{
private:
	static inline bool isMenuActive = false;
public:
	static bool GetIsMenuActive()
	{
		return isMenuActive;
	}
	static void SetIsMenuActive(const bool& isActive)
	{
		isMenuActive = isActive;
	}
	static void ToggleIsMenuActive()
	{
		isMenuActive = !isMenuActive;
	}




public:
	static void Init(const HMODULE& applicationModule);
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
	};





	class SharedData
	{
	public:
		struct S_ObjectsInformation
		{
			SDK::APlayerController* controller;
			SDK::ACharacter* character;
			SDK::UCharacterMovementComponent* movementComponent;
		};
		static inline S_ObjectsInformation objectsInfo = {};
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






namespace Features
{
	class Debug
	{
	public:
		static inline bool enabled;

		static inline double lastUpdateTime;

		static inline bool autoUpdate;
		static inline float autoUpdateDelay = 0.01f;

		static inline Unreal::Engine::DataStructure engine;

		static inline Unreal::GameInstance::DataStructure gameInstance;

		static inline Unreal::GameMode::DataStructure gameMode;

		static inline Unreal::PlayerController::DataStructure playerController;

		static inline Unreal::World::DataStructure world;

		static inline bool wasProjectNameObtained;
		static inline std::string projectName;

		static inline bool wasProjectPlatformObtained;
		static inline std::string projectPlatform;

		static inline bool wasProjectEngineVersionObtained;
		static inline std::string projectEngineVersion;

		static inline bool wasUsernameObtained;
		static inline std::string username;

		static inline bool wasCommandLineObtained;
		static inline std::string commandLine;


		static void Update();
	};



	class ActorsList
	{
	public:
		static inline bool enabled;

		static inline char filterBuffer[255];
		static inline size_t filterBufferSize = 255;
		static inline bool filterCaseSensitive = true;

		static inline char componentsFilterBuffer[255];
		static inline size_t componentsFilterBufferSize = 255;
		static inline bool componentsFilterCaseSensitive = true;

		static inline std::vector<Unreal::Actor::DataStructure> actors;


		static void Update();
	};




	class DirectionalMovement
	{
	public:
		static inline bool enabled;

		static inline double step = 45.0;
		static inline double delay = 0.05;


	private:
		static inline HANDLE thread = nullptr;
		static void Worker();
	public:
		static HANDLE GetThread()
		{
			return thread;
		}
		static bool StartThread()
		{
			if (thread)
				return false;

			thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Features::DirectionalMovement::Worker, 0, 0, 0);
			return thread;
		}
	};




	class Launch
	{
	public:
		static inline float velocity[3] = { 0.0f, 0.0f, 1325.0f };
	};




	class Dash
	{
	public:
		static inline double strength = 3375.0;
	};




#ifdef ACTOR_TRACE
	class ActorTrace
	{
	public:
		static inline bool enabled = false;
		static inline bool showOnScreen = false;
		static inline bool showLineTrace = true;

		static inline SDK::FVector traceStartLocation;
		static inline SDK::FVector traceEndLocation;
		static inline float traceColor[4] = { 0.118f, 1.0f, 0.0f, 0.5f };
		static inline float traceThickness = 3.5f;
		static inline float traceLength = 2048.0f;

		static inline bool traceHit;
		static inline Unreal::Actor::DataStructure actor;


		static bool Trace();
	};
#endif
};






class Keybindings
{
public:
	static inline ImGui::KeyBinding menuOpenClose = ImGui::KeyBinding(ImGuiKey_Insert);

	static inline ImGui::KeyBinding ghost;
	static inline ImGui::KeyBinding fly;
	static inline ImGui::KeyBinding walk;

	static inline ImGui::KeyBinding jump;

	static inline ImGui::KeyBinding launch;
	static inline ImGui::KeyBinding dash;

	static inline ImGui::KeyBinding actorTrace = ImGui::KeyBinding(ImGuiKey_T);


	static void Process();
};