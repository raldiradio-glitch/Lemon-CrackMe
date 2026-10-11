#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

// Educational crackme: deliberately simple and intended for local debugging.
// Build as a native x64 program with Visual Studio's x64 Native Tools prompt.

static bool IsLicenseValid(const std::string& key)
{
    return key == "LEMON-1234";
}

void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void PrintHeader()
{
    std::cout << "\n";
    std::cout << "  ╔════════════════════════════════════════╗\n";
    std::cout << "  ║                                        ║\n";
    std::cout << "  ║       ◆ LEMON CRACKME - LEVEL 1 ◆     ║\n";
    std::cout << "  ║                                        ║\n";
    std::cout << "  ║   Reverse Engineering Challenge       ║\n";
    std::cout << "  ║                                        ║\n";
    std::cout << "  ╚════════════════════════════════════════╝\n";
    std::cout << "\n";
}

void PrintInfo()
{
    std::cout << "  ┌─ OBJECTIVE ──────────────────────────────────┐\n";
    std::cout << "  │ Find the valid license key to unlock         │\n";
    std::cout << "  │ premium mode. Use debuggers to trace the     │\n";
    std::cout << "  │ validation logic and discover the secret.    │\n";
    std::cout << "  └───────────────────────────────────────────────┘\n";
    std::cout << "\n";
}

void AnimatedPrompt()
{
    std::cout << "  Enter license key";
    for (int i = 0; i < 3; i++)
    {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
    std::cout << " ";
}

void SuccessScreen(const std::string& key)
{
    std::cout << "\n";
    std::cout << "  ╔════════════════════════════════════════╗\n";
    std::cout << "  ║                                        ║\n";
    std::cout << "  ║  ✓✓✓ LICENSE ACCEPTED ✓✓✓             ║\n";
    std::cout << "  ║                                        ║\n";
    std::cout << "  ╚════════════════════════════════════════╝\n";
    std::cout << "\n";
    std::cout << "  ┌─ STATUS ─────────────────────────────────────┐\n";
    std::cout << "  │ ✓ Signature Valid                            │\n";
    std::cout << "  │ ✓ Key: " << std::setw(34) << std::left << key << " │\n";
    std::cout << "  │ ✓ Premium Mode: UNLOCKED                     │\n";
    std::cout << "  └───────────────────────────────────────────────┘\n";
    std::cout << "\n";
    std::cout << "  Secret message: You found the success path!\n";
    std::cout << "\n";
}

void FailureScreen()
{
    std::cout << "\n";
    std::cout << "  ╔════════════════════════════════════════╗\n";
    std::cout << "  ║                                        ║\n";
    std::cout << "  ║  ✗✗✗ LICENSE REJECTED ✗✗✗             ║\n";
    std::cout << "  ║                                        ║\n";
    std::cout << "  ╚════════════════════════════════════════╝\n";
    std::cout << "\n";
    std::cout << "  ┌─ STATUS ─────────────────────────────────────┐\n";
    std::cout << "  │ ✗ Signature Invalid                          │\n";
    std::cout << "  │ ✗ Premium Mode: LOCKED                       │\n";
    std::cout << "  │                                              │\n";
    std::cout << "  │ Hint: Try a debugger to find the key...      │\n";
    std::cout << "  └───────────────────────────────────────────────┘\n";
    std::cout << "\n";
}

int main()
{
#ifdef _WIN32
    SetConsoleTitleA("Lemon CrackMe - x64dbg practice");
    // Enable ANSI escape codes for better formatting on Windows
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= 0x0004;
    SetConsoleMode(hOut, dwMode);
#endif

    ClearScreen();
    PrintHeader();
    PrintInfo();

    AnimatedPrompt();
    std::string key;
    std::getline(std::cin, key);

    if (IsLicenseValid(key))
    {
        SuccessScreen(key);
    }
    else
    {
        FailureScreen();
    }

    std::cout << "  Press Enter to exit...";
    std::string unused;
    std::getline(std::cin, unused);
    return 0;
}
