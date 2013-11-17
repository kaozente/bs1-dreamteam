#include <windows.h>
#include <winternl.h>
#include <stdio.h>

__declspec(noinline)
__declspec(naked)

NTSTATUS CallNtQueryInformationProcess(	
	// vgl. WRK Docs
	HANDLE ProcessHandle,
	PROCESSINFOCLASS ProcessInformationClass,
	PVOID ProccessInformation,
	ULONG ProcessInformationenLength,
	PULONG ReturnLength								   
)
{
	
	__asm {           
		mov eax, 0x009a // Windows XP SP3 x86 //
		mov edx, 0x7FFE0300 /* KUSER_SHARED_DATA syscall stub */
		call dword ptr [edx] /* call the stub code */

		ret
	}
}

int main(int argc, char *argv[])
{
	PROCESS_BASIC_INFORMATION pbi;
	DWORD rueck;
	DWORD fehler;
	LPVOID lpMsgBuf;

	rueck = CallNtQueryInformationProcess(
		GetCurrentProcess(),		// Process Handle
		ProcessBasicInformation,	// Info Klasse
		&pbi,						// pointer auf Info Objekt
		sizeof(PROCESS_BASIC_INFORMATION), // groesse des objekts
		NULL // groesser der rueckgabe (null, pbi wird in place geaendert)
		);

	if (rueck > 0)
	{
		printf("Fehler  %lx \n", rueck);

	}
	else
	{
		printf("syscall: %d  ", pbi.UniqueProcessId);
		printf("usermode: %d  \n", GetCurrentProcessId() );
	}
	

	return 0;
}