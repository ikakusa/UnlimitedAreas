#include "dllmain.h"
#include <Libraries.h>
#include "UnlimitedArea/Hooks/HookManager.h"
#include <cassert>

DWORD WINAPI init(LPVOID lpParam) {

    MH_Initialize();
    HookManager::initHooks();

    void* limitChunk = (void*)(getBaseAddress() + 0x32aee71);
    char patch[5] = { 0x41, 0x81, 0x7F, 0x24, 0x0 };
    patchBytes(patch, limitChunk, 5);
    return 1;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)init, hModule, NULL, NULL);
        DisableThreadLibraryCalls(hModule);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

