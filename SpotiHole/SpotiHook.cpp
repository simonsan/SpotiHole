// ==========================================================
// Project: SpotiHole
// 
// Component: SpotiHole.dll
//          
// Initial author: meik97
//
// Started: 18.06.2020
// ==========================================================

#include ".\Components\include\BaseInclude.hpp"

void PatchSpotify()
{
	Modules::Initialization::Initialization();
}

DWORD WINAPI Exec(LPVOID lpParam)
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	PatchSpotify();
	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwAttached, LPVOID lpvReserved)
{
	if (dwAttached == DLL_PROCESS_ATTACH)
	{
		CreateThread(NULL, 0, &Exec, NULL, 0, NULL);
	}
	return 1;
}