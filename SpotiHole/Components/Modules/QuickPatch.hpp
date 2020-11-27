// ==========================================================
// Project: SpotiHole
// 
// Component: SpotiHole.dll
//
// Purpose: Apply quick patches to Spotify
//          
// Initial author: meik97
//
// Started: 28.07.2020
// ==========================================================

#pragma once

namespace Modules
{
	class QuickPatch
	{
	public:
		QuickPatch();
		static void ToggleDeveloperTools(bool active);
		static void Branding();
	};
}