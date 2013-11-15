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


## Aufgabe 1.2

### Programm

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

