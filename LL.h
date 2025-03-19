#ifndef LL_H
#define LL_H

typedef struct Node Node;

struct Node
{
	int value;
	Node* next;

};

typedef struct Linkedlist
{
	int size;
	Node* head;

} Linkedlist;

#endif /* LL_H */
