#include "io.h"

/*
void calculator()
{
	char operator;
    double firstNumber,secondNumber;

    printstr("Enter an operator (+, -, *,): ");
    scanf("%c", &operator);

    printstr("Enter two operands: ");
    scanf("%lf %lf",&firstNumber, &secondNumber);

    switch(operator)
    {
        case '+':
            printf("%.1lf + %.1lf = %.1lf",firstNumber, secondNumber, firstNumber + secondNumber);
            break;

        case '-':
            printf("%.1lf - %.1lf = %.1lf",firstNumber, secondNumber, firstNumber - secondNumber);
            break;

        case '*':
            printf("%.1lf * %.1lf = %.1lf",firstNumber, secondNumber, firstNumber * secondNumber);
            break;

        case '/':
            printf("%.1lf / %.1lf = %.1lf",firstNumber, secondNumber, firstNumber / firstNumber);
            break;

        // operator doesn't match any case constant (+, -, *, /)
        default:
            printf("Error! operator is not correct");
    }
    
    return 0;
}

*/


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
	//calculator();

	
}
