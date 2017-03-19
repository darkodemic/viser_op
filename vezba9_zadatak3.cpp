/*
Vezba: 9
Zadatak: 3
Dev: Darko Demic
Built using: GCC 7.0 on Arch Linux
Standard: C++ 17
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR_LENGTH 10


int removeNthElem(int *arr, int *arrnew, int num) {
	//Prolazimo kroz array i trazimo svaki nth element i prepisujemo tj. pomeramo niz preko njega za jedno mesto ulevo. 
	int removed = 0;
	int j = 0;
	for (int i = 0; i < num; i++) {
		if ((i % 2) == 1) {			
			removed++; //brojimo koliko elemenata smo izbrisali. tj. koliko drugih elemenata imamo.
		}
		if ((i % 2) == 0) {
			arrnew[j++] = arr[i];
		}
	}
	return removed;
}

void fillWithZeros(int removed, int *arrnew, int num) {
	for (int i = (num - removed); i < num; i++) {
		arrnew[i] = 0;
	}
}

int main(int argc, const char *argv[]) {
	
	int num, temp, arr[MAX_ARR_LENGTH];
	
	printf("Enter array length: ");
	scanf("%d", &num);
	if (num > MAX_ARR_LENGTH) {
		printf("Array length exceeded. Exiting.\n");
		exit(1);
	}
	for (int i = 0; i < num; i++) {
		printf("Array element %d: ", i);
		scanf("%d", &arr[i]);
	}
	//Array stored
	int removed = 0;
	int arrnew[MAX_ARR_LENGTH];
	removed = removeNthElem(arr, arrnew, num);

	fillWithZeros(removed, arrnew, num);

	printf("%d\n", removed);
	for (int i = 0; i < num; i++) {
		printf("Array element %d: %d \n", i, arrnew[i]);
	}

	return (0);
}
