#pragma once
#include <Windows.h>
#include <string>







class Clipboard
{
public:
    static bool SetClipboard(const std::string& text);
};

