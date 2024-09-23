#include "HookManager.h"
void HookManager::initHooks() {
	hooks.push_back(new TickingAreasManagerHook::countActiveStandaloneTickingAreas());
	hooks.push_back(new TickingAreasManagerHook::countActiveStandaloneTickingAreas2());
	hooks.push_back(new TickingAreasManagerHook::addArea);

	for (auto hook : hooks) {
		hook->Initialize();
		MH_EnableHook(MH_ALL_HOOKS);
	}
}