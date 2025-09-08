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
									? (text_true ? text_true : "True")
									: (text_false ? text_false : "False"));
		ImGui::PopStyleColor();
	}
	else
		ImGui::TextUnformatted(inBool
									? (text_true ? text_true : "True")
									: (text_false ? text_false : "False"));
	
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

	const double coords[3]
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
		ImGui::SetFontBig();
		ImGui::TextUnformatted(axis_prefixes[i]);
		ImGui::SetFontRegular();
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

	const double angles[3]
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
		ImGui::SetFontBig();
		ImGui::TextUnformatted(axis_prefixes[i]);
		ImGui::SetFontRegular();
		if (useColoring) ImGui::PopStyleColor();

		ImGui::SameLine();

		bool neutralValue = angles[i] > -0.0000001 && angles[i] < 0.0000001;
		if (useColoring && !neutralValue) ImGui::PushStyleColor(ImGuiCol_Text, angles[i] > 0.0 ? color_positive : color_negative);
		ImGui::Text("%f", neutralValue ? 0.0 : angles[i]);
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

	ImGui::PushID(label ? label : (text ? text : "ReadOnlyInputText"));
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
			Clipboard::SetClipboard(buffer.data());
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

		case ImGuiKey_A: return 'A'; case ImGuiKey_B: return 'B';
		case ImGuiKey_C: return 'C'; case ImGuiKey_D: return 'D';
		case ImGuiKey_E: return 'E'; case ImGuiKey_F: return 'F';
		case ImGuiKey_G: return 'G'; case ImGuiKey_H: return 'H';
		case ImGuiKey_I: return 'I'; case ImGuiKey_J: return 'J';
		case ImGuiKey_K: return 'K'; case ImGuiKey_L: return 'L';
		case ImGuiKey_M: return 'M'; case ImGuiKey_N: return 'N';
		case ImGuiKey_O: return 'O'; case ImGuiKey_P: return 'P';
		case ImGuiKey_Q: return 'Q'; case ImGuiKey_R: return 'R';
		case ImGuiKey_S: return 'S'; case ImGuiKey_T: return 'T';
		case ImGuiKey_U: return 'U'; case ImGuiKey_V: return 'V';
		case ImGuiKey_W: return 'W'; case ImGuiKey_X: return 'X';
		case ImGuiKey_Y: return 'Y'; case ImGuiKey_Z: return 'Z';

		case ImGuiKey_0: return '0'; case ImGuiKey_1: return '1';
		case ImGuiKey_2: return '2'; case ImGuiKey_3: return '3';
		case ImGuiKey_4: return '4'; case ImGuiKey_5: return '5';
		case ImGuiKey_6: return '6'; case ImGuiKey_7: return '7';
		case ImGuiKey_8: return '8'; case ImGuiKey_9: return '9';

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

		case ImGuiKey_F1: return VK_F1; case ImGuiKey_F2: return VK_F2;
		case ImGuiKey_F3: return VK_F3; case ImGuiKey_F4: return VK_F4;
		case ImGuiKey_F5: return VK_F5; case ImGuiKey_F6: return VK_F6;
		case ImGuiKey_F7: return VK_F7; case ImGuiKey_F8: return VK_F8;
		case ImGuiKey_F9: return VK_F9; case ImGuiKey_F10: return VK_F10;
		case ImGuiKey_F11: return VK_F11; case ImGuiKey_F12: return VK_F12;

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

const char* ImGui::ImGuiKey_GetName(const ImGuiKey& key)
{
	switch (key)
	{
		case ImGuiKey_Tab:            return "Tab";
		case ImGuiKey_LeftArrow:      return "Left";
		case ImGuiKey_RightArrow:     return "Right";
		case ImGuiKey_UpArrow:        return "Up";
		case ImGuiKey_DownArrow:      return "Down";
		case ImGuiKey_PageUp:         return "PgUp";
		case ImGuiKey_PageDown:       return "PgDn";
		case ImGuiKey_Home:           return "Home";
		case ImGuiKey_End:            return "End";
		case ImGuiKey_Insert:         return "Ins";
		case ImGuiKey_Delete:         return "Del";
		case ImGuiKey_Backspace:      return "Bspace";
		case ImGuiKey_Space:          return "Space";
		case ImGuiKey_Enter:          return "Enter";
		case ImGuiKey_Escape:         return "Esc";

		case ImGuiKey_A: return "A";  case ImGuiKey_B: return "B";
		case ImGuiKey_C: return "C";  case ImGuiKey_D: return "D";
		case ImGuiKey_E: return "E";  case ImGuiKey_F: return "F";
		case ImGuiKey_G: return "G";  case ImGuiKey_H: return "H";
		case ImGuiKey_I: return "I";  case ImGuiKey_J: return "J";
		case ImGuiKey_K: return "K";  case ImGuiKey_L: return "L";
		case ImGuiKey_M: return "M";  case ImGuiKey_N: return "N";
		case ImGuiKey_O: return "O";  case ImGuiKey_P: return "P";
		case ImGuiKey_Q: return "Q";  case ImGuiKey_R: return "R";
		case ImGuiKey_S: return "S";  case ImGuiKey_T: return "T";
		case ImGuiKey_U: return "U";  case ImGuiKey_V: return "V";
		case ImGuiKey_W: return "W";  case ImGuiKey_X: return "X";
		case ImGuiKey_Y: return "Y";  case ImGuiKey_Z: return "Z";

		case ImGuiKey_0: return "0";  case ImGuiKey_1: return "1";
		case ImGuiKey_2: return "2";  case ImGuiKey_3: return "3";
		case ImGuiKey_4: return "4";  case ImGuiKey_5: return "5";
		case ImGuiKey_6: return "6";  case ImGuiKey_7: return "7";
		case ImGuiKey_8: return "8";  case ImGuiKey_9: return "9";

		case ImGuiKey_Keypad0:        return "Num0";
		case ImGuiKey_Keypad1:        return "Num1";
		case ImGuiKey_Keypad2:        return "Num2";
		case ImGuiKey_Keypad3:        return "Num3";
		case ImGuiKey_Keypad4:        return "Num4";
		case ImGuiKey_Keypad5:        return "Num5";
		case ImGuiKey_Keypad6:        return "Num6";
		case ImGuiKey_Keypad7:        return "Num7";
		case ImGuiKey_Keypad8:        return "Num8";
		case ImGuiKey_Keypad9:        return "Num9";
		case ImGuiKey_KeypadMultiply: return "Num*";
		case ImGuiKey_KeypadAdd:      return "Num+";
		case ImGuiKey_KeypadSubtract: return "Num-";
		case ImGuiKey_KeypadDecimal:  return "Num.";
		case ImGuiKey_KeypadDivide:   return "Num/";

		case ImGuiKey_F1:  return "F1";   case ImGuiKey_F2:  return "F2";
		case ImGuiKey_F3:  return "F3";   case ImGuiKey_F4:  return "F4";
		case ImGuiKey_F5:  return "F5";   case ImGuiKey_F6:  return "F6";
		case ImGuiKey_F7:  return "F7";   case ImGuiKey_F8:  return "F8";
		case ImGuiKey_F9:  return "F9";   case ImGuiKey_F10: return "F10";
		case ImGuiKey_F11: return "F11";  case ImGuiKey_F12: return "F12";

		case ImGuiKey_LeftCtrl:   return "LCtrl";
		case ImGuiKey_RightCtrl:  return "RCtrl";
		case ImGuiKey_LeftShift:  return "LShift";
		case ImGuiKey_RightShift: return "RShift";
		case ImGuiKey_LeftAlt:    return "LAlt";
		case ImGuiKey_RightAlt:   return "RAlt";
		case ImGuiKey_LeftSuper:  return "LWin";
		case ImGuiKey_RightSuper: return "RWin";

		default: return "???";
	}
}




bool ImGui::KeyBindingInput(const char* label, KeyBinding* binding)
{
	if (!binding)
		return false;

	if (label)
	{
		const char* idPosition = std::strstr(label, "##");
		if (idPosition)
			ImGui::TextUnformatted(label, idPosition);
		else
			ImGui::TextUnformatted(label);

		ImGui::SameLine();
	}

	ImGui::PushID(label ? label : "KeyBindingInput");

	SameLine();

	/* 0 corresponds for default vertical size. */
	static const ImVec2 buttonSize = { 96.0f, 0.0f };

	static const ImVec4 buttonColor = { 0.20f, 0.50f, 0.20f, 1.00f };
	static const ImVec4 buttonColor_unbound = { 0.50f, 0.20f, 0.20f, 1.00f };
	static const ImVec4 buttonColor_capturing = { 0.25f, 0.25f, 0.25f, 1.00f };

	bool hasBindingChanged = false;
	if (binding->isDetermined)
	{
		const char* bindingName;

		if (binding->key == ImGuiKey_None)
		{
			ImGui::PushStyleColor(ImGuiCol_Button, buttonColor_unbound);
			bindingName = "?";
		}
		else
		{
			ImGui::PushStyleColor(ImGuiCol_Button, buttonColor);
			bindingName = ImGuiKey_GetName(binding->key);
		}

		if (Button(bindingName, buttonSize))
			binding->isDetermined = false;
	}
	else
	{
		ImGui::PushStyleColor(ImGuiCol_Button, buttonColor_capturing);

		Button("...", buttonSize);
		for (int keyCode = ImGuiKey_NamedKey_BEGIN; keyCode < ImGuiKey_NamedKey_END; keyCode++)
		{
			if (IsKeyPressed((ImGuiKey)keyCode))
			{
				/* Verify that keyCode is within pre-determined list of keys. */
				if (ImGuiKey_ToWinAPI((ImGuiKey)keyCode) == 0)
					continue;

				/* When user tries to assign same key that is already set, consider that as will to unbind. */
				if (keyCode == binding->key)
					binding->key = ImGuiKey_None;
				else
					binding->key = (ImGuiKey)keyCode;

				binding->isDetermined = true;
				hasBindingChanged = true;
				break;
			}
		}
	}

	ImGui::PopStyleColor();
	ImGui::PopID();

	return hasBindingChanged;
}

bool ImGui::IsKeyBindingPressed(KeyBinding* binding, const bool& waitForRelease)
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

bool ImGui::IsKeyBindingDown(KeyBinding* binding)
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

bool ImGui::IsKeyBindingReleased(KeyBinding* binding)
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
bool GUI::StartDirectWindowThread()
{
	if (directWindowThread)
		return false;

	directWindowThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DirectWindow::Create, 0, 0, 0);
	return directWindowThread;
}




void GUI::Init(const HMODULE& applicationModule)
{
	/* Before creating a DirectWindow, we need to make it aware of our DLL HMODULE. */
	DirectWindow::SetApplicationModule(applicationModule);
	StartDirectWindowThread();
}




