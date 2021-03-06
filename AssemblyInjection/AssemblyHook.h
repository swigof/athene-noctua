#pragma once
#include <windows.h>

struct hookpoint {
	DWORD address;
	DWORD size;
	DWORD next;
	char* bytes;
};

class AssemblyHook
{
private:
	DWORD instructionAddress;
	DWORD handlerAddress;
	DWORD jumpbackAddress;
	DWORD instructionSize;
	char* instructionBytes;
	bool attached;
public:
	AssemblyHook(void* handler, hookpoint hookPoint);
	~AssemblyHook();
	bool Attach();
	void Detach();
	void WriteInstructionToHandler();
};

