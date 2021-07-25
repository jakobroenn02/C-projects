#include <iostream>
#include <Windows.h>
#include <processthreadsapi.h>

using namespace std;

int main()
{
	DWORD pid = 0;
	cout << "Enter a Proccess ID: ";
	cin >> pid;

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hProcess == NULL)
	{
		cout << "Couldn't find any PID. Error code: " << GetLastError() << endl;
		system("Pause");
			return EXIT_FAILURE;
	}

	uintptr_t memoryAddress = 0x0;
	cout << "Enter a memory address: 0x";
	cin >> hex >> memoryAddress;
	cout << "Reading memory address.." << uppercase << hex << memoryAddress << endl;

	int readint = 0;
	BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)memoryAddress, &readint, sizeof(int), NULL);
	if (rpmReturn == FALSE)
	{
		cout << "Operation failed";
		system("pause");
		return EXIT_FAILURE;
	}

	cout << "Integer Read = " << dec << readint << endl;
	cout << "Press enter to quit." << endl;
	system("pause > nul");

	return EXIT_SUCCESS;
}


