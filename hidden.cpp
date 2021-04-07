#include <windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    size_t len = strlen(lpCmdLine) + 10;
    char* s = new char[len];
    s[0] = 0;
    strcat_s(s, len, "/c \"");
    strcat_s(s, len, lpCmdLine);
    strcat_s(s, len, "\"");

    SHELLEXECUTEINFO info = {0};
    info.cbSize = sizeof(SHELLEXECUTEINFO);
    info.fMask = SEE_MASK_NOCLOSEPROCESS;
    info.hwnd = nullptr;
    info.lpVerb = nullptr;
    info.lpFile = "cmd.exe";
    info.lpParameters = s;
    info.lpDirectory = nullptr;
    info.nShow = SW_HIDE;
    info.hInstApp = nullptr;
    ShellExecuteEx(&info);
#ifdef WAIT_UNTIL_TERMINATE
    WaitForSingleObject(info.hProcess, INFINITE);
#endif
    CloseHandle(info.hProcess);

    return 0;
}