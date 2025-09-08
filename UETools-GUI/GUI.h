#pragma once
#include "DirectWindow.h"
#include "imgui.h"

#include "Unreal.h"
#include "Clipboard.h"
#include "Math.h"

#include <Windows.h>
#include <algorithm>
#include <thread>

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


	/*
	* @brief Using pre-determined table, converts an ImGui key to the corresponding WinAPI virtual-key code.
	* @param key - ImGui key to be converted.
	* @return The corresponding WinAPI virtual-key code, or 0 if unsupported.
	*/
	static int ImGuiKey_ToWinAPI(const ImGuiKey& key);
	/*
	* @brief Using pre-determined table, returns a human-readable name for a given ImGui key.
	* @param key - ImGui key to get the name of.
	* @return The key name as a string.
	*/
	static const char* ImGuiKey_GetName(const ImGuiKey& key);

	/*
	* @brief Renders a key binding input control in ImGui.
	* 
	* Displays a button with the current binding state and allows the user
	* to assign or unbind a key interactively.
	* 
	* @param label - label text to display (may contain "##" to hide ID).
	* @param binding - pointer to key binding structure.
	* @return 'True' if the binding was changed; otherwise 'False'
	*/
	bool KeyBindingInput(const char* label, KeyBinding* binding);
	bool IsKeyBindingPressed(KeyBinding* binding, const bool& waitForRelease = true);
	bool IsKeyBindingDown(KeyBinding* binding);
	bool IsKeyBindingReleased(KeyBinding* binding);


	/*
	* @brief Sets the font scale to the specified value.
	* @param fontScale - scale factor.
	*/
	static void SetFontScale(const float& fontScale)
	{
		SetWindowFontScale(fontScale);
	}
	/*
	* @brief Sets the font scale to 0.5x.
	*/
	static void SetFontTiny()
	{
		SetFontScale(0.5f);
	}
	/*
	* @brief Sets the font scale to 0.75x.
	*/
	static void SetFontLittle()
	{
		SetFontScale(0.75f);
	}
	/*
	* @brief Sets the font scale to 0.9x.
	*/
	static void SetFontSmall()
	{
		SetFontScale(0.9f);
	}
	/*
	* @brief Sets the font scale to 1.0x.
	*/
	static void SetFontRegular()
	{
		SetFontScale(1.0f);
	}
	/*
	* @brief Sets the font scale to 1.1x.
	*/
	static void SetFontBig()
	{
		SetFontScale(1.1f);
	}
	/*
	* @brief Sets the font scale to 1.25x.
	*/
	static void SetFontLarge()
	{
		SetFontScale(1.25f);
	}
	/*
	* @brief Sets the font scale to 1.5x.
	*/
	static void SetFontTitle()
	{
		SetFontScale(1.5f);
	}




	/*
	* @brief New Line + Separator + New Line.
	*/
	static void CategorySeparator()
	{
		ImGui::NewLine();
		ImGui::Separator();
		ImGui::NewLine();
	}


	/*
	* @brief Prints pre-determined number of spaces to expand menu horizontally.
	*/
	static void MenuSpacer()
	{
		static const char* menuSpacer = "                                                                                               ";
		ImGui::TextUnformatted(menuSpacer, menuSpacer + 96);
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


private:
	static inline HANDLE directWindowThread = nullptr;
public:
	static HANDLE GetDirectWindowThread()
	{
		return directWindowThread;
	}
	static bool StartDirectWindowThread();




public:
	/*
	* @brief Initializes the GUI system. Should be called to start ImGui and create the menu.
	* @param applicationModule - Handle of the current (this) DLL module.
	*/
	static void Init(const HMODULE& applicationModule);
	/*
	* @brief Renders frame of GUI elements.
	* 
	* Called once per frame by DirectWindow class (on each ImGui::NewFrame())
	* to draw application-specific ImGui controls and windows.
	*/
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
	class Menu
	{
	public:
		static inline bool enableSound = true;
		static inline bool enableConsoleOutput = true;
	};




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




	class CharacterMovement
	{
	public:
		static void Ghost();
		static void Fly();
		static void Walk();


		static void Jump();


		static inline float launchVelocity[3] = { 0.0f, 0.0f, 1325.0f };
		static void Launch();


		static inline double dashStrength = 3375.0;
		static void Dash();
	};




	class Camera
	{
	public:
		static inline float fadeFromAlpha = 0.0f;
		static inline float fadeToAlpha = 1.0f;
		static inline float fadeDuration = 2.5f;
		static inline float fadeColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
		static inline bool fadeAudio = false;
		static inline bool fadePersistent = true;


		static void StartFade();
		static void StopFade();
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
		static bool StartThread();
		static bool InvalidateThread();
	};




#ifdef ACTOR_TRACE
	class ActorTrace
	{
	public:
		static inline bool enabled = false;
		static inline bool showOnScreen = true;
		static inline bool showLineTrace = true;

		static inline SDK::FVector traceStartLocation;
		static inline SDK::FVector traceEndLocation;
		static inline float traceColor[4] = { 0.118f, 1.0f, 0.0f, 0.5f };
		static inline float traceThickness = 3.5f;
		static inline float traceLength = 2048.0f;

		static inline bool traceCast; // When set to 'True', indicates that user have casted a ray; would render a dummy { 0.0, 0.0 } - { 0.0, 0.0 } line otherwise.
		static inline bool traceHit;

#ifdef UE5
		static inline Unreal::Object::DataStructure object;
#else
		static inline Unreal::Actor::DataStructure actor;
#endif


		static bool Trace();
	};
#endif
};






class Keybindings
{
public:
	static inline ImGui::KeyBinding general_MenuOpenClose = ImGui::KeyBinding(ImGuiKey_Insert);

	static inline ImGui::KeyBinding debug_ActorTrace = ImGui::KeyBinding(ImGuiKey_T);

	static inline ImGui::KeyBinding characterMovement_Ghost = ImGui::KeyBinding(ImGuiKey_Keypad7);
	static inline ImGui::KeyBinding characterMovement_Fly = ImGui::KeyBinding(ImGuiKey_Keypad8);
	static inline ImGui::KeyBinding characterMovement_Walk = ImGui::KeyBinding(ImGuiKey_Keypad9);
	static inline ImGui::KeyBinding characterMovement_Jump;
	static inline ImGui::KeyBinding characterMovement_Launch;
	static inline ImGui::KeyBinding characterMovement_Dash;

	static inline ImGui::KeyBinding characterCamera_StartFade;
	static inline ImGui::KeyBinding characterCamera_StopFade;


	static void Process();
};