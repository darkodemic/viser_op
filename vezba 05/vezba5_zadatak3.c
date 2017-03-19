/*
Vezba: 5
Zadatak: 3
Dev: Darko Demic
Built using: GCC 7.0 on Arch Linux
Standard: C11
Flags: -Wextra, -Wall, -Wfloat-equal, -O3, -ftrapv
*/

#include <stdio.h>
#include <math.h>


int main(int argc, const char *argv[]) {
	printf("Calculator v. 0.0.1\n\n"); //Title because why not have some fun
									   //Nice "menu"
	printf("Select Operation: \n"
		"+ : Addition\n"
		"- : Subtraction\n"
		"* : Multiplication\n"
		"/ : Division\n"
		"%% : remainder after division (modulo division)\n"
		"Option: ");

	char operation;
	scanf("%c", &operation);

	printf("Enter First Number: ");
	double firstNumber = 0; //Always 0-ed
	scanf("%lf", &firstNumber);

	printf("Enter Second Number: ");
	double secondNumber = 0; //Always 0-ed
	scanf("%lf", &secondNumber);

	double result = 0;

	switch (operation) {
	case '+':
		result = firstNumber + secondNumber;
		printf("Result: %lf\n", result);
		break;
	case '-':
		result = firstNumber - secondNumber;
		printf("Result: %lf\n", result);
		break;
	case '*':
		result = firstNumber * secondNumber;
		printf("Result: %lf\n", result);
		break;
	case '/':
		if (secondNumber == 0) {
			printf("Division by 0 is IMPOSSIBLE!!!\n");
			break;
		}
		result = firstNumber / secondNumber;
		printf("Result: %lf\n", result);
		break;
	case '%':
		result = fmod(firstNumber, secondNumber); //You asked for real numbers to be entered so here is function that does that
		//(int)(result) = (int)(firstNumber) % (int)(secondNumber); //This is solution if you want int type result
		printf("Result: %lf\n", result);
		break;
	}
	return 0;
}
