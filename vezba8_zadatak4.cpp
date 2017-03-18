/*
Vezba: 8
Zadatak: 4
Dev: Darko Demic
Built using: GCC 7.0 on Arch Linux
Standard: C++ 17
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR_LENGTH 20

int main(int argc, const char *argv[]) {

	int arr[MAX_ARR_LENGTH];

	printf("Enter array length: ");
	int arrLength = 0;
	scanf("%d", &arrLength);
	if (arrLength == 0) {
		printf("Error. Enter a valid length.");
		exit(1);
	}
	else if (arrLength > MAX_ARR_LENGTH) {
		printf("Maximum array length exceeded. Exiting.\n");
		exit(2);
	}

	for (int i = 0; i < arrLength; i++) {
		printf("Array element %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
	
	int i = 0;       // i will be pointing to first element
	int j = i - 1;   // j will Point to last Element
	int temp = 0;

	while (i < j) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;j--;          
	}

	//Print out the Result
	printf("\nResult after reversal: \n");
	for (i = 0; i < arrLength; i++) {
		printf("Array element %d: %d\n", i+1, arr[i]);
	}

	system("pause");
	return 0;
}
