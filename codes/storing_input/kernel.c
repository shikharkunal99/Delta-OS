#include "io.h"


void calculator()
{
    printstr("Calculator");
    endl();
    char operator;
    int a,b;

    printstr("Enter an operator (+, -, *,): ");
    operator=scanch();

    printstr("Enter two operands: ");
    a=scanint();
    b=scanint();
    
    switch(operator)
    {
        case '+':
            printint(a+b);
            endl();
            break;

        case '-':
            printint(a-b);
            endl();

        case '*':
            printint(a*b);
            endl();
        case '/':
            if(b==0)
                printstr("Division by 0 not defined");
            else
                printint(a/b);
            endl();

        default:
            printstr("Error! operator is not correct");
            calculator();
    }
     
   
}



void kmain(void)
{
    const char *str = "what is your name?";
    clrscr();
    printstr(str);
    endl();
    char *name=scanstr();
    printstr("welcome ");
    printstr(name);
    endl();
    calculator();

    
}
