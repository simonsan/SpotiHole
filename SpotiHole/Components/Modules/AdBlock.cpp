// ==========================================================
// Project: SpotiHole
// 
// Component: SpotiHole.dll
//
// Purpose: Adblocker
//          
// Initial author: meik97
//
// Started: 18.06.2020
// ==========================================================

#include "..\include\BaseInclude.hpp"

namespace Modules
{
	const char* Adblock::currentTrack;
	std::string Adblock::savedSong;
	bool Adblock::isAd;
	//int Adblock::adCounter = 0;

	bool __fastcall Adblock::EnableSkips_hk(void* _this, DWORD edx)
	{
		return true;
	}

	std::string Adblock::GetCurrentTrack()
	{
		if (currentTrack == nullptr && savedSong.empty() == false)
		{
			return "Current track is not set yet";
		}
		return savedSong;
	}

	void __declspec(naked) __fastcall Adblock::SetCurrentTrack_stub(void* _this, DWORD edx, int a2, int a3, __int64 speed, int normalization, int urgency, int flag, int a8, int stream_type)
	{
		__asm
		{
			mov	    currentTrack, eax
			call    IsAdOrTrack
		}

		savedSong = currentTrack;

		__asm
		{
			push    eax
			push    131FFF0h
			push    10Eh
			push    131FFA8h
			push    128989Ah
			push    0
			push    4
			push	0CB615Ch
			retn
		}
	}

	void Adblock::IsAdOrTrack()
	{
		if (strstr(currentTrack, "spotify:ad:") != nullptr)
		{
			Utils::Utils::DebugPrint(currentTrack);

			//TODO: Replace SkipAd with original skip function
			SkipAd();
			isAd = 1;
		}
		
		if (strstr(currentTrack, "spotify:track:") != nullptr )
		{
			Utils::Utils::DebugPrint(currentTrack);
			isAd = 0;
		}
	}

	void Adblock::SkipAd()
	{
		keybd_event(VK_MEDIA_NEXT_TRACK, 0, 0, 0);
	}

	Adblock::Adblock()
	{
		Utils::Utils::DebugPrint("Applying AdBlock patch...");
		Utils::Hook::InstallJmp(Functions::IsSkippable, EnableSkips_hk);
		Utils::Hook::InstallJmp((void*)0x0CB6143, SetCurrentTrack_stub);
	}
}