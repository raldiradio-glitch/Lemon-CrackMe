#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

// Educational crackme: deliberately simple and intended for local debugging.
// Build as a native x64 program with Visual Studio's x64 Native Tools prompt.

static bool IsLicenseValid(const std::string& key)
{
    return key == "LEMON-1234";
}

int main()
{
#ifdef _WIN32
    SetConsoleTitleA("Lemon CrackMe - x64dbg practice");
#endif

    std::cout << "====================================\n";
    std::cout << "       LEMON CRACKME - LEVEL 1\n";
    std::cout << "====================================\n";
    std::cout << "Practice reversing this local test app.\n";
    std::cout << "Enter license key: ";

    std::string key;
    std::getline(std::cin, key);

    if (IsLicenseValid(key))
    {
        std::cout << "\n[+] License accepted. PREMIUM MODE UNLOCKED!\n";
        std::cout << "Secret message: You found the success path.\n";
    }
    else
    {
        std::cout << "\n[-] License rejected. Premium mode is locked.\n";
    }

    std::cout << "\nPress Enter to exit...";
    std::string unused;
    std::getline(std::cin, unused);
    return 0;
}
