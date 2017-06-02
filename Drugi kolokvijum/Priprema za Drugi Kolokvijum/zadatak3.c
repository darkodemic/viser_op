/*
 * Задатак 3.
 * Написати програм на језику С који чита са тастатуре низ целих бројева а дужине n (n≤10), као и два цела броја
 * m и n и од задатог низа формира следеће низове: низ b од елемената низа a, у опсегу од m до n, а низ с од
 * елемената низа a, ван овог опсега; низ d, од низа c додатог на крај низа b.
*/

/*
 * Vizualizacija
 *
 * a = full
 * b = a[m .. n]
 * c = a[..m-n..]
 * d = b[] + c[]
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main() {

    int m = 0;
    int n = 0;
    unsigned int array_count = 0; //Kako korisnici ne bi mogli da unesu negativne brojeve

    //Nizovi
    int a_array[MAX];
    int b_array[MAX];
    int c_array[MAX];
    int d_array[MAX * 2]; //Zato sto moramo da se osiguramo za duplu velicinu

    printf("Unesite duzinu niza: ");
    scanf("%d", &array_count);

    //Provera vrednosti koju je korisnik uneo
    if (array_count == 0 || array_count > MAX) {
        perror("Array Length out of range.");
        exit(1);
    }

    //Unos originalnog/primarnog niza
    printf("Unesite niz A: ");
    for (int i = 0; i < array_count; i++) {
        scanf("%d", &a_array[i]);
    }

    printf("Unesite M: ");
    scanf("%d", &m);
    printf("Unesite N: ");
    scanf("%d", &n);

    //Popunjavanje niza b
    for (int i = m; i < n; i++) {
        b_array[i] = a_array[i];
    }

    //Popunjavanje niza c
    for (int i = 0; i < array_count; i++) {
        // Ako je unutar m-n opsega preskacemo tu iteraciju
        if (i > m || i < n) continue;
        c_array[i] = a_array[i];
    }

    int j = 0;
    //Popunjavanje niza d
    for (int i = 0; i < (array_count * 2); i++) {
        if (i <= array_count) {
            //Prvo kopiramo b
            d_array[i] = b_array[i];
        }
        else {
            d_array[i] = c_array[j++];
        }
    }


        printf("\nArray A: \n");
    for (int i = 0; i < array_count; i++) {
        printf("[ e:%d ] -> [ %d ]\n", i, a_array[i]);
    }
    printf("\nArray B: \n");
    for (int i = 0; i < array_count; i++) {
        printf("[ e:%d ] -> [ %d ]\n", i, b_array[i]);
    }
    printf("\nArray C: \n");
    for (int i = 0; i < array_count; i++) {
        printf("[ e:%d ] -> [ %d ]\n", i, c_array[i]);
    }

    printf("\nArray D: \n");
    for (int i = 0; i < (array_count * 2); i++) {
        printf("[ e:%d ] -> [ %d ]\n", i, d_array[i]);
    }
    
    return 0;
}

