#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 100

typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
} StackType;

void initStack(StackType* s) {
	s->top = -1;
}

int isEmpty(StackType* s) {
	return (s->top == -1);
}

int isFull(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, int item) {
	if (isFull(s)) {
		fprintf(stderr, "Stack is full\n");
		return;
	}
	s->data[++(s->top)] = item;
}

int pop(StackType* s) {
	if (isEmpty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	return s->data[(s->top)--];
}

void main() {
	StackType s;
	initStack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}

