#include "GUI.h"






// ========================================================
// |             #IMGUI #CONTROLS #KEYBINDINGS            |
// ========================================================
void ImGui::TextBool(const char* label, const bool& inBool, const char* text_true, const char* text_false, const bool& useColoring, const ImU32& color_true, const ImU32& color_false)
{
	if (label)
	{
		const char* idPosition = std::strstr(label, "##");
		if (idPosition)
			ImGui::TextUnformatted(label, idPosition);
		else
			ImGui::TextUnformatted(label);

		ImGui::SameLine();
	}

	if (useColoring)
	{
		ImGui::PushStyleColor(ImGuiCol_Text, inBool ? color_true : color_false);
		ImGui::TextUnformatted(inBool
									? (text_true ? text_true : "BOOL_TRUE")
									: (text_false ? text_false : "BOOL_FALSE"));
		ImGui::PopStyleColor();
	}
	else
		ImGui::TextUnformatted(inBool
									? (text_true ? text_true : "BOOL_TRUE")
									: (text_false ? text_false : "BOOL_FALSE"));
	
}

void ImGui::TextBool(const char* label, const bool& inBool)
{
	TextBool(label, inBool, "True", "False", false, ImU32(), ImU32());
}

void ImGui::TextBoolColored(const char* label, const bool& status)
{
	static const ImU32 color_true = IM_COL32(51, 204, 77, 255);
	static const ImU32 color_false = IM_COL32(204, 77, 51, 255);

	TextBool(label, status, "True", "False", true, color_true, color_false);
}

void ImGui::TextBoolPresence(const char* label, const bool& presence)
{
	TextBool(label, presence, "Is Present", "Doesn't Exist!", false, ImU32(), ImU32());
}

void ImGui::TextBoolPresenceColored(const char* label, const bool& presence)
{
	static const ImU32 color_true = IM_COL32(51, 204, 77, 255);
	static const ImU32 color_false = IM_COL32(204, 77, 51, 255);

	TextBool(label, presence, "Is Present", "Doesn't Exist!", true, color_true, color_false);
}

void ImGui::TextBoolMultiplePresence(const char* label, const bool& presence)
{
	TextBool(label, presence, "Are Present", "Are Non Existent!", false, ImU32(), ImU32());
}

void ImGui::TextBoolMultiplePresenceColored(const char* label, const bool& presence)
{
	static const ImU32 color_true = IM_COL32(51, 204, 77, 255);
	static const ImU32 color_false = IM_COL32(204, 77, 51, 255);

	TextBool(label, presence, "Are Present", "Are Non Existent!", true, color_true, color_false);
}




void ImGui::TextFloat(const char* label, const float& value, const bool& useColoring, const ImU32& color_positive, const ImU32& color_negative)
{
	if (label)
	{
		const char* idPosition = std::strstr(label, "##");
		if (idPosition)
			ImGui::TextUnformatted(label, idPosition);
		else
			ImGui::TextUnformatted(label);

		ImGui::SameLine();
	}

	if (useColoring && value != 0.0f)
	{
		ImGui::PushStyleColor(ImGuiCol_Text, value > 0.0f ? color_positive : color_negative);
		ImGui::Text("%f", value);
		ImGui::PopStyleColor();;
	}
	else
		ImGui::Text("%f", value);
}

void ImGui::TextFloat(const char* label, const float& value)
{
	TextFloat(label, value, false, ImU32(), ImU32());
}

void ImGui::TextFloatColored(const char* label, const float& value)
{
	static const ImU32 color_positive = IM_COL32(51, 204, 77, 255);
	static const ImU32 color_negative = IM_COL32(204, 77, 51, 255);

	TextFloat(label, value, true, color_positive, color_negative);
}




void ImGui::TextInt(const char* label, const int32_t& value, const bool& useColoring, const ImU32& color_positive, const ImU32& color_negative)
{
	if (label)
	{
		const char* idPosition = std::strstr(label, "##");
		if (idPosition)
			ImGui::TextUnformatted(label, idPosition);
		else
			ImGui::TextUnformatted(label);

		ImGui::SameLine();
	}

	if (useColoring && value != 0)
	{
		ImGui::PushStyleColor(ImGuiCol_Text, value > 0.0f ? color_positive : color_negative);
		ImGui::Text("%d", value);
		ImGui::PopStyleColor();;
	}
	else
		ImGui::Text("%d", value);
}

void ImGui::TextInt(const char* label, const int32_t& value)
{
	TextInt(label, value, false, ImU32(), ImU32());
}

void ImGui::TextIntColored(const char* label, const int32_t& value)
{
	static const ImU32 color_positive = IM_COL32(51, 204, 77, 255);
	static const ImU32 color_negative = IM_COL32(204, 77, 51, 255);

	TextInt(label, value, true, color_positive, color_negative);
}




void ImGui::TextVector(const char* label, const SDK::FVector& value, const bool& useColoring, const ImU32& color_positive, const ImU32& color_negative)
{
	constexpr ImU32 axis_colors[3]
	{
		IM_COL32(255, 0, 0, 255),
		IM_COL32(0, 255, 0, 255),
		IM_COL32(0, 0, 255, 255)
	};

	constexpr const char* axis_prefixes[3]
	{
		"X:",
		"Y:",
		"Z:"
	};

	const float coords[3]
	{
		value.X,
		value.Y,
		value.Z
	};

	if (label)
	{
		const char* idPosition = std::strstr(label, "##");
		if (idPosition)
			ImGui::TextUnformatted(label, idPosition);
		else
			ImGui::TextUnformatted(label);

		ImGui::SameLine();
	}

	for (int i = 0; i < 3; i++)
	{
		if (useColoring) ImGui::PushStyleColor(ImGuiCol_Text, axis_colors[i]);
		ImGui::TextUnformatted(axis_prefixes[i]);
		if (useColoring) ImGui::PopStyleColor();

		ImGui::SameLine();

		bool neutralValue = coords[i] > -0.0000001 && coords[i] < 0.0000001;
		if (useColoring && !neutralValue) ImGui::PushStyleColor(ImGuiCol_Text, coords[i] > 0.0 ? color_positive : color_negative);
		ImGui::Text("%f", neutralValue ? 0.0 : coords[i]);
		if (useColoring && !neutralValue) ImGui::PopStyleColor();

		if (i != 2)
		{
			ImGui::SameLine();
			ImGui::Spacing();
			ImGui::SameLine();
		}
	}
}

