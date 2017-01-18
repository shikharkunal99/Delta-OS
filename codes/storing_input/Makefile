all : kernel

run: kernel
	qemu-system-i386 -kernel kernel

kc.o : kernel.c
	gcc -m32 -c kernel.c -o kc.o


kasm.o : kernel.asm
	nasm -f elf32 kernel.asm -o kasm.o

kernel : kasm.o kc.o
	ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o
