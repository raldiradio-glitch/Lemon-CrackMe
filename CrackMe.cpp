#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#endif

// Educational crackme: deliberately simple and intended for local debugging.
// Build as a native x64 program with Visual Studio's x64 Native Tools prompt.

static bool IsLicenseValid(const std::string& key)
{
    return key == "LEMON-1234";
}

void BlurBackground()
{
#ifdef _WIN32
    // Set background to a darker theme by filling with spaces
    system("color 0F");  // Black background with white text
    
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD written = 0;
    
    // Fill screen with dark color
    for (int i = 0; i < 50; i++)
    {
        SetConsoleCursorPosition(hOut, coord);
        for (int j = 0; j < 120; j++)
        {
            std::cout << "█";
        }
        coord.Y++;
    }
#else
    system("clear");
#endif
}

void PrintRobloxHeader()
{
    std::cout << "\x1b[2J\x1b[H";  // Clear screen and move cursor to top
    
    std::cout << "\n\n";
    std::cout << "     ███████████████████████████████████████████████████████\n";
    std::cout << "     █                                                       █\n";
    std::cout << "     █         ██████╗  ██████╗ ██████╗ ██╗      ██╗██╗     █\n";
    std::cout << "     █         ██╔══██╗██╔═══██╗██╔══██╗██║      ██║██║     █\n";
    std::cout << "     █         ██████╔╝██║   ██║██████╔╝██║      ██║██║     █\n";
    std::cout << "     █         ██╔══██╗██║   ██║██╔══██╗██║      ██║██║     █\n";
    std::cout << "     █         ██║  ██║╚██████╔╝██████╔╝███████╗██║███████╗█\n";
    std::cout << "     █         ╚═╝  ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝╚══════╝█\n";
    std::cout << "     █                                                       █\n";
    std::cout << "     █              SCRIPT EXECUTOR v2.7.1                  █\n";
    std::cout << "     █                                                       █\n";
    std::cout << "     ███████████████████████████████████████████████████████\n";
    std::cout << "\n";
}

void PrintLoginForm()
{
    std::cout << "     ╔═══════════════════════════════════════════════════════╗\n";
    std::cout << "     ║                   PREMIUM ACCESS                      ║\n";
    std::cout << "     ║              Verify Your Activation Key               ║\n";
    std::cout << "     ╚═══════════════════════════════════════════════════════╝\n";
    std::cout << "\n";
    std::cout << "     Please enter your activation key to proceed:\n";
    std::cout << "\n";
}

void PrintLoading()
{
    std::cout << "     Processing";
    for (int i = 0; i < 4; i++)
    {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    std::cout << "\n\n";
}

void PrintSuccessScreen()
{
    std::cout << "\x1b[2J\x1b[H";  // Clear screen
    
    std::cout << "\n\n";
    std::cout << "     ███████████████████████████████████████████████████████\n";
    std::cout << "     █                                                       █\n";
    std::cout << "     █                   ✓ VERIFIED ✓                       █\n";
    std::cout << "     █                                                       █\n";
    std::cout << "     ███████████████████████████████████████████████████████\n";
    std::cout << "\n";
    
    std::cout << "     ╔═══════════════════════════════════════════════════════╗\n";
    std::cout << "     ║                                                       ║\n";
    std::cout << "     ║        PREMIUM EXECUTOR UNLOCKED                      ║\n";
    std::cout << "     ║                                                       ║\n";
    std::cout << "     ║   Status: ACTIVE                                      ║\n";
    std::cout << "     ║   Level: ADMIN                                        ║\n";
    std::cout << "     ║   Scripts Available: UNLIMITED                        ║\n";
    std::cout << "     ║                                                       ║\n";
    std::cout << "     ╚═══════════════════════════════════════════════════════╝\n";
    std::cout << "\n";
    std::cout << "     ⚠️  NOTICE ⚠️\n";
    std::cout << "     This is a FAKE executor for educational purposes only.\n";
    std::cout << "     This software does NOT actually execute Roblox scripts.\n";
    std::cout << "     Background is intentionally blurred for demonstration.\n";
    std::cout << "\n";
    std::cout << "     DO NOT use real executors - they violate Roblox ToS!\n";
    std::cout << "\n";
    std::cout << "     ════════════════════════════════════════════════════════\n";
    std::cout << "\n";
    std::cout << "     Console Output:\n";
    std::cout << "     > Injecting into Roblox process...\n";
    std::cout << "     > [INFO] Script context initialized\n";
    std::cout << "     > [SUCCESS] Executor ready for scripts\n";
    std::cout << "\n";
}

void PrintFailureScreen()
{
    std::cout << "\x1b[2J\x1b[H";  // Clear screen
    
    std::cout << "\n\n";
    std::cout << "     ███████████████████████████████████████████████████████\n";
    std::cout << "     █                                                       █\n";
    std::cout << "     █                   ✗ INVALID ✗                        █\n";
    std::cout << "     █                                                       █\n";
    std::cout << "     ███████████████████████████████████████████████████████\n";
    std::cout << "\n";
    
    std::cout << "     ╔═══════════════════════════════════════════════════════╗\n";
    std::cout << "     ║                                                       ║\n";
    std::cout << "     ║        ERROR: INVALID ACTIVATION KEY                  ║\n";
    std::cout << "     ║                                                       ║\n";
    std::cout << "     ║   Status: ACCESS DENIED                               ║\n";
    std::cout << "     ║   Level: FREE                                         ║\n";
    std::cout << "     ║   Scripts Available: LIMITED                          ║\n";
    std::cout << "     ║                                                       ║\n";
    std::cout << "     ║   Try reversing this to find the key...               ║\n";
    std::cout << "     ║                                                       ║\n";
    std::cout << "     ╚═══════════════════════════════════════════════════════╝\n";
    std::cout << "\n";
}

int main()
{
#ifdef _WIN32
    SetConsoleTitleA("Roblox Script Executor Premium");
    
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= 0x0004;
    SetConsoleMode(hOut, dwMode);
    
    // Set background color to dark (simulating blurred background)
    system("color 01");
#endif

    PrintRobloxHeader();
    PrintLoginForm();

    std::cout << "     [INPUT] > ";
    std::string key;
    std::getline(std::cin, key);

    PrintLoading();

    if (IsLicenseValid(key))
    {
        PrintSuccessScreen();
    }
    else
    {
        PrintFailureScreen();
    }

    std::cout << "     Press Enter to exit...";
    std::string unused;
    std::getline(std::cin, unused);
    return 0;
}
