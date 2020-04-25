#include <malloc.h>
#include <stdio.h>
#define Infinity 214748360
#define MaxSize 1000000

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef Node* List;

typedef struct {
    int path;
    int vertex;
} KeyType;

typedef struct {
    KeyType Keys[MaxSize];
    int size;
} PriorityQueue;


void swap(KeyType* a, KeyType* b) {
    KeyType temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(PriorityQueue *pQ, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    int size = pQ->size;

    if (right < size && pQ->Keys[right].path < pQ->Keys[smallest].path) {
        smallest = right;
    }
    if (left < size && pQ->Keys[left].path < pQ->Keys[smallest].path) {
        smallest = left;
    }
    if (smallest != i) {
        swap(&pQ->Keys[smallest], &pQ->Keys[i]);
        minHeapify(pQ, smallest);
    }
}

KeyType extractMin(PriorityQueue* pQ) {
    KeyType result = pQ->Keys[0];

    swap(&pQ->Keys[pQ->size - 1], &pQ->Keys[0]);
    pQ->size--;

    minHeapify(pQ, 0);

    return result;
}

void insert(PriorityQueue* pQ, KeyType k) {
    pQ->Keys[pQ->size] = k;
    int i = pQ->size;
    pQ->size++;

    while (i > 0 && pQ->Keys[i].path < pQ->Keys[(i - 1) / 2].path) {
        swap(&pQ->Keys[(i - 1) / 2], &pQ->Keys[i]);
        i = (i - 1) / 2;
    }
}

// -- end minheap
void makeNull(List *list) {
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = NULL;
    *list = header;
}

void unshift(List *list, int vertex, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;

    newNode->next = (*list)->next;
    (*list)->next = newNode;
}

void calculateDistance(const char *filename) {
    freopen(filename, "r", stdin);

    int n, m;
    scanf("%d%d", &n, &m);
    List graph[n];
    for (int i = 0; i < n; i++) {
        makeNull(&graph[i]);
    }

    for (int i = 0; i < m; i++) {
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);

        unshift(&graph[a - 1], b - 1, d);
    }

    int checked[n];
    int resultSet[n];
    for (int i = 0; i < n; i++) {
        checked[i] = 0;
        resultSet[i] = Infinity;
    }

    PriorityQueue queue = {(KeyType){}, 0};

    insert(&queue, (KeyType){0, 0});
    while (queue.size != 0) {
        KeyType min = extractMin(&queue);

        if (checked[min.vertex] == 0) {
            checked[min.vertex] = 1;

            for (Node* i = graph[min.vertex]; i->next != NULL; i = i->next) {
                int vertex = i->next->vertex;
                int weight = i->next->weight;

                if (min.path + weight < resultSet[vertex]) {
                    resultSet[vertex] = min.path + weight;
                    insert(&queue, (KeyType){resultSet[vertex], vertex});
                }
            }
        }
    }
    for (int i = 1; i < n; i++) {
        printf("%d ", resultSet[i]);
    }
}

int main() {
    calculateDistance("./shortestPath.input");

    return 0;
}
