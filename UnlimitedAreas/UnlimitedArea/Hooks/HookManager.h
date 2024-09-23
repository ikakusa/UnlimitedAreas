#pragma once
#include "Hooks.h"

//Hooks
#include "TickingAreasManagerHook/TickingAreasManagerHook.h"
//
class Hook;
class HookManager {
private:
	static inline std::vector<Hook*> hooks;
public:
	static void initHooks();
	static void DeleteHooks() {
		hooks.clear();
	}
};