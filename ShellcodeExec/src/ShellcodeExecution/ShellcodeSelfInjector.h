#pragma once

#include "ShellcodeExecutor.h"

namespace ShellcodeExecution
{
	// ShellcodeSelfInjector is a class that provides a method to execute shellcode in the current process
	class ShellcodeSelfInjector :
		public ShellcodeExecutor
	{
	public:

		ShellcodeSelfInjector(unsigned char* shellcode, size_t shellcodeSize) :
			ShellcodeExecutor(shellcode, shellcodeSize) {}

		void Execute();

	private:

		// SelfInjection is a method that injects shellcode into the current process.
		int SelfInjection();
	};
}


