#include "Engine.h"






SDK::UEngine* Engine::GetEngine()
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return nullptr;

    return Engine;
}




SDK::UFont* Engine::GetTinyFont()
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr || Engine->TinyFont == nullptr)
        return nullptr;

    return Engine->TinyFont;
}

bool Engine::SetTinyFont(SDK::UFont* newFont)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->TinyFont = newFont;
    return true;
}


bool Engine::GetTinyFontSoftPath(SDK::FSoftObjectPath* outPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    *outPath = Engine->TinyFontName;
    return true;
}

bool Engine::SetTinyFontSoftPath(const SDK::FSoftObjectPath& newPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->TinyFontName = newPath;
    return true;
}




SDK::UFont* Engine::GetSmallFont()
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr || Engine->TinyFont == nullptr)
        return nullptr;

    return Engine->SmallFont;
}

bool Engine::SetSmallFont(SDK::UFont* newFont)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->SmallFont = newFont;
    return true;
}


bool Engine::GetSmallFontSoftPath(SDK::FSoftObjectPath* outPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    *outPath = Engine->SmallFontName;
    return true;
}

bool Engine::SetSmallFontSoftPath(const SDK::FSoftObjectPath& newPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->SmallFontName = newPath;
    return true;
}




SDK::UFont* Engine::GetMediumFont()
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr || Engine->TinyFont == nullptr)
        return nullptr;

    return Engine->MediumFont;
}

bool Engine::SetMediumFont(SDK::UFont* newFont)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->MediumFont = newFont;
    return true;
}


bool Engine::GetMediumFontSoftPath(SDK::FSoftObjectPath* outPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    *outPath = Engine->MediumFontName;
    return true;
}

bool Engine::SetMediumFontSoftPath(const SDK::FSoftObjectPath& newPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->MediumFontName = newPath;
    return true;
}




SDK::UFont* Engine::GetLargeFont()
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr || Engine->TinyFont == nullptr)
        return nullptr;

    return Engine->LargeFont;
}

bool Engine::SetLargeFont(SDK::UFont* newFont)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->LargeFont = newFont;
    return true;
}


bool Engine::GetLargeFontSoftPath(SDK::FSoftObjectPath* outPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    *outPath = Engine->LargeFontName;
    return true;
}

bool Engine::SetLargeFontSoftPath(const SDK::FSoftObjectPath& newPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->LargeFontName = newPath;
    return true;
}




SDK::UFont* Engine::GetSubtitleFont()
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr || Engine->TinyFont == nullptr)
        return nullptr;

    return Engine->SubtitleFont;
}

bool Engine::SetSubtitleFont(SDK::UFont* newFont)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->SubtitleFont = newFont;
    return true;
}


bool Engine::GetSubtitleFontSoftPath(SDK::FSoftObjectPath* outPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    *outPath = Engine->SubtitleFontName;
    return true;
}

bool Engine::SetSubtitleFontSoftPath(const SDK::FSoftObjectPath& newPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->SubtitleFontName = newPath;
    return true;
}




SDK::TSubclassOf<SDK::UConsole> Engine::GetConsoleClass()
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr || Engine->ConsoleClass == nullptr)
        return nullptr;

    return Engine->ConsoleClass;
}

bool Engine::SetConsoleClass(const SDK::TSubclassOf<SDK::UConsole>& newConsoleClass)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->ConsoleClass = newConsoleClass;
    return true;
}


bool Engine::GetConsoleSoftPath(SDK::FSoftClassPath* outPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    *outPath = Engine->ConsoleClassName;
    return true;
}

bool Engine::SetConsoleSoftPath(const SDK::FSoftClassPath& newPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->ConsoleClassName = newPath;
    return true;
}




SDK::UGameViewportClient* Engine::GetGameViewport()
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr || Engine->GameViewport == nullptr)
        return nullptr;

    return Engine->GameViewport;
}

bool Engine::SetGameViewport(SDK::UGameViewportClient* newViewport)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->GameViewport = newViewport;
    return true;
}



SDK::TSubclassOf<SDK::UGameViewportClient> Engine::GetGameViewportClass()
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr || Engine->GameViewportClientClass == nullptr)
        return nullptr;

    return Engine->GameViewportClientClass;
}

bool Engine::SetGameViewportClass(const SDK::TSubclassOf<SDK::UGameViewportClient>& newGameViewportClass)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->GameViewportClientClass = newGameViewportClass;
    return true;
}


bool Engine::GetGameViewportSoftPath(SDK::FSoftClassPath* outPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    *outPath = Engine->GameViewportClientClassName;
    return true;
}

bool Engine::SetGameViewportSoftPath(const SDK::FSoftClassPath& newPath)
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr)
        return false;

    Engine->GameViewportClientClassName = newPath;
    return true;
}
