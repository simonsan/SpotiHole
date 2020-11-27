#include "..\include\BaseInclude.hpp"

namespace Utils
{
	void Hook::InstallDetour(void* source, void* destination, OpCode opcode, int len)
	{
		DWORD curProtection;
		VirtualProtect(source, len, PAGE_EXECUTE_READWRITE, &curProtection);

		memset(source, 0x90, len);

		DWORD relativeAddress = ((DWORD)destination - (DWORD)source) - 5;

		*(BYTE*)source = opcode;
		*(DWORD*)((DWORD)source + 1) = relativeAddress;

		DWORD temp;
		VirtualProtect(source, len, curProtection, &temp);
	}

	void Hook::InstallJmp(void* source, void* destination)
	{
		Hook::InstallDetour(source, destination, HOOK_JMP);
	}

	void Hook::InstallCall(void* source, void* destination)
	{
		Hook::InstallDetour(source, destination, HOOK_CALL);
	}
}