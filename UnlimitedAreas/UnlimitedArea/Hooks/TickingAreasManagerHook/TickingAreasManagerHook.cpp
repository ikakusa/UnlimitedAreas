#include "TickingAreasManagerHook.h"

int TickingAreasManagerHook::countActiveStandaloneTickingAreas::handle(__int64 a1) {
	static auto oFunc = funcPtr->GetFastcall<int, __int64>();
	return 1;
}

int TickingAreasManagerHook::countActiveStandaloneTickingAreas2::handle(__int64 a1) {
	static auto oFunc = funcPtr->GetFastcall<int, __int64>();
	return 1;
}

__int64 TickingAreasManagerHook::addArea::handle(__int64** a1, int a2, __int64 a3, int* a4, char a5, int a6, char a7, unsigned __int8 a8, __int64 a9) {
	static auto oFunc = funcPtr->GetFastcall<__int64, __int64**, int, __int64, int*, char, int, char, unsigned __int8, __int64>();
	a4[9] = 1;
	return oFunc(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}