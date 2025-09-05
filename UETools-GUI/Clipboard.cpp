#include "Clipboard.h"






bool Clipboard::SetClipboard(const std::string& text)
{
    if (OpenClipboard(nullptr))
    {
        EmptyClipboard();
        size_t textSize = text.size() + 1;

        HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, textSize);
        if (hGlobal)
        {
            void* pMem = GlobalLock(hGlobal);
            if (pMem)
            {
                std::memcpy(pMem, text.c_str(), textSize);
                GlobalUnlock(hGlobal);

                SetClipboardData(CF_TEXT, hGlobal);

                CloseClipboard();
                return true;
            }


            GlobalUnlock(hGlobal);
        }

        CloseClipboard();
    }

    return true;
}
