/*
Vezba: 3
Zadatak: 6
Dev: Darko Demic
Built using: GCC 7.0 on Arch Linux
Standard: C11
Flags: -Wextra, -Wall, -Wfloat-equal, -O3, -ftrapv
*/

#include <stdio.h>

int main(int argc, const char *argv[]) {
    
    printf("Enter X: "); float x = 0; scanf("%f",&x);
    printf("Enter Y: "); float y = 0; scanf("%f",&y);
    printf("Enter Z: "); float z = 0; scanf("%f",&z);
    
    if ( x >= y && y >= z) {
        x *= 2; 
        y *= 2;
        z *= 2;
    }
    else {
        x *= -1;
        y *= -1;
        z *= -1;
    }
    
    printf("X: %f\nY: %f\nZ: %f", x, y, z);
    
    return 0;
}
