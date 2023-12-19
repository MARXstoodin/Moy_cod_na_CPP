#include <windows.h>
#include <iostream>

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10); // make it green so we know it's the highlighted option
    std::cout << "1231";
}
