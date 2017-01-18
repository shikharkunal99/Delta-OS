#Build Commands

###For compiling ASM : 
nasm -f elf32 kernel.asm -o kasm.o

###For compiling C files :
gcc -m32 -c kernel.c -o kc.o
If you get the following error message:

kc.o: In function `idt_init':
kernel.c:(.text+0x129): 
undefined reference to `__stack_chk_fail'

compile with the -fno-stack-protector option:

gcc -fno-stack-protector -m32 -c kernel.c -o kc.o

###For linking :
ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o

##For running on emulator(qemu) :
qemu-system-i386 -kernel kernel
