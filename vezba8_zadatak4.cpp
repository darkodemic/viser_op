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
	int i, j, num, temp;
	num = 0;
	printf("\nEnter no of array elements: ");
	scanf("%d", &num);

	if (num == 0) {
		printf("Error. Enter a valid length.");
		exit(1);
	}

	if (num > MAX_ARR_LENGTH) {
		printf("Maximum array length exceeded. Exiting.\n");
		exit(1);
	}

	//Read elements in an array
	for (i = 0; i < num; i++) {
		printf("Array element %d : ", i + 1);
		scanf("%d", &arr[i]);
	}

	j = i - 1;   // j will Point to last Element
	i = 0;       // i will be pointing to first element
	temp = 0;

	while (i < j) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;             // increment i
		j--;          // decrement j
	}

	//Print out the Result
	printf("\nResult after reversal : \n");
	for (i = 0; i < num; i++) {
		printf("Array element %d: %d\n", i + 1, arr[i]);
	}

	return (0);
}
