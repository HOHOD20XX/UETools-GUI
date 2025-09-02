#include "GUI.h"






int ImGui::ImGuiKey_ToWinAPI(const ImGuiKey& key)
{
	switch (key)
	{
		case ImGuiKey_Tab: return VK_TAB;
		case ImGuiKey_LeftArrow: return VK_LEFT;
		case ImGuiKey_RightArrow: return VK_RIGHT;
		case ImGuiKey_UpArrow: return VK_UP;
		case ImGuiKey_DownArrow: return VK_DOWN;
		case ImGuiKey_PageUp: return VK_PRIOR;
		case ImGuiKey_PageDown: return VK_NEXT;
		case ImGuiKey_Home: return VK_HOME;
		case ImGuiKey_End: return VK_END;
		case ImGuiKey_Insert: return VK_INSERT;
		case ImGuiKey_Delete: return VK_DELETE;
		case ImGuiKey_Backspace: return VK_BACK;
		case ImGuiKey_Space: return VK_SPACE;
		case ImGuiKey_Enter: return VK_RETURN;
		case ImGuiKey_Escape: return VK_ESCAPE;
		case ImGuiKey_A: return 'A';
		case ImGuiKey_B: return 'B';
		case ImGuiKey_C: return 'C';
		case ImGuiKey_D: return 'D';
		case ImGuiKey_E: return 'E';
		case ImGuiKey_F: return 'F';
		case ImGuiKey_G: return 'G';
		case ImGuiKey_H: return 'H';
		case ImGuiKey_I: return 'I';
		case ImGuiKey_J: return 'J';
		case ImGuiKey_K: return 'K';
		case ImGuiKey_L: return 'L';
		case ImGuiKey_M: return 'M';
		case ImGuiKey_N: return 'N';
		case ImGuiKey_O: return 'O';
		case ImGuiKey_P: return 'P';
		case ImGuiKey_Q: return 'Q';
		case ImGuiKey_R: return 'R';
		case ImGuiKey_S: return 'S';
		case ImGuiKey_T: return 'T';
		case ImGuiKey_U: return 'U';
		case ImGuiKey_V: return 'V';
		case ImGuiKey_W: return 'W';
		case ImGuiKey_X: return 'X';
		case ImGuiKey_Y: return 'Y';
		case ImGuiKey_Z: return 'Z';
		case ImGuiKey_0: return '0';
		case ImGuiKey_1: return '1';
		case ImGuiKey_2: return '2';
		case ImGuiKey_3: return '3';
		case ImGuiKey_4: return '4';
		case ImGuiKey_5: return '5';
		case ImGuiKey_6: return '6';
		case ImGuiKey_7: return '7';
		case ImGuiKey_8: return '8';
		case ImGuiKey_9: return '9';

		case ImGuiKey_Keypad0: return VK_NUMPAD0;
		case ImGuiKey_Keypad1: return VK_NUMPAD1;
		case ImGuiKey_Keypad2: return VK_NUMPAD2;
		case ImGuiKey_Keypad3: return VK_NUMPAD3;
		case ImGuiKey_Keypad4: return VK_NUMPAD4;
		case ImGuiKey_Keypad5: return VK_NUMPAD5;
		case ImGuiKey_Keypad6: return VK_NUMPAD6;
		case ImGuiKey_Keypad7: return VK_NUMPAD7;
		case ImGuiKey_Keypad8: return VK_NUMPAD8;
		case ImGuiKey_Keypad9: return VK_NUMPAD9;
		case ImGuiKey_KeypadMultiply: return VK_MULTIPLY;
		case ImGuiKey_KeypadAdd: return VK_ADD;
		case ImGuiKey_KeypadSubtract: return VK_SUBTRACT;
		case ImGuiKey_KeypadDecimal: return VK_DECIMAL;
		case ImGuiKey_KeypadDivide: return VK_DIVIDE;

		case ImGuiKey_F1: return VK_F1;
		case ImGuiKey_F2: return VK_F2;
		case ImGuiKey_F3: return VK_F3;
		case ImGuiKey_F4: return VK_F4;
		case ImGuiKey_F5: return VK_F5;
		case ImGuiKey_F6: return VK_F6;
		case ImGuiKey_F7: return VK_F7;
		case ImGuiKey_F8: return VK_F8;
		case ImGuiKey_F9: return VK_F9;
		case ImGuiKey_F10: return VK_F10;
		case ImGuiKey_F11: return VK_F11;
		case ImGuiKey_F12: return VK_F12;

		case ImGuiKey_LeftCtrl: return VK_LCONTROL;
		case ImGuiKey_RightCtrl: return VK_RCONTROL;
		case ImGuiKey_LeftShift: return VK_LSHIFT;
		case ImGuiKey_RightShift: return VK_RSHIFT;
		case ImGuiKey_LeftAlt: return VK_LMENU;
		case ImGuiKey_RightAlt: return VK_RMENU;
		case ImGuiKey_LeftSuper: return VK_LWIN;
		case ImGuiKey_RightSuper: return VK_RWIN;

		default: return 0;
	}
}




bool ImGui::KeyBindingInput(const char* label, S_KeyBinding* binding)
{
	if (!binding)
		return false;

	bool hasChanged = false;

	const char* elementId = strstr(label, "##");
	if (elementId)
		TextUnformatted(label, elementId);
	else
		TextUnformatted(label);

	SameLine();

	if (binding->isDetermined)
	{
		const char* inputName = binding->key == ImGuiKey_None ? "Unbound" : GetKeyName(binding->key);
		std::string buttonName = std::string(inputName) + "##" + label;

		if (Button(buttonName.c_str()))
			binding->isDetermined = false;
	}
	else
	{
		Button("Press any key...");
		for (int keyCode = ImGuiKey_NamedKey_BEGIN; keyCode < ImGuiKey_NamedKey_END; keyCode++)
		{
			if (IsKeyPressed((ImGuiKey)keyCode))
			{
				binding->key = (ImGuiKey)keyCode;
				binding->isDetermined = true;
				hasChanged = true;
				break;
			}
		}
	}

	return hasChanged;
}

bool ImGui::IsKeyBindingPressed(S_KeyBinding* binding, const bool& waitForRelease)
{
	if (!binding)
		return false;

	if (binding->isDetermined == false)
		return false;

	if (binding->isInUse)
		return false;

	if (binding->key == ImGuiKey_None)
		return false;

	int keyCode = ImGuiKey_ToWinAPI(binding->key);
	if (waitForRelease)
	{
		if (GetAsyncKeyState(keyCode) & 0x8000)
		{
			binding->isInUse = true;
			while (GetAsyncKeyState(keyCode) & 0x8000)
			{
				Sleep(1);
			}

			binding->isInUse = false;
			return true;
		}
	}
	else
		return (GetAsyncKeyState(keyCode) & 1);
	
	return false;
}

bool ImGui::IsKeyBindingDown(S_KeyBinding* binding)
{
	if (!binding)
		return false;

	if (binding->isDetermined == false)
		return false;

	if (binding->isInUse) // <-- !
		return true;

	if (binding->key == ImGuiKey_None)
		return false;

	int keyCode = ImGuiKey_ToWinAPI(binding->key);
	if (GetAsyncKeyState(keyCode) & 0x8000)
		return true;

	return false;
}

