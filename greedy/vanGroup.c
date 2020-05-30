#include <stdio.h>
#define MaxSize 1000010
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


void maxHeapify(PriorityQueue *pQ, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    int size = pQ->size;

    if (right < size && pQ->Keys[right] > pQ->Keys[largest]) {
        largest = right;
    }
    if (left < size && pQ->Keys[left] > pQ->Keys[largest]) {
        largest = left;
    }
    if (largest != i) {
        swap(&pQ->Keys[largest], &pQ->Keys[i]);
        maxHeapify(pQ, largest);
    }
}

KeyType extractMax(PriorityQueue* pQ) {
    int result = pQ->Keys[0];

    int temp = pQ->Keys[pQ->size - 1];
    pQ->Keys[pQ->size - 1] = pQ->Keys[0];
    pQ->Keys[0] = temp;

    pQ->size--;

    maxHeapify(pQ, 0);

    return result;
}

void buildMaxHeapify(PriorityQueue *pQ) {
    for (int i = pQ->size / 2 - 1; i >= 0; i--) {
        maxHeapify(pQ, i);
    }
}

void insert(PriorityQueue* pQ, int k) {
    pQ->Keys[pQ->size] = k;
    int i = pQ->size;
    pQ->size++;

    while (i > 0 && pQ->Keys[i] > pQ->Keys[(i - 1) / 2]) {
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

void estimateProfit(const char* filename) {
    freopen(filename, "r", stdin);
    int n;
    scanf("%d", &n);
    PriorityQueue ln = {{}, 0};
    PriorityQueue v = {{}, 0};

    for (int i = 0; i < n; i++) {
        int lnk;
        scanf("%d", &lnk);
        insert(&ln, lnk);
    }
    for (int i = 0; i < n; i++) {
        int vk;
        scanf("%d", &vk);
        insert(&v, vk);
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += (long)extractMax(&ln) * (long)extractMax(&v);
    }
    printf("%lld\n", res);

}
int main() {
    estimateProfit("/home/riverflow/Desktop/Input/VanGroup/vg09.inp");
}
