#include "wintools.h"
#include <Windows.h>

void OutputDebugStringA(std::string str)
{
	OutputDebugStringA(str.c_str());
}
