#include <stdio.h>
#include "LinkedList.h"



int main() {
	struct LinkedList* lista = NULL;
	lista = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	lista->head = NULL;
	lista->tail = NULL;
	lista->size = 0;

	//Citanje i pisanje iz fajla;

	loadList(lista, "ulaz.txt");

	printf("Trenutna velicina linkovane liste: %d \n", getSize(lista));

	removeFirst(lista);
	removeLast(lista);

	printf("Trenutna velicina linkovane liste (uklonjena dva elementa): %d \n", getSize(lista));

	printList(lista);

	saveList(lista, "izlaz.txt");

	clear(lista);
	printf("Lista nakon brisanja: ");
	printList(lista);

	free(lista);
	lista = NULL;

	//Rucni unos

	lista = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	lista->head = NULL;
	lista->tail = NULL;
	lista->size = 0;

	printf("Unesite broj elemenata koji zelite da unesete: ");
	int n = 0;
	scanf_s("%d", &n);

	int* niz = (int)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		printf("Unesite clan niza na indeksu [%d]: ", i);
		scanf_s("%d", niz + i);
	}

	loadFromArray(lista, niz, n);
	printList(lista);


	free(niz);

	clear(lista);
	free(lista);
	lista = NULL;
	return 0;
}


