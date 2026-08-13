#include <Windows.h>
#include <string>
#include <iostream>
#pragma comment(lib, "psapi.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")

//CREDITS TO STATIC FOR THE EYECRAWL API
// christiancombine.github.io won noob
#include "eyestep_utility.h"




int main()
{
	SetConsoleTitleA("Fuggen Dumper | Edited By Combine");
    std::cout << "Finding Roblox... ";

HWND hWnd = FindWindowA(NULL, "Roblox");

if (!hWnd)
{
    std::cout << "Roblox window not found!\n";
    system("PAUSE");
    return;
}

DWORD id = 0;
GetWindowThreadProcessId(hWnd, &id);

if (!id)
{
    std::cout << "Failed to get Roblox PID!\n";
    system("PAUSE");
    return;
}

HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, id);

if (!handle)
{
    std::cout << "Failed to open Roblox process!\n";
    system("PAUSE");
    return;
}

std::cout << "Success!\n";

EyeStep::open(handle);


	//begin scan

	std::cout << "Scanning...\n";
	

	printf("Lua_Print: 0x%08X.\n", EyeStep::scanner::scan_xrefs("Video Recording Started", 1)[1]);
    printf("Lua_GetField: 0x%08X.\n", EyeStep::scanner::scan_xrefs("tostring", 1)[1]); // Good Luck on this one 
	printf("LuaU_Load: 0x%08X.\n", EyeStep::scanner::scan_xrefs(": Bytecode Version Mismatch", 1)[1]);
	// ok no need for ts but its AOB scanning so u can add it
  //  printf("yourfunc: 0x%08X.\n", EyeStep::scanner::scan("Invalid", true)); // Good Luck on this one 
	std::cout << "Success!\n";


	system("PAUSE");
	return 0;

}

