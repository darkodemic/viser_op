#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char *argv[]) {

	int x = 0;
	int y = 0;

	printf("Enter X: "); scanf("%d", &x);
	printf("Enter Y: "); scanf("%d", &y);

	//Ispis u decimalnom i hexa sistemu
	printf("X as Decimal : %d\nX as Hexadecimal %hhx\nY as Decimal : %d\nY as Hexadecimal %hhx\n", x, x, y, y);

	int cel = 0; // Cisto da bi bio u main scope-u

	if (x != y) {
		double real = (double)x / y;
		cel = x / y;
		printf("Kolicnik : %lf | %d\n", real, cel);
	}

    // Ovde dobijamo broj bita u nasoj var cel posto ne znamo da li je sistem 32-bit ili 64-bit
    int numberOfBytesInInt = sizeof(int) * 8;

    // Pravimo array za svakog naseg karaktera u slucaju da imamo maximalan 64bit broj
    int bufferSize = numberOfBytesInInt;
    
    char *binArr = (char*)calloc(bufferSize,sizeof(char));
   
    if (!binArr) {
        printf("Memory Allocation error. Exiting.\n");
        exit(1);
    }

    int i = 0;

	while (cel) {
	    if (cel & 1) {
            binArr[i++] = '1';
	    }
	    
	    else {
            binArr[i++] = '0';
	    }
	    cel >>= 1;
	}
	
	int firstOccurrence = 0;
	int lastOccurrence  = 0;
    int j = 1;
    
    for (i = bufferSize - 1; i >= 0; i-- ) {
        int temp = j++ % 4;
        if (binArr[i] == '1') {
            //Posto idemo od najveceg do najmanjeg bita prvi na koji naidjemo nam je poslednji a poslenji kec je prvi bit sa 1 kao vrednoscu
            if(lastOccurrence == 0) lastOccurrence = i; //Njega vise ne diramo
            firstOccurrence = i;
            //Ne znamo da li ce biti jos jedinica i zbog toga nam je trenutno pozicija i, najveca i najmanja
        }
        if(temp == 0) {
            if(isdigit(binArr[i])) {
                printf("%c ", binArr[i]);
            }
            else printf("0 "); //Cisto da popunimo sta nam fali tj. sta nismo uneli prilikom prvog citanja broja
        }
        else {
            if(isdigit(binArr[i])) {
                printf("%c", binArr[i]);
            }
            else printf("0");  //Cisto da popunimo sta nam fali tj. sta nismo uneli prilikom prvog citanja broja
        }
        
    }
    
    printf("\nLast Occurrence of 1 on bit: %d", lastOccurrence);
    printf("\nFirst Occurrence of 1 on bit: %d", firstOccurrence);
    
    return 0;
}
