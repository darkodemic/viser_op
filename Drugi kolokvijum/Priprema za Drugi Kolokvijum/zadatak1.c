/*
 * Задатак 1.
 * Написати програм на језику С који чита са тастатуре два низа реалних бројева а и b сваки дужине n, а онда
 * приказује на екрану низ с формиран као: с=a[i]b[i], i=0÷n-1 и понавља задатак све док је n у опсегу од 1 до 10.
*/
#include <stdio.h>

#define MAX 10

int main() {

    float a[MAX], b[MAX], s = 0;
    int i, n;

    while (1) {
        printf("\nn?");
        scanf("%d", &n);

        if (n < 1 || n > MAX) break;

        /*Citanje nizova*/

        printf("\nPrvi niz realnih brojeva:\n");
        for (i = 0; i < n; i++) scanf("%f", &a[i]);

        printf("\nDrugi niz realnih brojeva:\n");
        for (i = 0; i < n; i++) scanf("%f", &b[i]);

        /*Stampanje rezultata*/
        for (i = 0; i < n; i++) s += a[i] * b[i];

        printf("\nSkalarni proizvod: %f", s);
    }
}