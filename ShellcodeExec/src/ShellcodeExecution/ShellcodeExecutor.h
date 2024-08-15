#pragma once

namespace ShellcodeExecution
{
	// ShellcodeExecutor is an abstract class that provides a common interface for executing shellcode.
	class ShellcodeExecutor
	{
	protected:
		unsigned char* _shellcode;
		size_t _shellcodeSize;

	public:

		ShellcodeExecution::ShellcodeExecutor(unsigned char* shellcode, size_t shellcodeSize);

		virtual void Execute() = 0;
	};
}


