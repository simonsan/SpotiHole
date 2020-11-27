#include "..\include\BaseInclude.hpp"

namespace Utils
{

	void Utils::DebugPrint(const char* msg)
	{
		#ifdef DEBUG
		std::cout << msg << std::endl;
		#endif
	}

	int Utils::GetFileSize(const char* filename)
	{
		std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
		return in.tellg();
	}
}