#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 5
#define MIN 2

int main(int argc, const char *argv[]) {

    char letter;
    printf("Enter a letter: ");
    scanf("%c", &letter);
    if (!isalpha(letter)) {
        fprintf(stderr, "Entered char not a letter. Exiting.");
        exit(1);
    }

    char before = letter - 1;
    char after = letter + 1;

    printf("Symbol: %c | Before: %c | After: %c\n", letter, before, after);

    int n = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n < MIN || n > MAX) {
        fprintf(stderr, "Entered number is out of limits (min: %d | max: %d). Exiting.", MIN, MAX);
        exit(2);
    }

    //Printing circle
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == (n - 1)) {
            for (int j = 0; j < n; j++) printf("%c", letter);
        } else {
            printf("%c%*s%c", letter, n - 2, "", letter);
        }
        printf("\n");
    }

    n = 0;
    int m = 0;
    printf("Enter a number n: ");
    scanf("%d", &n);
    if (n < MIN || n > MAX) {
        fprintf(stderr, "Entered number is out of limits (min: %d | max: %d). Exiting.", MIN, MAX);
        exit(2);
    }

    printf("Enter a number m: ");
    scanf("%d", &m);
    if (m < MIN || m > MAX) {
        fprintf(stderr, "Entered number is out of limits (min: %d | max: %d). Exiting.", MIN, MAX);
        exit(2);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) putchar(letter);
            for (int k = 0; k < n; k++) putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}
