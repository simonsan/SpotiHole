#pragma once

namespace Utils
{
	class Hook
	{
	private:
		enum OpCode
		{
			HOOK_CALL = 0xE8,
			HOOK_JMP = 0xE9,
		};

	public:
		static void InstallDetour(void* source, void* destination, OpCode opcode, int len = 5);
		static void InstallJmp(void* source, void* destination);
		static void InstallCall(void* source, void* destination);
	};
}