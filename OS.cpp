#include "OS.hpp"

#include <stdexcept>

#ifdef WIN32
#include <windows.h>

void OS::System(std::string cmd_line) {
	STARTUPINFO StartupInfo;
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);

	PROCESS_INFORMATION ProcInfo;
	ZeroMemory(&ProcInfo, sizeof(ProcInfo));
	if (not CreateProcess(NULL,
						  const_cast<char*>(cmd_line.c_str()),
						  NULL,
						  NULL,
						  FALSE,
						  0,
						  NULL,
						  NULL,
						  &StartupInfo,
						  &ProcInfo)) 
	{

		throw std::runtime_error("\n"
			                     "Class OS\n"
			                     "_WIN32\n"
			                     "not CreateProcess\n");
	}

	WaitForSingleObject(ProcInfo.hProcess, INFINITE);
	CloseHandle(ProcInfo.hProcess);
	CloseHandle(ProcInfo.hThread);
}
#endif