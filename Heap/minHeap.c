#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *array;
    int size;
    int capacity;
} Heap;

Heap *createHeap(int capacity);
void insert(Heap *Heap, int data);
void swap(int *a, int *b);
void printHeap(Heap *heap);
int removeMin(Heap *heap);
void heapify(Heap *heap, int i);

int main() {
    Heap *myHeap = createHeap(10);
    insert(myHeap, 9);
    insert(myHeap, 1);
    insert(myHeap, 12);
    insert(myHeap, 5);
    insert(myHeap, 7);
    insert(myHeap, 20);
    printHeap(myHeap);
    printf("\n");
    printf("Remove Value: %d\n", removeMin(myHeap));
    printHeap(myHeap);
    printf("\n");
    printf("Remove Value: %d\n", removeMin(myHeap));
    printHeap(myHeap);
    free(myHeap->array);
    free(myHeap);
    return 0;
}

Heap *createHeap(int capacity) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (int *)malloc(sizeof(capacity * sizeof(int)));
    return heap;
}

void insert(Heap *heap, int data) {
    if (heap->size > heap->capacity) {
        printf("OVERFLOW");
        return;
    }
    
    heap->array[heap->size] = data;
    int i = heap->size;
    heap->size++;

    while (i != 0) {
        if (heap->array[(i - 1) / 2] > heap->array[i]) {
            swap(&heap->array[(i - 1) / 2], &heap->array[i]);
            i = (i - 1) / 2;
        } else {
            i = (i - 1) / 2;
        }
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printHeap(Heap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
}

void heapify(Heap *heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left] < heap->array[smallest]) {
        smallest = left;
    }

    if (right < heap->size && heap->array[right] < heap->array[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&heap->array[smallest], &heap->array[i]);
        heapify(heap, smallest);
    }
}

int removeMin(Heap *heap) {
    int tmp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return tmp;
}