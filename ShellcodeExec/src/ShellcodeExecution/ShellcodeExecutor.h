#pragma once

namespace ShellcodeExecution
{
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


