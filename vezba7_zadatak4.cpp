/*
Vezba: 7
Zadatak: 4
Dev: Darko Demic
Built using: GCC 7.0 on Arch Linux
Standard: C++ 17
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct osoba {
	char *ime;
	struct osoba *next;
} Osoba;


//functions here and not in external files for easier readability

char *readCli(int* bufferSize) {
	printf("Enter your name: ");
	//E sad ajmo
	int size_b = 30;
	char *buffer;
	buffer = (char*)malloc(size_b*sizeof(char));
	if (buffer == NULL) { exit(1); }
	char enterEater;
	enterEater = getchar();
	char c; int i = 0;
	while ((c = fgetc(stdin)) != '\n') {
		if (i > 30) {
			buffer = (char*)realloc(buffer, (size_b * 2) * sizeof(char));
			if (buffer == NULL) { exit(3); }
		}
		buffer[i++] = c;
	}
	
	buffer[i] = '\0';
	buffer = (char*)realloc(buffer, (i+1) * sizeof(char));
	if (buffer == NULL) { exit(4); }
	//Unutar buffera imamo ime 
	*bufferSize = i+1; //da promenimo var u kome se nalazi duzina koja nam treba za kasnije
	return buffer;
}


Osoba *addToEnd(Osoba *lp, char *buffer, int bufferSize) {

	Osoba *temp = (Osoba*)malloc(sizeof(Osoba));//safe casting from void to Osoba
	if (temp == NULL) {
		printf("Memory Allocation Error. Exiting.");
		exit(5);
	}
	temp->ime = (char*)malloc(sizeof(char)*(bufferSize));//We create accurate storage for our names
	temp->next = NULL; //Set last to Null
	temp->ime = buffer;
	//Ako niz ne postoji, kreiramo ga i dodajemo na pocetak, ako postoji samo dodamo na kraj
	if (lp == NULL) {
		lp = temp;
		lp->next = NULL;
	}
	else {
		Osoba *tp;
		for (tp = lp; tp->next; tp = tp->next);
		tp->next = temp;
		temp->next = NULL;
	}

	return lp;
}

int checkExistence(Osoba *lp, char *buffer) {
	Osoba *temp;
	for (temp = lp; temp; temp = temp->next) {
		int stringCheck = strcmp(temp->ime, buffer);
		if (stringCheck == 0) {
			return 0;
		}
		else return 1;
		//Ako string ne postoji vracamo 1 znaci da mozemo da nastavimo sa unosom, ako vec postoji saljemo 0 da ne unosi ime
	}
	return 0;
}

Osoba *unos(Osoba *lp) {

	int bufferSize = 0;
	char *buffer = readCli(&bufferSize);
	
	//Provera da li vec postoji
	int exists; 
	if (lp == NULL) {
		exists = 1;
	}
	else {
		exists = checkExistence(lp, buffer);
	}
	
	if (exists == 1) {

		lp = addToEnd(lp, buffer, bufferSize);
	}
	else if (exists == 0) {
		printf("Your name already exists. Aborted.\n");
	}
	//kraj unosa imena
	return lp;
}

Osoba *printSelectedName(int elemChange,Osoba *lp) {
	Osoba *temp = lp;
	for (int i = 1; i < elemChange; i++)temp = temp->next; //Sada nam je temp podesen na element koji mi zelimo
	printf("Name to change: %s\n", temp->ime);
	return temp;
}

Osoba *izmena(Osoba *lp) {
	printf("Select list element you would like to change: ");
	int elemChange = -1;
	scanf("%d", &elemChange);
	if (elemChange == -1) {
		printf("You forgot to type out a number.\n");
		exit(7);
	}
	
	Osoba *nameToChange = printSelectedName(elemChange,lp);

	int bufferSize = 0;
	char *buffer = readCli(&bufferSize);

	nameToChange->ime = buffer;
	
	return lp;
}

void prikaz(Osoba *lp) {
	Osoba *temp;
	int i = 0;
	printf("\nList of Persons\n-------------------\n");
	for (temp = lp; temp; temp = temp->next) {
		i++;
		printf("Osoba %d: %s\n", i, temp->ime);
	}
}

void memClean(Osoba *lp) {
	Osoba *temp;
	while (lp) {
		temp = lp;
		lp = lp->next;
		free(temp);
	}
}

int main(int argc, const char *argv[]) {

	Osoba *lp = NULL;

	printf(
		"Opcije: \n"
		"1. Unos\n"
		"2. Izmene\n"
		"3. Prikaz\n"
		"4. Izlaz\n"
		"Izbor: ");

	int option = 0;

	while (scanf("%d", &option), option < 5) {
		if (option == 4) {
			memClean(lp); // Da ocistimo memoriju za sobom
			return 1;
		}
		if (option < 1 || option > 4) {
			printf("Pogresna opcija. Pokusajte ponovo.\n");
			exit(2);
		}
		//Sada smo sigurni da je opcija tacno uneta
		
		switch (option) {
		case 1: lp = unos(lp);
			break;
		case 2: lp = izmena(lp);
			break;
		case 3: prikaz(lp);
			break;
		}
		//Opet nudimo korisniku meni
		printf("---------------\n"
			"Opcije: \n"
			"1. Unos\n"
			"2. Izmene\n"
			"3. Prikaz\n"
			"4. Izlaz\n"
			"Izbor: ");
	}

	memClean(lp); // Da ocistimo memoriju za sobom

	return 0;
}
