/*
Vezba: 6
Zadatak: 4
Dev: Darko Demic
Built using: GCC 7.0 on Arch Linux
Standard: C++ 17
*/

#include <stdio.h>

#define MAX_STUDENTS 50

int main(int argc, const char *argv[]) {
    
    int desetke = 0;
    int devetke = 0;
    int osmice = 0;
    int sedmice = 0;
    int sestice = 0;
    int petice = 0;
    float averageGrade = 0;
    
    int studentCount = 0;
    
    printf("Enter student count: "); scanf("%d", &studentCount);
    if (studentCount > MAX_STUDENTS) {
        printf("Student Count cannot exceed %d.\n", MAX_STUDENTS);
        return 1;
    }
    
    for (int i = 0; i < studentCount; i++) {
        printf("Student %d. score: ",i+1);
        float temp = 0;
        while(scanf("%f",&temp)){
            if(temp < 0 || temp > 100) {
                printf("Minimum score is 0 and maximum is 100.\nEnter Again for student %d:", i+1);
            }
            else {
                //If the number is valid we continue
                if (temp >= 95 && temp <= 100) {
                    desetke += 1;
                    averageGrade += 10;
                }
                else if (temp >= 85 && temp <= 94) {
                    devetke += 1;
                    averageGrade += 9;
                }
                else if (temp >= 75 && temp <= 84) {
                    osmice += 1;
                    averageGrade += 8;
                }
                else if (temp >= 65 && temp <= 74) {
                    sedmice += 1;
                    averageGrade += 7;
                }
                else if (temp >= 55 && temp <= 64) {
                    sestice += 1;
                    averageGrade += 6;
                }
                else if (temp >= 0 && temp <= 54) {
                    petice += 1;
                    averageGrade += 5;
                }
                break;
            }
        }
        
    }
    
    averageGrade /= studentCount;
    
    printf("-------------------------------------------\n"
    "Average grade is : %f\n"
    "Number of students with 10: %d\n"
    "Number of students with 9: %d\n"
    "Number of students with 8: %d\n"
    "Number of students with 7: %d\n"
    "Number of students with 6: %d\n"
    "Number of students with 5: %d\n",averageGrade,desetke,devetke,osmice,sedmice,sestice,petice);
    
    return 0;
}
