#include <Windows.h>
#include <string>
#include <iostream>

//CREDITS TO STATIC FOR THE EYECRAWL API
//IT CAN BE FOUND HERE
//OPEN SOURCE AT
//https://github.com/thedoomed/EyeCrawl/
#include "eyecrawl.h"


std::vector<std::string> LoggedCFunctions;

void LogCFunction(std::string FunctionName, unsigned int Function) {
	std::vector<std::string>::iterator it = std::find(LoggedCFunctions.begin(), LoggedCFunctions.end(), FunctionName);
	if (it == LoggedCFunctions.cend()) {
		std::cout << "[" << FunctionName << "] - 0x" << EyeCrawl::to_str(EyeCrawl::non_aslr(Function)) << " - __" << EyeCrawl::util::calltype(Function) << "\n";
		LoggedCFunctions.push_back(FunctionName);
	}
}





int main()
{
	SetConsoleTitleA("Fuggen Dumper | Edited By Combine");
    std::cout << "Finding Roblox... ";

	HWND hWnd;
	HANDLE handle;
	unsigned long id = 0;
	hWnd = FindWindowA(NULL, "Roblox");
	GetWindowThreadProcessId(hWnd, &id);

	handle = OpenProcess(PROCESS_ALL_ACCESS, false, id);
	if (handle == INVALID_HANDLE_VALUE) {
		std::cout << "Failure!\n\n";
		std::cout << "Open Roblox!\n";
		system("PAUSE");
	}

	//else open the process as a handle
	std::cout << "Success!\n";
	//set eyecrawls target process to this handle
	EyeCrawl::open(handle);


	//begin scan

	std::cout << "Scanning...\n";
	

	printf("Lua_Print: 0x%08X.\n", EyeStep::scanner::scan_xrefs("Video Recording Started", 1)[1]);
    printf("Lua_GetField: 0x%08X.\n", EyeStep::scanner::scan_xrefs("tostring", 1)[1]); // Good Luck on this one 
	printf("LuaU_Load: 0x%08X.\n", EyeStep::scanner::scan_xrefs(": Bytecode Version Mismatch", 1)[1]);
    printf("yourfunc: 0x%08X.\n", EyeStep::scanner::scan("Invalid", true)); // Good Luck on this one 
	std::cout << "Success!\n";

	std::cout << "Credits To Static For His Beautiful EyeCrawl API!\n";
	std::cout << "https://github.com/thedoomed/EyeCrawl/ \n";

	system("PAUSE");
	return 0;


	//note: I hope this example served you well, and will help you in creating fully-fledged applications
	//such as dumpers as statics beautiful eyecrawl api can be used for A LOT more than just this
	//Keep in mind this is an example and please feel free to expand it and make it dump more offsets!
}

