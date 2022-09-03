#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 100

typedef struct {
	int data[MAX_ELEMENT];
	int top;
} StackType;

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

/*
스택 관련 함수
*/
void initStack(StackType* s) {
	s->top = -1;
}

int isEmpty(StackType* s) {
	return (s->top == -1);
}

void push(StackType* s, int item) {
	s->data[++(s->top)] = item;
}

int pop(StackType* s) {
	if (isEmpty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	return s->data[(s->top)--];
}

/*
힙 관련 함수
*/
void initHeap(HeapType* h) {
	h->heap_size = 0;
}

void upHeap(HeapType* h) {
	int i = h->heap_size;
	int key = h->heap[i];

	while ((i != 1) && (key < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = key;
}

void insertItem(HeapType* h, int key) {
	h->heap_size += 1;
	h->heap[h->heap_size] = key;
	upHeap(h);
}

void printHeap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
	printf("\n");
}

/*
응용문제: 힙의 마지막 노드 찾기
*/
void binaryExpansion(StackType* s, int i) {
	while (i >= 2) {
		push(s, i % 2);
		i /= 2;
	}
	push(s, i);
	return;
}

int findLastNode(HeapType* h, int n) {
	int v;
	int i = 1;
	StackType stack;
	initStack(&stack);
	binaryExpansion(&stack, n);
	pop(&stack);
	while (!isEmpty(&stack)) {
		int bit = pop(&stack);
		printf("%d\t", bit);
		if (bit == 0) {
			v = h->heap[i * 2];
			i = i * 2;
			printf("left: %d\n", v);
		}
		else {
			v = h->heap[i * 2 + 1];
			i = i * 2 + 1;
			printf("right: %d\n", v);
		}
	}
	return v;
}

void main() {
	HeapType heap;
	srand(42);
	initHeap(&heap);
	printf("Size of heap: ");
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		insertItem(&heap, rand() % 100);
	printHeap(&heap);
	printf("Last node: %d\n", findLastNode(&heap, heap.heap_size));
}