bool ImGui::IsKeyBindingReleased(S_KeyBinding* binding)
{
	if (!binding)
		return false;

	if (binding->isDetermined == false)
		return false;

	if (binding->isInUse)
		return false;

	if (binding->key == ImGuiKey_None)
		return false;

	int keyCode = ImGuiKey_ToWinAPI(binding->key);
	return (GetAsyncKeyState(keyCode) & 0x8000) == false;
}







void GUI::Create(const HMODULE& applicationModule)
{
	DirectWindow::SetApplicationModule(applicationModule);

	SharedWorkers::SetUserInterfaceThread(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DirectWindow::Construct, 0, 0, 0));
	SharedWorkers::SetFeaturesThread(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SharedWorkers::FeaturesWorker, 0, 0, 0));
}




void GUI::Draw()
{
	if (GetIsActive())
	{
		if (GetIsInWaitMode())
		{
			double waitModeTimeLeft = GetWaitModeEndTime() - ImGui::GetTime();
			if (waitModeTimeLeft < 0.0)
			{
				if (SharedData::debugInfo.isActive)
					SharedCalls::UpdateDebugInformation();

				SetIsInWaitMode(false);
			}


			ImGuiIO& io = ImGui::GetIO();
			ImDrawList* drawList = ImGui::GetBackgroundDrawList();

			ImVec2 screenSize = io.DisplaySize;

			drawList->AddRectFilled(ImVec2(0, 0), screenSize, IM_COL32(0, 0, 0, 128));

			std::string labelString = std::to_string(waitModeTimeLeft);
			const char* labelText = labelString.c_str();

			double labelFontSize = 48.0;
			ImGui::PushFont(ImGui::GetFont());

			ImVec2 labelSize = ImGui::CalcTextSize(labelText);
			ImVec2 labelPosition = ImVec2((screenSize.x - labelSize.x) * 0.5, (screenSize.y - labelSize.y) * 0.5);

			drawList->AddText(ImGui::GetFont(), labelFontSize, labelPosition, IM_COL32(255, 255, 255, 255), labelText);

			ImGui::PopFont();
			return;
		}


		if (ImGui::BeginMainMenuBar())
		{
			ImGui::Text("UETools GUI (v0.5) | ");
			if (ImGui::BeginMenu("Debug"))
			{
				if (SharedData::debugInfo.isActive)
				{
					ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0 / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
					if (SharedData::SharedData::debugInfo.autoUpdate)
					{
						ImGui::Text("Updates on every frame");
						SharedCalls::UpdateDebugInformation();
					}
					else
					{
						const double now = ImGui::GetTime();
						const double elapsed = now - SharedData::debugInfo.lastUpdateTime;
						if (elapsed < 60.0)
						{
							int seconds = (int)elapsed;
							ImGui::Text("Last Update: %d %s ago", seconds, (seconds == 1 ? "second" : "seconds"));
						}
						else if (elapsed < 3600.0)
						{
							int minutes = (int)(elapsed / 60.0);
							ImGui::Text("Last Update: %d %s ago", minutes, (minutes == 1 ? "minute" : "minutes"));
						}
						else if (elapsed < 86400.0)
						{
							int hours = (int)(elapsed / 3600.0);
							ImGui::Text("Last Update: %d %s ago", hours, (hours == 1 ? "hour" : "hours"));
						}
						else
						{
							int days = (int)(elapsed / 86400.0);
							ImGui::Text("Last Update: %d %s ago", days, (days == 1 ? "day" : "days"));
						}
					}
					

					ImGui::BeginDisabled(SharedData::debugInfo.autoUpdate);
					if (ImGui::Button("Update"))
					{
						SharedCalls::UpdateDebugInformation();
						PlayActionSound(true);
					}
					ImGui::EndDisabled();
					ImGui::SameLine();
					ImGui::Checkbox("Auto", &SharedData::debugInfo.autoUpdate);
					if (ImGui::Button("Stop"))
					{
						SharedData::debugInfo.isActive = false;
						PlayActionSound(true);
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::Text("Engine: %s", SharedData::debugInfo.engine.engineReference ? "Is Present" : "Doesn't Exist!");
					if (SharedData::debugInfo.engine.engineReference)
					{
						ImGui::Text("Engine Class: %s", SharedData::debugInfo.engine.engineClass.c_str());
						ImGui::Text("Engine Object: %s", SharedData::debugInfo.engine.engineObject.c_str());

						ImGui::NewLine();

						ImGui::Text("Fixed FrameRate Enabled: %s", SharedData::debugInfo.engine.fixedFrameRateEnabled ? "True" : "False");
						ImGui::SameLine();
						ImGui::Spacing();
						ImGui::SameLine();
						if (ImGui::Button(SharedData::debugInfo.engine.fixedFrameRateEnabled ? "Disable##FixedFrameRate" : "Enable##FixedFrameRate"))
						{
							if (SharedData::debugInfo.engine.engineReference)
							{
								SharedData::debugInfo.engine.engineReference->bUseFixedFrameRate = !SharedData::debugInfo.engine.fixedFrameRateEnabled;
								SharedCalls::UpdateDebugInformation();
								PlayActionSound(true);
							}
							else
								PlayActionSound(false);
						}
						ImGui::Text("Fixed FrameRate: %f", SharedData::debugInfo.engine.fixedFrameRate);

						ImGui::NewLine();

						ImGui::Text("Smooth FrameRate Enabled: %s", SharedData::debugInfo.engine.smoothFrameRateEnabled ? "True" : "False");
						ImGui::SameLine();
						ImGui::Spacing();
						ImGui::SameLine();
						if (ImGui::Button(SharedData::debugInfo.engine.smoothFrameRateEnabled ? "Disable##SmoothFrameRat" : "Enable##SmoothFrameRat"))
						{
							if (SharedData::debugInfo.engine.engineReference)
							{
								SharedData::debugInfo.engine.engineReference->bSmoothFrameRate = !SharedData::debugInfo.engine.smoothFrameRateEnabled;
								SharedCalls::UpdateDebugInformation();
								PlayActionSound(true);
							}
							else
								PlayActionSound(false);
						}
						ImGui::Text("Smooth FrameRate Lower Bound: %f", SharedData::debugInfo.engine.smoothFrameRateLowerBound);
						ImGui::Text("Smooth FrameRate Upper Bound: %f", SharedData::debugInfo.engine.smoothFrameRateUpperBound);

						ImGui::NewLine();

						ImGui::Text("Subtitles Enabled: %s", SharedData::debugInfo.engine.subtitlesEnabled ? "True" : "False");
						ImGui::SameLine();
						ImGui::Spacing();
						ImGui::SameLine();
						if (ImGui::Button(SharedData::debugInfo.engine.subtitlesEnabled ? "Disable##SubtitlesEnabled" : "Enable##SubtitlesEnabled"))
						{
							if (SharedData::debugInfo.engine.engineReference)
							{
								SharedData::debugInfo.engine.engineReference->bSubtitlesEnabled = !SharedData::debugInfo.engine.subtitlesEnabled;
								SharedCalls::UpdateDebugInformation();
								PlayActionSound(true);
							}
							else
								PlayActionSound(false);
						}
						ImGui::Text("Subtitles Forced Off: %s", SharedData::debugInfo.engine.subtitlesForcedOff ? "True" : "False");
						ImGui::SameLine();
						ImGui::Spacing();
						ImGui::SameLine();
						if (ImGui::Button(SharedData::debugInfo.engine.subtitlesForcedOff ? "Disable##SubtitlesForcedOff" : "Enable##SubtitlesForcedOff"))
						{
							if (SharedData::debugInfo.engine.engineReference)
							{
								SharedData::debugInfo.engine.engineReference->bSubtitlesForcedOff = !SharedData::debugInfo.engine.subtitlesForcedOff;
								SharedCalls::UpdateDebugInformation();
								PlayActionSound(true);
							}
							else
								PlayActionSound(false);
						}

						ImGui::NewLine();

						ImGui::Text("Pause On Lost Focus: %s", SharedData::debugInfo.engine.pauseOnLossOfFocus ? "True" : "False");
						ImGui::SameLine();
						ImGui::Spacing();
						ImGui::SameLine();
						if (ImGui::Button(SharedData::debugInfo.engine.pauseOnLossOfFocus ? "Disable##PauseOnLostFocus" : "Enable##SmoothFrameRat##PauseOnLostFocus"))
						{
							if (SharedData::debugInfo.engine.engineReference)
							{
								SharedData::debugInfo.engine.engineReference->bPauseOnLossOfFocus = !SharedData::debugInfo.engine.pauseOnLossOfFocus;
								SharedCalls::UpdateDebugInformation();
								PlayActionSound(true);
							}
							else
								PlayActionSound(false);
						}
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::Text("Game Instance: %s", SharedData::debugInfo.isGameInstancePresent ? "Is Present" : "Doesn't Exist!");
					if (SharedData::debugInfo.isGameInstancePresent)
					{
						ImGui::Text("Game Instance Class: %s", SharedData::debugInfo.gameInstanceClass.c_str());
						ImGui::Text("Game Instance Object: %s", SharedData::debugInfo.gameInstanceObject.c_str());
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::Text("Game Mode: %s", SharedData::debugInfo.gameMode.gameModeReference ? "Is Present" : "Doesn't Exist!");
					if (SharedData::debugInfo.gameMode.gameModeReference)
					{
						ImGui::Text("Game Mode Class: %s", SharedData::debugInfo.gameMode.gameModeClass.c_str());
						ImGui::Text("Game Mode Object: %s", SharedData::debugInfo.gameMode.gameModeObject.c_str());

						ImGui::NewLine();

						ImGui::Text("Game Session: %s", SharedData::debugInfo.gameMode.gameSession.gameSessionReference ? "Is Present" : "Doesn't Exist!");
						if (SharedData::debugInfo.gameMode.gameSession.gameSessionReference)
						{
							if (ImGui::TreeNode("Game Session"))
							{
								ImGui::Text("Game Session Class: %s", SharedData::debugInfo.gameMode.gameSession.gameSessionClass.c_str());
								ImGui::Text("Game Session Object: %s", SharedData::debugInfo.gameMode.gameSession.gameSessionObject.c_str());

								ImGui::NewLine();

								ImGui::Text("Max Players: %d", SharedData::debugInfo.gameMode.gameSession.maxPlayers);
								ImGui::Text("Max Spectators: %d", SharedData::debugInfo.gameMode.gameSession.maxSpectators);
								ImGui::Text("Max Party Size: %d", SharedData::debugInfo.gameMode.gameSession.maxPartySize);
								ImGui::Text("Max Splitscreens Per Connection: %d", SharedData::debugInfo.gameMode.gameSession.maxSplitScreensPerConnection);

								ImGui::NewLine();

								ImGui::Text("Session Name: %s", SharedData::debugInfo.gameMode.gameSession.sessionName);

								ImGui::TreePop();
							}
						}

						ImGui::NewLine();

						ImGui::Text("Players Count: %d", SharedData::debugInfo.gameMode.playersCount);
						ImGui::Text("Spectators Count: %d", SharedData::debugInfo.gameMode.spectatorsCount);

						ImGui::NewLine();

						ImGui::Text("Start Players As Spectator: %s", SharedData::debugInfo.gameMode.startPlayersAsSpectators ? "True" : "False");
						ImGui::Text("Default Player Name: %s", SharedData::debugInfo.gameMode.defaultPlayerName);

						ImGui::NewLine();

						ImGui::Text("Use Seamless Travel: %s", SharedData::debugInfo.gameMode.useSeamlessTravel ? "True" : "False");

						ImGui::NewLine();

						ImGui::Text("Options: %s", SharedData::debugInfo.gameMode.options);
						ImGui::Text("Is Pausable: %s", SharedData::debugInfo.gameMode.isPausable ? "True" : "False");
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::Text("Game State: %s", SharedData::debugInfo.isGameStatePresent ? "Is Present" : "Doesn't Exist!");
					if (SharedData::debugInfo.isGameStatePresent)
					{
						ImGui::Text("Game State Class: %s", SharedData::debugInfo.gameStateClass.c_str());
						ImGui::Text("Game State Object: %s", SharedData::debugInfo.gameStateObject.c_str());
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::Text("Console: %s", SharedData::debugInfo.isConsolePresent ? "Is Present" : "Doesn't Exist!");
					if (SharedData::debugInfo.isConsolePresent)
					{
						ImGui::Text("Console Class: %s", SharedData::debugInfo.consoleClass.c_str());
						ImGui::Text("Console Object: %s", SharedData::debugInfo.consoleObject.c_str());
					}
					else
					{
						if (ImGui::Button("Construct Console"))
						{
							bool wasConsoleConstructed = Console::ConstructConsole();
							if (wasConsoleConstructed)
								SharedCalls::UpdateDebugInformation();

							PlayActionSound(wasConsoleConstructed);
							Input::CreateConsoleBindings();
						}
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::Text("Cheat Manager: %s", SharedData::debugInfo.isCheatManagerPresent ? "Is Present" : "Doesn't Exist!");
					if (SharedData::debugInfo.isCheatManagerPresent)
					{
						ImGui::Text("Cheat Manager Class: %s", SharedData::debugInfo.cheatManagerClass.c_str());
						ImGui::Text("Cheat Manager Object: %s", SharedData::debugInfo.cheatManagerObject.c_str());
					}
					else
					{
						if (ImGui::Button("Construct Cheat Manager"))
						{
							bool wasCheatManagerConstructed = CheatManager::ConstructCheatManager();
							if (wasCheatManagerConstructed)
								SharedCalls::UpdateDebugInformation();

							PlayActionSound(wasCheatManagerConstructed);
						}
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();
					
					ImGui::Text("Controller: %s", SharedData::debugInfo.isControllerPresent ? "Is Present" : "Doesn't Exist!");
					if (SharedData::debugInfo.isControllerPresent)
					{
						ImGui::Text("Controller Class: %s", SharedData::debugInfo.controllerClass.c_str());
						ImGui::Text("Controller Object: %s", SharedData::debugInfo.controllerObject.c_str());
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();
					
					ImGui::Text("Pawn: %s", SharedData::debugInfo.isPawnPresent ? "Is Present" : "Doesn't Exist!");
					if (SharedData::debugInfo.isPawnPresent)
					{
						ImGui::Text("Pawn Class: %s", SharedData::debugInfo.pawnClass.c_str());
						ImGui::Text("Pawn Object: %s", SharedData::debugInfo.pawnObject.c_str());
						ImGui::Text("Location: %s", SharedData::debugInfo.pawnLocation.c_str());
						ImGui::Text("Rotation: %s", SharedData::debugInfo.pawnRotation.c_str());
						ImGui::Text("Scale: %s", SharedData::debugInfo.pawnScale.c_str());

						ImGui::NewLine();

						ImGui::Text("Is Controlled: %s", SharedData::debugInfo.isPawnControlled ? "True" : "False");
						ImGui::Text("Is Pawn Controlled: %s", SharedData::debugInfo.isPawnPawnControlled ? "True" : "False");
						ImGui::Text("Is Player Controlled: %s", SharedData::debugInfo.isPawnPlayerControlled ? "True" : "False");
						ImGui::Text("Is Locally Controlled: %s", SharedData::debugInfo.isPawnLocallyControlled ? "True" : "False");
						ImGui::Text("Is Bot Controlled: %s", SharedData::debugInfo.isPawnBotControlled ? "True" : "False");
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::Text("Camera Manager: %s", SharedData::debugInfo.isCameraManagerPresent ? "Is Present" : "Doesn't Exist!");
					if (SharedData::debugInfo.isCameraManagerPresent)
					{
						ImGui::Text("Camera Manager Class: %s", SharedData::debugInfo.cameraManagerClass.c_str());
						ImGui::Text("Camera Manager Object: %s", SharedData::debugInfo.cameraManagerObject.c_str());
						ImGui::Text("Location: %s", SharedData::debugInfo.cameraManagerLocation.c_str());
						ImGui::Text("Rotation: %s", SharedData::debugInfo.cameraManagerRotation.c_str());
						ImGui::Text("Scale: %s", SharedData::debugInfo.cameraManagerScale.c_str());
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::Text("Viewport Client: %s", SharedData::debugInfo.isViewportClientPresent ? "Is Present" : "Doesn't Exist!");
					if (SharedData::debugInfo.isViewportClientPresent)
					{
						ImGui::Text("Viewport Client Class: %s", SharedData::debugInfo.viewportClientClass.c_str());
						ImGui::Text("Viewport Client Object: %s", SharedData::debugInfo.viewportClientObject.c_str());
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::Text("World: %s", SharedData::debugInfo.isWorldPresent ? "Is Present" : "Doesn't Exist!");
					if (SharedData::debugInfo.isWorldPresent)
					{
						ImGui::Text("World Class: %s", SharedData::debugInfo.worldClass.c_str());
						ImGui::Text("World Object: %s", SharedData::debugInfo.worldObject.c_str());
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::Text("Persistent Level: %s", SharedData::debugInfo.persistentLevel.levelReference ? "Is Present" : "Doesn't Exist!");
					if (SharedData::debugInfo.persistentLevel.levelReference)
					{
						ImGui::Text("Persistent Level Class: %s", SharedData::debugInfo.persistentLevel.levelClass.c_str());
						ImGui::Text("Persistent Level Object: %s", SharedData::debugInfo.persistentLevel.levelObject.c_str());
						ImGui::Text("Persistent Level Name: %s", SharedData::debugInfo.persistentLevel.levelName.c_str());
						ImGui::Text("Is Visible: %s", SharedData::debugInfo.persistentLevel.isLevelVisible ? "True" : "False");

						ImGui::NewLine();

						bool worldSettingsPresent = SharedData::debugInfo.persistentLevel.worldSettings.worldSettingsReference;
						ImGui::Text("World Settings: %s", worldSettingsPresent ? "Is Present" : "Doesn't Exist!");
						if (worldSettingsPresent)
						{
							if (ImGui::TreeNode("World Settings"))
							{
								ImGui::Text("World Settings Class: %s", SharedData::debugInfo.persistentLevel.worldSettings.worldSettingsClass.c_str());
								ImGui::Text("World Settings Object: %s", SharedData::debugInfo.persistentLevel.worldSettings.worldSettingsObject.c_str());

								ImGui::NewLine();

								ImGui::Text("High Priority Loading: %s", SharedData::debugInfo.persistentLevel.worldSettings.worldHighPriorityLoading ? "True" : "False");
								ImGui::Text("Local High Priority Loading: %s", SharedData::debugInfo.persistentLevel.worldSettings.worldLocalHighPriorityLoading ? "True" : "False");

								ImGui::NewLine();

								ImGui::Text("Unreal Units = 1m: %f", SharedData::debugInfo.persistentLevel.worldSettings.worldToMeters);

								ImGui::TreePop();
							}
						}

						ImGui::NewLine();

						ImGui::Text("Streaming Levels: %s", SharedData::debugInfo.areStreamingLevelsPresent ? "Are Present" : "Are Non Existent!");
						if (SharedData::debugInfo.areStreamingLevelsPresent)
						{
							if (ImGui::CollapsingHeader("Streaming Levels"))
							{
								for (SharedData::S_StreamingLevel streamingLevel : SharedData::debugInfo.streamingLevels)
								{
									ImU32 levelColor = IM_COL32(
										static_cast<int>(streamingLevel.streamingLevelColor.R * 255.0),
										static_cast<int>(streamingLevel.streamingLevelColor.G * 255.0),
										static_cast<int>(streamingLevel.streamingLevelColor.B * 255.0),
										static_cast<int>(streamingLevel.streamingLevelColor.A * 255.0)
									);

									ImGui::PushStyleColor(ImGuiCol_Text, levelColor);
									bool isTreeNodeOpen = ImGui::TreeNode(streamingLevel.streamingLevelPath.c_str());
									ImGui::PopStyleColor();

									if (isTreeNodeOpen)
									{
										bool isLevelLoaded = streamingLevel.level.levelReference;

										ImGui::Text("Is Loaded: %s", isLevelLoaded ? "True" : "False");
										ImGui::SameLine();
										ImGui::Spacing();
										ImGui::SameLine();
										if (ImGui::Button(isLevelLoaded ? "Unload" : "Load"))
										{
											if (streamingLevel.streamingLevelReference != nullptr)
											{
												streamingLevel.streamingLevelReference->SetShouldBeLoaded(!isLevelLoaded);

												if (SharedData::SharedData::debugInfo.autoUpdate == false)
													StartWaitMode(3.25);

												PlayActionSound(true);
											}
											else
												PlayActionSound(false);
										}

										ImGui::Text("Is Visible: %s", streamingLevel.level.isLevelVisible ? "True" : "False");
										ImGui::SameLine();
										ImGui::Spacing();
										ImGui::SameLine();
										ImGui::BeginDisabled(isLevelLoaded == false);
										if (ImGui::Button(streamingLevel.level.isLevelVisible ? "Hide" : "Show"))
										{
											if (isLevelLoaded && streamingLevel.streamingLevelReference != nullptr)
											{
												streamingLevel.streamingLevelReference->SetShouldBeVisible(!streamingLevel.level.isLevelVisible);

												if (SharedData::SharedData::debugInfo.autoUpdate == false)
													StartWaitMode(3.25);

												PlayActionSound(true);
											}
											else
												PlayActionSound(false);
										}
										ImGui::EndDisabled();

										ImGui::NewLine();

										bool worldSettingsPresent = streamingLevel.level.worldSettings.worldSettingsReference;
										ImGui::Text("World Settings: %s", worldSettingsPresent ? "Is Present" : "Doesn't Exist!");
										if (worldSettingsPresent)
										{
											if (ImGui::TreeNode("World Settings"))
											{
												ImGui::Text("World Settings Class: %s", streamingLevel.level.worldSettings.worldSettingsClass.c_str());
												ImGui::Text("World Settings Object: %s", streamingLevel.level.worldSettings.worldSettingsObject.c_str());

												ImGui::NewLine();

												ImGui::Text("High Priority Loading: %s", streamingLevel.level.worldSettings.worldHighPriorityLoading ? "True" : "False");
												ImGui::Text("Local High Priority Loading: %s", streamingLevel.level.worldSettings.worldLocalHighPriorityLoading ? "True" : "False");

												ImGui::NewLine();

												ImGui::Text("Unreal Units = 1m: %f", streamingLevel.level.worldSettings.worldToMeters);

												ImGui::TreePop();
											}
										}

										ImGui::TreePop();
									}
								}
							}
						}
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					if (SharedData::debugInfo.gameTimeInSeconds > 0.0)
						ImGui::Text("Game Time (In Seconds): %f", SharedData::debugInfo.gameTimeInSeconds);

					ImGui::Text("Is Server: %s", SharedData::debugInfo.isServer ? "True" : "False");
					ImGui::Text("Is Dedicated Server: %s", SharedData::debugInfo.isDedicatedServer ? "True" : "False");
					ImGui::Text("Is Split Screen: %s", SharedData::debugInfo.isSplitScreen ? "True" : "False");
					ImGui::Text("Is Standalone: %s", SharedData::debugInfo.isStandalone ? "True" : "False");

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					if (SharedData::debugInfo.wasProjectNameObtained)
						ImGui::Text("Project Name: %s", SharedData::debugInfo.projectName.c_str());

					if (SharedData::debugInfo.wasProjectPlatformObtained)
						ImGui::Text("Project Platform: %s", SharedData::debugInfo.projectPlatform.c_str());

					if (SharedData::debugInfo.wasUsernameObtained)
						ImGui::Text("Username: %s", SharedData::debugInfo.username.c_str());

					if (SharedData::debugInfo.wasCommandLineObtained)
					{
						std::vector<char> commandLineBuffer;
						size_t commandLineLength = SharedData::debugInfo.commandLine.size();

						commandLineBuffer.resize(commandLineLength + 1);
						std::memcpy(commandLineBuffer.data(), SharedData::debugInfo.commandLine.data(), SharedData::debugInfo.commandLine.size());

						ImGui::Text("Command Line:");
						ImGui::SameLine();
						ImGui::InputText("##commandLine", commandLineBuffer.data(), commandLineBuffer.size(), ImGuiInputTextFlags_ReadOnly);
						ImGui::SameLine();
						if (ImGui::Button("Copy"))
						{
							WindowsUtilities::SetClipboard(SharedData::debugInfo.commandLine);
							PlayActionSound(true);
						}
					}
				}
				else
				{
					if (ImGui::Button("Start"))
					{
						if (SharedData::debugInfo.autoUpdate == false)
							SharedCalls::UpdateDebugInformation();

						SharedData::debugInfo.isActive = true;
						PlayActionSound(true);
					}
				}
				
				ImGui::EndMenu();
			}




			SDK::UWorld* world = SDK::UWorld::GetWorld();
			ImGui::BeginDisabled(world == nullptr);
			if (ImGui::BeginMenu("World"))
			{
				if (world)
				{
					if (SDK::ULevel* persistentLevel = world->PersistentLevel)
					{
						if (SDK::AWorldSettings* worldSettings = persistentLevel->WorldSettings)
						{
							bool globalGravitySet = worldSettings->bGlobalGravitySet == 1;
							ImGui::Checkbox("Global Gravity Set", &globalGravitySet);
							worldSettings->bGlobalGravitySet = globalGravitySet ? 1 : 0;

							ImGui::BeginDisabled(globalGravitySet == false);
							ImGui::InputFloat("Global Gravity", &worldSettings->GlobalGravityZ, 0.1, 1.0);
							ImGui::EndDisabled();

							bool worldGravitySet = worldSettings->bWorldGravitySet == 1;
							ImGui::Checkbox("World Gravity Set", &worldGravitySet);
							worldSettings->bWorldGravitySet = worldGravitySet ? 1 : 0;

							ImGui::BeginDisabled(worldGravitySet == false);
							ImGui::InputFloat("World Gravity", &worldSettings->WorldGravityZ, 0.1, 1.0);
							ImGui::EndDisabled();

							ImGui::NewLine();
							ImGui::Separator();
							ImGui::NewLine();

							ImGui::InputFloat("Minimum Time Dilation", &worldSettings->MinGlobalTimeDilation, 0.1, 1.0);
							ImGui::InputFloat("Maximum Time Dilation", &worldSettings->MaxGlobalTimeDilation, 0.1, 1.0);
							double timeDilation = worldSettings->TimeDilation;
							ImGui::InputDouble("Time Dilation", &timeDilation, 0.1, 1.0);
							worldSettings->TimeDilation = std::clamp(timeDilation, (double)worldSettings->MinGlobalTimeDilation, (double)worldSettings->MaxGlobalTimeDilation);

							ImGui::NewLine();

							ImGui::InputFloat("Demo Time Dilation", &worldSettings->DemoPlayTimeDilation, 0.1, 1.0);

							ImGui::NewLine();
							ImGui::Separator();
							ImGui::NewLine();

							bool enableAISystem = worldSettings->bEnableAISystem == 1;
							ImGui::Checkbox("Enable AI System", &enableAISystem);
							worldSettings->bEnableAISystem = enableAISystem ? 1 : 0;

							bool enableNavigationSystem = worldSettings->bEnableNavigationSystem == 1;
							ImGui::Checkbox("Enable Navigation System", &enableNavigationSystem);
							worldSettings->bEnableNavigationSystem = enableNavigationSystem ? 1 : 0;

							ImGui::NewLine();
							ImGui::Separator();
							ImGui::NewLine();

							ImGui::InputFloat("KillZ", &worldSettings->KillZ, 0.1, 1.0);
						}
						else
							ImGui::Text("World Settings Doesn't Exist!");
					}
					else
						ImGui::Text("Persistent Level Doesn't Exist!");
				}
				else
					ImGui::Text("World Doesn't Exist!");

				ImGui::EndMenu();
			}
			ImGui::EndDisabled();




			SDK::APlayerController* controller = Controller::GetController();
			SDK::ACharacter* character = controller ? controller->Character : nullptr;
			SDK::UCharacterMovementComponent* movementComponent = (character && character->CharacterMovement) ? character->CharacterMovement : nullptr;
			ImGui::BeginDisabled(controller == nullptr || character == nullptr || movementComponent == nullptr);
			if (ImGui::BeginMenu("Character"))
			{
				if (controller)
				{
					SharedData::objectsInfo.controller = controller;
					if (character)
					{
						SharedData::objectsInfo.character = character;
						if (movementComponent)
						{
							SharedData::objectsInfo.movementComponent = movementComponent;

							bool hasCollision = character->bActorEnableCollision;
							if (movementComponent->bCheatFlying)
								ImGui::Text("Character Is In %s Mode", hasCollision ? "Fly" : "Ghost");
							else
							{
								SDK::EMovementMode movementMode = movementComponent->MovementMode;
								switch (movementMode)
								{
									case SDK::EMovementMode::MOVE_Walking:
										ImGui::Text("Character Is Walking");
										break;

									case SDK::EMovementMode::MOVE_NavWalking:
										ImGui::Text("Character Is Nav Walking");
										break;

									case SDK::EMovementMode::MOVE_Falling:
										ImGui::Text("Character Is Falling");
										break;

									case SDK::EMovementMode::MOVE_Swimming:
										ImGui::Text("Character Is Swimming");
										break;

									case SDK::EMovementMode::MOVE_Flying:
										ImGui::Text("Character Is Flying");
										break;

									default:
										ImGui::Text("Character Is In %d Mode", movementMode);
										break;
								}
							}
							ImGui::Text("Custom Movement Mode: %d", movementComponent->CustomMovementMode);

							if (ImGui::Button("Ghost"))
							{
								SharedFunctions::Ghost();
							}
							ImGui::SameLine();
							ImGui::Spacing();
							ImGui::SameLine();
							ImGui::KeyBindingInput("Key:##Ghost", &SharedData::keybindingsInfo.ghost);

							if (ImGui::Button("Fly"))
							{
								SharedFunctions::Fly();
							}
							ImGui::SameLine();
							ImGui::Spacing();
							ImGui::SameLine();
							ImGui::KeyBindingInput("Key:##Fly", &SharedData::keybindingsInfo.fly);

							if (ImGui::Button("Walk"))
							{
								SharedFunctions::Walk();
							}
							ImGui::SameLine();
							ImGui::Spacing();
							ImGui::SameLine();
							ImGui::KeyBindingInput("Key:##Walk", &SharedData::keybindingsInfo.walk);

							ImGui::BeginDisabled(movementComponent->bCheatFlying == false);
							ImGui::Checkbox("Directional Movement", &SharedData::featuresInfo.isDirectionalMovementEnabled);
							ImGui::InputDouble("Directional Movement Step", &SharedData::featuresInfo.directionalMovementStep, 0.1, 1.0);
							ImGui::InputDouble("Directional Movement Delay", &SharedData::featuresInfo.directionalMovementDelay, 0.01, 0.1);
							ImGui::EndDisabled();

							ImGui::NewLine();
							ImGui::Separator();
							ImGui::NewLine();

							if (ImGui::Button("Jump"))
							{
								SharedFunctions::Jump();
							}
							ImGui::SameLine();
							ImGui::Spacing();
							ImGui::SameLine();
							ImGui::KeyBindingInput("Key:##Jump", &SharedData::keybindingsInfo.jump);
							ImGui::InputInt("Jump Limit", &character->JumpMaxCount, 1, 1);
							ImGui::InputFloat("Jump Height", &movementComponent->JumpZVelocity, 0.1, 1.0);

							ImGui::NewLine();
							ImGui::Separator();
							ImGui::NewLine();

							if (ImGui::Button("Launch"))
							{
								SharedFunctions::Launch();
							}
							ImGui::SameLine();
							ImGui::Spacing();
							ImGui::SameLine();
							ImGui::KeyBindingInput("Key:##Launch", &SharedData::keybindingsInfo.launch);
							ImGui::InputFloat3("Launch Velocity", SharedData::featuresInfo.launchVelocity);

							ImGui::NewLine();

							if (ImGui::Button("Dash"))
							{
								SharedFunctions::Dash();
							}
							ImGui::SameLine();
							ImGui::Spacing();
							ImGui::SameLine();
							ImGui::KeyBindingInput("Key:##Dash", &SharedData::keybindingsInfo.dash);
							ImGui::InputDouble("Dash Strength", &SharedData::featuresInfo.dashStrength, 0.1, 1.0);
						}
						else
							ImGui::Text("Movement Component Doesn't Exist!");
					}
					else
						ImGui::Text("Character Doesn't Exist!");
				}
				else
					ImGui::Text("Controller Doesn't Exist!");


				ImGui::EndMenu();
			}
			ImGui::EndDisabled();




			ImGui::EndMainMenuBar();
		}
	}
}




void GUI::PlaySound(const E_Sound& soundToPlay)
{
	uint16_t soundFrequency;
	uint16_t soundDuration;

	switch (soundToPlay)
	{
		case E_Sound::BUTTON_PRESS:
			soundFrequency = 245;
			soundDuration = 50;
			break;

		case E_Sound::BUTTON_CANCEL:
			soundFrequency = 100;
			soundDuration = 150;
			break;

		case E_Sound::ACTION_SUCCESS:
			soundFrequency = 350;
			soundDuration = 300;
			break;

		case E_Sound::ACTION_ERROR:
			soundFrequency = 175;
			soundDuration = 300;
			break;

		default:
			soundFrequency = 500;
			soundDuration = 1000;
			break;
	}

	Beep(soundFrequency, soundDuration);
}






void GUI::SharedWorkers::FeaturesWorker()
{
	while (GetFeaturesThread())
	{
		if (SharedData::featuresInfo.isDirectionalMovementEnabled)
		{
			if (SharedData::objectsInfo.controller && SharedData::objectsInfo.character && SharedData::objectsInfo.movementComponent
				&& SharedData::objectsInfo.movementComponent->bCheatFlying)
			{
				SDK::FVector characterVelocity = SharedData::objectsInfo.movementComponent->Velocity;
				if (characterVelocity.X != 0.0 || characterVelocity.Y != 0.0)
				{
					SDK::APlayerCameraManager* cameraManager = SharedData::objectsInfo.controller->PlayerCameraManager;
					if (cameraManager)
					{
						SDK::FVector characterVelocityNormalized = Math::Normalize(characterVelocity);
						SDK::FVector cameraForwardVector = cameraManager->GetActorForwardVector();
						double dotProduct = SDK::UKismetMathLibrary::Dot_VectorVector(characterVelocityNormalized, cameraForwardVector);

						if (dotProduct > 0.5)
						{
							SDK::FVector currentLocation = SharedData::objectsInfo.character->K2_GetActorLocation();
							SDK::FVector finalLocation = SDK::UKismetMathLibrary::Add_VectorVector(currentLocation, cameraForwardVector * SharedData::featuresInfo.directionalMovementStep);

							SharedData::objectsInfo.character->K2_TeleportTo(finalLocation, SharedData::objectsInfo.character->K2_GetActorRotation());
						}
					}
				}
			}
		}

		Sleep(Math::Seconds_ToMilliseconds(SharedData::featuresInfo.directionalMovementDelay));
	}
}






void GUI::SharedCalls::UpdateDebugInformation()
{
	SDK::UEngine* engine = Engine::GetEngine();
	if (SharedData::debugInfo.engine.engineReference = engine)
	{
		SharedData::debugInfo.engine.engineClass = engine->Class->GetFullName();
		SharedData::debugInfo.engine.engineObject = engine->GetFullName();

		SharedData::debugInfo.engine.fixedFrameRate = engine->bUseFixedFrameRate;
		SharedData::debugInfo.engine.fixedFrameRateEnabled = engine->FixedFrameRate;

		SharedData::debugInfo.engine.smoothFrameRateEnabled = engine->bSmoothFrameRate;
		SharedData::debugInfo.engine.smoothFrameRateLowerBound = engine->SmoothedFrameRateRange.LowerBound.Value;
		SharedData::debugInfo.engine.smoothFrameRateUpperBound = engine->SmoothedFrameRateRange.UpperBound.Value;

		SharedData::debugInfo.engine.subtitlesEnabled = engine->bSubtitlesEnabled;
		SharedData::debugInfo.engine.subtitlesForcedOff = engine->bSubtitlesForcedOff;

		SharedData::debugInfo.engine.pauseOnLossOfFocus = engine->bPauseOnLossOfFocus;
	}


	SDK::UGameInstance* gameInstance = GameInstance::GetGameInstance();
	if (SharedData::debugInfo.isGameInstancePresent = gameInstance)
	{
		SharedData::debugInfo.gameInstanceClass = gameInstance->Class->GetFullName();
		SharedData::debugInfo.gameInstanceObject = gameInstance->GetFullName();
	}


	SDK::AGameModeBase* gameMode = GameMode::GetGameMode();
	if (SharedData::debugInfo.gameMode.gameModeReference = gameMode)
	{
		SharedData::debugInfo.gameMode.gameModeClass = gameMode->Class->GetFullName();
		SharedData::debugInfo.gameMode.gameModeObject = gameMode->GetFullName();

		SDK::AGameSession* gameSession = gameMode->GameSession;
		if (SharedData::debugInfo.gameMode.gameSession.gameSessionReference = gameSession)
		{
			SharedData::debugInfo.gameMode.gameSession.gameSessionClass = gameSession->Class->GetFullName();
			SharedData::debugInfo.gameMode.gameSession.gameSessionObject = gameSession->GetFullName();

			SharedData::debugInfo.gameMode.gameSession.maxPlayers = gameSession->MaxPlayers;
			SharedData::debugInfo.gameMode.gameSession.maxSpectators = gameSession->MaxSpectators;
			SharedData::debugInfo.gameMode.gameSession.maxPartySize = gameSession->MaxPartySize;
			SharedData::debugInfo.gameMode.gameSession.maxSplitScreensPerConnection = gameSession->MaxSplitscreensPerConnection;

			SharedData::debugInfo.gameMode.gameSession.sessionName = gameSession->SessionName.ToString();
		}

		SharedData::debugInfo.gameMode.playersCount = gameMode->GetNumPlayers();
		SharedData::debugInfo.gameMode.spectatorsCount = gameMode->GetNumSpectators();

		SharedData::debugInfo.gameMode.startPlayersAsSpectators = gameMode->bStartPlayersAsSpectators;
		SharedData::debugInfo.gameMode.defaultPlayerName = gameMode->DefaultPlayerName.ToString();

		SharedData::debugInfo.gameMode.useSeamlessTravel = gameMode->bUseSeamlessTravel;
		SharedData::debugInfo.gameMode.options = gameMode->OptionsString.ToString();
		
		SharedData::debugInfo.gameMode.isPausable = gameMode->bPauseable;
	}


	SDK::AGameStateBase* gameState = GameState::GetGameState();
	if (SharedData::debugInfo.isGameStatePresent = gameState)
	{
		SharedData::debugInfo.gameStateClass = gameState->Class->GetFullName();
		SharedData::debugInfo.gameStateObject = gameState->GetFullName();
	}


	SDK::UConsole* console = Console::GetConsole();
	if (SharedData::debugInfo.isConsolePresent = console)
	{
		SharedData::debugInfo.consoleClass = console->Class->GetFullName();
		SharedData::debugInfo.consoleObject = console->GetFullName();
	}


	SDK::UCheatManager* cheatManager = CheatManager::GetCheatManager();
	if (SharedData::debugInfo.isCheatManagerPresent = cheatManager)
	{
		SharedData::debugInfo.cheatManagerClass = cheatManager->Class->GetFullName();
		SharedData::debugInfo.cheatManagerObject = cheatManager->GetFullName();
	}


	SDK::APlayerController* controller = Controller::GetController();
	if (SharedData::debugInfo.isControllerPresent = controller)
	{
		SharedData::debugInfo.controllerClass = controller->Class->GetFullName();
		SharedData::debugInfo.controllerObject = controller->GetFullName();


		SDK::UPlayer* player = controller->Player;
		if (SharedData::debugInfo.isPlayerPresent = player)
		{
			SharedData::debugInfo.playerClass = player->Class->GetFullName();
			SharedData::debugInfo.playerObject = player->GetFullName();
		}


		SDK::APawn* pawn = controller->AcknowledgedPawn;
		if (SharedData::debugInfo.isPawnPresent = pawn)
		{
			SharedData::debugInfo.pawnClass = pawn->Class->GetFullName();
			SharedData::debugInfo.pawnObject = pawn->GetFullName();

			SDK::FTransform pawnTransform = pawn->GetTransform();
			SharedData::debugInfo.pawnLocation = SDK::UKismetStringLibrary::Conv_VectorToString(pawnTransform.Translation).ToString();
			SharedData::debugInfo.pawnRotation = SDK::UKismetStringLibrary::Conv_RotatorToString(SDK::FRotator(pawnTransform.Rotation.X, pawnTransform.Rotation.Y, pawnTransform.Rotation.Z)).ToString();
			SharedData::debugInfo.pawnScale = SDK::UKismetStringLibrary::Conv_VectorToString(pawnTransform.Scale3D).ToString();

			SharedData::debugInfo.isPawnControlled = pawn->IsControlled();
			SharedData::debugInfo.isPawnPawnControlled = pawn->IsPawnControlled();
			SharedData::debugInfo.isPawnPlayerControlled = pawn->IsPlayerControlled();
			SharedData::debugInfo.isPawnLocallyControlled = pawn->IsLocallyControlled();
			SharedData::debugInfo.isPawnBotControlled = pawn->IsBotControlled();
		}


		SDK::APlayerCameraManager* cameraManager = controller->PlayerCameraManager;
		if (SharedData::debugInfo.isCameraManagerPresent = cameraManager)
		{
			SharedData::debugInfo.cameraManagerClass = cameraManager->Class->GetFullName();
			SharedData::debugInfo.cameraManagerObject = cameraManager->GetFullName();

			SDK::FTransform cameraManagerTransform = cameraManager->GetTransform();
			SharedData::debugInfo.cameraManagerLocation = SDK::UKismetStringLibrary::Conv_VectorToString(cameraManagerTransform.Translation).ToString();
			SharedData::debugInfo.cameraManagerRotation = SDK::UKismetStringLibrary::Conv_RotatorToString(SDK::FRotator(cameraManagerTransform.Rotation.X, cameraManagerTransform.Rotation.Y, cameraManagerTransform.Rotation.Z)).ToString();
			SharedData::debugInfo.cameraManagerScale = SDK::UKismetStringLibrary::Conv_VectorToString(cameraManagerTransform.Scale3D).ToString();
		}
	}


	SDK::UGameViewportClient* viewportClient = Engine::GetGameViewport();
	if (SharedData::debugInfo.isViewportClientPresent = viewportClient)
	{
		SharedData::debugInfo.viewportClientClass = viewportClient->Class->GetFullName();
		SharedData::debugInfo.viewportClientObject = viewportClient->GetFullName();
	}


	SDK::UWorld* world = SDK::UWorld::GetWorld();
	if (SharedData::debugInfo.isWorldPresent = world)
	{
		SharedData::debugInfo.worldClass = world->Class->GetFullName();
		SharedData::debugInfo.worldObject = world->GetFullName();

		if (SDK::ULevel* persistentLevel = world->PersistentLevel)
		{
			SharedData::debugInfo.persistentLevel.levelReference = persistentLevel;

			SharedData::debugInfo.persistentLevel.levelClass = persistentLevel->Class->GetFullName();
			SharedData::debugInfo.persistentLevel.levelObject = persistentLevel->GetFullName();
			SharedData::debugInfo.persistentLevel.levelName = SDK::UGameplayStatics::GetCurrentLevelName(world, false).ToString();

			SharedData::debugInfo.persistentLevel.isLevelVisible = persistentLevel->bIsVisible;

			if (SDK::AWorldSettings* worldSettings = persistentLevel->WorldSettings)
			{
				SharedData::debugInfo.persistentLevel.worldSettings.worldSettingsReference = worldSettings;
				SharedData::debugInfo.persistentLevel.worldSettings.worldSettingsClass = worldSettings->Class->GetFullName();
				SharedData::debugInfo.persistentLevel.worldSettings.worldSettingsObject = worldSettings->GetFullName();

				SharedData::debugInfo.persistentLevel.worldSettings.worldHighPriorityLoading = worldSettings->bHighPriorityLoading;
				SharedData::debugInfo.persistentLevel.worldSettings.worldLocalHighPriorityLoading = worldSettings->bHighPriorityLoadingLocal;

				SharedData::debugInfo.persistentLevel.worldSettings.worldToMeters = worldSettings->WorldToMeters;
			}
		}

		SDK::TArray<SDK::ULevelStreaming*> streamingLevels = world->StreamingLevels;
		if (SharedData::debugInfo.areStreamingLevelsPresent = streamingLevels.Num() > 0)
		{
			SharedData::debugInfo.streamingLevels.clear();

			for (SDK::ULevelStreaming* level : streamingLevels)
			{
				if (level == nullptr)
					continue;

#ifdef UE5
				std::string streamingLevelPath = level->WorldAsset.ObjectID.AssetPath.AssetName.GetRawString();
#else
				std::string streamingLevelPath = level->WorldAsset.ObjectID.AssetPathName.GetRawString();
#endif
				if (streamingLevelPath.empty())
					continue;

				SharedData::S_StreamingLevel streamingLevel = {};
				streamingLevel.streamingLevelReference = level;
				streamingLevel.streamingLevelPath = streamingLevelPath;
				streamingLevel.streamingLevelColor = level->LevelColor;

				SDK::ULevel* loadedLevel = level->LoadedLevel;
				if (streamingLevel.level.levelReference = loadedLevel)
				{
					streamingLevel.level.levelClass = level->Class->GetFullName();
					streamingLevel.level.levelObject = level->GetFullName();
					streamingLevel.level.levelName = SDK::UGameplayStatics::GetCurrentLevelName(world, false).ToString();

					streamingLevel.level.isLevelVisible = loadedLevel->bIsVisible;
					
					SDK::AWorldSettings* worldSettings = loadedLevel->WorldSettings;
					if (streamingLevel.level.worldSettings.worldSettingsReference = worldSettings)
					{
						streamingLevel.level.worldSettings.worldSettingsClass = worldSettings->Class->GetFullName();
						streamingLevel.level.worldSettings.worldSettingsObject = worldSettings->GetFullName();

						streamingLevel.level.worldSettings.worldHighPriorityLoading = worldSettings->bHighPriorityLoading;
						streamingLevel.level.worldSettings.worldLocalHighPriorityLoading = worldSettings->bHighPriorityLoadingLocal;

						streamingLevel.level.worldSettings.worldToMeters = worldSettings->WorldToMeters;
					}
				}

				SharedData::debugInfo.streamingLevels.push_back(streamingLevel);
			}
		}

		SharedData::debugInfo.gameTimeInSeconds = SDK::UKismetSystemLibrary::GetGameTimeInSeconds(world);

		SharedData::debugInfo.isServer = SDK::UKismetSystemLibrary::IsServer(world);
		SharedData::debugInfo.isDedicatedServer = SDK::UKismetSystemLibrary::IsDedicatedServer(world);
		SharedData::debugInfo.isSplitScreen = SDK::UKismetSystemLibrary::IsSplitScreen(world);
		SharedData::debugInfo.isStandalone = SDK::UKismetSystemLibrary::IsStandalone(world);
	}


	if (SharedData::debugInfo.wasProjectNameObtained == false)
	{
		std::string projectName = SDK::UKismetSystemLibrary::GetGameName().ToString();
		if (projectName.empty() == false)
		{
			SharedData::debugInfo.projectName = projectName;
			SharedData::debugInfo.wasProjectNameObtained = true;
		}
	}


	if (SharedData::debugInfo.wasProjectPlatformObtained == false)
	{
		std::string projectPlatform = SDK::UGameplayStatics::GetPlatformName().ToString();
		if (projectPlatform.empty() == false)
		{
			SharedData::debugInfo.projectPlatform = projectPlatform;
			SharedData::debugInfo.wasProjectPlatformObtained = true;
		}
	}


	if (SharedData::debugInfo.wasProjectEngineVersionObtained == false)
	{
		std::string engineVersion = SDK::UKismetSystemLibrary::GetEngineVersion().ToString();
		if (engineVersion.empty() == false)
		{
			SharedData::debugInfo.projectEngineVersion = engineVersion;
			SharedData::debugInfo.wasProjectEngineVersionObtained = true;
		}
	}


	if (SharedData::debugInfo.wasUsernameObtained == false)
	{
		std::string username = SDK::UKismetSystemLibrary::GetPlatformUserName().ToString();
		if (username.empty() == false)
		{
			SharedData::debugInfo.username = username;
			SharedData::debugInfo.wasUsernameObtained = true;
		}
	}


	if (SharedData::debugInfo.wasCommandLineObtained == false)
	{
		LPWSTR lCommandLine = GetCommandLineW();
		std::wstring wCommandLine = std::wstring(lCommandLine);
		std::string commandLine = std::string(wCommandLine.begin(), wCommandLine.end());

		SharedData::debugInfo.commandLine = commandLine;
		SharedData::debugInfo.wasCommandLineObtained = true;
	}


	SharedData::debugInfo.lastUpdateTime = ImGui::GetTime();
}




void GUI::SharedCalls::ProcessKeybindings()
{
	if (ImGui::IsKeyBindingPressed(&SharedData::keybindingsInfo.menuOpenClose))
	{
		ToggleIsActive();
	}

	if (GetIsActive() == false)
	{
		if (ImGui::IsKeyBindingPressed(&SharedData::keybindingsInfo.ghost))
		{
			SharedFunctions::Ghost();
		}

		if (ImGui::IsKeyBindingPressed(&SharedData::keybindingsInfo.fly))
		{
			SharedFunctions::Fly();
		}

		if (ImGui::IsKeyBindingPressed(&SharedData::keybindingsInfo.walk))
		{
			SharedFunctions::Walk();
		}




		if (ImGui::IsKeyBindingPressed(&SharedData::keybindingsInfo.jump))
		{
			SharedFunctions::Jump();
		}




		if (ImGui::IsKeyBindingPressed(&SharedData::keybindingsInfo.launch))
		{
			SharedFunctions::Launch();
		}

		if (ImGui::IsKeyBindingPressed(&SharedData::keybindingsInfo.dash))
		{
			SharedFunctions::Dash();
		}
	}
}






void GUI::SharedFunctions::Ghost()
{
	GUI::PlayActionSound(Character::Ghost());
}

void GUI::SharedFunctions::Fly()
{
	GUI::PlayActionSound(Character::Fly());
}

void GUI::SharedFunctions::Walk()
{
	GUI::PlayActionSound(Character::Walk());
}




void GUI::SharedFunctions::Jump()
{
	GUI::PlayActionSound(Character::Jump());
}




void GUI::SharedFunctions::Launch()
{
	GUI::PlayActionSound(Character::Launch({ SharedData::featuresInfo.launchVelocity[0], SharedData::featuresInfo.launchVelocity[1], SharedData::featuresInfo.launchVelocity[2] }));
}

void GUI::SharedFunctions::Dash()
{
	SDK::FVector forwardVector = SharedData::objectsInfo.character->GetActorForwardVector();

	forwardVector.Z = 0.0;
	forwardVector.Normalize();

	PlayActionSound(Character::Launch(forwardVector * SharedData::featuresInfo.dashStrength));
}