void ImGui::TextVector(const char* label, const SDK::FVector& value)
{
	TextVector(label, value, false, ImU32(), ImU32());
}

void ImGui::TextVectorColored(const char* label, const SDK::FVector& value)
{
	static const ImU32 color_positive = IM_COL32(51, 204, 77, 255);
	static const ImU32 color_negative = IM_COL32(204, 77, 51, 255);

	TextVector(label, value, true, color_positive, color_negative);
}




void ImGui::TextRotator(const char* label, const SDK::FRotator& value, const bool& useColoring, const ImU32& color_positive, const ImU32& color_negative)
{
	constexpr ImU32 axis_colors[3]
	{
		IM_COL32(255, 0, 0, 255),
		IM_COL32(0, 255, 0, 255),
		IM_COL32(0, 0, 255, 255)
	};

	constexpr const char* axis_prefixes[3]
	{
		"Pitch:",
		"Yaw:",
		"Roll:"
	};

	const float angles[3]
	{
		value.Pitch,
		value.Yaw,
		value.Roll
	};

	if (label)
	{
		const char* idPosition = std::strstr(label, "##");
		if (idPosition)
			ImGui::TextUnformatted(label, idPosition);
		else
			ImGui::TextUnformatted(label);

		ImGui::SameLine();
	}

	for (int i = 0; i < 3; i++)
	{
		if (useColoring) ImGui::PushStyleColor(ImGuiCol_Text, axis_colors[i]);
		ImGui::TextUnformatted(axis_prefixes[i]);
		if (useColoring) ImGui::PopStyleColor();

		ImGui::SameLine();

		bool neutralValue = angles[i] > -0.0000001 && angles[i] < 0.0000001;
		if (useColoring && !neutralValue) ImGui::PushStyleColor(ImGuiCol_Text, angles[i] > 0.0 ? color_positive : color_negative);
		ImGui::Text("%f (%.2fC)", neutralValue ? 0.0 : angles[i], neutralValue ? 0.0 : (-360.0 + (angles[i] + 1) * 360.0));
		if (useColoring && !neutralValue) ImGui::PopStyleColor();

		if (i != 2)
		{
			ImGui::SameLine();
			ImGui::Spacing();
			ImGui::SameLine();
		}
	}
}

void ImGui::TextRotator(const char* label, const SDK::FRotator& value)
{
	TextRotator(label, value, false, ImU32(), ImU32());
}

void ImGui::TextRotatorColored(const char* label, const SDK::FRotator& value)
{
	static const ImU32 color_positive = IM_COL32(51, 204, 77, 255);
	static const ImU32 color_negative = IM_COL32(204, 77, 51, 255);

	TextRotator(label, value, true, color_positive, color_negative);
}




void ImGui::ReadOnlyInputText(const char* label, const char* text, const bool& showCopyButton)
{
	if (label)
	{
		const char* idPosition = std::strstr(label, "##");
		if (idPosition)
			ImGui::TextUnformatted(label, idPosition);
		else
			ImGui::TextUnformatted(label);

		ImGui::SameLine();
	}

	ImGui::PushID(label ? label : (text ? text : "##ReadOnlyInputText"));
	const size_t length = text ? strlen(text) : 0;

	static std::vector<char> buffer;
	buffer.clear();

	if (text && length)
		buffer.insert(buffer.end(), text, text + length);
	buffer.push_back('\0');

	ImGui::InputText("##ReadOnlyInputText", buffer.data(), buffer.size(), ImGuiInputTextFlags_ReadOnly);
	if (showCopyButton)
	{
		ImGui::SameLine();
		if (ImGui::Button("Copy"))
		{
			WindowsUtilities::SetClipboard(buffer.data());
			GUI::PlayActionSound(true);
		}
	}

	ImGui::PopID();
}




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






