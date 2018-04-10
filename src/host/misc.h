/*++
Copyright (c) Microsoft Corporation

Module Name:
- misc.h

Abstract:
- This file implements the NT console server font routines.

Author:
- Therese Stowell (ThereseS) 22-Jan-1991

Revision History:
 - Mike Griese, 30-oct-2017: Moved all functions that didn't require the host
    to the contypes lib. The ones that are still here in one way or another
    require code from the host to build.
--*/

#pragma once

#include "screenInfo.hpp"
#include "../types/inc/IInputEvent.hpp"
#include <deque>
#include <memory>

WCHAR CharToWchar(_In_reads_(cch) const char * const pch, const UINT cch);

void SetConsoleCPInfo(const BOOL fOutput);

BOOL CheckBisectStringW(_In_reads_bytes_(cBytes) const WCHAR * pwchBuffer,
                        _In_ DWORD cWords,
                        _In_ DWORD cBytes);
BOOL CheckBisectProcessW(const SCREEN_INFORMATION& ScreenInfo,
                         _In_reads_bytes_(cBytes) const WCHAR * pwchBuffer,
                         _In_ DWORD cWords,
                         _In_ DWORD cBytes,
                         _In_ SHORT sOriginalXPosition,
                         _In_ BOOL fEcho);

int ConvertToOem(const UINT uiCodePage,
                 _In_reads_(cchSource) const WCHAR * const pwchSource,
                 const UINT cchSource,
                 _Out_writes_(cchTarget) CHAR * const pchTarget,
                 const UINT cchTarget);

[[nodiscard]]
HRESULT SplitToOem(_Inout_ std::deque<std::unique_ptr<IInputEvent>>& events);

int ConvertInputToUnicode(const UINT uiCodePage,
                          _In_reads_(cchSource) const CHAR * const pchSource,
                          const UINT cchSource,
                          _Out_writes_(cchTarget) WCHAR * const pwchTarget,
                          const UINT cchTarget);


int ConvertOutputToUnicode(_In_ UINT uiCodePage,
                           _In_reads_(cchSource) const CHAR * const pchSource,
                           _In_ UINT cchSource,
                           _Out_writes_(cchTarget) WCHAR *pwchTarget,
                           _In_ UINT cchTarget);
