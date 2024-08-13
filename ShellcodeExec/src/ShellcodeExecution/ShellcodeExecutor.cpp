#include "ShellcodeExecutor.h"

namespace ShellcodeExecution
{
	ShellcodeExecutor::ShellcodeExecutor(unsigned char* shellcode, size_t shellcodeSize)
	{
		this->_shellcode = shellcode;
		this->_shellcodeSize = shellcodeSize;
	}
}