#include <stdio.h>
#define MaxSize 1000000
#define MINVALUE -32768

typedef int KeyType;

typedef struct {
    KeyType Keys[MaxSize];
    int size;
} PriorityQueue;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void minHeapify(PriorityQueue *pQ, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    int size = pQ->size;

    if (right < size && pQ->Keys[right] < pQ->Keys[smallest]) {
        smallest = right;
    }
    if (left < size && pQ->Keys[left] < pQ->Keys[smallest]) {
        smallest = left;
    }
    if (smallest != i) {
        swap(&pQ->Keys[smallest], &pQ->Keys[i]);
        minHeapify(pQ, smallest);
    }
}

KeyType extractMin(PriorityQueue* pQ) {
    int result = pQ->Keys[0];

    swap(&pQ->Keys[pQ->size - 1], &pQ->Keys[0]);
    pQ->size--;

    minHeapify(pQ, 0);

    return result;
}

void buildMinHeapify(PriorityQueue *pQ) {
    for (int i = pQ->size / 2 - 1; i >= 0; i--) {
        minHeapify(pQ, i);
    }
}

void insert(PriorityQueue* pQ, int k) {
    pQ->Keys[pQ->size] = k;
    int i = pQ->size;
    pQ->size++;

    while (i > 0 && pQ->Keys[i] < pQ->Keys[(i - 1) / 2]) {
        swap(&pQ->Keys[(i - 1) / 2], &pQ->Keys[i]);
        i = (i - 1) / 2;
    }
}

void increaseKey(PriorityQueue* pQ, int i, KeyType k) {
    if (k < pQ->Keys[i]) return;
    pQ->Keys[i] = k;

    while (i > 0 && pQ->Keys[i] > pQ->Keys[(i - 1) / 2]) {
        swap(&pQ->Keys[(i - 1) / 2], &pQ->Keys[i]);
        i = (i - 1) / 2;
    }
}

int right(PriorityQueue Q, int i) {
    int right = 2 * i + 2;
    return right >= Q.size ? -1 : right;
}

int left(PriorityQueue Q, int i) {
    int left = 2 * i + 1;
    return left >= Q.size ? -1 : left;
}
