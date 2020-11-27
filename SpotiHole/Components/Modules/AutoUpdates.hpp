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

#pragma once

namespace Modules
{
	class AutoUpdates
	{
	public:
		AutoUpdates();
		static bool ParseUpdateUrl_hk(int a1, int a2);
	};
}
