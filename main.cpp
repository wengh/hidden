#include <string>
#include <filesystem>
#include <windows.h>

using namespace std;
namespace fs = filesystem;

int main()
{
    FreeConsole();
    string path = "./no-console";
    if (!fs::exists(path)) {
        fs::create_directory(path);
    }
    for (const auto& entry : fs::directory_iterator(path)) {
        if (!entry.is_directory()) {
            WinExec(('"' + entry.path().string() + '"').c_str(), SW_HIDE);
        }
    }
    return 0;
}
