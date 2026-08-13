#include <Windows.h>
#include <string>
#include <iostream>

// discord.gg/qdl
#include "eyestep_utility.h"



int main()
{
	SetConsoleTitleA("Fuggen Dumper | Edited By Combine");
    std::cout << "Finding Roblox... ";

HWND hWnd = FindWindowA(NULL, "Roblox");
if (!hWnd) return 1;

DWORD id;
GetWindowThreadProcessId(hWnd, &id);

HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, id);
if (!handle) return 1;

EyeStep::external_mode = true;
EyeStep::current_proc = handle;

MODULEENTRY32 me = { sizeof(me) };
HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, id);
if (hSnap != INVALID_HANDLE_VALUE)
{
    if (Module32First(hSnap, &me))
    {
        do
        {
            if (_stricmp(me.szModule, "RobloxPlayerBeta.exe") == 0)
            {
                EyeStep::base_module = me.modBaseAddr;
                EyeStep::base_module_size = me.modBaseSize;
                break;
            }
        } while (Module32Next(hSnap, &me));
    }
    CloseHandle(hSnap);
}

	//begin scan

	std::cout << "Scanning...\n";
	

	printf("Lua_Print: 0x%08X.\n", EyeStep::scanner::scan_xrefs("Video Recording Started", 1)[1]);
    printf("Lua_GetField: 0x%08X.\n", EyeStep::scanner::scan_xrefs("tostring", 1)[1]); // Good Luck on this one 
	printf("LuaU_Load: 0x%08X.\n", EyeStep::scanner::scan_xrefs(": Bytecode Version Mismatch", 1)[1]);
	// ok no need for ts but its AOB scanning so u can add it
  //  printf("yourfunc: 0x%08X.\n", EyeStep::scanner::scan("Invalid", true)); // Good Luck on this one 
	std::cout << "Success!\n";

	std::cout << "Credits To Static For His Beautiful EyeCrawl API!\n";
	std::cout << "https://github.com/thedoomed/EyeCrawl/ \n";

	system("PAUSE");
	return 0;


	//note: I hope this example served you well, and will help you in creating fully-fledged applications
	//such as dumpers as statics beautiful eyecrawl api can be used for A LOT more than just this
	//Keep in mind this is an example and please feel free to expand it and make it dump more offsets!
}

