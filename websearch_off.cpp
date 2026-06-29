#include <windows.h>
#include <shellapi.h>
#include <iostream>

#pragma comment(lib, "Shell32.lib")

bool IsRunningAsAdmin()
{
    BOOL isAdmin = FALSE;
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;
    PSID adminGroup = nullptr;

    if (AllocateAndInitializeSid(
            &ntAuthority,
            2,
            SECURITY_BUILTIN_DOMAIN_RID,
            DOMAIN_ALIAS_RID_ADMINS,
            0, 0, 0, 0, 0, 0,
            &adminGroup))
    {
        if (!CheckTokenMembership(nullptr, adminGroup, &isAdmin))
            isAdmin = FALSE;

        FreeSid(adminGroup);
    }

    return isAdmin == TRUE;
}

void WaitForExit()
{
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
}

bool RelaunchAsAdmin()
{
    wchar_t exePath[MAX_PATH];

    if (!GetModuleFileNameW(nullptr, exePath, MAX_PATH))
        return false;

    HINSTANCE result = ShellExecuteW(
        nullptr,
        L"runas",
        exePath,
        nullptr,
        nullptr,
        SW_SHOWNORMAL);

    return reinterpret_cast<INT_PTR>(result) > 32;
}

int main()
{
    std::cout << "Windows Registry Utility\n\n";

    if (!IsRunningAsAdmin())
    {
        std::cout << "Administrator privileges required.\n";
        std::cout << "Requesting elevation...\n";

        if (!RelaunchAsAdmin())
        {
            std::cout << "User denied elevation or ShellExecute failed.\n";
        }

        WaitForExit();
        return 0;
    }

    std::cout << "Running as Administrator.\n";

    HKEY hKey;

    LONG result = RegCreateKeyExW(
        HKEY_CURRENT_USER,
        L"Software\\Policies\\Microsoft\\Windows\\Explorer",
        0,
        nullptr,
        REG_OPTION_NON_VOLATILE,
        KEY_ALL_ACCESS,
        nullptr,
        &hKey,
        nullptr);

    if (result != ERROR_SUCCESS)
    {
        std::cout << "RegCreateKeyEx failed.\n";
        std::cout << "Error Code: " << result << std::endl;

        WaitForExit();
        return 1;
    }

    DWORD value = 1;

    result = RegSetValueExW(
        hKey,
        L"DisableSearchBoxSuggestions",
        0,
        REG_DWORD,
        reinterpret_cast<const BYTE*>(&value),
        sizeof(value));

    RegCloseKey(hKey);

    if (result == ERROR_SUCCESS)
    {
        std::cout << "\nRegistry updated successfully.\n";
        std::cout << "Restart Explorer or reboot Windows.\n";
    }
    else
    {
        std::cout << "RegSetValueEx failed.\n";
        std::cout << "Error Code: " << result << std::endl;
    }

    WaitForExit();

    return 0;
}