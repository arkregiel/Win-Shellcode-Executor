#pragma once

#include "ShellcodeExecutor.h"

namespace ShellcodeExecution
{
	class ShellcodeSelfInjector :
		public ShellcodeExecutor
	{
	public:
		ShellcodeSelfInjector(unsigned char* shellcode, size_t shellcodeSize) :
			ShellcodeExecutor(shellcode, shellcodeSize) {}

		void Execute();

	private:
		int SelfInjection();
	};
}


