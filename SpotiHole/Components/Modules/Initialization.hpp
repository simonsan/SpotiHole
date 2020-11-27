// ==========================================================
// Project: SpotiHole
// 
// Component: SpotiHole.dll
//
// Purpose: Initialization checks
//          
// Initial author: meik97
//
// Started: 18.10.2020
// ==========================================================

#pragma once

namespace Modules
{
	class Initialization
	{
	public:
		Initialization();
		static void WelcomeMessage();
		static bool CheckSpotify();
	};
}