all : kernel-001

run : kernel-001
	qemu-system-i386 -kernel kernel-001

kc.o : kernel.c
	gcc -m32 -c kernel.c -o kc.o


kasm.o : kernel.asm
	nasm -f elf32 kernel.asm -o kasm.o

kernel-001 : kasm.o kc.o
	ld -m elf_i386 -T link.ld -o kernel-001 kasm.o kc.o

clean :
	rm -fr *.o 


	
