#include "keyboard_map.h"

/* there are 25 lines each of 80 columns; each element takes 2 bytes */
#define LINES 25
#define COLUMNS_IN_LINE 80
#define BYTES_FOR_EACH_ELEMENT 2
#define SCREENSIZE BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE * LINES

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64


#define ENTER_KEY_CODE 0x1C

extern unsigned char keyboard_map[128];
//extern char keyboard_handler(void);
extern char read_port(unsigned short port);
extern void write_port(unsigned short port, unsigned char data);

/* current cursor location */
unsigned int current_loc = 0;
/* video memory begins at address 0xb8000 */
char *vidptr = (char*)0xb8000;

void kprint(const char *str)
{
	unsigned int i = 0;
	while (str[i] != '\0') {
		vidptr[current_loc++] = str[i++];
		vidptr[current_loc++] = 0x07;
	}
}

void kprint_newline(void)
{
	unsigned int line_size = BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE;
	current_loc = current_loc + (line_size - current_loc % (line_size));
}

void clear_screen(void)
{
	unsigned int i = 0;
	while (i < SCREENSIZE) {
		vidptr[i++] = ' ';
		vidptr[i++] = 0x07;
	}
}

char *scan(void)
{	
	unsigned char status;
	char keycode;
	static char str[100];
	int i=0;
	while(1)
	{
		write_port(0x20, 0x20);
		status = read_port(KEYBOARD_STATUS_PORT);
		if (status & 0x01)
		{
			keycode = read_port(KEYBOARD_DATA_PORT);
			if(keycode == ENTER_KEY_CODE) 
			{
				kprint_newline();
				str[i++]='\0';
				return str;
			}
			if(keycode<0)
				continue;
			str[i++]=keyboard_map[(unsigned char) keycode];
			vidptr[current_loc++] = keyboard_map[(unsigned char) keycode];
			vidptr[current_loc++] = 0x07;
		}
	}
	return str;
	
}


void kmain(void)
{
	const char *str = "what is your name?";
	clear_screen();
	kprint(str);
	kprint_newline();
	kprint_newline();
	char *name=scan();
	kprint("welcome ");
	kprint(name);

	
}