void GUI::Draw()
{
	ImGuiViewport* iViewPort = ImGui::GetMainViewport();
	ImVec2 iViewPortPosition = { iViewPort->Pos.x, iViewPort->Pos.y };
	ImVec2 iViewPortSize = { iViewPort->Size.x, iViewPort->Size.y };

	ImDrawList* iDrawList = ImGui::GetBackgroundDrawList();


	if (GetIsMenuActive())
	{
		if (ImGui::BeginMainMenuBar())
		{
			ImGui::Text("UETools GUI (v0.8) | ");
			if (ImGui::BeginMenu("Debug"))
			{
				if (Features::Debug::enabled == false)
				{
					if (ImGui::Button("Start"))
					{
						if (Features::Debug::autoUpdate == false)
							Features::Debug::Update();

						Features::Debug::enabled = true;
						PlayActionSound(true);
					}
				}
				else
				{
					ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0 / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

					ImGui::NewLine();

					if (Features::Debug::autoUpdate)
					{
						float updatesPerSecond = 1.0f / Features::Debug::autoUpdateDelay;
						if (updatesPerSecond > 1.0f)
							ImGui::Text("Updates %d times per second", (int32_t)(updatesPerSecond));
						else
						{
							float updatesPerMinute = 60.0f / Features::Debug::autoUpdateDelay;
							if (updatesPerMinute > 1.0f)
								ImGui::Text("Updates %d times per minute", (int32_t)(updatesPerMinute));
							else
							{
								float updatesPerHour = 3600.0f / Features::Debug::autoUpdateDelay;
								if (updatesPerHour > 1.0f)
									ImGui::Text("Updates %d times per hour", (int32_t)(updatesPerHour));
								else
								{
									float updatesPerDay = 86400.0f / Features::Debug::autoUpdateDelay;
									if (updatesPerDay > 1.0f)
										ImGui::Text("Updates %d times per day", (int32_t)(updatesPerDay));
									else
										ImGui::Text("Updates periodically", (int32_t)(updatesPerDay));
								}
							}
						}
						if (ImGui::InputFloat("Auto Update Delay", &Features::Debug::autoUpdateDelay, 0.01f, 0.1f))
						{
							if (Features::Debug::autoUpdateDelay < 0.01f)
								Features::Debug::autoUpdateDelay = 0.01f;
						}

						const double now = ImGui::GetTime();
						const double elapsed = now - Features::Debug::lastUpdateTime;

						if (elapsed >= Features::Debug::autoUpdateDelay)
							Features::Debug::Update();
					}
					else
					{
						const double now = ImGui::GetTime();
						const double elapsed = now - Features::Debug::lastUpdateTime;
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
					

					ImGui::BeginDisabled(Features::Debug::autoUpdate);
					if (ImGui::Button("Update##DebugInformation"))
					{
						Features::Debug::Update();
						PlayActionSound(true);
					}
					ImGui::EndDisabled();
					ImGui::SameLine();
					ImGui::Checkbox("Auto", &Features::Debug::autoUpdate);
					if (ImGui::Button("Stop"))
					{
						Features::Debug::enabled = false;
						PlayActionSound(true);
					}

					ImGui::CategorySeparator();

					ImGui::SetFontTitle();
					ImGui::TextBoolPresenceColored("Engine:", Features::Debug::engine.reference);
					ImGui::SetFontRegular();
					if (Features::Debug::engine.reference)
					{
						if (ImGui::CollapsingHeader("Details##Engine"))
						{
							ImGui::Text("Engine Class: %s", Features::Debug::engine.className.c_str());
							ImGui::Text("Engine Object: %s", Features::Debug::engine.objectName.c_str());

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Game Viewport Client:", Features::Debug::engine.gameViewportClient.reference);
							ImGui::SetFontRegular();
							if (Features::Debug::engine.gameViewportClient.reference)
							{
								if (ImGui::TreeNode("Details##GameViewportClient"))
								{
									ImGui::Text("Viewport Client Class: %s", Features::Debug::engine.gameViewportClient.className.c_str());
									ImGui::Text("Viewport Client Object: %s", Features::Debug::engine.gameViewportClient.objectName.c_str());

									ImGui::NewLine();

									ImGui::SetFontTitle();
									ImGui::TextBoolPresenceColored("Console:", Features::Debug::engine.gameViewportClient.console.reference);
									ImGui::SetFontRegular();
									if (Features::Debug::engine.gameViewportClient.console.reference)
									{
										if (ImGui::TreeNode("Details##Console"))
										{
											ImGui::Text("Console Class: %s", Features::Debug::engine.gameViewportClient.console.className.c_str());
											ImGui::Text("Console Object: %s", Features::Debug::engine.gameViewportClient.console.objectName.c_str());

											ImGui::TreePop();
										}
									}
									else
									{
										if (ImGui::Button("Construct Console"))
										{
											bool wasConstructed = Unreal::Console::Construct() && Unreal::InputSettings::AssignConsoleBindings();
											if (wasConstructed) // Only gather debug information if we're aware of changes.
												Features::Debug::Update();

											PlayActionSound(wasConstructed);
										}
									}

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							bool fixedFrameRateEnabled = Features::Debug::engine.fixedFrameRateEnabled;
							if (ImGui::Checkbox("Fixed FrameRate Enabled", &fixedFrameRateEnabled))
							{
								if (Features::Debug::engine.reference)
								{
									Features::Debug::engine.fixedFrameRateEnabled = fixedFrameRateEnabled;
									Features::Debug::engine.reference->bUseFixedFrameRate = fixedFrameRateEnabled;
								}
							}
							float fixedFrameRate = Features::Debug::engine.fixedFrameRate;
							if (ImGui::InputFloat("Fixed FrameRate", &fixedFrameRate, 1.0f, 10.0f))
							{
								if (Features::Debug::engine.reference)
								{
									Features::Debug::engine.fixedFrameRate = fixedFrameRate;
									Features::Debug::engine.reference->FixedFrameRate = fixedFrameRate;
								}
							}

							ImGui::NewLine();

							bool smoothFrameRateEnabled = Features::Debug::engine.smoothFrameRateEnabled;
							if (ImGui::Checkbox("Smooth FrameRate Enabled", &smoothFrameRateEnabled))
							{
								if (Features::Debug::engine.reference)
								{
									Features::Debug::engine.smoothFrameRateEnabled = smoothFrameRateEnabled;
									Features::Debug::engine.reference->bSmoothFrameRate = smoothFrameRateEnabled;
								}
							}
							float smoothFrameRateRange[2] = { Features::Debug::engine.smoothFrameRateRange.LowerBound.Value, Features::Debug::engine.smoothFrameRateRange.UpperBound.Value };
							if (ImGui::InputFloat2("Smooth FrameRate Range", smoothFrameRateRange))
							{
								if (Features::Debug::engine.reference)
								{
									SDK::FFloatRange floatRange = Features::Debug::engine.smoothFrameRateRange;
									floatRange.LowerBound.Value = smoothFrameRateRange[0];
									floatRange.UpperBound.Value = smoothFrameRateRange[1];

									Features::Debug::engine.smoothFrameRateRange = floatRange;
									Features::Debug::engine.reference->SmoothedFrameRateRange = floatRange;
								}
							}

							ImGui::NewLine();

							bool subtitlesEnabled = Features::Debug::engine.subtitlesEnabled;
							if (ImGui::Checkbox("Subtitles Enabled", &subtitlesEnabled))
							{
								if (Features::Debug::engine.reference)
								{
									Features::Debug::engine.subtitlesEnabled = subtitlesEnabled;
									Features::Debug::engine.reference->bSubtitlesEnabled = subtitlesEnabled;
								}
							}
							bool subtitlesForcedOff = Features::Debug::engine.subtitlesForcedOff;
							if (ImGui::Checkbox("Subtitles Forced Off", &subtitlesForcedOff))
							{
								if (Features::Debug::engine.reference)
								{
									Features::Debug::engine.subtitlesForcedOff = subtitlesForcedOff;
									Features::Debug::engine.reference->bSubtitlesForcedOff = subtitlesForcedOff;
								}
							}

							ImGui::NewLine();

							bool pauseOnLossOfFocus = Features::Debug::engine.pauseOnLossOfFocus;
							if (ImGui::Checkbox("Pause On Loss Of Focus", &pauseOnLossOfFocus))
							{
								if (Features::Debug::engine.reference)
								{
									Features::Debug::engine.pauseOnLossOfFocus = pauseOnLossOfFocus;
									Features::Debug::engine.reference->bPauseOnLossOfFocus = pauseOnLossOfFocus;
								}
							}
						}
					}

					ImGui::CategorySeparator();

					ImGui::SetFontTitle();
					ImGui::TextBoolPresenceColored("Game Instance:", Features::Debug::gameInstance.reference);
					ImGui::SetFontRegular();
					if (Features::Debug::gameInstance.reference)
					{
						if (ImGui::CollapsingHeader("Details##GameInstance"))
						{
							ImGui::Text("Game Instance Class: %s", Features::Debug::gameInstance.className.c_str());
							ImGui::Text("Game Instance Object: %s", Features::Debug::gameInstance.objectName.c_str());

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Online Session:", Features::Debug::gameInstance.onlineSession.reference);
							ImGui::SetFontRegular();
							if (Features::Debug::gameInstance.onlineSession.reference)
							{
								if (ImGui::TreeNode("Details##OnlineSession"))
								{
									ImGui::Text("Online Session Class: %s", Features::Debug::gameInstance.onlineSession.className.c_str());
									ImGui::Text("Online Session Object: %s", Features::Debug::gameInstance.onlineSession.objectName.c_str());

									ImGui::TreePop();
								}
							}
						}
					}

					ImGui::CategorySeparator();

					ImGui::SetFontTitle();
					ImGui::TextBoolPresenceColored("Game Mode:", Features::Debug::gameMode.reference);
					ImGui::SetFontRegular();
					if (Features::Debug::gameMode.reference)
					{
						if (ImGui::CollapsingHeader("Details##GameMode"))
						{
							ImGui::Text("Game Mode Class: %s", Features::Debug::gameMode.className.c_str());
							ImGui::Text("Game Mode Object: %s", Features::Debug::gameMode.objectName.c_str());

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Game Session:", Features::Debug::gameMode.gameSession.reference);
							ImGui::SetFontRegular();
							if (Features::Debug::gameMode.gameSession.reference)
							{
								if (ImGui::TreeNode("Details##GameSession"))
								{
									ImGui::Text("Game Session Class: %s", Features::Debug::gameMode.gameSession.className.c_str());
									ImGui::Text("Game Session Object: %s", Features::Debug::gameMode.gameSession.objectName.c_str());

									ImGui::NewLine();

									int32_t maxPlayers = Features::Debug::gameMode.gameSession.maxPlayers;
									if (ImGui::InputInt("Max Players", &maxPlayers, 1, 10))
									{
										if (Features::Debug::gameMode.gameSession.reference)
										{
											Features::Debug::gameMode.gameSession.maxPlayers = maxPlayers;
											Features::Debug::gameMode.gameSession.reference->MaxPlayers = maxPlayers;
										}
									}
									int32_t maxSpectators = Features::Debug::gameMode.gameSession.maxSpectators;
									if (ImGui::InputInt("Max Spectators", &maxSpectators, 1, 10))
									{
										if (Features::Debug::gameMode.gameSession.reference)
										{
											Features::Debug::gameMode.gameSession.maxSpectators = maxSpectators;
											Features::Debug::gameMode.gameSession.reference->MaxSpectators = maxSpectators;
										}
									}
									int32_t maxPartySize = Features::Debug::gameMode.gameSession.maxPartySize;
									if (ImGui::InputInt("Max Party Size", &maxPartySize, 1, 10))
									{
										if (Features::Debug::gameMode.gameSession.reference)
										{
											Features::Debug::gameMode.gameSession.maxPartySize = maxPartySize;
											Features::Debug::gameMode.gameSession.reference->MaxPartySize = maxPartySize;
										}
									}
									int32_t maxSplitScreensPerConnection = Features::Debug::gameMode.gameSession.maxSplitScreensPerConnection;
									if (ImGui::InputInt("Max Split Screens Per Connection", &maxSplitScreensPerConnection, 1, 10))
									{
										if (Features::Debug::gameMode.gameSession.reference)
										{
											Features::Debug::gameMode.gameSession.maxSplitScreensPerConnection = maxSplitScreensPerConnection;
											Features::Debug::gameMode.gameSession.reference->MaxSplitscreensPerConnection = maxSplitScreensPerConnection;
										}
									}

									ImGui::NewLine();

									ImGui::ReadOnlyInputText("Session Name:", Features::Debug::gameMode.gameSession.sessionName.c_str(), true);

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							ImGui::TextIntColored("Players Count:", Features::Debug::gameMode.playersCount);
							ImGui::TextIntColored("Spectators Count:", Features::Debug::gameMode.spectatorsCount);

							ImGui::NewLine();

							ImGui::TextBoolColored("Start Players As Spectator:", Features::Debug::gameMode.startPlayersAsSpectators);
							ImGui::ReadOnlyInputText("Default Player Name:", Features::Debug::gameMode.defaultPlayerName.c_str(), true);

							ImGui::NewLine();

							bool useSeamlessTravel = Features::Debug::gameMode.useSeamlessTravel;
							if (ImGui::Checkbox("Use Seamless Travel", &useSeamlessTravel))
							{
								if (Features::Debug::gameMode.reference)
								{
									Features::Debug::gameMode.useSeamlessTravel = useSeamlessTravel;
									Features::Debug::gameMode.reference->bUseSeamlessTravel = useSeamlessTravel;
								}
							}
							bool isPausable = Features::Debug::gameMode.isPausable;
							if (ImGui::Checkbox("Is Pausable", &isPausable))
							{
								if (Features::Debug::gameMode.reference)
								{
									Features::Debug::gameMode.isPausable = isPausable;
									Features::Debug::gameMode.reference->bPauseable = isPausable;
								}
							}

							ImGui::NewLine();

							ImGui::ReadOnlyInputText("Options:", Features::Debug::gameMode.options.c_str(), true);
						}
					}

					ImGui::CategorySeparator();
					
					ImGui::SetFontTitle();
					ImGui::TextBoolPresenceColored("Player Controller:", Features::Debug::playerController.reference);
					ImGui::SetFontRegular();
					if (Features::Debug::playerController.reference)
					{
						if (ImGui::CollapsingHeader("Details##PlayerController"))
						{
							ImGui::Text("Player Controller Class: %s", Features::Debug::playerController.className.c_str());
							ImGui::Text("Player Controller Object: %s", Features::Debug::playerController.objectName.c_str());

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Pawn:", Features::Debug::playerController.pawn.reference);
							ImGui::SetFontRegular();
							if (Features::Debug::playerController.pawn.reference)
							{
								if (ImGui::TreeNode("Details##Pawn"))
								{
									ImGui::Text("Pawn Class: %s", Features::Debug::playerController.pawn.className.c_str());
									ImGui::Text("Pawn Object: %s", Features::Debug::playerController.pawn.objectName.c_str());
									ImGui::TextVectorColored("Location:", Features::Debug::playerController.pawn.location);
									ImGui::TextRotatorColored("Rotation:", Features::Debug::playerController.pawn.rotation);
									ImGui::TextVectorColored("Scale:", Features::Debug::playerController.pawn.scale);

									ImGui::NewLine();

									ImGui::TextBoolColored("Is Controlled:", Features::Debug::playerController.pawn.isControlled);
									ImGui::TextBoolColored("Is Pawn Controlled:", Features::Debug::playerController.pawn.isPawnControlled);
									ImGui::TextBoolColored("Is Player Controlled:", Features::Debug::playerController.pawn.isPlayerControlled);
									ImGui::TextBoolColored("Is Locally Controlled:", Features::Debug::playerController.pawn.isLocallyControlled);
									ImGui::TextBoolColored("Is Bot Controlled:", Features::Debug::playerController.pawn.isBotControlled);

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Camera Manager:", Features::Debug::playerController.cameraManager.reference);
							ImGui::SetFontRegular();
							if (Features::Debug::playerController.cameraManager.reference)
							{
								if (ImGui::TreeNode("Details##CameraManager"))
								{
									ImGui::Text("Camera Manager Class: %s", Features::Debug::playerController.cameraManager.className.c_str());
									ImGui::Text("Camera Manager Object: %s", Features::Debug::playerController.cameraManager.objectName.c_str());
									ImGui::TextVectorColored("Location:", Features::Debug::playerController.cameraManager.location);
									ImGui::TextRotatorColored("Rotation:", Features::Debug::playerController.cameraManager.rotation);
									ImGui::TextVectorColored("Scale:", Features::Debug::playerController.cameraManager.scale);

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Cheat Manager:", Features::Debug::playerController.cheatManager.reference);
							ImGui::SetFontRegular();
							if (Features::Debug::playerController.cheatManager.reference)
							{
								if (ImGui::TreeNode("Details##CheatManager"))
								{
									ImGui::Text("Cheat Manager Class: %s", Features::Debug::playerController.cheatManager.className.c_str());
									ImGui::Text("Cheat Manager Object: %s", Features::Debug::playerController.cheatManager.objectName.c_str());

									ImGui::TreePop();
								}
							}
							else
							{
								if (ImGui::Button("Construct Cheat Manager"))
								{
									bool wasConstructed = Unreal::CheatManager::Construct();
									if (wasConstructed) // Only gather debug information if we're aware of changes.
										Features::Debug::Update();

									PlayActionSound(wasConstructed);
								}
							}
						}
					}

					ImGui::CategorySeparator();

					ImGui::SetFontTitle();
					ImGui::TextBoolPresenceColored("World:", Features::Debug::world.reference);
					ImGui::SetFontRegular();
					if (Features::Debug::world.reference)
					{
						if (ImGui::CollapsingHeader("Details##World"))
						{
							ImGui::Text("World Class: %s", Features::Debug::world.className.c_str());
							ImGui::Text("World Object: %s", Features::Debug::world.objectName.c_str());

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Game State:", Features::Debug::world.gameState.reference);
							ImGui::SetFontRegular();
							if (Features::Debug::world.gameState.reference)
							{
								if (ImGui::TreeNode("Details##GameState"))
								{
									ImGui::Text("Game State Class: %s", Features::Debug::world.gameState.className.c_str());
									ImGui::Text("Game State Object: %s", Features::Debug::world.gameState.objectName.c_str());

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Net Driver:", Features::Debug::world.netDriver.reference);
							ImGui::SetFontRegular();
							if (Features::Debug::world.netDriver.reference)
							{
								if (ImGui::TreeNode("Details##NetDriver"))
								{
									ImGui::Text("Net Driver Class: %s", Features::Debug::world.netDriver.className.c_str());
									ImGui::Text("Net Driver Object: %s", Features::Debug::world.netDriver.objectName.c_str());

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Demo Net Driver:", Features::Debug::world.demoNetDriver.reference);
							ImGui::SetFontRegular();
							if (Features::Debug::world.demoNetDriver.reference)
							{
								if (ImGui::TreeNode("Details##DemoNetDriver"))
								{
									ImGui::Text("Demo Net Driver Class: %s", Features::Debug::world.demoNetDriver.className.c_str());
									ImGui::Text("Demo Net Driver Object: %s", Features::Debug::world.demoNetDriver.objectName.c_str());

									ImGui::TreePop();
								}
							}

							ImGui::NewLine();

							ImGui::SetFontTitle();
							ImGui::TextBoolPresenceColored("Persistent Level:", Features::Debug::world.persistentLevel.reference);
							ImGui::SetFontRegular();
							if (Features::Debug::world.persistentLevel.reference)
							{
								if (ImGui::TreeNode("Details##PersistentLevel"))
								{
									ImGui::Text("Persistent Level Class: %s", Features::Debug::world.persistentLevel.className.c_str());
									ImGui::Text("Persistent Level Object: %s", Features::Debug::world.persistentLevel.objectName.c_str());
									ImGui::TextBoolColored("Is Visible:", Features::Debug::world.persistentLevel.isVisible);

									ImGui::NewLine();

									bool worldSettingsPresent = Features::Debug::world.persistentLevel.worldSettings.reference;
									ImGui::TextBoolPresenceColored("World Settings:", worldSettingsPresent);
									if (worldSettingsPresent)
									{
										if (ImGui::TreeNode("World Settings"))
										{
											ImGui::Text("World Settings Class: %s", Features::Debug::world.persistentLevel.worldSettings.className.c_str());
											ImGui::Text("World Settings Object: %s", Features::Debug::world.persistentLevel.worldSettings.objectName.c_str());

											ImGui::NewLine();

											ImGui::TextBoolColored("High Priority Loading:", Features::Debug::world.persistentLevel.worldSettings.highPriorityLoading);
											ImGui::TextBoolColored("Local High Priority Loading:", Features::Debug::world.persistentLevel.worldSettings.localHighPriorityLoading);

											ImGui::NewLine();

											ImGui::TextFloat("Unreal Units = 1m:", Features::Debug::world.persistentLevel.worldSettings.unitsToMeters);

											ImGui::TreePop();
										}
									}

									ImGui::NewLine();

									bool areStreamingLevelsPresent = Features::Debug::world.streamingLevels.size() > 0;
									ImGui::TextBoolMultiplePresenceColored("Streaming Levels:", areStreamingLevelsPresent);
									if (areStreamingLevelsPresent)
									{
										if (ImGui::TreeNode("Streaming Levels"))
										{
											for (Unreal::LevelStreaming::DataStructure streamingLevel : Features::Debug::world.streamingLevels)
											{
												ImVec4 levelColor
												{
													streamingLevel.levelColor.R,
													streamingLevel.levelColor.G,
													streamingLevel.levelColor.B,
													streamingLevel.levelColor.A
												};

												ImGui::PushStyleColor(ImGuiCol_Text, levelColor);
												bool isTreeNodeOpen = ImGui::TreeNode(streamingLevel.levelPath.c_str());
												ImGui::PopStyleColor();

												if (isTreeNodeOpen)
												{
													bool isLevelLoaded = streamingLevel.level.reference;

													ImGui::TextBoolColored("Is Loaded:", isLevelLoaded);
													ImGui::SameLine();
													ImGui::Spacing();
													ImGui::SameLine();
													if (ImGui::Button(isLevelLoaded ? "Unload" : "Load"))
													{
														if (streamingLevel.reference != nullptr)
														{
															streamingLevel.reference->SetShouldBeLoaded(!isLevelLoaded);
															PlayActionSound(true);
														}
														else
															PlayActionSound(false);
													}

													ImGui::TextBoolColored("Is Visible:", streamingLevel.level.isVisible);
													ImGui::SameLine();
													ImGui::Spacing();
													ImGui::SameLine();
													ImGui::BeginDisabled(isLevelLoaded == false);
													if (ImGui::Button(streamingLevel.level.isVisible ? "Hide" : "Show"))
													{
														if (isLevelLoaded && streamingLevel.reference != nullptr)
														{
															streamingLevel.reference->SetShouldBeVisible(!streamingLevel.level.isVisible);
															PlayActionSound(true);
														}
														else
															PlayActionSound(false);
													}
													ImGui::EndDisabled();

													ImGui::NewLine();

													bool worldSettingsPresent = streamingLevel.level.worldSettings.reference;
													ImGui::TextBoolPresence("World Settings:", worldSettingsPresent);
													if (worldSettingsPresent)
													{
														if (ImGui::TreeNode("World Settings"))
														{
															ImGui::Text("World Settings Class: %s", streamingLevel.level.worldSettings.className.c_str());
															ImGui::Text("World Settings Object: %s", streamingLevel.level.worldSettings.objectName.c_str());

															ImGui::NewLine();

															ImGui::TextBoolColored("High Priority Loading:", streamingLevel.level.worldSettings.highPriorityLoading);
															ImGui::TextBoolColored("Local High Priority Loading:", streamingLevel.level.worldSettings.localHighPriorityLoading);

															ImGui::NewLine();

															ImGui::TextFloat("Unreal Units = 1m:", streamingLevel.level.worldSettings.unitsToMeters);

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

									ImGui::TextFloatColored("Game Time (In Seconds):", Features::Debug::world.gameTimeInSeconds);

									ImGui::NewLine();

									ImGui::TextBoolColored("Is Server:", Features::Debug::world.isServer);
									ImGui::TextBoolColored("Is Dedicated Server:", Features::Debug::world.isDedicatedServer);
									ImGui::TextBoolColored("Is Split Screen:", Features::Debug::world.isSplitScreen);
									ImGui::TextBoolColored("Is Standalone:", Features::Debug::world.isStandalone);

									ImGui::TreePop();
								}
							}
						}
					}

					ImGui::CategorySeparator();

					ImGui::SetFontTitle();
					ImGui::Text("Actors");
					ImGui::SetFontRegular();
					if (ImGui::CollapsingHeader("Details##Actors"))
					{
#ifdef ACTOR_TRACE
						ImGui::SetFontTitle();
						ImGui::Text("Actor Trace");
						ImGui::SetFontSmall();
						ImGui::Text("Performs a trace starting at the camera's position and outputs the name of the Actor hit by the trace.");
						ImGui::Text("X - Location at where trace has hit an Actor.");
						ImGui::Text("@ - Location at where trace has ended without a hit.");
						ImGui::Text("O - Location at where trace has started.");
						ImGui::SetFontRegular();
						ImGui::Checkbox("Enabled##ActorTrace", &Features::ActorTrace::enabled);
						ImGui::BeginDisabled(Features::ActorTrace::enabled == false);
						if (ImGui::TreeNode("Settings##ActorTrace"))
						{
							ImGui::KeyBindingInput("Key Binding:", &Keybindings::debug_ActorTrace);

							ImGui::NewLine();

							ImGui::Checkbox("Show On Screen##ActorTrace", &Features::ActorTrace::showOnScreen);
							ImGui::Checkbox("Show Line Trace##ActorTrace", &Features::ActorTrace::showLineTrace);

							ImGui::NewLine();

							ImGui::ColorPicker4("Trace Color", Features::ActorTrace::traceColor);
							ImGui::InputFloat("Trace Thickness", &Features::ActorTrace::traceThickness, 0.1f, 1.0f);
							ImGui::InputFloat("Trace Length", &Features::ActorTrace::traceLength, 1.0f, 10.0f);

							ImGui::TreePop();
						}
						ImGui::EndDisabled();

						ImGui::NewLine();
#endif

						if (ImGui::Button("Update##Actors"))
						{
							Features::ActorsList::Update();
							PlayActionSound(true);
						}
						ImGui::SameLine();
						ImGui::Spacing();
						ImGui::SameLine();
						ImGui::InputText("Search Filter", Features::ActorsList::filterBuffer, Features::ActorsList::filterBufferSize);
						size_t filterLength = strlen(Features::ActorsList::filterBuffer);
						ImGui::SameLine();
						ImGui::Spacing();
						ImGui::SameLine();
						ImGui::Checkbox("Case Sensitive", &Features::ActorsList::filterCaseSensitive);

						ImGui::NewLine();

						for (Unreal::Actor::DataStructure& actor : Features::ActorsList::actors) // <-- Reference!
						{
							bool outputToUserInterface = filterLength == 0;

							if (outputToUserInterface == false)
							{
								if (Features::ActorsList::filterCaseSensitive)
									outputToUserInterface = actor.objectName.find(Features::ActorsList::filterBuffer) != std::string::npos;
								else
								{
									std::string actorObjectLower = actor.objectName;
									std::string filterLower = Features::ActorsList::filterBuffer;

									std::transform(actorObjectLower.begin(), actorObjectLower.end(), actorObjectLower.begin(),
										[](unsigned char c) { return std::tolower(c); });
									std::transform(filterLower.begin(), filterLower.end(), filterLower.begin(),
										[](unsigned char c) { return std::tolower(c); });

									outputToUserInterface = actorObjectLower.find(filterLower) != std::string::npos;
								}
							}

							if (outputToUserInterface)
							{
								if (ImGui::TreeNode(actor.objectName.c_str()))
								{
									ImGui::PushID(actor.objectName.c_str());

									ImGui::Text("Actor Class: %s", actor.className.c_str());
									ImGui::Text("Actor Object: %s", actor.objectName.c_str());

									float actorLocation[3] = { actor.location.X, actor.location.Y, actor.location.Z };
									ImGui::Text("Location:");
									ImGui::SameLine();
									if (ImGui::InputFloat3("##Location", actorLocation))
										actor.location = SDK::FVector(actorLocation[0], actorLocation[1], actorLocation[2]);
									ImGui::SameLine();
									if (ImGui::Button("Set##Location"))
									{
										if (actor.reference)
										{
											actor.reference->K2_TeleportTo(actor.location, actor.reference->K2_GetActorRotation());
											PlayActionSound(true);
										}
										else
											PlayActionSound(false);
									}

									float actorRotation[3] = { actor.rotation.Pitch, actor.rotation.Yaw, actor.rotation.Roll };
									ImGui::Text("Rotation:");
									ImGui::SameLine();
									if (ImGui::InputFloat3("##Rotation", actorRotation))
										actor.rotation = SDK::FRotator(actorRotation[0], actorRotation[1], actorRotation[2]);
									ImGui::SameLine();
									if (ImGui::Button("Set##Rotation"))
									{
										if (actor.reference)
										{
											actor.reference->K2_TeleportTo(actor.reference->K2_GetActorLocation(), actor.rotation);
											PlayActionSound(true);
										}
										else
											PlayActionSound(false);
									}

									float actorScale[3] = { actor.scale.X, actor.scale.Y, actor.scale.Z };
									ImGui::Text("Scale:   ");
									ImGui::SameLine();
									if (ImGui::InputFloat3("##Scale", actorScale))
										actor.scale = SDK::FVector(actorScale[0], actorScale[1], actorScale[2]);
									ImGui::SameLine();
									if (ImGui::Button("Set##Scale"))
									{
										if (actor.reference)
										{
											actor.reference->SetActorScale3D(actor.scale);
											PlayActionSound(true);
										}
										else
											PlayActionSound(false);
									}

									ImGui::Text("         ");
									ImGui::SameLine();
									if (ImGui::Button("Static"))
									{
										if (actor.reference && actor.reference->RootComponent)
										{
											actor.reference->RootComponent->Mobility = SDK::EComponentMobility::Static;
											PlayActionSound(true);
										}
										else
											PlayActionSound(false);
									}
									ImGui::SameLine();
									if (ImGui::Button("Stationary"))
									{
										if (actor.reference && actor.reference->RootComponent)
										{
											actor.reference->RootComponent->Mobility = SDK::EComponentMobility::Stationary;
											PlayActionSound(true);
										}
										else
											PlayActionSound(false);
									}
									ImGui::SameLine();
									if (ImGui::Button("Movable"))
									{
										if (actor.reference && actor.reference->RootComponent)
										{
											actor.reference->RootComponent->Mobility = SDK::EComponentMobility::Movable;
											PlayActionSound(true);
										}
										else
											PlayActionSound(false);
									}

									ImGui::Text("         ");
									ImGui::SameLine();
									if (ImGui::Button("Set Visible"))
									{
										if (actor.reference)
										{
											actor.reference->SetActorHiddenInGame(false);
											PlayActionSound(true);
										}
										else
											PlayActionSound(false);
									}
									ImGui::SameLine();
									if (ImGui::Button("Set Hidden"))
									{
										if (actor.reference)
										{
											actor.reference->SetActorHiddenInGame(true);
											PlayActionSound(true);
										}
										else
											PlayActionSound(false);
									}

									ImGui::NewLine();

									ImGui::SetFontTitle();
									ImGui::Text("Components");
									ImGui::SetFontRegular();
									if (ImGui::TreeNode("Details##Components"))
									{
										
										ImGui::InputText("Search Filter", Features::ActorsList::componentsFilterBuffer, Features::ActorsList::componentsFilterBufferSize);
										size_t componentsFilterLength = strlen(Features::ActorsList::componentsFilterBuffer);
										ImGui::SameLine();
										ImGui::Spacing();
										ImGui::SameLine();
										ImGui::Checkbox("Case Sensitive", &Features::ActorsList::componentsFilterCaseSensitive);

										ImGui::NewLine();

										for (Unreal::ActorComponent::DataStructure& component : actor.components) // <-- Reference!
										{
											bool componentOutputToUserInterface = componentsFilterLength == 0;

											if (componentOutputToUserInterface == false)
											{
												if (Features::ActorsList::componentsFilterCaseSensitive)
													componentOutputToUserInterface = component.objectName.find(Features::ActorsList::componentsFilterBuffer) != std::string::npos;
												else
												{
													std::string componentObjectLower = component.objectName;
													std::string componentFilterLower = Features::ActorsList::componentsFilterBuffer;

													std::transform(componentObjectLower.begin(), componentObjectLower.end(), componentObjectLower.begin(),
														[](unsigned char c) { return std::tolower(c); });
													std::transform(componentFilterLower.begin(), componentFilterLower.end(), componentFilterLower.begin(),
														[](unsigned char c) { return std::tolower(c); });

													componentOutputToUserInterface = componentObjectLower.find(componentFilterLower) != std::string::npos;
												}
											}

											if (componentOutputToUserInterface)
											{
												if (ImGui::TreeNode(component.objectName.c_str()))
												{
													ImGui::Text("Component Class: %s", component.className.c_str());
													ImGui::Text("Component Object: %s", component.objectName.c_str());

													ImGui::NewLine();

													ImGui::TextBoolColored("Is Active:", component.isActive);
													ImGui::TextBoolColored("Auto Activate:", component.autoActivate);
													ImGui::TextBoolColored("Editor Only:", component.editorOnly);
													if (ImGui::Button("Activate"))
													{
														if (component.reference)
														{
															component.reference->Activate(false);
															component.isActive = true;
															PlayActionSound(true);
														}
														else
															PlayActionSound(false);
													}
													ImGui::SameLine();
													if (ImGui::Button("Reset"))
													{
														if (component.reference)
														{
															component.reference->Activate(true);
															component.isActive = true;
															PlayActionSound(true);
														}
														else
															PlayActionSound(false);
													}
													ImGui::SameLine();
													if (ImGui::Button("Deactivate"))
													{
														if (component.reference)
														{
															component.reference->Deactivate();
															component.isActive = false;
															PlayActionSound(true);
														}
														else
															PlayActionSound(false);
													}

													ImGui::NewLine();

													ImGui::TextBoolColored("Net Addressible:", component.netAddressible);
													ImGui::TextBoolColored("Replicates:", component.replicates);

													ImGui::NewLine();

													ImGui::Text("Creation Method: %d", component.creationMethod);

													ImGui::TreePop();
												}
											}
										}

										ImGui::TreePop();
									}

									ImGui::PopID();
									ImGui::TreePop();
								}
							}
						}
					}

					ImGui::CategorySeparator();

					if (Features::Debug::wasProjectNameObtained)
						ImGui::Text("Project Name: %s", Features::Debug::projectName.c_str());

					if (Features::Debug::wasProjectPlatformObtained)
						ImGui::Text("Project Platform: %s", Features::Debug::projectPlatform.c_str());

					if (Features::Debug::wasUsernameObtained)
						ImGui::Text("Username: %s", Features::Debug::username.c_str());

					if (Features::Debug::wasCommandLineObtained)
					{
						ImGui::ReadOnlyInputText("Command Line:", Features::Debug::commandLine.c_str(), true);
					}

					ImGui::MenuSpacer();
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

							ImGui::CategorySeparator();

							ImGui::InputFloat("Minimum Time Dilation", &worldSettings->MinGlobalTimeDilation, 0.1, 1.0);
							ImGui::InputFloat("Maximum Time Dilation", &worldSettings->MaxGlobalTimeDilation, 0.1, 1.0);
							double timeDilation = worldSettings->TimeDilation;
							ImGui::InputDouble("Time Dilation", &timeDilation, 0.1, 1.0);
							worldSettings->TimeDilation = std::clamp(timeDilation, (double)worldSettings->MinGlobalTimeDilation, (double)worldSettings->MaxGlobalTimeDilation);

							ImGui::NewLine();

							ImGui::InputFloat("Demo Time Dilation", &worldSettings->DemoPlayTimeDilation, 0.1, 1.0);

							ImGui::CategorySeparator();

							bool enableAISystem = worldSettings->bEnableAISystem == 1;
							ImGui::Checkbox("Enable AI System", &enableAISystem);
							worldSettings->bEnableAISystem = enableAISystem ? 1 : 0;

							bool enableNavigationSystem = worldSettings->bEnableNavigationSystem == 1;
							ImGui::Checkbox("Enable Navigation System", &enableNavigationSystem);
							worldSettings->bEnableNavigationSystem = enableNavigationSystem ? 1 : 0;

							ImGui::CategorySeparator();

							ImGui::InputFloat("KillZ", &worldSettings->KillZ, 0.1, 1.0);

							ImGui::MenuSpacer();
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




			SDK::APlayerController* playerController = Unreal::PlayerController::Get();
			SDK::ACharacter* character = playerController ? playerController->Character : nullptr;
			SDK::UCharacterMovementComponent* movementComponent = (character && character->CharacterMovement) ? character->CharacterMovement : nullptr;

			bool characterObtained = playerController && character && movementComponent;
			ImGui::BeginDisabled(characterObtained == false);
			if (ImGui::BeginMenu("Character"))
			{
				if (characterObtained)
				{
					ImGui::Text("Character: %s", character->GetFullName().c_str());
					SDK::FVector characterLocation = character->K2_GetActorLocation();
					ImGui::TextVectorColored("Location:", characterLocation);
					SDK::FRotator characterRotation = character->K2_GetActorRotation();
					ImGui::TextRotatorColored("Rotation:", characterRotation);

					ImGui::NewLine();

					ImGui::SetFontTitle();
					ImGui::Text("Movement");
					ImGui::SetFontRegular();
					if (ImGui::TreeNode("Details##CharacterMovement"))
					{
						if (movementComponent->bCheatFlying)
							ImGui::Text("Character Is In %s Mode", character->bActorEnableCollision ? "Fly" : "Ghost");
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
						
						ImGui::NewLine();

						/* 0 corresponds for default vertical size. */
						static const ImVec2 buttonSize = { 128.0f, 0.0f };

						if (ImGui::Button("Ghost", buttonSize))
						{
							Features::CharacterMovement::Ghost();
						}
						ImGui::SameLine();
						if (ImGui::Button("Fly", buttonSize))
						{
							Features::CharacterMovement::Fly();
						}
						ImGui::SameLine();
						if (ImGui::Button("Walk", buttonSize))
						{
							Features::CharacterMovement::Walk();
						}

						ImGui::NewLine();

						ImGui::KeyBindingInput("Ghost Key Binding:##Ghost", &Keybindings::characterMovement_Ghost);
						ImGui::KeyBindingInput("Fly Key Binding:  ##Fly", &Keybindings::characterMovement_Fly);
						ImGui::KeyBindingInput("Walk Key Binding: ##Walk", &Keybindings::characterMovement_Walk);

						ImGui::NewLine();

						ImGui::SetFontTitle();
						ImGui::Text("Directional Movement");
						ImGui::SetFontSmall();
						ImGui::Text("When the character is Flying or in Ghost mode, moving forward teleports them in the direction the camera is facing,");
						ImGui::Text("allowing for quick and easy navigation through the world.");
						ImGui::SetFontRegular();
						ImGui::BeginDisabled(movementComponent->bCheatFlying == false);
						if (ImGui::TreeNode("Settings##DirectionalMovement"))
						{
							if (ImGui::Checkbox("Enabled##DirectionalMovement", &Features::DirectionalMovement::enabled))
							{
								if (Features::DirectionalMovement::enabled)
									Features::DirectionalMovement::StartThread();
								else
									Features::DirectionalMovement::InvalidateThread();
							}
							ImGui::InputDouble("Movement Step##DirectionalMovement", &Features::DirectionalMovement::step, 0.1, 1.0);
							if (ImGui::InputDouble("Movement Delay##DirectionalMovement", &Features::DirectionalMovement::delay, 0.01, 0.1))
							{
								if (Features::DirectionalMovement::delay < 0.001)
									Features::DirectionalMovement::delay = 0.001;
							}

							ImGui::TreePop();
						}
						ImGui::EndDisabled();

						ImGui::CategorySeparator();

						ImGui::InputFloat("Gravity Scale:", &movementComponent->GravityScale, 0.1f, 1.0f);

						ImGui::NewLine();

						ImGui::InputFloat("Max Acceleration", &movementComponent->MaxAcceleration, 1.0f, 10.0f);
						ImGui::InputFloat("Max Step Height", &movementComponent->MaxStepHeight, 1.0f, 10.0f);
						ImGui::InputFloat("Weight", &movementComponent->Mass, 1.0f, 10.0f);

						ImGui::NewLine();

						ImGui::InputFloat("Max Walk Speed", &movementComponent->MaxWalkSpeed, 1.0f, 10.0f);
						ImGui::InputFloat("Max Crouch Speed", &movementComponent->MaxWalkSpeedCrouched, 1.0f, 10.0f);
						ImGui::InputFloat("Max Swim Speed", &movementComponent->MaxSwimSpeed, 1.0f, 10.0f);
						ImGui::InputFloat("Max Fly Speed", &movementComponent->MaxFlySpeed, 1.0f, 10.0f);
						ImGui::InputFloat("Max Custom Movement Speed", &movementComponent->MaxCustomMovementSpeed, 1.0f, 10.0f);

						ImGui::NewLine();

						ImGui::TextFloatColored("Walkable Floor Z:", movementComponent->WalkableFloorZ);

						ImGui::CategorySeparator();

						if (ImGui::Button("Jump"))
						{
							Features::CharacterMovement::Jump();
						}
						ImGui::InputInt("Jump Limit", &character->JumpMaxCount, 1, 1);
						ImGui::InputFloat("Jump Height", &movementComponent->JumpZVelocity, 0.1, 1.0);
						ImGui::KeyBindingInput("Jump Key Binding:##Jump", &Keybindings::characterMovement_Jump);

						ImGui::NewLine();

						if (ImGui::Button("Launch"))
						{
							Features::CharacterMovement::Launch();
						}
						ImGui::InputFloat3("Launch Velocity", Features::CharacterMovement::launchVelocity);
						ImGui::KeyBindingInput("Launch Key Binding:##Launch", &Keybindings::characterMovement_Launch);

						ImGui::NewLine();

						if (ImGui::Button("Dash"))
						{
							Features::CharacterMovement::Dash();
						}
						ImGui::InputDouble("Dash Strength", &Features::CharacterMovement::dashStrength, 0.1, 1.0);
						ImGui::KeyBindingInput("Dash Key Binding:##Dash", &Keybindings::characterMovement_Dash);

						ImGui::TreePop();
					}

					ImGui::CategorySeparator();

					SDK::APlayerCameraManager* cameraManager = playerController->PlayerCameraManager;
					ImGui::SetFontTitle();
					ImGui::Text("Camera");
					ImGui::SetFontRegular();
					ImGui::BeginDisabled(cameraManager == nullptr);
					if (ImGui::TreeNode("Details##Camera"))
					{
						if (cameraManager)
						{
							/* 0 corresponds for default vertical size. */
							static const ImVec2 buttonSize = { 204.0f, 0.0f };

							if (ImGui::Button("Start Fade", buttonSize))
							{
								Features::Camera::StartFade();
							}
							ImGui::SameLine();
							if (ImGui::Button("Stop Fade", buttonSize))
							{
								Features::Camera::StopFade();
							}

							if (ImGui::InputFloat("Fade From Alpha", &Features::Camera::fadeFromAlpha, 0.01f, 0.1f))
							{
								if (Features::Camera::fadeFromAlpha < 0.0f)
									Features::Camera::fadeFromAlpha = 0.0f;

								if (Features::Camera::fadeFromAlpha > 1.0f)
									Features::Camera::fadeFromAlpha = 1.0f;
							}

							if (ImGui::InputFloat("Fade To Alpha", &Features::Camera::fadeToAlpha, 0.01f, 0.1f))
							{
								if (Features::Camera::fadeToAlpha < 0.0f)
									Features::Camera::fadeToAlpha = 0.0f;

								if (Features::Camera::fadeToAlpha > 1.0f)
									Features::Camera::fadeToAlpha = 1.0f;
							}

							ImGui::InputFloat("Fade Duration", &Features::Camera::fadeDuration, 0.1f, 1.0f);
							ImGui::ColorPicker4("Fade Color", Features::Camera::fadeColor);

							ImGui::NewLine();

							ImGui::Checkbox("Fade Audio", &Features::Camera::fadeAudio);
							ImGui::Checkbox("Fade Persistent", &Features::Camera::fadePersistent);

							ImGui::NewLine();

							ImGui::KeyBindingInput("Start Fade Key Binding:", &Keybindings::characterCamera_StartFade);
							ImGui::KeyBindingInput("Stop Fade Key Binding:", &Keybindings::characterCamera_StopFade);
						}
						else
							ImGui::Text("Camera Manager Doesn't Exist!");

						ImGui::TreePop();
					}
					ImGui::EndDisabled();

					ImGui::MenuSpacer();
				}
				else
				{
					if (playerController == nullptr)
						ImGui::Text("Player Controller Doesn't Exist!");
					else if (character == nullptr)
						ImGui::Text("Character Doesn't Exist!");
					else if (movementComponent == nullptr)
						ImGui::Text("Movement Component Doesn't Exist!");
					else
						ImGui::Text("Something Went Wrong.");
				}

				ImGui::EndMenu();
			}
			ImGui::EndDisabled();




			ImGui::EndMainMenuBar();
		}
	}


#ifdef ACTOR_TRACE
	if (Features::ActorTrace::enabled)
	{
		if (Features::ActorTrace::showOnScreen)
		{
			const char* labelText = Features::ActorTrace::traceHit ? Features::ActorTrace::actor.objectName.c_str() : "No Actor Traced";
			ImVec2 labelSize = ImGui::CalcTextSize(labelText);

			ImVec2 labelPosition = ImVec2
			(
				/*
					Horizontal: ImGui Viewport center;
					Vertical: ImGui Viewport bottom - 12 pixels.

					Flooring the values allows to avoid potential subpixel conflicts.
				*/
				floorf(iViewPortPosition.x + (iViewPortSize.x - labelSize.x) * 0.5f),
				floorf(iViewPortSize.y - labelSize.y - 12.0f)
			);

			iDrawList->AddText(labelPosition, ImGui::GetColorU32(ImGuiCol_Text), labelText);
		}
		
		if (Features::ActorTrace::showLineTrace)
		{
			SDK::FVector2D screenStartPosition;
			SDK::FVector2D screenEndPosition;

			/* UGameplayStatics::ProjectWorldToScreen() verify Player Controller reference within its code. */
			SDK::APlayerController* playerController = Unreal::PlayerController::Get();
			bool startPositionProjected = SDK::UGameplayStatics::ProjectWorldToScreen(playerController, Features::ActorTrace::traceStartLocation, &screenStartPosition, false);
			bool endPositionProjected = SDK::UGameplayStatics::ProjectWorldToScreen(playerController, Features::ActorTrace::traceEndLocation, &screenEndPosition, false);

			/* Inverse Normalize RGBA values set by color picker. */
			ImU32 color = ImGui::ColorConvertFloat4ToU32(ImVec4(Features::ActorTrace::traceColor[0], Features::ActorTrace::traceColor[1], Features::ActorTrace::traceColor[2], Features::ActorTrace::traceColor[3]));

			static float traceStartCircleRadius;
			if (startPositionProjected)
				traceStartCircleRadius = Features::ActorTrace::traceThickness * 1.5f;

			static float traceEndCircleRadius;
			static float traceCrossSize;
			if (endPositionProjected)
			{
				traceEndCircleRadius = Features::ActorTrace::traceThickness * 1.75f;
				traceCrossSize = 8.0f + (Features::ActorTrace::traceThickness * 0.5f);
			}

			/* Both start and end position are within player view. */
			if (startPositionProjected && endPositionProjected)
			{
				ImVec2 startPosition = { screenStartPosition.X, screenStartPosition.Y };
				ImVec2 endPosition = { screenEndPosition.X, screenEndPosition.Y };

				/* Draw the trace. */
				iDrawList->AddLine(startPosition, endPosition, color, Features::ActorTrace::traceThickness);

				/* Draw a hollow circle to mark position where trace was sent from. */
				iDrawList->AddCircle(startPosition, traceStartCircleRadius, color);

				/*
					If trace has hit something, draw a cross to mark position where the trace hit;
					Otherwise draw a filled circle to mark position where the trace ends.
				*/
				if (Features::ActorTrace::traceHit)
				{
					iDrawList->AddLine({ endPosition.x - traceCrossSize, endPosition.y - traceCrossSize }, { endPosition.x + traceCrossSize, endPosition.y + traceCrossSize }, color, Features::ActorTrace::traceThickness);
					iDrawList->AddLine({ endPosition.x - traceCrossSize, endPosition.y + traceCrossSize }, { endPosition.x + traceCrossSize, endPosition.y - traceCrossSize }, color, Features::ActorTrace::traceThickness);
				}
				else
					iDrawList->AddCircleFilled(endPosition, traceEndCircleRadius, color);
			}
			/* Only start position is within player view. */
			else if (startPositionProjected)
			{
				ImVec2 position = { screenStartPosition.X, screenStartPosition.Y };

				iDrawList->AddCircle(position, traceStartCircleRadius, color);
			}
			/* Only end position is within player view. */
			else if (endPositionProjected)
			{
				ImVec2 position = { screenEndPosition.X, screenEndPosition.Y };

				if (Features::ActorTrace::traceHit)
				{
					iDrawList->AddLine({ position.x - traceCrossSize, position.y - traceCrossSize }, { position.x + traceCrossSize, position.y + traceCrossSize }, color, Features::ActorTrace::traceThickness);
					iDrawList->AddLine({ position.x - traceCrossSize, position.y + traceCrossSize }, { position.x + traceCrossSize, position.y - traceCrossSize }, color, Features::ActorTrace::traceThickness);
				}
				else
					iDrawList->AddCircleFilled(position, traceEndCircleRadius, color);
			}
		}
	}
#endif
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

	/* 
		Dedicate sound playback in to separate thread.
		This prevents the main thread from blocking while Beep() is playing the sound.
	*/
	std::thread([=]() 
	{
		Beep(soundFrequency, soundDuration);
	}).detach();
}






// ========================================================
// |            #GUI #SHARED #CALLS #SHAREDCALLS          |
// ========================================================
void Features::Debug::Update()
{
	SDK::UEngine* engine = Unreal::Engine::Get();
	if (Features::Debug::engine.reference = engine)
	{
		Features::Debug::engine.className = engine->Class->GetFullName();
		Features::Debug::engine.objectName = engine->GetFullName();

		Features::Debug::engine.fixedFrameRateEnabled = engine->bUseFixedFrameRate;
		Features::Debug::engine.fixedFrameRate = engine->FixedFrameRate;

		Features::Debug::engine.smoothFrameRateEnabled = engine->bSmoothFrameRate;
		Features::Debug::engine.smoothFrameRateRange = engine->SmoothedFrameRateRange;

		Features::Debug::engine.subtitlesEnabled = engine->bSubtitlesEnabled;
		Features::Debug::engine.subtitlesForcedOff = engine->bSubtitlesForcedOff;

		Features::Debug::engine.pauseOnLossOfFocus = engine->bPauseOnLossOfFocus;

		SDK::UGameViewportClient* viewportClient = engine->GameViewport;
		if (Features::Debug::engine.gameViewportClient.reference = viewportClient)
		{
			Features::Debug::engine.gameViewportClient.className = viewportClient->Class->GetFullName();
			Features::Debug::engine.gameViewportClient.objectName = viewportClient->GetFullName();

			SDK::UConsole* console = viewportClient->ViewportConsole;
			if (Features::Debug::engine.gameViewportClient.console.reference = console)
			{
				Features::Debug::engine.gameViewportClient.console.className = console->Class->GetFullName();
				Features::Debug::engine.gameViewportClient.console.objectName = console->GetFullName();
			}
		}
	}


	SDK::UGameInstance* gameInstance = Unreal::GameInstance::Get();
	if (Features::Debug::gameInstance.reference = gameInstance)
	{
		Features::Debug::gameInstance.className = gameInstance->Class->GetFullName();
		Features::Debug::gameInstance.objectName = gameInstance->GetFullName();

		SDK::UOnlineSession* onlineSession = gameInstance->OnlineSession;
		if (Features::Debug::gameInstance.onlineSession.reference = onlineSession)
		{
			Features::Debug::gameInstance.onlineSession.className = gameInstance->Class->GetFullName();
			Features::Debug::gameInstance.onlineSession.objectName = gameInstance->GetFullName();
		}
	}


	SDK::AGameModeBase* gameMode = Unreal::GameMode::Get();
	if (Features::Debug::gameMode.reference = gameMode)
	{
		Features::Debug::gameMode.className = gameMode->Class->GetFullName();
		Features::Debug::gameMode.objectName = gameMode->GetFullName();

		SDK::AGameSession* gameSession = gameMode->GameSession;
		if (Features::Debug::gameMode.gameSession.reference = gameSession)
		{
			Features::Debug::gameMode.gameSession.className = gameSession->Class->GetFullName();
			Features::Debug::gameMode.gameSession.objectName = gameSession->GetFullName();

			Features::Debug::gameMode.gameSession.maxPlayers = gameSession->MaxPlayers;
			Features::Debug::gameMode.gameSession.maxSpectators = gameSession->MaxSpectators;
			Features::Debug::gameMode.gameSession.maxPartySize = gameSession->MaxPartySize;
			Features::Debug::gameMode.gameSession.maxSplitScreensPerConnection = gameSession->MaxSplitscreensPerConnection;

			Features::Debug::gameMode.gameSession.sessionName = gameSession->SessionName.ToString();
		}

		Features::Debug::gameMode.playersCount = gameMode->GetNumPlayers();
		Features::Debug::gameMode.spectatorsCount = gameMode->GetNumSpectators();

		Features::Debug::gameMode.startPlayersAsSpectators = gameMode->bStartPlayersAsSpectators;
		Features::Debug::gameMode.defaultPlayerName = gameMode->DefaultPlayerName.ToString();

		Features::Debug::gameMode.useSeamlessTravel = gameMode->bUseSeamlessTravel;
		Features::Debug::gameMode.options = gameMode->OptionsString.ToString();
		
		Features::Debug::gameMode.isPausable = gameMode->bPauseable;
	}


	SDK::APlayerController* playerController = Unreal::PlayerController::Get();
	if (Features::Debug::playerController.reference = playerController)
	{
		Features::Debug::playerController.className = playerController->Class->GetFullName();
		Features::Debug::playerController.objectName = playerController->GetFullName();


		SDK::UPlayer* player = playerController->Player;
		if (Features::Debug::playerController.player.reference = player)
		{
			Features::Debug::playerController.player.className = player->Class->GetFullName();
			Features::Debug::playerController.player.objectName = player->GetFullName();
		}


		SDK::APawn* pawn = playerController->AcknowledgedPawn;
		if (Features::Debug::playerController.pawn.reference = pawn)
		{
			Features::Debug::playerController.pawn.className = pawn->Class->GetFullName();
			Features::Debug::playerController.pawn.objectName = pawn->GetFullName();

			SDK::FTransform pawnTransform = pawn->GetTransform();
			Features::Debug::playerController.pawn.location = pawnTransform.Translation;
			Features::Debug::playerController.pawn.rotation = SDK::FRotator(Math::InverseNormalizeAngle(pawnTransform.Rotation.X), Math::InverseNormalizeAngle(pawnTransform.Rotation.Y), Math::InverseNormalizeAngle(pawnTransform.Rotation.Z));
			Features::Debug::playerController.pawn.scale = pawnTransform.Scale3D;

			Features::Debug::playerController.pawn.isControlled = pawn->IsControlled();
			Features::Debug::playerController.pawn.isPawnControlled = pawn->IsPawnControlled();
			Features::Debug::playerController.pawn.isPlayerControlled = pawn->IsPlayerControlled();
			Features::Debug::playerController.pawn.isLocallyControlled = pawn->IsLocallyControlled();
			Features::Debug::playerController.pawn.isBotControlled = pawn->IsBotControlled();
		}


		SDK::APlayerCameraManager* cameraManager = playerController->PlayerCameraManager;
		if (Features::Debug::playerController.cameraManager.reference = cameraManager)
		{
			Features::Debug::playerController.cameraManager.className = cameraManager->Class->GetFullName();
			Features::Debug::playerController.cameraManager.objectName = cameraManager->GetFullName();

			SDK::FTransform cameraManagerTransform = cameraManager->GetTransform();
			Features::Debug::playerController.cameraManager.location = cameraManagerTransform.Translation;
			Features::Debug::playerController.cameraManager.rotation = SDK::FRotator(Math::InverseNormalizeAngle(cameraManagerTransform.Rotation.X), Math::InverseNormalizeAngle(cameraManagerTransform.Rotation.Y), Math::InverseNormalizeAngle(cameraManagerTransform.Rotation.Z));
			Features::Debug::playerController.cameraManager.scale = cameraManagerTransform.Scale3D;
		}


		SDK::UCheatManager* cheatManager = playerController->CheatManager;
		if (Features::Debug::playerController.cheatManager.reference = cheatManager)
		{
			Features::Debug::playerController.cheatManager.className = cheatManager->Class->GetFullName();
			Features::Debug::playerController.cheatManager.objectName = cheatManager->GetFullName();
		}
	}


	SDK::UWorld* world = SDK::UWorld::GetWorld();
	if (Features::Debug::world.reference = world)
	{
		Features::Debug::world.className = world->Class->GetFullName();
		Features::Debug::world.objectName = world->GetFullName();

		if (SDK::AGameStateBase* gameState = world->GameState)
		{
			Features::Debug::world.gameState.reference = gameState;

			Features::Debug::world.gameState.className = gameState->Class->GetFullName();
			Features::Debug::world.gameState.objectName = gameState->GetFullName();
		}

		if (SDK::UNetDriver* netDriver = world->NetDriver)
		{
			Features::Debug::world.netDriver.reference = netDriver;

			Features::Debug::world.netDriver.className = netDriver->Class->GetFullName();
			Features::Debug::world.netDriver.objectName = netDriver->GetFullName();
		}

		if (SDK::UNetDriver* demoNetDriver = world->NetDriver)
		{
			Features::Debug::world.demoNetDriver.reference = demoNetDriver;

			Features::Debug::world.demoNetDriver.className = demoNetDriver->Class->GetFullName();
			Features::Debug::world.demoNetDriver.objectName = demoNetDriver->GetFullName();
		}

		if (SDK::ULevel* persistentLevel = world->PersistentLevel)
		{
			Features::Debug::world.persistentLevel.reference = persistentLevel;

			Features::Debug::world.persistentLevel.className = persistentLevel->Class->GetFullName();
			Features::Debug::world.persistentLevel.objectName = persistentLevel->GetFullName();

			Features::Debug::world.persistentLevel.isVisible = persistentLevel->bIsVisible;

			if (SDK::AWorldSettings* worldSettings = persistentLevel->WorldSettings)
			{
				Features::Debug::world.persistentLevel.worldSettings.reference = worldSettings;
				Features::Debug::world.persistentLevel.worldSettings.className = worldSettings->Class->GetFullName();
				Features::Debug::world.persistentLevel.worldSettings.objectName = worldSettings->GetFullName();

				Features::Debug::world.persistentLevel.worldSettings.highPriorityLoading = worldSettings->bHighPriorityLoading;
				Features::Debug::world.persistentLevel.worldSettings.localHighPriorityLoading = worldSettings->bHighPriorityLoadingLocal;

				Features::Debug::world.persistentLevel.worldSettings.unitsToMeters = worldSettings->WorldToMeters;
			}
		}

		SDK::TArray<SDK::ULevelStreaming*> streamingLevels = world->StreamingLevels;
		if (streamingLevels.Num() > 0)
		{
			Features::Debug::world.streamingLevels.clear();

			for (SDK::ULevelStreaming* streamingLevel : streamingLevels)
			{
				if (streamingLevel == nullptr)
					continue;

#ifdef UE5
				std::string streamingLevelPath = streamingLevel->WorldAsset.ObjectID.AssetPath.AssetName.GetRawString();
#else
				std::string streamingLevelPath = streamingLevel->WorldAsset.ObjectID.AssetPathName.GetRawString();
#endif
				if (streamingLevelPath.empty())
					continue;

				Unreal::LevelStreaming::DataStructure levelStreamingData = {};
				levelStreamingData.reference = streamingLevel;
				levelStreamingData.levelPath = streamingLevelPath;
				levelStreamingData.levelColor = streamingLevel->LevelColor;

				SDK::ULevel* loadedLevel = streamingLevel->LoadedLevel;
				if (levelStreamingData.level.reference = loadedLevel)
				{
					levelStreamingData.level.className = loadedLevel->Class->GetFullName();
					levelStreamingData.level.objectName = loadedLevel->GetFullName();

					levelStreamingData.level.isVisible = loadedLevel->bIsVisible;
					
					SDK::AWorldSettings* worldSettings = loadedLevel->WorldSettings;
					if (levelStreamingData.level.worldSettings.reference = worldSettings)
					{
						levelStreamingData.level.worldSettings.className = worldSettings->Class->GetFullName();
						levelStreamingData.level.worldSettings.objectName = worldSettings->GetFullName();

						levelStreamingData.level.worldSettings.highPriorityLoading = worldSettings->bHighPriorityLoading;
						levelStreamingData.level.worldSettings.localHighPriorityLoading = worldSettings->bHighPriorityLoadingLocal;

						levelStreamingData.level.worldSettings.unitsToMeters = worldSettings->WorldToMeters;
					}
				}

				Features::Debug::world.streamingLevels.push_back(levelStreamingData);
			}
		}

		Features::Debug::world.gameTimeInSeconds = SDK::UKismetSystemLibrary::GetGameTimeInSeconds(world);

		Features::Debug::world.isServer = SDK::UKismetSystemLibrary::IsServer(world);
		Features::Debug::world.isDedicatedServer = SDK::UKismetSystemLibrary::IsDedicatedServer(world);
		Features::Debug::world.isSplitScreen = SDK::UKismetSystemLibrary::IsSplitScreen(world);
		Features::Debug::world.isStandalone = SDK::UKismetSystemLibrary::IsStandalone(world);
	}


	if (Features::Debug::wasProjectNameObtained == false)
	{
		std::string projectName = SDK::UKismetSystemLibrary::GetGameName().ToString();
		if (projectName.empty() == false)
		{
			Features::Debug::projectName = projectName;
			Features::Debug::wasProjectNameObtained = true;
		}
	}


	if (Features::Debug::wasProjectPlatformObtained == false)
	{
		std::string projectPlatform = SDK::UGameplayStatics::GetPlatformName().ToString();
		if (projectPlatform.empty() == false)
		{
			Features::Debug::projectPlatform = projectPlatform;
			Features::Debug::wasProjectPlatformObtained = true;
		}
	}


	if (Features::Debug::wasProjectEngineVersionObtained == false)
	{
		std::string engineVersion = SDK::UKismetSystemLibrary::GetEngineVersion().ToString();
		if (engineVersion.empty() == false)
		{
			Features::Debug::projectEngineVersion = engineVersion;
			Features::Debug::wasProjectEngineVersionObtained = true;
		}
	}


	if (Features::Debug::wasUsernameObtained == false)
	{
		std::string username = SDK::UKismetSystemLibrary::GetPlatformUserName().ToString();
		if (username.empty() == false)
		{
			Features::Debug::username = username;
			Features::Debug::wasUsernameObtained = true;
		}
	}


	if (Features::Debug::wasCommandLineObtained == false)
	{
		LPWSTR lCommandLine = GetCommandLineW();
		std::wstring wCommandLine = std::wstring(lCommandLine);
		std::string commandLine = std::string(wCommandLine.begin(), wCommandLine.end());

		Features::Debug::commandLine = commandLine;
		Features::Debug::wasCommandLineObtained = true;
	}


	Features::Debug::lastUpdateTime = ImGui::GetTime();
}




void Features::ActorsList::Update()
{
	Features::ActorsList::actors.clear();

	int32_t objectsNum = SDK::UObject::GObjects->Num();
	for (int i = 0; i < objectsNum; i++)
	{
		SDK::UObject* objectReference = SDK::UObject::GObjects->GetByIndex(i);

		if (objectReference == nullptr || objectReference->IsDefaultObject())
			continue;

		if (objectReference->IsA(SDK::AActor::StaticClass()))
		{
			Unreal::Actor::DataStructure actorData = {};

			SDK::AActor* actor = static_cast<SDK::AActor*>(objectReference);
			actorData.reference = actor;
			actorData.className = actor->Class->GetFullName();
			actorData.objectName = actor->GetFullName();

			SDK::FTransform actorTransform = actor->GetTransform();
			actorData.location = actorTransform.Translation;
			actorData.rotation = SDK::FRotator(Math::InverseNormalizeAngle(actorTransform.Rotation.X), Math::InverseNormalizeAngle(actorTransform.Rotation.Y), Math::InverseNormalizeAngle(actorTransform.Rotation.Z));
			actorData.scale = actorTransform.Scale3D;

			SDK::TArray<SDK::UActorComponent*> actorComponents = actor->K2_GetComponentsByClass(SDK::UActorComponent::StaticClass());
			for (SDK::UActorComponent* component : actorComponents)
			{
				Unreal::ActorComponent::DataStructure componentData = {};

				componentData.reference = component;
				componentData.className = component->Class->GetFullName();
				componentData.objectName = component->GetFullName();

				componentData.isActive = component->bIsActive;
				componentData.autoActivate = component->bAutoActivate;
				componentData.editorOnly = component->bIsEditorOnly;

				componentData.netAddressible = component->bNetAddressable;
				componentData.replicates = component->bReplicates;

				componentData.creationMethod = component->CreationMethod;

				actorData.components.push_back(componentData);
			}

			Features::ActorsList::actors.push_back(actorData);
		}
	}
}






// ========================================================
// |       #GUI #SHARED #FUNCTIONS #SHAREDFUNCTIONS       |
// ========================================================
void Features::CharacterMovement::Ghost()
{
	GUI::PlayActionSound(Unreal::Character::Ghost(0));
}

void Features::CharacterMovement::Fly()
{
	GUI::PlayActionSound(Unreal::Character::Fly(0));
}

void Features::CharacterMovement::Walk()
{
	GUI::PlayActionSound(Unreal::Character::Walk(0));
}




void Features::CharacterMovement::Jump()
{
	GUI::PlayActionSound(Unreal::Character::Jump(0));
}




void Features::CharacterMovement::Launch()
{
	GUI::PlayActionSound(Unreal::Character::Launch(0, { Features::CharacterMovement::launchVelocity[0], Features::CharacterMovement::launchVelocity[1], Features::CharacterMovement::launchVelocity[2] }));
}

void Features::CharacterMovement::Dash()
{
	SDK::ACharacter* character = Unreal::Character::Get();
	if (character == nullptr)
	{
		GUI::PlayActionSound(false);
		return;
	}

	SDK::FVector forwardVector = character->GetActorForwardVector();

	/* Dash shouldn't involve any vertical movement. */
	forwardVector.Z = 0.0;
	forwardVector.Normalize();

	SDK::FVector launchVelocity = forwardVector * Features::CharacterMovement::dashStrength;
	GUI::PlayActionSound(Unreal::Character::Launch(character, launchVelocity));
}




void Features::DirectionalMovement::Worker()
{
	while (GetThread())
	{
		/* See if we have a Player Controller alongside the Camera Manager. */
		SDK::APlayerController* playerController = Unreal::PlayerController::Get();
		if (playerController == nullptr || playerController->PlayerCameraManager == nullptr)
			continue;

		/* See if we have a Character under control and verify that Character is cheat flying. */
		SDK::ACharacter* character = playerController->Character;
		if (character == nullptr || character->CharacterMovement == nullptr || character->CharacterMovement->bCheatFlying != true)
			continue;

		/* Get Character velocity and see if we have any horizontal movement. */
		SDK::FVector characterVelocity = character->CharacterMovement->Velocity;
		if (characterVelocity.X == 0.0 && characterVelocity.Y == 0.0)
			continue;

		/* Normalize Character velocity (-1.0 to 1.0) and get Camera forward vector. */
		SDK::FVector characterVelocityNormalized = Math::NormalizeVector(characterVelocity);
		SDK::FVector cameraForwardVector = playerController->PlayerCameraManager->GetActorForwardVector();

		/*
			Compute the dot product of the normalized character velocity and the camera's forward vector.
			Result interpretation:
			  +1.0 -> character moves exactly forward,
			  -1.0 -> character moves exactly backward,
			   0.0 -> movement is perpendicular to the camera.
		*/
		double dotProduct = SDK::UKismetMathLibrary::Dot_VectorVector(characterVelocityNormalized, cameraForwardVector);
		if (dotProduct > 0.5) // Character is mostly targeting forward direction.
		{
			SDK::FVector currentLocation = character->K2_GetActorLocation();
			SDK::FVector finalLocation = SDK::UKismetMathLibrary::Add_VectorVector(currentLocation, cameraForwardVector * Features::DirectionalMovement::step);

			SDK::FHitResult hitResult;
			character->K2_SetActorLocation(finalLocation, true, &hitResult, false);
		}

		Sleep(Math::Seconds_ToMilliseconds(Features::DirectionalMovement::delay));
	}
}




void Features::Camera::StartFade()
{
	SDK::APlayerController* playerController = Unreal::PlayerController::Get();
	if (playerController == nullptr || playerController->PlayerCameraManager == nullptr)
	{
		GUI::PlayActionSound(false);
		return;
	}

	SDK::FLinearColor fadeColor;
	fadeColor.R = Features::Camera::fadeColor[0];
	fadeColor.G = Features::Camera::fadeColor[1];
	fadeColor.B = Features::Camera::fadeColor[2];
	fadeColor.A = Features::Camera::fadeColor[3];

	playerController->PlayerCameraManager->StartCameraFade(Features::Camera::fadeFromAlpha, Features::Camera::fadeToAlpha, Features::Camera::fadeDuration, fadeColor, Features::Camera::fadeAudio, Features::Camera::fadePersistent);
	GUI::PlayActionSound(true);
}

void Features::Camera::StopFade()
{
	SDK::APlayerController* playerController = Unreal::PlayerController::Get();
	if (playerController == nullptr || playerController->PlayerCameraManager == nullptr)
	{
		GUI::PlayActionSound(false);
		return;
	}

	playerController->PlayerCameraManager->StopCameraFade();
	GUI::PlayActionSound(true);
}




bool Features::DirectionalMovement::StartThread()
{
	if (thread)
		return false;

	thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Features::DirectionalMovement::Worker, 0, 0, 0);
	return thread;
}

bool Features::DirectionalMovement::InvalidateThread()
{
	if (thread == nullptr)
		return false;

	if (CloseHandle(thread))
	{
		thread = nullptr;
		return true;
	}
	else
		return false;
}




#ifdef ACTOR_TRACE
bool Features::ActorTrace::Trace()
{
	SDK::UWorld* world = Unreal::World::Get();
	if (world == nullptr)
		return false;

	SDK::APlayerController* playerController = Unreal::PlayerController::Get();
	if (playerController == nullptr || playerController->PlayerCameraManager == nullptr)
		return false;

	SDK::FVector cameraLocation = playerController->PlayerCameraManager->K2_GetActorLocation();
	SDK::FVector cameraForwardVector = playerController->PlayerCameraManager->GetActorForwardVector();
	SDK::FVector traceEndLocation = cameraLocation + (cameraForwardVector * Features::ActorTrace::traceLength);

	SDK::TArray<SDK::AActor*> actorsToIgnore;
	if (SDK::ACharacter* character = Unreal::Character::Get())
		actorsToIgnore.Add(character);

	SDK::FHitResult hitResult;
	if (SDK::UKismetSystemLibrary::LineTraceSingle(world, cameraLocation, traceEndLocation, SDK::ETraceTypeQuery::TraceTypeQuery1, false, actorsToIgnore, SDK::EDrawDebugTrace::ForDuration, &hitResult, true, SDK::FLinearColor(), SDK::FLinearColor(), 5.0f))
	{
		SDK::AActor* hitActor = hitResult.Actor.Get();
		if (hitActor == nullptr)
			return false;

		Features::ActorTrace::traceHit = true;

		Features::ActorTrace::traceStartLocation = cameraLocation;
		Features::ActorTrace::traceEndLocation = hitResult.Location;

		Features::ActorTrace::actor.reference = hitActor;
		Features::ActorTrace::actor.className = hitActor->Class->GetFullName();
		Features::ActorTrace::actor.objectName = hitActor->GetFullName();

		Unreal::Console::Print("[Actor Trace] " + Features::ActorTrace::actor.objectName);
	}
	else
	{
		Features::ActorTrace::traceHit = false;

		Features::ActorTrace::traceStartLocation = cameraLocation;
		Features::ActorTrace::traceEndLocation = traceEndLocation;

		Features::ActorTrace::actor.reference = nullptr;

		Unreal::Console::Print("[Actor Trace] Didn't hit any actor.");
	}

	return true;
}
#endif






void Keybindings::Process()
{
	if (ImGui::IsKeyBindingPressed(&Keybindings::general_MenuOpenClose))
		GUI::ToggleIsMenuActive();


	if (GUI::GetIsMenuActive() == false)
	{
#ifdef ACTOR_TRACE
		if (Features::ActorTrace::enabled)
		{
			if (ImGui::IsKeyBindingPressed(&Keybindings::debug_ActorTrace))
			{
				GUI::PlayActionSound(Features::ActorTrace::Trace());
			}
		}
#endif




		if (ImGui::IsKeyBindingPressed(&Keybindings::characterMovement_Ghost))
		{
			Features::CharacterMovement::Ghost();
		}

		if (ImGui::IsKeyBindingPressed(&Keybindings::characterMovement_Fly))
		{
			Features::CharacterMovement::Fly();
		}

		if (ImGui::IsKeyBindingPressed(&Keybindings::characterMovement_Walk))
		{
			Features::CharacterMovement::Walk();
		}

		if (ImGui::IsKeyBindingPressed(&Keybindings::characterMovement_Jump))
		{
			Features::CharacterMovement::Jump();
		}

		if (ImGui::IsKeyBindingPressed(&Keybindings::characterMovement_Launch))
		{
			Features::CharacterMovement::Launch();
		}

		if (ImGui::IsKeyBindingPressed(&Keybindings::characterMovement_Dash))
		{
			Features::CharacterMovement::Dash();
		}




		if (ImGui::IsKeyBindingPressed(&Keybindings::characterCamera_StartFade))
		{
			Features::Camera::StartFade();
		}

		if (ImGui::IsKeyBindingPressed(&Keybindings::characterCamera_StopFade))
		{
			Features::Camera::StopFade();
		}
	}
}