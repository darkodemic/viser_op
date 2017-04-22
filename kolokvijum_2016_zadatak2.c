#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define MIN 3

int main(int argc, const char *argv[]) {

    char c;
    puts("Enter Char: ");
    c = fgetc(stdin);
    printf("Entered char : %c | Char Before: %c | Char After : %c\n", c, c - 1, c + 1);

    printf("Enter n: ");
    int n = 0;
    scanf("%d", &n);

    if (n < MIN || n > MAX) {
        fprintf(stderr, "n exceeded maximum of %d or minimum of %d", MAX, MIN);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        if (i == 0 || i == (n - 1)) {
            for (int j = 0; j < n; j++) printf("%c", c);
        } else {
            //n - 2 jer ispisujemo samo prvi i zadnji a treba nam onda 2 mesta manje
            printf("%c%*s%c", c, n - 2, "", c);
        }
        printf("\n");
    }

    char side = 'l';
    scanf("%c", &side); // Da ponistimo/pojedemo '\n' znak koji saljemo zadnjim printf("\n"); u console buffer
    printf("Select side (L/l) or (R/r): ");

    scanf("%c", &side);

    if (side == 'l' || side == 'L') {
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == (n - 1)) {
                for (int j = 0; j < n; j++) printf("%c", c);
            } else {
                printf("%*s%c", n - 1, "", c);
            }
            printf("\n");
        }
    } else if (side == 'r' || side == 'R') {
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == (n - 1)) {
                for (int j = 0; j < n; j++) printf("%c", c);
            } else {
                printf("%c%*s", c, n - 1, "");
            }
            printf("\n");
        }
    }

    return 0;
}
