/*
Vezba: 2
Zadatak: 5
Dev: Darko Demic
Built using: GCC 7.0 on Arch Linux
Standard: C++ 17
*/

#include <stdio.h>

int main(int argc, const char *argv[]) {
    
    printf("Enter A and B: ");
    int a = 0; int b = 0; //Initialised them for safety reasons
    scanf("%d %d", &a, &b); //We accept them as ints
    //Added casting so operation would be performed as float not as int.
    //Some optimization toolchains perform operation based on member types not final type
    float c = ((float)(a) + b) / 2;
    printf("Arithmetic mean:\nAs real number: %f\nAs Integer: %d",c, (int)(c));
    
    return 0;
}
