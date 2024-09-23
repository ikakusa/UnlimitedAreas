#pragma once
#include <MemUtils.h>
#include "../Hooks.h"

namespace TickingAreasManagerHook {
	class countActiveStandaloneTickingAreas : public Hook {
	private:
		static inline std::unique_ptr<FuncHook> funcPtr;
	public:
		countActiveStandaloneTickingAreas() : Hook("TickingAreasManager::countActiveStandaloneTickingAreas") {};
		static int handle(__int64 a1);
		bool Initialize() override {
			uintptr_t address = SigScan("48 89 5C 24 ?? 41 56 48 83 EC ?? 48 8B 19 45");
			return CreateHook(funcPtr, address, handle);
		}
	};

	class countActiveStandaloneTickingAreas2 : public Hook {
	private:
		static inline std::unique_ptr<FuncHook> funcPtr;
	public:
		countActiveStandaloneTickingAreas2() : Hook("TickingAreasManager::countActiveStandaloneTickingAreas2") {};
		static int handle(__int64 a1);
		bool Initialize() override {
			uintptr_t address = SigScan("40 53 48 83 EC ?? 48 8B 51 ?? 33 DB");
			return CreateHook(funcPtr, address, handle);
		}
	};

	class addArea : public Hook {
	private:
		static inline std::unique_ptr<FuncHook> funcPtr;
	public:
		addArea() : Hook("TickingAreasManager::_addArea") {};
		static __int64 handle(__int64** a1, int a2, __int64 a3, int* a4, char a5, int a6, char a7, unsigned __int8 a8, __int64 a9);
		bool Initialize() override {
			uintptr_t address = SigScan("89 54 24 ? 55 53 56 57 41 54 41 56 41 57 48 8d 6c 24 ? 48 81 ec ? ? ? ? 48 8b 05 ? ? ? ? 48 33 c4 48 89 45 ? 4d 8b f9 49 8b d8");
			return CreateHook(funcPtr, address, handle);
		}
	};
}