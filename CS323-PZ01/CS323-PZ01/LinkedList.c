#include "LinkedList.h"

void addFirst(int elem, struct LinkedList* list) {
	struct Node* temp = NULL;
	if (list->head == NULL) {
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = elem;
		temp->next = NULL;

		list->head = (struct Node*)malloc(sizeof(struct Node));
		list->head = temp;

		list->tail = (struct Node*)malloc(sizeof(struct Node));
		list->tail = temp;
		list->size++;
	}
	else if (list->head != NULL) {
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = elem;
		temp->next = (struct Node*)malloc(sizeof(struct Node));
		temp->next = list->head;
		list->head = temp;
		list->size++;
	}
}

void addLast(int elem, struct LinkedList* list) {
	struct Node* temp = NULL;
	if (list->head == NULL) {
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = elem;
		temp->next = NULL;

		list->head = (struct Node*)malloc(sizeof(struct Node));
		list->head = temp;

		list->tail = (struct Node*)malloc(sizeof(struct Node));
		list->tail = temp;
		list->size++;
	}
	else if (list->head != NULL) {
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->next = NULL;
		temp->data = elem;
		list->tail->next = (struct Node*)malloc(sizeof(struct Node));
		list->tail->next = temp;
		list->tail = temp;
		list->size++;
	}
}

int removeFirst(struct LinkedList* list) {
	if (list->head == NULL) {
		return;
	}
	else {
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp = list->head;
		list->head = temp->next;
		int res = temp->data;
		free(temp);
		list->size--;
		return res;
	}
}

int removeLast(struct LinkedList* list) {
	if (list->head == NULL) {
		return;
	}
	else if (list->head->next == NULL) {
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		list->size--;
	}
	else {
		struct Node* last = (struct Node*)malloc(sizeof(struct Node));
		last = list->tail;

		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp = list->head;
		while (temp->next != last) {
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
		list->tail = temp;
		int res = last->data;
		list->size--;
		return res;
	}
}

int peekFirst(const struct LinkedList* list)
{
	return list->head;
}

int peekLast(const struct LinkedList* list)
{
	return list->tail;
}

void printList(const struct LinkedList* list)
{
	if (list->head == NULL) {
		printf("The list is empty\n");
		return;
	}
	struct Node* temp = NULL;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp = list->head;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	free(temp);
}

int getSize(const struct LinkedList* list) {
	return list->size;
}

void clear(struct LinkedList* list)
{
	if (list->head == NULL) {
		return;
	}
	struct Node* temp = NULL;
	while (list->head != NULL) {
		removeFirst(list);
	}
	list->tail = NULL;
}

void loadList(struct LinkedList* list, const char* path)
{
	FILE* file;
	fopen_s(&file, path, "r");
	int i = 0;
	while (!feof(file))
	{
		fscanf_s(file, "%d", &i);
		addLast(i, list);
	}
	fclose(file);
}

void saveList(const struct LinkedList* list, const char* path)
{
	FILE* file;
	fopen_s(&file, path, "w");
	if (list->head == NULL) {
		fprintf_s(file, "The list is empty");
		return;
	}
	struct Node* temp = NULL;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp = list->head;
	while (temp != NULL) {
		fprintf_s(file, "%d", temp->data);
		temp = temp->next;
		if (temp != NULL) {
			fprintf_s(file, "\n");
		}
	}
	free(temp);
	fclose(file);
}

void loadFromArray(const struct LinkedList* list, int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		addLast(*(array + i), list);
	}
}
