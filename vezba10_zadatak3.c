/*
Vezba: 10
Zadatak: 3
Dev: Darko Demic
Built using: GCC 7.0 on Arch Linux
Standard: C11
Flags: -Wextra, -Wall, -Wfloat-equal, -O3, -ftrapv
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 80

char *readCli(int* bufferSize) {
	printf("Enter your text: ");
	int size_b = 40;
	char *buffer;
	buffer = (char*)malloc(size_b * sizeof(char));
	if (buffer == NULL) { exit(1); }
	char c; int i = 0;
	while ((c = fgetc(stdin)) != '\n') {
		if ((i % 40) == 0) {
			buffer = (char*)realloc(buffer, (size_b * 2) * sizeof(char));
			if (buffer == NULL) { exit(3); }
		}
		if (i >= 80) {
			printf("Maximum buffer size exceeded! Maximum is: %d characters.", MAX_INPUT_LENGTH);
			break;
		}
		buffer[i++] = c;
	}

	buffer[i] = '\0';
	buffer = (char*)realloc(buffer, (i + 1) * sizeof(char));
	if (buffer == NULL) { exit(4); }
	//Unutar buffera imamo text 
	*bufferSize = i + 1; //da promenimo var u kome se nalazi duzina koja nam treba za kasnije
	return buffer;
}

char findFirstSymbol(char *text, int length) {
	
	char notfound = '0';
	for (int i = 0; i < length; i++) {
		if (isalpha(text[i])) {
			notfound = '0';
		}
		else if (isdigit(text[i])) {
			notfound = '0';
		}
		else {
			return text[i];
		}
	}
	return notfound;
}

void makeTriangle(char symbol) {
	printf("Triangle align (Left - L/l | Right: R/r): ");
	char alignPyramide = 'L'; //Pretpostavljamo da je jedno ako korisnik samo pritisne enter
	scanf("%c", &alignPyramide);
	if (alignPyramide == 'L' || alignPyramide == 'l') {
		//Align Left or default align
		int j = 1;
		for (int i = 1; i <= 10; i++) { //Idemo za svaki red. deset redova imamo
			j = 1; //Brojimo koliko puta smo ucrtali taj char
			while (j <= i) {
				printf("%c", symbol);
				j++;
			}
			printf("\n");
		}
		
	}
	if (alignPyramide == 'R' || alignPyramide == 'r') {
		//Align Right
		
		for (int i = 1; i <= 10; i++) {
			printf("%*s", 10 - i, "");
			for (int j = 0; j<i; j++) {
				printf("%c", symbol);
			}
			printf("\n");
		}
	}
}

int main(int argc, const char *argv[]) {
	
	int textLength = 0;
	char *text = readCli(&textLength);
	
	char symbol = findFirstSymbol(text, textLength);
	if (symbol == '0') {
		printf("No non-alphanumeric symbols have been found in provided text.\n");
		exit(2);
	}
	else {
		makeTriangle(symbol);
	}
	system("pause");
	return (0);
}
