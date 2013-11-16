# BS Uebung #

## Aufgabe 1.1 ##

### Ziele beim BS Entwurf 

* Hardware Abstraktion
* Skalierbarkeit
* Kompatibilitaet
* Stabilitaet??

### Beispiele fuer BS-Funktionen in User/Kernelmode

#### Kernel Mode

* CPU / Process / Thread Mgmt
* Memory / IO Management
* Multiprocessor Management
* Interprozess Kommunikation
* Teile von Datei/Netzwerkverwaltung

#### User Mode

* Compiler / Assembler / Linker / Loader
* Teile von Datei/Netzwerkverwaltung
* Alle User Applications / Anwenderprogramme


### Vor / Nachteile der Trennung von U/K

#### Vorteile:

* Schutzkonzept: kritische Aufgaben dürfen nur im Kernel Mode durchgeführt werden
* (Prozesserzeugung, Treiber ändern, etc.)
* -> Crashes im Kernel Mode führen grundsätzlich zum Absturz
* Usermode hat nur begrenzten Zugriff auf Ressourcen -> kein Konflikt im Hauptspeicher


#### Nachteile:

* Trennung erfordert Zyklen zum Umschalten -> Rechner wird "langsamer" (Stichwort Interrupts)

## Aufgabe 1.2

### Programm

* Abfolge von Befehlen in einer Programmiersprache
* die Ausführung eines Programms erzwingt genau einen Prozess

### Prozess

Repraesentiert die Instanz eines laufenden Programms

* Adressbreich
* Resourcen
* Sicherheit (Token..)

Konzept von Signalen, Unterprozessen...

Startet immer mit genau einem Thread (Main Methode)


### Thread

"*Execution Context*"

* Werden unabhaengig von ihrem Prozess gescheduled
* Teilen sich den Adressraum ihres Prozesses
* Hat eigenen Programm Counter

Ermoeglicht parallele Ausfuehrung (besser fuer den User, kann mehrere Kerne nutzen) aber erhoeht Komplexitaet beim Programmieren (Synchronisation, zuviele Threads erzeugen Overhead durch zu viel Context Switching)


### Task

* Synonym für eine Aufgabe des Betriebssystems
* Oft auch als mit dem begriff des Prozesses gleichgesetzt
* Im Kontext eines Subprozesses kann ein Task auch einen Thread meinen
* Meist beschreibt ein Task eine Menge von Threads und ist daher mit dem Begriff Prozess gleichgesetzt

## Aufgabe 1.3

## Verzeichnisstruktur auf Kernel abbilden

## Aufgabe 1.4

### Windows

* Windows NT übernimmt die Win16-API von OS/2
* wurde ständig weiterentwickelt und ist heute unter WinAPI bekannt
* cmd.exe

### Linux/Unix

* Shell
* Linux-Kernel haben eine API zum Zugriff auf Resourcen im User-Mode, jedoch keine Kernel-Mode-Kernel-API (lol)
* 

## Aufgabe 1.5

### Windows

```c
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
                GetCurrentProcess(),                // Process Handle
                ProcessBasicInformation,        // Info Klasse
                &pbi,                                                // pointer auf Info Objekt
                sizeof(PROCESS_BASIC_INFORMATION), // groesse des objekts
                NULL // groesser der rueckgabe (null, pbi wird in place geaendert)
                );

        if (rueck > 0)
        {
                printf("Fehler %lx \n", rueck);

        }
        else
        {
                printf("syscall: %d ", pbi.UniqueProcessId);
                printf("usermode: %d \n", GetCurrentProcessId() );
        }
        

        return 0;
}
```

