#pragma once

namespace Functions
{
	typedef bool(__thiscall* ParseUpdateUrl_t)(int a1, int a2);
	extern ParseUpdateUrl_t ParseUpdateUrl;

	typedef void(__thiscall* CreateTrack_t)(void* _this, int a2, int a3, __int64 speed, int normalization, int urgency, int flag, int a8, int stream_type);
	extern CreateTrack_t CreateTrack;

	typedef bool(__thiscall* IsSkippable_t)(void* _this);
	extern IsSkippable_t IsSkippable;

	typedef void(__thiscall* LoadCommand_t)(void* _this, const char* cmd, unsigned int cmdlen);
	extern LoadCommand_t LoadCommand;
}