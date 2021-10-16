

#include <iostream>
#include "Testovanie/Vyber.h"
#define initHeapMonitor() _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF)
int main()
{
	initHeapMonitor();
	Vyber vyber;
	vyber.input();
}

