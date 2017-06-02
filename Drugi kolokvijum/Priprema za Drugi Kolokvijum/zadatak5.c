/*
 *
 * Задатак 5.
 * Написати програм на језику С који израчунава и приказује на екрану суму свих елемената задатог низа целих
 * бројева дужине n (n≤100), који су између прве и друге нуле тог низа, ако постоје бар две нуле у задатом низу.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {

    unsigned int n = 0;
    int array[MAX];
    int suma = 0;
    int prvaNula = 0;
    int drugaNula = 0;

    //Unos duzine niza
    printf("Unesite duzinu niza: ");
    scanf("%d", &n);

    //Provera podataka koje je korisnik uneo
    if (n <= 0 || n > MAX) {
        perror("Array length out of range.");
        exit(1);
    }

    printf("Unos niza: \n");

    for (int i = 0; i < n; i++) {
        printf("Unesite %d. element: ", i + 1);
        scanf("%d", &array[i]);

        //Ako smo vec imali nulu i trenutni element je 0 znaci da je to druga nula
        if (prvaNula == 1 && array[i] == 0) {
            drugaNula = 1;
        }

        //Ako smo naisli na nulu i prvaNula se nije jos pojavila trigerujemo/setujemo prvuNulu
        if (array[i] == 0 && prvaNula == 0) {
            prvaNula = 1;
        }

        //Ako je prvaNula trigger-ovana i trenutni element nije 0 unosimo ovaj broj u sumu
        //Naknadno posto nam se trazi samo prvi "podniz" izmedju prve i druge nule primacemo brojeve ali ih necemo sabirati
        if (prvaNula == 1 && drugaNula == 0) {
            suma += array[i];
        }
    }

    printf("Ukupna suma brojeva izmedju prve i druge nule u nizu je: %d", suma);

    return 0;
}