// Copyright (C) 2001-2003 Even Balance, Inc.
//
//
// pbcl.h
//
// EVEN BALANCE - T.RAY
//
// The only file in the game project that needs to include this file is pbcl.cpp
//

#ifndef __PBCL_H__
#define __PBCL_H__

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "pbcommon.h"

#if !defined(NOT_USE_PUNKBUSTER_SDK)

#ifdef __PBWIN32__
#include <direct.h>
#include <Windows.h>
#endif
#ifdef __PBLINUX__
#include <unistd.h>
#include "CryLibrary.h"
#endif
#ifdef __PBMAC__
#include <unistd.h>
#include "../macosx/dlfcn.h"
#endif

#ifdef __WITH_PB__

#ifdef _cplusplus

#ifndef __PBDLL__
extern char* ca(void* cp, int ticklimit);
extern char* cb(void* cp, int event, int datalen, char* data, int retry);
#endif

//
// Class/Struct Definitions
//
struct stPbCl {
    int m_clId;
    void* m_Md5;
    void *m_ClInstance, *m_AgInstance;
    int m_ReloadClient;
    char m_guid[PB_GUIDLEN + 1], m_msgPrefix[PB_MISCLEN + 1], m_CdKeyNums[17], m_basepath[PB_Q_MAXRESULTLEN + 4], m_homepath[PB_Q_MAXRESULTLEN + 4], m_cwd[PB_Q_MAXRESULTLEN + 4];

    unsigned int rk1, rk2, rk3, rk4;

    // func ptrs
    tdPbGameCommand m_GameCommand;
    tdPbGameQuery m_GameQuery;
    tdPbGameMsg m_GameMsg;
    tdPbSendToServer m_SendToServer;
    tdPbAddClEvent m_AddPbEvent;
    tdPbProcessPbEvents m_ProcessPbEvents;
    tdPbSendToAddrPort m_SendToAddrPort;
    tdPbGlQuery m_GlQuery;
    tdPbClientConnect m_ClientConnect;
    tdPbTrapPreExecCmd m_TrapPreExecCmd;
    tdPbTrapConsole m_TrapConsole;

    void* pbsvptr;

    inline char* getBasePath(char* path) {
        strncpy(path, m_basepath, PB_Q_MAXRESULTLEN);
        path[PB_Q_MAXRESULTLEN] = 0;
        if (!(*path))
            getcwd(path, PB_Q_MAXRESULTLEN - 4);
        if (*path && path[strlen(path) - 1] != *pbDIRSEP)
            strcat(path, pbDIRSEP);
        strcat(path, "pb" pbDIRSEP);
        return path;
    }

    inline char* getHomePath(char* path) {
        strncpy(path, m_homepath, PB_Q_MAXRESULTLEN);
        path[PB_Q_MAXRESULTLEN] = 0;
        if (!(*path))
            getcwd(path, PB_Q_MAXRESULTLEN - 4);
        if (*path && path[strlen(path) - 1] != *pbDIRSEP)
            strcat(path, pbDIRSEP);
        strcat(path, "pb" pbDIRSEP);
        return path;
    }

    inline char* makefn(char* buf, char* fn) { // assumes buf is large enough to hold cwd + fn + overhead
        if (!(*m_cwd)) {
            getHomePath(m_cwd);
        }
        strcpy(buf, m_cwd);
        strcat(buf, fn);
        return buf;
    }

    inline void UnloadAgentDll(void) {
        if (m_AgInstance == nullptr)
            return;
#ifdef __PBWIN32__
        FreeLibrary((HINSTANCE)m_AgInstance);
#endif
#ifdef __PBLINUX__
        dlclose(m_AgInstance);
#endif
#ifdef __PBMAC__
        dlclose(m_AgInstance);
#endif
        m_AgInstance = nullptr;
    }

    inline void LoadAgentDll(void) {
        if (m_AgInstance != nullptr)
            return;
        UnloadAgentDll();

        char fn[PB_Q_MAXRESULTLEN * 2 + 1];

#ifdef __PBWIN32__
        m_AgInstance = LoadLibraryA(makefn(fn, "pbag" pbDLLEXT));
#endif
#ifdef __PBLINUX__
        m_AgInstance = ::dlopen(makefn(fn, "pbag" pbDLLEXT), RTLD_LAZY);
#endif
#ifdef __PBMAC__
        m_AgInstance = dlopen(makefn(fn, "pbag" pbDLLEXT), RTLD_LAZY);
#endif
    }

#ifndef __PBDLL__ // the following functions are not needed by the PB DLLs

    inline void uninitialize(void) { // also initializes game-side func ptrs
        m_GameCommand = nullptr;
        m_GameQuery = nullptr;
        m_GameMsg = nullptr;
        m_SendToServer = nullptr;
    }

    inline void initialize(void) {
        uninitialize();
        m_GameCommand = PbClGameCommand;
        m_GameQuery = PbClGameQuery;
        m_GameMsg = PbClGameMsg;
        m_SendToServer = PbClSendToServer;
        m_SendToAddrPort = PbClSendToAddrPort;
        // note: m_GlQuery is set in pbsdk.h
    }

