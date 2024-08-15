#pragma once

#include "ShellcodeExecutor.h"

// Program name of process to inject shellcode into
#define TARGET_PROCESS_PROGRAM_NAME L"mspaint.exe"

namespace ShellcodeExecution
{
	// ShellcodeProcessInjector is a class that provides a method to execute shellcode in a remote process.
	class ShellcodeProcessInjector :
		public ShellcodeExecutor
	{
	public:
		ShellcodeProcessInjector(unsigned char* shellcode, size_t shellcodeSize) :
			ShellcodeExecutor(shellcode, shellcodeSize) {}

		void Execute();

	private:

		// ProcessInjection is a method that injects shellcode into a remote process.
		int ProcessInjection();
	};
}


