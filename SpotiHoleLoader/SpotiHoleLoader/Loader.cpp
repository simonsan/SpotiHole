// ==========================================================
// Project: SpotiHole
// 
// Component: Loader.dll
//     
// Initial author: meik97
//
// Started: 18.06.2020
// ==========================================================

#include <iostream>
#include <windows.h>

void* GetModuleProc(const char* module, const char* proc)
{
	HMODULE base = GetModuleHandleA(module);
	void* addr = GetProcAddress(base, proc);

	if (addr)
	{
		return addr;
	}

	return 0;
}

void* __cdecl DwmIsCompositionEnabled_fk(void)
{
	static void* DwmIsCompositionEnabled_p = NULL;
	char FullPath[MAX_PATH];

	LoadLibraryA("SpotiHole.dll");
	GetSystemDirectoryA(FullPath, MAX_PATH);
	strcat(FullPath, "\\dwmapi.dll");
	DwmIsCompositionEnabled_p = GetModuleProc(FullPath, "DwmIsCompositionEnabled");

	return DwmIsCompositionEnabled_p;
}

void* __cdecl DwmExtendFrameIntoClientArea_fk(void)
{
	static void* DwmExtendFrameIntoClientArea_p = NULL;
	char FullPath[MAX_PATH];

	LoadLibraryA("SpotiHole.dll");
	GetSystemDirectoryA(FullPath, MAX_PATH);
	strcat(FullPath, "\\dwmapi.dll");
	DwmExtendFrameIntoClientArea_p = GetModuleProc(FullPath, "DwmExtendFrameIntoClientArea");

	return DwmExtendFrameIntoClientArea_p;
}

void* __cdecl DwmSetWindowAttribute_fk(void)
{
	static void* DwmSetWindowAttribute_p = NULL;
	char FullPath[MAX_PATH];

	LoadLibraryA("SpotiHole.dll");
	GetSystemDirectoryA(FullPath, MAX_PATH);
	strcat(FullPath, "\\dwmapi.dll");
	DwmSetWindowAttribute_p = GetModuleProc(FullPath, "DwmSetWindowAttribute");

	return DwmSetWindowAttribute_p;
}

extern "C"
{
	void __declspec(dllexport, naked) DwmIsCompositionEnabled()
	{
		__asm
		{
			call DwmIsCompositionEnabled_fk
			jmp eax
		}
	}

	void __declspec(dllexport, naked) DwmExtendFrameIntoClientArea()
	{
		__asm
		{
			call DwmExtendFrameIntoClientArea_fk
			jmp eax
		}
	}

	void __declspec(dllexport, naked) DwmSetWindowAttribute()
	{
		__asm
		{
			call DwmSetWindowAttribute_fk
			jmp eax
		}
	}
}