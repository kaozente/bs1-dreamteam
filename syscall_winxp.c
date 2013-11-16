#include <windows.h>
#include <winternl.h>
#include <stdio.h>

__declspec(noinline)
__declspec(naked)

NTSTATUS CallNtQueryInformationProcess(	
	// vgl. WRK Docs
	HANDLE Processhandle,
	PROCESSINFOCLASS ProcessInformationClass,
	PVOID ProccessInformation,
	ULONG ProcessInformationenLength,
	PULONG ReturnLength								   
)
{
	
	__asm {           
		mov eax, 0x0086 // Windows XP SP2 //
		mov edx, 0x7FFE0300 /* KUSER_SHARED_DATA syscall stub */
		call dword ptr [edx] /* call the stub code */

		ret
	}
}

int main(int argc, char *argv[])
{

  return 0;
}