/*
 * Задатак 2.
 * Написати програм на језику С који чита са тастатуре низ целих бројева а дужине 2*n (n≤10) и од њега формира
 * и приказује на екрану низове: низ b чији су елементи a[0], a[2], a[4]… и низ c чији су елементи: a[1], a[3], a[5]…
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main() {

    int limit = 2 * MAX;
    int a_array[10];
    int b_array[10];
    int j = 0;
    int k = 0;
    int n = 0;

    //Unos velicine niza
    printf("Unesite velicinu individualnih nizova: ");
    scanf("%d", &n);
    //Provera podataka koje je korisnik uneo
    if (n <= 0 || n > MAX) {
        perror("N out of range.");
        exit(1);
    }

    for (int i = 0; i < n * 2; i++) {
        printf("Unesite %d. element : ", i + 1);

        if ((i % 2) == 0) {
            //Ako je paran element ide u a
            scanf("%d", &a_array[j++]);
        } else {
            //Ako je neparan element ide u b
            scanf("%d", &b_array[k++]);
        }
    }

    //Ispis niza a
    printf("\nNiz A: ");
    for (int i = 0; i < n; i++) {
        printf("\n%d. Element: %d\n", i, a_array[i]);
    }

    //Ispis niza b
    printf("\nNiz B: ");
    for (int i = 0; i < n; i++) {
        printf("\n%d. Element: %d\n", i, b_array[i]);
    }

    return 0;
}

