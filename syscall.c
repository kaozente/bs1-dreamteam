#include <windows.h>
#include <winternl.h>
#include <stdio.h>

__declspec(noinline)
__declspec(naked)
NTSTATUS CallNtQueryInformationProcess(
  #pragma message("\t\tTODO: !!!!!!   Funktionssignatur erg�nzen    !!!!!")    
	// TODO: SIGNATUR ERG�NZEN //
    )
{
	
	__asm {           
#pragma message("\t\tTODO: !!!!!!   Syscall Nummber erg�nzen und benutzte Windows Version als Kommentar  !!!!!")            
		mov eax, // TODO: SYSCALL NR ERG�NZEN //
		mov edx, 0x7FFE0300 /* KUSER_SHARED_DATA syscall stub */
		call dword ptr [edx] /* call the stub code */

		ret
	}
}

int main(int argc, char *argv[])
{
#pragma message("\t\tTODO: !!!!!!   Funktionsruf, Fehlerbehandlung, Ausgabe implementieren    !!!!!")   
  return 0;
}