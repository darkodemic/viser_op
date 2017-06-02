/*
 * Задатак 4.
 * Написати програм на језику С који у задатом низу целих бројева дужине n (n≤100), одређује и приказује на
 * екрану: редни број елемента код кога се по први пут појављује најмања вредност истог низа, као и редни број
 * елемента код кога се по последњи пут појављује највећа вредност истог низа.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {

    int n = 0;
    int array[MAX];
    int min = 0; //Minimalna vrednost niza
    int max = 0; //Maximalna vrednost niza
    int minLoc = 0; //Lokacija max-a
    int maxLoc = 0; //Lokacija max-a

    //Unos duzine niza
    printf("Unesite duzinu niza: ");
    scanf("%d",&n);
    //U slucaju da je niz izvan opsega izlazimo iz programa
    if (n == 0 || n > MAX) {
        perror("Array Lenght out of range.");
        exit(1);
    }
    //Popunjavanje niza
    printf("Unos niza: \n");
    for (int i = 0; i < n; i++) {
        printf("Unesite %d. element: ", i + 1);
        scanf("%d", &array[i]);

        //Provera odmah prilikom unosa
        if (i == 0) {
            min = array[i];
            max = array[i];
        }
        //Provera min niza
        if (array[i] < min) {
            min = array[i];
            minLoc = i;
        }
        //Provera max niza
        if (array[i] >= max) {
            max = array[i];
            maxLoc = i;
        }
    }

    printf("Poslednji Maximum niza je: %d | Njegova lokacija u nizu je: %d\n"
                   "Prvi Minimum niza je: %d | Njegova lokacija u nizu je: %d\n", max, maxLoc + 1,min,minLoc + 1);

    return 0;
}