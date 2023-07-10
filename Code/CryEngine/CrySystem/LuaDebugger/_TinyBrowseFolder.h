#ifndef _TINY_BROWSE_FOLDER_H_
#define _TINY_BROWSE_FOLDER_H_

#pragma once

#ifndef __TINY_MAIN_H__
#error "_TinyBrowseFolder require <_TinyMain.h>"
#endif

#include <Shlobj.h>
#include <Windows.h>

// TODO

BOOL _TinyBrowseForFolder(char szPathOut[_MAX_PATH], _TinyWindow* pParent = nullptr) {
    BROWSEINFO sInfo;
    char szDisplayName[_MAX_PATH];
    ITEMIDLIST* pList = nullptr;

    szPathOut[0] = '\0';

    sInfo.hwndOwner = (pParent == nullptr) ? nullptr : pParent->m_hWnd;
    sInfo.pidlRoot = nullptr;
    sInfo.pszDisplayName = szDisplayName;
    sInfo.ulFlags = BIF_RETURNONLYFSDIRS;
    sInfo.lpfn = nullptr;
    sInfo.lParam = 0;
    sInfo.iImage = 0;

    __try {
        if (FAILED(CoInitialize(nullptr)))
            __leave;

        CoInitialize(nullptr);

        SHBrowseForFolder(&sInfo);
        if ((pList = SHBrowseForFolder(&sInfo)) == nullptr)
            __leave;

        // SHGetPathFromIDList
    } __finally {
        CoUninitialize();
    }

    return TRUE;
}

// char szTmp[_MAX_PATH];
// extern BOOL g_bTest = _TinyBrowseForFolder(szTmp);

#endif
