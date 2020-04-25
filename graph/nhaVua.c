#include <malloc.h>
#include <stdio.h>

typedef int Datatype;

typedef struct Node {
    Datatype key;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} List;

void makeNull(List *list) {
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = NULL;

    list->front = header;
    list->rear = header;
}

void push(List *list, Datatype key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    list->front->next = newNode;
    list->front = newNode;
}

Datatype shift(List *list) {
    Node* old = list->rear;

    list->rear = list->rear->next;

    free(old);
    return list->rear->key;
}

int* calculateDistances(List graph[], int n) {
    List queue;
    int *distances = (int*)malloc(sizeof(int) * n);
    int visited[n];

    makeNull(&queue);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        distances[i] = 0;
    }

    push(&queue, 0);
    visited[0] = 1;
    while (queue.front != queue.rear) {
        int pivot = shift(&queue);
        List *node = &graph[pivot];

        // loop through all associate node
        while (node->front != node->rear) {
            int associate = shift(node);
            if (visited[associate] == 0) {
                push(&queue, associate);
                visited[associate] = 1;

                distances[associate] = distances[pivot] + 1;
            }
        }
    }

    return distances;
}

int main() {
    freopen("./input", "r", stdin);

    int n, k;
    scanf("%d", &n);

    List graph[n];
    for (int i = 0; i < n; i++) {
        makeNull(&graph[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int from, to;
        scanf("%d%d", &from, &to);
        push(&graph[from - 1], to - 1);
        push(&graph[to - 1], from - 1);
    }

    scanf("%d", &k);
    int capable[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &capable[i]);
        capable[i]--;
    }
    // end input

    int *distances = calculateDistances(graph, n);

    int minDistance = distances[capable[0]];
    for (int i = 1; i < k; i++) {
        if (minDistance > distances[capable[i]]) {
            minDistance = distances[capable[i]];
        }
    }

    int result = n;
    for (int i = 0; i < k; i++) {
        if (distances[capable[i]] == minDistance) {
            if (capable[i] < result) {
                result = capable[i];
            }
        }
    }

    printf("%d", result + 1);

    free(distances);
    return 0;
}
