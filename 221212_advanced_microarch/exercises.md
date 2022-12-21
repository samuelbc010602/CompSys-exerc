# Øvelser til 12. december

## Opsamling

Brug tid til at afklare spørgsmål A5.

Overskydende øvelser fra forrige uge.

## Øvelser i afviklingsplot

(se note her: https://github.com/diku-compSys/compSys-e2022-pub/blob/main/resources/Afviklingsplot/plot.md)

### Opgave 1

Opstil et afviklingsplot for en simpel 5-trins pipeline som beskrevet i COD (og i begyndelsen af noten) for to
iterationer af følgende programstump:

~~~
Loop:
    addi x4,x4,1
    slli x11,x4,5
    add  x11,x16,x11
    lw	 x11,8(x11)
    slli x12,x4,2
    add	 x12,x17,x12
    sw   x11,0(x12)
    bge  x9,x4,Loop
~~~


addi x4  x4 1		= fe de ex mm wb
slli x11 x4 1		=    fe -- de ex mm wb
add x11  x16  x11	=    	fe -- -- de ex mm wb
lw x11 8(x11) 		=	      fe -- -- de ex mm wb
slli x12 x4 2		=	      	    fe -- de ex mm wb
add x12,x17,x12		= 		       	  fe -- de ex mm wb
sw x11 0(x12)		= 		       	     fe -- de de ex mm wb
bge x9 x4 loop		= 			           fe -- de ex mm wb



### Opgave 2

Opstil et afviklingsplot for en 5-trins 2-vejs superskalar pipeline som beskrevet i noten for to
iterationer af programstumpen fra opgave 1.


addi x4  x4 1		= fe de ex wb
slli x11 x4 1		= fe -- de ex wb
add x11  x16  x11	=    fe -- de ex wb
lw x11 8(x11) 		=    fe -- de -- ag mm wb !!
slli x12 x4 2		=    	fe -- de ex wb (der kan ikke køres tre de på samme tid derfor stall, selvom den er ufhængig)
add x12,x17,x12		= 	   fe -- de ex wb (den kan først "ex" når wb fra den forrige er foretaget)
sw x11 0(x12)		=	      fe -- de ag mm (ag nedenunder wb)
bge x9 x4 loop		=	      	 fe de ex wb (uafhængig)

Med 5-trins menes der at der køres fem stages ligesom sædvanlig
Lig mærke til at kommandoer som lw der er afhængig af den foregående først kan lave "ag" når der er lavet "wb"

Hvis der er tvivlspørgsmål undervejs vælges en mulig fortolkning - gå ikke i stå.
Anfør eventuelle antagelser om mikroarkitekturen.





/*case 59: Disse funktioner hører ikke til i RISC-V32 de er en del af RISC-V64
            switch(funct3){
                case 0:
                    if(funct7 == 0){
                        registers[rd] = ((int)registers[rs1]+(int)registers[rs2]);
                        //rTypeAddw(instruction);

                    }else{
                        registers[rd] = ((int)registers[rs1]+(int)registers[rs2]);
                        //rTypeSubw(instruction);
                    }
                    break;
                case 1:
                    //rTypeSllw(instruction);
                    break;
                case 2:
                    //rTypeSrlw(instruction);
                    break;
                case 3:
                    //rTypeSraw(instruction);
                    break;
            }
            break;
            */test


int instructions[] = {0b00010101100100000000000010010011,
                        0b00000111101100000000000100010011,
                        0b00000000001000001000010001100011,
                        0b00000000100000000000000011101111,
                        0b00000000001000000000000010010011,
                        0b00000010100000000000000100010011};
for(int i = 0;i<(sizeof(instructions)/sizeof(int));i++){
    segmentHandler(instructions[i],mem);
}  
assert(registers[2] == 40);





