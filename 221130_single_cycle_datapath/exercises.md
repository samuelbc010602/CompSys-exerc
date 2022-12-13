# Øvelsesopgaver til 30/11

# Øvelsesopgaver til 30/11

COD: 4.1
4.1.1 True 0 and false false 0
4.1.2 Since we save to a register and not to memory the only block that isn't used is Data memory
4.1.3 All blocks produce, Imm gen and data-memory produces output but it isn't used

4.2
MemToReg field is irrelevant when the RegWrite signal is 0: since the register is not being written, the value of the data on the register data write port is not used.


Download "Ripes" simulatoren.
https://github.com/mortbopet/Ripes/releases

Prøv at bruge den til at løse samme opgave.

NB: Vælg "32-bit single cycle" processor i menuen.

COD: 4.5
4.5.1 ALUop = 00 ALU control input = 0001
4.5.2 Since SD isnt a branch, which makes the AND operator return false which makes the mux choose the first ALU that adds 4 to the original PC counter which is then added to PC  see figure 4.17

Prøv også at bruge Ripes til at at løse denne opgave.
Er Ripes og COD enige i deres beskrivelse af maskinen.

Prøv også at bruge Ripes til at at løse denne opgave.
Er Ripes og COD enige i deres beskrivelse af maskinen.

COD 4.6:
4.6.1: There is already and Imm Gen connected to the MUX before the ALU
4.6.2: Branch = 0 MemRead = 0 MemtoReg = 1 ALUOp = 0010 MemWrite = 0 ALUsrc = 1 RegWrite = 1 
COD 4.15:

----------

Installer gcc kryds-oversætter til risc-v.
Linux: https://github.com/stnolting/riscv-gcc-prebuilt
Macos: https://github.com/riscv-software-src/homebrew-riscv

Skriv et lille C-program (gerne uden brug af I/O) og tjek
at krydsoversætteren virker.

Prøv at få "Ripes" simulatoren til at bruge krydsoversætteren,
således at du kan skrive C i Ripes editor og få det oversat
og udført på simulatoren.

