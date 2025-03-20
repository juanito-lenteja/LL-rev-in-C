#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL.h"

#define SIZE 10

void printLL(Linkedlist list);
void reverseLL(Linkedlist* list);
void makeNodeList(Linkedlist* list, int size);
void initnodes(Node** head, int size);
void freeLL(Linkedlist* list);

int main(void)
{
	Linkedlist list;
	memset(&list, 0, sizeof(Linkedlist));
	makeNodeList(&list, SIZE);

	printLL(list);
	reverseLL(&list);
	printLL(list);
	reverseLL(&list);
	printLL(list);
	
	freeLL(&list);
	
	return 0;
}

void makeNodeList(Linkedlist* list, int size)
{
	if(size <= 0)
	{
		printf("Error: cannot make a linked list of size %d\n", size);
		return;
	}

	list->size = size;
	initnodes(&list->head, size);
}

void initnodes(Node** head, int size)
{
	/* make new mem and initialize head */
	Node* newHead = (Node *) malloc(sizeof(Node));
	newHead->value = 0;
	newHead->next = NULL;
	
	Node* prev = newHead;
	Node* curr = NULL;
	for(int i = 1; i < size; i ++)
	{
		curr = (Node *) malloc(sizeof(Node));
		if(curr == NULL)
		{
			perror("Error in malloc");
			continue;
		}

		curr->value = i;

		prev->next = curr;
		curr->next = NULL;
		
		prev = curr; /* step forward */
	}
	
	*head = newHead;
}

void printLL(Linkedlist list)
{
	Node* curr = list.head;

	while(curr != NULL)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n");
}

void reverseLL(Linkedlist* list)
{
	if(list->size <= 1)
	{
		return;
	}
	
	Node* next = list->head->next;
	Node* aNext;
	list->head->next = NULL;
	
	do
	{
		aNext = next->next; /* store next's next */
		next->next = list->head; /* link to next to current (head) */
		list->head = next; /* step current one over */
		next = aNext; /* step next one over */
	}
	while(next != NULL);
}

void freeLL(Linkedlist* list)
{
	Node* prev = list->head;
	Node* curr = prev->next;
	
	while(curr != NULL)
	{
		free(prev);
		prev = curr;
		curr = curr->next;
	}
	free(prev);
	
	list->size = 0;
}
