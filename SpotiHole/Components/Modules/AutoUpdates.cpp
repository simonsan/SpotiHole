// ==========================================================
// Project: SpotiHole
// 
// Component: SpotiHole.dll
//
// Purpose: Disable auto updates
//          
// Initial author: meik97
//
// Started: 21.07.2020
// ==========================================================

#include "..\include\BaseInclude.hpp"

namespace Modules
{
	bool AutoUpdates::ParseUpdateUrl_hk(int a1, int a2)
	{
		Utils::Utils::DebugPrint("ParseUpdateUrl called");
		return 0;
	}

	AutoUpdates::AutoUpdates()
	{
		Utils::Utils::DebugPrint("Applying AutoUpdate patch...");
		Utils::Hook::InstallCall((void*)0xA2CD34, AutoUpdates::ParseUpdateUrl_hk);
	}
}