    inline void UnloadClientDll(void) {
        m_ProcessPbEvents = nullptr;
        m_AddPbEvent = nullptr;
        m_ClientConnect = nullptr;
        m_TrapPreExecCmd = nullptr;
        m_TrapConsole = nullptr;
        if (m_ClInstance == nullptr)
            return;

#ifdef __PBWIN32__
        FreeLibrary((HMODULE)m_ClInstance);
#endif
#ifdef __PBLINUX__
        dlclose(m_ClInstance);
#endif
#ifdef __PBMAC__
        dlclose(m_ClInstance);
#endif
        m_ClInstance = nullptr;
    }

    inline char* LoadClientDll(void) {
        if (m_ClInstance != nullptr)
            return nullptr;
        UnloadClientDll();

        char fn[PB_Q_MAXRESULTLEN * 2 + 1], extrafn[PB_Q_MAXRESULTLEN * 2 + 1];

        // check for replacement (updated) dll file and rename if necessary
        // load PB client dll and retrieve exported function pointers
        FILE* f = fopen(makefn(fn, "pbclnew" pbDLLEXT), "rb");
        if (f != nullptr) {
            fclose(f);
            setRW(makefn(fn, "pbclold" pbDLLEXT));
            remove(makefn(fn, "pbclold" pbDLLEXT));
            rename(makefn(fn, "pbcl" pbDLLEXT), makefn(extrafn, "pbclold" pbDLLEXT));
            setRW(makefn(fn, "pbcl" pbDLLEXT));
            remove(makefn(fn, "pbcl" pbDLLEXT));
            rename(makefn(fn, "pbclnew" pbDLLEXT), makefn(extrafn, "pbcl" pbDLLEXT));
        }
#ifdef __PBWIN32__
        m_ClInstance = LoadLibraryA(makefn(fn, "pbcl" pbDLLEXT));
        if (m_ClInstance == nullptr)
            return PbsClDllLoadFail;
        m_ProcessPbEvents = (tdPbProcessPbEvents)GetProcAddress((HINSTANCE)m_ClInstance, "ca");
        m_AddPbEvent = (tdPbAddClEvent)GetProcAddress((HINSTANCE)m_ClInstance, "cb");
#endif
#ifdef __PBLINUX__
        m_ClInstance = ::dlopen(makefn(fn, "pbcl" pbDLLEXT), RTLD_LAZY);
        if (m_ClInstance == nullptr)
            return PbsClDllLoadFail;
        m_ProcessPbEvents = (tdPbProcessPbEvents)dlsym(m_ClInstance, "ca");
        m_AddPbEvent = (tdPbAddClEvent)dlsym(m_ClInstance, "cb");
#endif
#ifdef __PBMAC__
        m_ClInstance = dlopen(makefn(fn, "pbcl" pbDLLEXT), RTLD_LAZY);
        if (m_ClInstance == nullptr)
            return PbsClDllLoadFail;
        m_ProcessPbEvents = (tdPbProcessPbEvents)dlsym(m_ClInstance, "_ca");
        m_AddPbEvent = (tdPbAddClEvent)dlsym(m_ClInstance, "_cb");
#endif

        if (m_ProcessPbEvents == nullptr || m_AddPbEvent == nullptr) {
            UnloadClientDll();
            return PbsClDllProcFail;
        }

        m_ReloadClient = 0;

        return nullptr;
    }

    inline char* AddPbEvent(int type, int datalen, char* data, int retry = 0) {
        if (m_GameCommand == nullptr)
            return nullptr; // not considered an error, this signifies that PB is disabled

        if (m_ReloadClient || m_ClInstance == nullptr) {
            if (m_ClInstance != nullptr) {
                UnloadClientDll();
                return nullptr;
            }
            char* res = LoadClientDll();
            if (res != nullptr) {
                if (type == PB_EV_ISENABLED)
                    return (char*)0;
                return res;
            }
        }

        return m_AddPbEvent(this, type, datalen, data, retry);
    }

    inline char* ProcessPbEvents(int TickLimit = 0) {
        if (m_GameCommand == nullptr)
            return nullptr; // not considered an error, this signifies that PB is disabled
        if (m_ClInstance == nullptr) {
            if (m_ReloadClient)
                AddPbEvent(PB_EV_CONFIG, 0, "");
            return nullptr; // no events have been successfully added so nothing to process
        }

        if (m_ReloadClient) {
            UnloadClientDll();
            return nullptr;
        }

        return m_ProcessPbEvents(this, TickLimit);
    }

    inline void init(void) {
        memset(this, 0, sizeof(stPbCl));
        m_clId = PB_CL_ID;
        strcpy(m_msgPrefix, "PunkBuster Client");
        m_ClInstance = m_AgInstance = nullptr;
        m_ReloadClient = 1;
        uninitialize();
        m_Md5 = nullptr;
        m_AddPbEvent = nullptr;
        m_ProcessPbEvents = nullptr;
        m_SendToAddrPort = nullptr;
        m_GlQuery = nullptr;
        m_ClientConnect = nullptr;
        m_TrapPreExecCmd = nullptr;
        m_TrapConsole = nullptr;
    }

    inline stPbCl() {
        init();
    }

    inline ~stPbCl() {
        UnloadClientDll();
        UnloadAgentDll();
    }

#endif // #ifndef __PBDLL__
};

#endif // #ifdef _cplusplus
#endif // #ifdef __WITHPB__
#endif // #ifndef __PBCL_H__

#endif // NOT_USE_PUNKBUSTER_SDK