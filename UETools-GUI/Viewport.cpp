#include "Viewport.h"
#include "Engine.h"






SDK::UGameViewportClient* Viewport::GetGameViewport()
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr || Engine->GameViewport == nullptr)
        return nullptr;

    return Engine->GameViewport;
}


SDK::TSubclassOf<SDK::UGameViewportClient> Viewport::GetGameViewportClass()
{
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    if (Engine == nullptr || Engine->GameViewportClientClass == nullptr)
        return nullptr;

    return Engine->GameViewportClientClass;
}
