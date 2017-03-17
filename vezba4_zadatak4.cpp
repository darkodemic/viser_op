/*
Vezba: 4
Zadatak: 4
Dev: Darko Demic
Built using: GCC 7.0 on Arch Linux
Standard: C++ 17
*/

#include <stdio.h>

int main(int argc, const char *argv[]) {
    
    int temp;
    int max = 0; //0-ed so we can compare it
    int min = 0; //0-ed so we can compare it
    printf("Enter array of numbers, press enter after each number: \n");
    while (scanf("%d",&temp), temp != 0) { //First arguments gets executed second evaluated
        if (temp > max){
            max = temp;    
        }
        else if (temp < min){
            min = temp;
        }
    }
    
    printf("MAX: %d\nMIN: %d",max,min);
    
}
