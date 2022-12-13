# Exercises for performant servers

## Exercises from Chapter 8 of Bryant and O'Hallaron on "Control Flow"

* 8.15
Antallet af gange "Example\n" bliver printet svarer til antallet af procesore der bliver startet hvilket svarer til antallet af 2^(antallet af processore)
* 8.23
When the if-statement is called by the child the parent doesnt wait for all five events to trigger it waits at line 26 until the first threads have executed. The parent process needs to wait for all five events
## Exercises from Chapter 12 of Bryant and O'Hallaron on "Concurrent Programming"

* 12.17
Race condition, parent threads returnere (10) inden child thread kan nå at printe
Denne bug kan fikses ved at bruge pthread_join(tid), ved at bruge denne så venter parent på at child returnere
* 12.18
A = unsafe L1 før S1, den updaterede værdi af cnt bliver ikke gemt af thread 2
B = safe
C = L1 før U2, thread 2 opdaterer efter thread 1 har loadet. 
* 12.27
Når der bliver skrevet til en af file-descriptorne så skal de gemmes inden en af de andre begynder at skrive eller læse fra filen. 
* 12.29
Der vil opstå deadlock, da P(b) (thread 1) har eksekveret vil den anden P(b) i (thread 2) vente i uendelig tid hvilket vil blokere for V(b) i Thread 1. 

## Programming task
In C, create a peer that can act as a client and server at the same time. A Python example has been included which will both send and recieve messages concurrently. Your client should be able to do the same. 

Messages sent between the peers have a simple format. The only element in the header is 4 bytes giving the length of the following body. 