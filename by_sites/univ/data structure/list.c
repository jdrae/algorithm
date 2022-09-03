#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
}LinkedListType;

void init(LinkedListType* L) {
	L->head = NULL;
}

int removeFirst(LinkedListType* L) {
	ListNode* p = L->head;
	L->head = p->link;
	int data = p->data;
	free(p);
	return data;
}

int removeLast(LinkedListType* L) {
	ListNode* p = L->head;
	for (;p->link->link != NULL; p = p->link);
	int data = p->link->data;
	free(p->link);
	p->link = NULL;
	return data;
}

void addFirst(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void addLast(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = NULL;
	ListNode* p = L->head;
	for (; p->link != NULL; p = p->link);
	p->link = node;
	//printf("p->data: %d\n", p->link->data);
}

void add(LinkedListType* L, int pos, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++) {
		before = before->link;
	}
	node->data = item;
	node->link = before->link;
	before->link = node;
}

int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++) {
		p = p->link;
	}
	return p->data;
}

void set(LinkedListType* L, int pos, int item) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++) {
		p = p->link;
	}
	p->data = item;
}


void printList(LinkedListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->link) {
		printf("[%d] -> ", p->data);
	}
	printf("NULL\n");
}

void main() {
	LinkedListType list;
	init(&list);

	addFirst(&list, 1); printList(&list);
	addFirst(&list, 2); printList(&list);
	addFirst(&list, 5); printList(&list);
	add(&list, 1, 3); printList(&list);
	add(&list, 1, 4); printList(&list);
	addLast(&list,0); printList(&list);

	printf("REMOVE FIRST DATA: %d\n", removeFirst(&list)); printList(&list);
	printf("REMOVE LAST DATA: %d\n", removeLast(&list)); printList(&list);

}