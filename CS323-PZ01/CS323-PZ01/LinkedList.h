#pragma once
#include <stdio.h>

struct Node {
	int data;
	struct Node* next;
};

struct LinkedList {
	int size;
	struct Node* head;
	struct Node* tail;
};

void addFirst(int elem, struct LinkedList* list);
void addLast(int elem, struct LinkedList* list);
int removeFirst(struct LinkedList* list);
int removeLast(struct LinkedList* list);
int peekFirst(const struct LinkedList* list);
int peekLast(const struct LinkedList* list);
void printList(const struct LinkedList* list);
int getSize(const struct LinkedList* list);
void clear(struct LinkedList* list);
void loadList(struct LinkedList* list, const char* path);
void saveList(const struct LinkedList* list, const char* path);
void loadFromArray(const struct LinkedList* list, int* array, int size);