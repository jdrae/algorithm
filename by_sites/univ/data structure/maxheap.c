#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 100

struct HeapType {
	int H[MAX_ELEMENT];
	int n;
}heap;

void downHeap(int i) {
	if (i * 2 > heap.n) return;
	if (heap.H[i] < heap.H[i * 2] || heap.H[i] < heap.H[i * 2 + 1]) {
		if (heap.H[i * 2] > heap.H[i * 2 + 1]) {
			int temp;
			temp = heap.H[i];
			heap.H[i] = heap.H[i * 2];
			heap.H[i * 2] = temp;
			downHeap(i * 2);
		}
		else {
			int temp;
			temp = heap.H[i];
			heap.H[i] = heap.H[i * 2 + 1];
			heap.H[i * 2 + 1] = temp;
			downHeap(i * 2 + 1);
		}
	}
	return;
}

void buildHeap() {
	for (int i = heap.n / 2; i >= 1; i--)
		downHeap(i);
}

void rBuildHeap(int i) {
	if (i > heap.n) return;
	if (i * 2 <= heap.n)
		rBuildHeap(2 * i);
	if (i * 2 + 1 <= heap.n)
		rBuildHeap(2 * i + 1);
	downHeap(i);
}

int removeMax() {
	int key = heap.H[1];
	heap.H[1] = heap.H[heap.n--];
	downHeap(1);
	printf("deleted: %d\n", key);
	return key;
}

void inPlaceHeapSort() {
	int size = heap.n;
	int key;
	for (int i = 0; i < size; i++) {
		key = removeMax();
		heap.H[heap.n + 1] = key;

	}
}

void printArray() {
	for (int i = 1; heap.H[i] > 0; i++)
		printf("[%d] ", heap.H[i]);
	printf("\n");
}

void printHeap() {
	for (int i = 1; i <= heap.n; i++)
		printf("[%d] ", heap.H[i]);
	printf("\n");
}

void main() {
	heap.n = 0;
	srand(time(NULL));
	printf("입력할 원소의 개수: ");
	scanf_s("%d", &heap.n);
	for (int i = 1; i <= heap.n; i++)
		heap.H[i] = rand() % 100;
	// buildHeap();
	rBuildHeap(1);
	printHeap();
	inPlaceHeapSort();
	printArray();
}