// ========================================================
// |                #GUI #UI #USERINTERFACE               |
// ========================================================
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
			ImGui::Text("UETools GUI (v0.6) | ");
			if (ImGui::BeginMenu("Debug"))
			{
				if (SharedData::debugInfo.isActive)
				{
					ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0 / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

					static const char* menuSpacer = "                                                                                               ";
					ImGui::TextUnformatted(menuSpacer, menuSpacer + 96);

					if (SharedData::debugInfo.autoUpdate)
					{
						float updatesPerSecond = 1.0f / SharedData::debugInfo.autoUpdateDelay;
						if (updatesPerSecond > 1.0f)
							ImGui::Text("Updates %d times per second", (int32_t)(updatesPerSecond));
						else
						{
							float updatesPerMinute = 60.0f / SharedData::debugInfo.autoUpdateDelay;
							if (updatesPerMinute > 1.0f)
								ImGui::Text("Updates %d times per minute", (int32_t)(updatesPerMinute));
							else
							{
								float updatesPerHour = 3600.0f / SharedData::debugInfo.autoUpdateDelay;
								if (updatesPerHour > 1.0f)
									ImGui::Text("Updates %d times per hour", (int32_t)(updatesPerHour));
								else
								{
									float updatesPerDay = 86400.0f / SharedData::debugInfo.autoUpdateDelay;
									if (updatesPerDay > 1.0f)
										ImGui::Text("Updates %d times per day", (int32_t)(updatesPerDay));
									else
										ImGui::Text("Updates periodically", (int32_t)(updatesPerDay));
								}
							}
						}
						if (ImGui::InputFloat("Auto Update Delay", &SharedData::debugInfo.autoUpdateDelay, 0.01f, 0.1f))
						{
							if (SharedData::debugInfo.autoUpdateDelay < 0.01f)
								SharedData::debugInfo.autoUpdateDelay = 0.01f;
						}

						const double now = ImGui::GetTime();
						const double elapsed = now - SharedData::debugInfo.lastUpdateTime;

						if (elapsed >= SharedData::debugInfo.autoUpdateDelay)
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

					ImGui::SetFontTitle();
					ImGui::TextBoolPresenceColored("Engine:", SharedData::debugInfo.engine.engineReference);
					ImGui::SetFontRegular();
					if (SharedData::debugInfo.engine.engineReference)
					{
						if (ImGui::CollapsingHeader("Details##Engine"))
						{
							ImGui::Text("Engine Class: %s", SharedData::debugInfo.engine.engineClass.c_str());
							ImGui::Text("Engine Object: %s", SharedData::debugInfo.engine.engineObject.c_str());

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Viewport Client:", SharedData::debugInfo.engine.viewportClient.viewportClientReference);
							ImGui::SetFontRegular();
							if (SharedData::debugInfo.engine.viewportClient.viewportClientReference)
							{
								if (ImGui::TreeNode("Details##ViewportClient"))
								{
									ImGui::Text("Viewport Client Class: %s", SharedData::debugInfo.engine.viewportClient.viewportClientClass.c_str());
									ImGui::Text("Viewport Client Object: %s", SharedData::debugInfo.engine.viewportClient.viewportClientObject.c_str());

									ImGui::NewLine();

									ImGui::SetFontTitle();
									ImGui::TextBoolPresenceColored("Console:", SharedData::debugInfo.engine.viewportClient.console.consoleReference);
									ImGui::SetFontRegular();
									if (SharedData::debugInfo.engine.viewportClient.console.consoleReference)
									{
										if (ImGui::TreeNode("Details##Console"))
										{
											ImGui::Text("Console Class: %s", SharedData::debugInfo.engine.viewportClient.console.consoleClass.c_str());
											ImGui::Text("Console Object: %s", SharedData::debugInfo.engine.viewportClient.console.consoleObject.c_str());

											ImGui::TreePop();
										}
									}
									else
									{
										if (ImGui::Button("Construct Console"))
										{
											bool wasConsoleConstructed = Console::ConstructConsole() && Input::CreateConsoleBindings();
											if (wasConsoleConstructed)
												SharedCalls::UpdateDebugInformation();

											PlayActionSound(wasConsoleConstructed);
										}
									}

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							bool fixedFrameRateEnabled = SharedData::debugInfo.engine.fixedFrameRateEnabled;
							if (ImGui::Checkbox("Fixed FrameRate Enabled", &fixedFrameRateEnabled))
							{
								if (SharedData::debugInfo.engine.engineReference)
								{
									SharedData::debugInfo.engine.fixedFrameRateEnabled = fixedFrameRateEnabled;
									SharedData::debugInfo.engine.engineReference->bUseFixedFrameRate = fixedFrameRateEnabled;
								}
							}
							float fixedFrameRate = SharedData::debugInfo.engine.fixedFrameRate;
							if (ImGui::InputFloat("Fixed FrameRate", &fixedFrameRate, 1.0f, 10.0f))
							{
								if (SharedData::debugInfo.engine.engineReference)
								{
									SharedData::debugInfo.engine.fixedFrameRate = fixedFrameRate;
									SharedData::debugInfo.engine.engineReference->FixedFrameRate = fixedFrameRate;
								}
							}

							ImGui::NewLine();

							bool smoothFrameRateEnabled = SharedData::debugInfo.engine.smoothFrameRateEnabled;
							if (ImGui::Checkbox("Smooth FrameRate Enabled", &smoothFrameRateEnabled))
							{
								if (SharedData::debugInfo.engine.engineReference)
								{
									SharedData::debugInfo.engine.smoothFrameRateEnabled = smoothFrameRateEnabled;
									SharedData::debugInfo.engine.engineReference->bSmoothFrameRate = smoothFrameRateEnabled;
								}
							}
							float smoothFrameRateRange[2] = { SharedData::debugInfo.engine.smoothFrameRateRange.LowerBound.Value, SharedData::debugInfo.engine.smoothFrameRateRange.UpperBound.Value };
							if (ImGui::InputFloat2("Smooth FrameRate Range", smoothFrameRateRange))
							{
								if (SharedData::debugInfo.engine.engineReference)
								{
									SDK::FFloatRange floatRange = SharedData::debugInfo.engine.smoothFrameRateRange;
									floatRange.LowerBound.Value = smoothFrameRateRange[0];
									floatRange.UpperBound.Value = smoothFrameRateRange[1];

									SharedData::debugInfo.engine.smoothFrameRateRange = floatRange;
									SharedData::debugInfo.engine.engineReference->SmoothedFrameRateRange = floatRange;
								}
							}

							ImGui::NewLine();

							bool subtitlesEnabled = SharedData::debugInfo.engine.subtitlesEnabled;
							if (ImGui::Checkbox("Subtitles Enabled", &subtitlesEnabled))
							{
								if (SharedData::debugInfo.engine.engineReference)
								{
									SharedData::debugInfo.engine.subtitlesEnabled = subtitlesEnabled;
									SharedData::debugInfo.engine.engineReference->bSubtitlesEnabled = subtitlesEnabled;
								}
							}
							bool subtitlesForcedOff = SharedData::debugInfo.engine.subtitlesForcedOff;
							if (ImGui::Checkbox("Subtitles Forced Off", &subtitlesForcedOff))
							{
								if (SharedData::debugInfo.engine.engineReference)
								{
									SharedData::debugInfo.engine.subtitlesForcedOff = subtitlesForcedOff;
									SharedData::debugInfo.engine.engineReference->bSubtitlesForcedOff = subtitlesForcedOff;
								}
							}

							ImGui::NewLine();

							bool pauseOnLossOfFocus = SharedData::debugInfo.engine.pauseOnLossOfFocus;
							if (ImGui::Checkbox("Pause On Loss Of Focus", &pauseOnLossOfFocus))
							{
								if (SharedData::debugInfo.engine.engineReference)
								{
									SharedData::debugInfo.engine.pauseOnLossOfFocus = pauseOnLossOfFocus;
									SharedData::debugInfo.engine.engineReference->bPauseOnLossOfFocus = pauseOnLossOfFocus;
								}
							}
						}
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::SetFontTitle();
					ImGui::TextBoolPresenceColored("Game Instance:", SharedData::debugInfo.gameInstance.gameInstanceReference);
					ImGui::SetFontRegular();
					if (SharedData::debugInfo.gameInstance.gameInstanceReference)
					{
						if (ImGui::CollapsingHeader("Details##GameInstance"))
						{
							ImGui::Text("Game Instance Class: %s", SharedData::debugInfo.gameInstance.gameInstanceClass.c_str());
							ImGui::Text("Game Instance Object: %s", SharedData::debugInfo.gameInstance.gameInstanceObject.c_str());

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Online Session:", SharedData::debugInfo.gameInstance.onlineSession.onlineSessionReference);
							ImGui::SetFontRegular();
							if (SharedData::debugInfo.gameInstance.onlineSession.onlineSessionReference)
							{
								if (ImGui::TreeNode("Details##OnlineSession"))
								{
									ImGui::Text("Online Session Class: %s", SharedData::debugInfo.gameInstance.onlineSession.onlineSessionClass.c_str());
									ImGui::Text("Online Session Object: %s", SharedData::debugInfo.gameInstance.onlineSession.onlineSessionObject.c_str());

									ImGui::TreePop();
								}
							}
						}
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::SetFontTitle();
					ImGui::TextBoolPresenceColored("Game Mode:", SharedData::debugInfo.gameMode.gameModeReference);
					ImGui::SetFontRegular();
					if (SharedData::debugInfo.gameMode.gameModeReference)
					{
						if (ImGui::CollapsingHeader("Details##GameMode"))
						{
							ImGui::Text("Game Mode Class: %s", SharedData::debugInfo.gameMode.gameModeClass.c_str());
							ImGui::Text("Game Mode Object: %s", SharedData::debugInfo.gameMode.gameModeObject.c_str());

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Game Session:", SharedData::debugInfo.gameMode.gameSession.gameSessionReference);
							ImGui::SetFontRegular();
							if (SharedData::debugInfo.gameMode.gameSession.gameSessionReference)
							{
								if (ImGui::TreeNode("Details##GameSession"))
								{
									ImGui::Text("Game Session Class: %s", SharedData::debugInfo.gameMode.gameSession.gameSessionClass.c_str());
									ImGui::Text("Game Session Object: %s", SharedData::debugInfo.gameMode.gameSession.gameSessionObject.c_str());

									ImGui::NewLine();

									int32_t maxPlayers = SharedData::debugInfo.gameMode.gameSession.maxPlayers;
									if (ImGui::InputInt("Max Players", &maxPlayers, 1, 10))
									{
										if (SharedData::debugInfo.gameMode.gameSession.gameSessionReference)
										{
											SharedData::debugInfo.gameMode.gameSession.maxPlayers = maxPlayers;
											SharedData::debugInfo.gameMode.gameSession.gameSessionReference->MaxPlayers = maxPlayers;
										}
									}
									int32_t maxSpectators = SharedData::debugInfo.gameMode.gameSession.maxSpectators;
									if (ImGui::InputInt("Max Spectators", &maxSpectators, 1, 10))
									{
										if (SharedData::debugInfo.gameMode.gameSession.gameSessionReference)
										{
											SharedData::debugInfo.gameMode.gameSession.maxSpectators = maxSpectators;
											SharedData::debugInfo.gameMode.gameSession.gameSessionReference->MaxSpectators = maxSpectators;
										}
									}
									int32_t maxPartySize = SharedData::debugInfo.gameMode.gameSession.maxPartySize;
									if (ImGui::InputInt("Max Party Size", &maxPartySize, 1, 10))
									{
										if (SharedData::debugInfo.gameMode.gameSession.gameSessionReference)
										{
											SharedData::debugInfo.gameMode.gameSession.maxPartySize = maxPartySize;
											SharedData::debugInfo.gameMode.gameSession.gameSessionReference->MaxPartySize = maxPartySize;
										}
									}
									int32_t maxSplitScreensPerConnection = SharedData::debugInfo.gameMode.gameSession.maxSplitScreensPerConnection;
									if (ImGui::InputInt("Max Split Screens Per Connection", &maxSplitScreensPerConnection, 1, 10))
									{
										if (SharedData::debugInfo.gameMode.gameSession.gameSessionReference)
										{
											SharedData::debugInfo.gameMode.gameSession.maxSplitScreensPerConnection = maxSplitScreensPerConnection;
											SharedData::debugInfo.gameMode.gameSession.gameSessionReference->MaxSplitscreensPerConnection = maxSplitScreensPerConnection;
										}
									}

									ImGui::NewLine();

									ImGui::ReadOnlyInputText("Session Name:", SharedData::debugInfo.gameMode.gameSession.sessionName.c_str(), true);

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							ImGui::TextIntColored("Players Count:", SharedData::debugInfo.gameMode.playersCount);
							ImGui::TextIntColored("Spectators Count:", SharedData::debugInfo.gameMode.spectatorsCount);

							ImGui::NewLine();

							ImGui::TextBoolColored("Start Players As Spectator:", SharedData::debugInfo.gameMode.startPlayersAsSpectators);
							ImGui::ReadOnlyInputText("Default Player Name:", SharedData::debugInfo.gameMode.defaultPlayerName.c_str(), true);

							ImGui::NewLine();

							bool useSeamlessTravel = SharedData::debugInfo.gameMode.useSeamlessTravel;
							if (ImGui::Checkbox("Use Seamless Travel", &useSeamlessTravel))
							{
								if (SharedData::debugInfo.gameMode.gameModeReference)
								{
									SharedData::debugInfo.gameMode.useSeamlessTravel = useSeamlessTravel;
									SharedData::debugInfo.gameMode.gameModeReference->bUseSeamlessTravel = useSeamlessTravel;
								}
							}
							bool isPausable = SharedData::debugInfo.gameMode.isPausable;
							if (ImGui::Checkbox("Is Pausable", &isPausable))
							{
								if (SharedData::debugInfo.gameMode.gameModeReference)
								{
									SharedData::debugInfo.gameMode.isPausable = isPausable;
									SharedData::debugInfo.gameMode.gameModeReference->bPauseable = isPausable;
								}
							}

							ImGui::NewLine();

							ImGui::ReadOnlyInputText("Options:", SharedData::debugInfo.gameMode.options.c_str(), true);
						}
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();
					
					ImGui::SetFontTitle();
					ImGui::TextBoolPresenceColored("Player Controller:", SharedData::debugInfo.playerController.playerControllerReference);
					ImGui::SetFontRegular();
					if (SharedData::debugInfo.playerController.playerControllerReference)
					{
						if (ImGui::CollapsingHeader("Details##PlayerController"))
						{
							ImGui::Text("Player Controller Class: %s", SharedData::debugInfo.playerController.playerControllerClass.c_str());
							ImGui::Text("Player Controller Object: %s", SharedData::debugInfo.playerController.playerControllerObject.c_str());

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Pawn:", SharedData::debugInfo.playerController.pawn.pawnReference);
							ImGui::SetFontRegular();
							if (SharedData::debugInfo.playerController.pawn.pawnReference)
							{
								if (ImGui::TreeNode("Details##Pawn"))
								{
									ImGui::Text("Pawn Class: %s", SharedData::debugInfo.playerController.pawn.pawnClass.c_str());
									ImGui::Text("Pawn Object: %s", SharedData::debugInfo.playerController.pawn.pawnObject.c_str());
									ImGui::TextVectorColored("Location:", SharedData::debugInfo.playerController.pawn.location);
									ImGui::TextRotatorColored("Rotation:", SharedData::debugInfo.playerController.pawn.rotation);
									ImGui::TextVectorColored("Scale:", SharedData::debugInfo.playerController.pawn.scale);

									ImGui::NewLine();

									ImGui::TextBoolColored("Is Controlled:", SharedData::debugInfo.playerController.pawn.isControlled);
									ImGui::TextBoolColored("Is Pawn Controlled:", SharedData::debugInfo.playerController.pawn.isPawnControlled);
									ImGui::TextBoolColored("Is Player Controlled:", SharedData::debugInfo.playerController.pawn.isPlayerControlled);
									ImGui::TextBoolColored("Is Locally Controlled:", SharedData::debugInfo.playerController.pawn.isLocallyControlled);
									ImGui::TextBoolColored("Is Bot Controlled:", SharedData::debugInfo.playerController.pawn.isBotControlled);

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Camera Manager:", SharedData::debugInfo.playerController.cameraManager.cameraManagerReference);
							ImGui::SetFontRegular();
							if (SharedData::debugInfo.playerController.cameraManager.cameraManagerReference)
							{
								if (ImGui::TreeNode("Details##CameraManager"))
								{
									ImGui::Text("Camera Manager Class: %s", SharedData::debugInfo.playerController.cameraManager.cameraManagerClass.c_str());
									ImGui::Text("Camera Manager Object: %s", SharedData::debugInfo.playerController.cameraManager.cameraManagerObject.c_str());
									ImGui::TextVectorColored("Location:", SharedData::debugInfo.playerController.cameraManager.location);
									ImGui::TextRotatorColored("Rotation:", SharedData::debugInfo.playerController.cameraManager.rotation);
									ImGui::TextVectorColored("Scale:", SharedData::debugInfo.playerController.cameraManager.scale);

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Cheat Manager:", SharedData::debugInfo.playerController.cheatManager.cheatManagerReference);
							ImGui::SetFontRegular();
							if (SharedData::debugInfo.playerController.cheatManager.cheatManagerReference)
							{
								if (ImGui::TreeNode("Details##CheatManager"))
								{
									ImGui::Text("Cheat Manager Class: %s", SharedData::debugInfo.playerController.cheatManager.cheatManagerClass.c_str());
									ImGui::Text("Cheat Manager Object: %s", SharedData::debugInfo.playerController.cheatManager.cheatManagerObject.c_str());

									ImGui::TreePop();
								}
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
						}
					}

					ImGui::NewLine();
					ImGui::Separator();
					ImGui::NewLine();

					ImGui::SetFontTitle();
					ImGui::TextBoolPresenceColored("World:", SharedData::debugInfo.world.worldReference);
					ImGui::SetFontRegular();
					if (SharedData::debugInfo.world.worldReference)
					{
						if (ImGui::CollapsingHeader("Details##World"))
						{
							ImGui::Text("World Class: %s", SharedData::debugInfo.world.worldClass.c_str());
							ImGui::Text("World Object: %s", SharedData::debugInfo.world.worldObject.c_str());

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Game State:", SharedData::debugInfo.world.gameState.gameStateReference);
							ImGui::SetFontRegular();
							if (SharedData::debugInfo.world.gameState.gameStateReference)
							{
								if (ImGui::TreeNode("Details##GameState"))
								{
									ImGui::Text("Game State Class: %s", SharedData::debugInfo.world.gameState.gameStateClass.c_str());
									ImGui::Text("Game State Object: %s", SharedData::debugInfo.world.gameState.gameStateObject.c_str());

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Net Driver:", SharedData::debugInfo.world.netDriver.netDriverReference);
							ImGui::SetFontRegular();
							if (SharedData::debugInfo.world.netDriver.netDriverReference)
							{
								if (ImGui::TreeNode("Details##NetDriver"))
								{
									ImGui::Text("Net Driver Class: %s", SharedData::debugInfo.world.netDriver.netDriverClass.c_str());
									ImGui::Text("Net Driver Object: %s", SharedData::debugInfo.world.netDriver.netDriverObject.c_str());

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Demo Net Driver:", SharedData::debugInfo.world.demoNetDriver.demoNetDriverReference);
							ImGui::SetFontRegular();
							if (SharedData::debugInfo.world.demoNetDriver.demoNetDriverReference)
							{
								if (ImGui::TreeNode("Details##DemoNetDriver"))
								{
									ImGui::Text("Demo Net Driver Class: %s", SharedData::debugInfo.world.demoNetDriver.demoNetDriverClass.c_str());
									ImGui::Text("Demo Net Driver Object: %s", SharedData::debugInfo.world.demoNetDriver.demoNetDriverObject.c_str());

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Persistent Level:", SharedData::debugInfo.world.persistentLevel.levelReference);
							ImGui::SetFontRegular();
							if (SharedData::debugInfo.world.persistentLevel.levelReference)
							{
								if (ImGui::TreeNode("Details##PersistentLevel"))
								{
									ImGui::Text("Persistent Level Class: %s", SharedData::debugInfo.world.persistentLevel.levelClass.c_str());
									ImGui::Text("Persistent Level Object: %s", SharedData::debugInfo.world.persistentLevel.levelObject.c_str());
									ImGui::Text("Persistent Level Name: %s", SharedData::debugInfo.world.persistentLevel.levelName.c_str());
									ImGui::TextBoolColored("Is Visible:", SharedData::debugInfo.world.persistentLevel.isLevelVisible);

									ImGui::NewLine();

									bool worldSettingsPresent = SharedData::debugInfo.world.persistentLevel.worldSettings.worldSettingsReference;
									ImGui::TextBoolPresenceColored("World Settings:", worldSettingsPresent);
									if (worldSettingsPresent)
									{
										if (ImGui::TreeNode("World Settings"))
										{
											ImGui::Text("World Settings Class: %s", SharedData::debugInfo.world.persistentLevel.worldSettings.worldSettingsClass.c_str());
											ImGui::Text("World Settings Object: %s", SharedData::debugInfo.world.persistentLevel.worldSettings.worldSettingsObject.c_str());

											ImGui::NewLine();

											ImGui::TextBoolColored("High Priority Loading:", SharedData::debugInfo.world.persistentLevel.worldSettings.worldHighPriorityLoading);
											ImGui::TextBoolColored("Local High Priority Loading:", SharedData::debugInfo.world.persistentLevel.worldSettings.worldLocalHighPriorityLoading);

											ImGui::NewLine();

											ImGui::TextFloat("Unreal Units = 1m:", SharedData::debugInfo.world.persistentLevel.worldSettings.worldToMeters);

											ImGui::TreePop();
										}
									}

									ImGui::NewLine();

									bool areStreamingLevelsPresent = SharedData::debugInfo.world.streamingLevels.size() > 0;
									ImGui::TextBoolMultiplePresenceColored("Streaming Levels:", areStreamingLevelsPresent);
									if (areStreamingLevelsPresent)
									{
										if (ImGui::TreeNode("Streaming Levels"))
										{
											for (SharedData::S_StreamingLevel streamingLevel : SharedData::debugInfo.world.streamingLevels)
											{
												ImVec4 levelColor
												{
													streamingLevel.streamingLevelColor.R,
													streamingLevel.streamingLevelColor.G,
													streamingLevel.streamingLevelColor.B,
													streamingLevel.streamingLevelColor.A
												};

												ImGui::PushStyleColor(ImGuiCol_Text, levelColor);
												bool isTreeNodeOpen = ImGui::TreeNode(streamingLevel.streamingLevelPath.c_str());
												ImGui::PopStyleColor();

												if (isTreeNodeOpen)
												{
													bool isLevelLoaded = streamingLevel.level.levelReference;

													ImGui::TextBoolColored("Is Loaded:", isLevelLoaded);
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

													ImGui::TextBoolColored("Is Visible:", streamingLevel.level.isLevelVisible);
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
													ImGui::TextBoolPresence("World Settings:", worldSettingsPresent);
													if (worldSettingsPresent)
													{
														if (ImGui::TreeNode("World Settings"))
														{
															ImGui::Text("World Settings Class: %s", streamingLevel.level.worldSettings.worldSettingsClass.c_str());
															ImGui::Text("World Settings Object: %s", streamingLevel.level.worldSettings.worldSettingsObject.c_str());

															ImGui::NewLine();

															ImGui::TextBoolColored("High Priority Loading:", streamingLevel.level.worldSettings.worldHighPriorityLoading);
															ImGui::TextBoolColored("Local High Priority Loading:", streamingLevel.level.worldSettings.worldLocalHighPriorityLoading);

															ImGui::NewLine();

															ImGui::TextFloat("Unreal Units = 1m:", streamingLevel.level.worldSettings.worldToMeters);

															ImGui::TreePop();
														}
													}

													ImGui::TreePop();
												}
											}

											ImGui::TreePop();
										}
									}

									ImGui::NewLine();

									ImGui::TextFloatColored("Game Time (In Seconds):", SharedData::debugInfo.world.gameTimeInSeconds);

									ImGui::NewLine();

									ImGui::TextBoolColored("Is Server:", SharedData::debugInfo.world.isServer);
									ImGui::TextBoolColored("Is Dedicated Server:", SharedData::debugInfo.world.isDedicatedServer);
									ImGui::TextBoolColored("Is Split Screen:", SharedData::debugInfo.world.isSplitScreen);
									ImGui::TextBoolColored("Is Standalone:", SharedData::debugInfo.world.isStandalone);

									ImGui::TreePop();
								}
							}
						}
					}

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
						ImGui::ReadOnlyInputText("Command Line:", SharedData::debugInfo.commandLine.c_str(), true);
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




			SDK::APlayerController* controller = PlayerController::GetPlayerController();
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
							ImGui::Checkbox("Directional Movement", &SharedData::featuresInfo.directionalMovement.enabled);
							ImGui::InputDouble("Directional Movement Step", &SharedData::featuresInfo.directionalMovement.movementStep, 0.1, 1.0);
							if (ImGui::InputDouble("Directional Movement Delay", &SharedData::featuresInfo.directionalMovement.movementDelay, 0.01, 0.1))
							{
								if (SharedData::featuresInfo.directionalMovement.movementDelay < 0.001)
									SharedData::featuresInfo.directionalMovement.movementDelay = 0.001;
							}
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






// ========================================================
// |          #GUI #SHARED #WORKERS #SHAREDWORKERS        |
// ========================================================
void GUI::SharedWorkers::FeaturesWorker()
{
	while (GetFeaturesThread())
	{
		if (SharedData::featuresInfo.directionalMovement.enabled)
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
							SDK::FVector finalLocation = SDK::UKismetMathLibrary::Add_VectorVector(currentLocation, cameraForwardVector * SharedData::featuresInfo.directionalMovement.movementStep);

							SharedData::objectsInfo.character->K2_TeleportTo(finalLocation, SharedData::objectsInfo.character->K2_GetActorRotation());
						}
					}
				}
			}
		}

		Sleep(Math::Seconds_ToMilliseconds(SharedData::featuresInfo.directionalMovement.movementDelay));
	}
}






// ========================================================
// |            #GUI #SHARED #CALLS #SHAREDCALLS          |
// ========================================================
void GUI::SharedCalls::UpdateDebugInformation()
{
	SDK::UEngine* engine = Engine::GetEngine();
	if (SharedData::debugInfo.engine.engineReference = engine)
	{
		SharedData::debugInfo.engine.engineClass = engine->Class->GetFullName();
		SharedData::debugInfo.engine.engineObject = engine->GetFullName();

		SharedData::debugInfo.engine.fixedFrameRateEnabled = engine->bUseFixedFrameRate;
		SharedData::debugInfo.engine.fixedFrameRate = engine->FixedFrameRate;

		SharedData::debugInfo.engine.smoothFrameRateEnabled = engine->bSmoothFrameRate;
		SharedData::debugInfo.engine.smoothFrameRateRange = engine->SmoothedFrameRateRange;

		SharedData::debugInfo.engine.subtitlesEnabled = engine->bSubtitlesEnabled;
		SharedData::debugInfo.engine.subtitlesForcedOff = engine->bSubtitlesForcedOff;

		SharedData::debugInfo.engine.pauseOnLossOfFocus = engine->bPauseOnLossOfFocus;

		SDK::UGameViewportClient* viewportClient = engine->GameViewport;
		if (SharedData::debugInfo.engine.viewportClient.viewportClientReference = viewportClient)
		{
			SharedData::debugInfo.engine.viewportClient.viewportClientClass = viewportClient->Class->GetFullName();
			SharedData::debugInfo.engine.viewportClient.viewportClientObject = viewportClient->GetFullName();

			SDK::UConsole* console = viewportClient->ViewportConsole;
			if (SharedData::debugInfo.engine.viewportClient.console.consoleReference = console)
			{
				SharedData::debugInfo.engine.viewportClient.console.consoleClass = console->Class->GetFullName();
				SharedData::debugInfo.engine.viewportClient.console.consoleObject = console->GetFullName();
			}
		}
	}


	SDK::UGameInstance* gameInstance = GameInstance::GetGameInstance();
	if (SharedData::debugInfo.gameInstance.gameInstanceReference = gameInstance)
	{
		SharedData::debugInfo.gameInstance.gameInstanceClass = gameInstance->Class->GetFullName();
		SharedData::debugInfo.gameInstance.gameInstanceObject = gameInstance->GetFullName();

		SDK::UOnlineSession* onlineSession = gameInstance->OnlineSession;
		if (SharedData::debugInfo.gameInstance.onlineSession.onlineSessionReference = onlineSession)
		{
			SharedData::debugInfo.gameInstance.onlineSession.onlineSessionClass = gameInstance->Class->GetFullName();
			SharedData::debugInfo.gameInstance.onlineSession.onlineSessionObject = gameInstance->GetFullName();
		}
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


	SDK::APlayerController* playerController = PlayerController::GetPlayerController();
	if (SharedData::debugInfo.playerController.playerControllerReference = playerController)
	{
		SharedData::debugInfo.playerController.playerControllerClass = playerController->Class->GetFullName();
		SharedData::debugInfo.playerController.playerControllerObject = playerController->GetFullName();


		SDK::UPlayer* player = playerController->Player;
		if (SharedData::debugInfo.playerController.player.playerReference = player)
		{
			SharedData::debugInfo.playerController.player.playerClass = player->Class->GetFullName();
			SharedData::debugInfo.playerController.player.playerObject = player->GetFullName();
		}


		SDK::APawn* pawn = playerController->AcknowledgedPawn;
		if (SharedData::debugInfo.playerController.pawn.pawnReference = pawn)
		{
			SharedData::debugInfo.playerController.pawn.pawnClass = pawn->Class->GetFullName();
			SharedData::debugInfo.playerController.pawn.pawnObject = pawn->GetFullName();

			SDK::FTransform pawnTransform = pawn->GetTransform();
			SharedData::debugInfo.playerController.pawn.location = pawnTransform.Translation;
			SharedData::debugInfo.playerController.pawn.rotation = SDK::FRotator(pawnTransform.Rotation.X, pawnTransform.Rotation.Y, pawnTransform.Rotation.Z);
			SharedData::debugInfo.playerController.pawn.scale = pawnTransform.Scale3D;

			SharedData::debugInfo.playerController.pawn.isControlled = pawn->IsControlled();
			SharedData::debugInfo.playerController.pawn.isPawnControlled = pawn->IsPawnControlled();
			SharedData::debugInfo.playerController.pawn.isPlayerControlled = pawn->IsPlayerControlled();
			SharedData::debugInfo.playerController.pawn.isLocallyControlled = pawn->IsLocallyControlled();
			SharedData::debugInfo.playerController.pawn.isBotControlled = pawn->IsBotControlled();
		}


		SDK::APlayerCameraManager* cameraManager = playerController->PlayerCameraManager;
		if (SharedData::debugInfo.playerController.cameraManager.cameraManagerReference = cameraManager)
		{
			SharedData::debugInfo.playerController.cameraManager.cameraManagerClass = cameraManager->Class->GetFullName();
			SharedData::debugInfo.playerController.cameraManager.cameraManagerObject = cameraManager->GetFullName();

			SDK::FTransform cameraManagerTransform = cameraManager->GetTransform();
			SharedData::debugInfo.playerController.cameraManager.location = cameraManagerTransform.Translation;
			SharedData::debugInfo.playerController.cameraManager.rotation = SDK::FRotator(cameraManagerTransform.Rotation.X, cameraManagerTransform.Rotation.Y, cameraManagerTransform.Rotation.Z);
			SharedData::debugInfo.playerController.cameraManager.scale = cameraManagerTransform.Scale3D;
		}


		SDK::UCheatManager* cheatManager = playerController->CheatManager;
		if (SharedData::debugInfo.playerController.cheatManager.cheatManagerReference = cheatManager)
		{
			SharedData::debugInfo.playerController.cheatManager.cheatManagerClass = cheatManager->Class->GetFullName();
			SharedData::debugInfo.playerController.cheatManager.cheatManagerObject = cheatManager->GetFullName();
		}
	}


	SDK::UWorld* world = SDK::UWorld::GetWorld();
	if (SharedData::debugInfo.world.worldReference = world)
	{
		SharedData::debugInfo.world.worldClass = world->Class->GetFullName();
		SharedData::debugInfo.world.worldObject = world->GetFullName();

		if (SDK::AGameStateBase* gameState = world->GameState)
		{
			SharedData::debugInfo.world.gameState.gameStateReference = gameState;

			SharedData::debugInfo.world.gameState.gameStateClass = gameState->Class->GetFullName();
			SharedData::debugInfo.world.gameState.gameStateObject = gameState->GetFullName();
		}

		if (SDK::UNetDriver* netDriver = world->NetDriver)
		{
			SharedData::debugInfo.world.netDriver.netDriverReference = netDriver;

			SharedData::debugInfo.world.netDriver.netDriverClass = netDriver->Class->GetFullName();
			SharedData::debugInfo.world.netDriver.netDriverObject = netDriver->GetFullName();
		}

		if (SDK::UNetDriver* demoNetDriver = world->NetDriver)
		{
			SharedData::debugInfo.world.demoNetDriver.demoNetDriverReference = demoNetDriver;

			SharedData::debugInfo.world.demoNetDriver.demoNetDriverClass = demoNetDriver->Class->GetFullName();
			SharedData::debugInfo.world.demoNetDriver.demoNetDriverObject = demoNetDriver->GetFullName();
		}

		if (SDK::ULevel* persistentLevel = world->PersistentLevel)
		{
			SharedData::debugInfo.world.persistentLevel.levelReference = persistentLevel;

			SharedData::debugInfo.world.persistentLevel.levelClass = persistentLevel->Class->GetFullName();
			SharedData::debugInfo.world.persistentLevel.levelObject = persistentLevel->GetFullName();
			SharedData::debugInfo.world.persistentLevel.levelName = SDK::UGameplayStatics::GetCurrentLevelName(world, false).ToString();

			SharedData::debugInfo.world.persistentLevel.isLevelVisible = persistentLevel->bIsVisible;

			if (SDK::AWorldSettings* worldSettings = persistentLevel->WorldSettings)
			{
				SharedData::debugInfo.world.persistentLevel.worldSettings.worldSettingsReference = worldSettings;
				SharedData::debugInfo.world.persistentLevel.worldSettings.worldSettingsClass = worldSettings->Class->GetFullName();
				SharedData::debugInfo.world.persistentLevel.worldSettings.worldSettingsObject = worldSettings->GetFullName();

				SharedData::debugInfo.world.persistentLevel.worldSettings.worldHighPriorityLoading = worldSettings->bHighPriorityLoading;
				SharedData::debugInfo.world.persistentLevel.worldSettings.worldLocalHighPriorityLoading = worldSettings->bHighPriorityLoadingLocal;

				SharedData::debugInfo.world.persistentLevel.worldSettings.worldToMeters = worldSettings->WorldToMeters;
			}
		}

		SDK::TArray<SDK::ULevelStreaming*> streamingLevels = world->StreamingLevels;
		if (streamingLevels.Num() > 0)
		{
			SharedData::debugInfo.world.streamingLevels.clear();

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

				SharedData::debugInfo.world.streamingLevels.push_back(streamingLevel);
			}
		}

		SharedData::debugInfo.world.gameTimeInSeconds = SDK::UKismetSystemLibrary::GetGameTimeInSeconds(world);

		SharedData::debugInfo.world.isServer = SDK::UKismetSystemLibrary::IsServer(world);
		SharedData::debugInfo.world.isDedicatedServer = SDK::UKismetSystemLibrary::IsDedicatedServer(world);
		SharedData::debugInfo.world.isSplitScreen = SDK::UKismetSystemLibrary::IsSplitScreen(world);
		SharedData::debugInfo.world.isStandalone = SDK::UKismetSystemLibrary::IsStandalone(world);
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
	if (ImGui::IsKeyBindingDown(&SharedData::keybindingsInfo.menuOpenCloseSub) && ImGui::IsKeyBindingPressed(&SharedData::keybindingsInfo.menuOpenCloseMain))
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






// ========================================================
// |       #GUI #SHARED #FUNCTIONS #SHAREDFUNCTIONS       |
// ========================================================
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
