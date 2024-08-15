#pragma once

#include "ShellcodeExecutor.h"

#define TARGET_PROCESS_PROGRAM_NAME L"mspaint.exe"

namespace ShellcodeExecution
{
	class ShellcodeProcessInjector :
		public ShellcodeExecutor
	{
	public:
		ShellcodeProcessInjector(unsigned char* shellcode, size_t shellcodeSize) :
			ShellcodeExecutor(shellcode, shellcodeSize) {}

		void Execute();

	private:
		int ProcessInjection();
	};
}


