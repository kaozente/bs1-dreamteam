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

Ermoeglicht parallele Ausfuehrung (besser fuer den User, kann mehrere Kerne nutzen) aber erhoeht Komplexitaet beim Programmieren (Synchronisation, zuviele Threads erzeugen Overhead durch zu viel Context Switching)


### Task


## Aufgabe 1.3

## Verzeichnisstruktur auf Kernel abbilden

## Aufgabe 1.4

### Windows

* Windows NT übernimmt die Win16-API von OS/2
* wurde ständig weiterentwickelt und ist heute unter WinAPI bekannt
* cmd.exe

### Linux/Unix

* Shell
* 

