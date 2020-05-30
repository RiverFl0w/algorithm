#include <stdio.h>
#define MaxSize 1000000
#define MINVALUE -32768

typedef int KeyType;
typedef struct{
     KeyType Keys[MaxSize];
     int size;

}PriorityQueue;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void minHeapify(PriorityQueue *pQ, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    int size = pQ->size;

    if (right < size && pQ->Keys[right] < pQ->Keys[largest]) {
        largest = right;
    }
    if (left < size && pQ->Keys[left] < pQ->Keys[largest]) {
        largest = left;
    }
    if (largest != i) {
        int temp = pQ->Keys[largest];
        pQ->Keys[largest] = pQ->Keys[i];
        pQ->Keys[i] = temp;
        minHeapify(pQ, largest);
    }
}

KeyType extractMin(PriorityQueue* pQ) {
    int result = pQ->Keys[0];

    int temp = pQ->Keys[pQ->size - 1];
    pQ->Keys[pQ->size - 1] = pQ->Keys[0];
    pQ->Keys[0] = temp;

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
        int temp = pQ->Keys[(i - 1) / 2];
        pQ->Keys[(i - 1) / 2] = pQ->Keys[i];
        pQ->Keys[i] = temp;
        i = (i - 1) / 2;
    }
}

void increaseKey(PriorityQueue* pQ, int i, KeyType k) {
    if (k < pQ->Keys[i]) return;
    pQ->Keys[i] = k;

    while (i > 0 && pQ->Keys[i] > pQ->Keys[(i - 1) / 2]) {
        int temp = pQ->Keys[(i - 1) / 2];
        pQ->Keys[(i - 1) / 2] = pQ->Keys[i];
        pQ->Keys[i] = temp;
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

int main() {
    /* freopen("/home/riverflow/Desktop/Input/Merge/merge01.inp", "r", stdin); */
    int n;
    PriorityQueue Q = {{}, 0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        insert(&Q, key);
    }

    long result = 0;
    while (Q.size != 1) {
        int a = extractMin(&Q);
        int b = extractMin(&Q);
        result += a + b;
        insert(&Q, a + b);
    }

    printf("%ld", result);
}
