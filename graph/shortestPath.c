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

void makeNull(List* list) {
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = NULL;

    list->front = header;
    list->rear = header;
}

void push(List* list, Datatype key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    list->front->next = newNode;
    list->front = newNode;
}

Datatype shift(List* list) {
    Node* old = list->rear;

    list->rear = list->rear->next;

    free(old);
    return list->rear->key;
}

void freeQueue(List* queue) {
    while (queue->front != queue->rear) {
        shift(queue);
    }
}

void freeGraph(List graph[], int n) {
    for (int i = 0; i < n; i++) {
        freeQueue(&graph[i]);
    }
}

int bfs(List graph[], int n) {
    List queue;
    List distanceQueue;
    int visited[n];

    makeNull(&queue);
    makeNull(&distanceQueue);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    push(&queue, 0);
    push(&distanceQueue, 0);
    visited[0] = 1;
    while (queue.front != queue.rear) {
        List* node = &graph[shift(&queue)];
        int distance = shift(&distanceQueue);

        // loop through all associate node
        while (node->front != node->rear) {
            int associate = shift(node);
            if (visited[associate] == 0) {
                push(&queue, associate);
                push(&distanceQueue, distance + 1);
                visited[associate] = 1;

                if (associate == n - 1) {
                    freeQueue(&queue);
                    freeQueue(&distanceQueue);
                    return distance + 1;
                }
            }
        }
    }

    return -1;
}

void findShortestPath(const char* input) {
    freopen(input, "r", stdin);

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d%d", &n, &m);
        List graph[n];
        for (int i = 0; i < n; i++) {
            makeNull(&graph[i]);
        }
        for (int i = 0; i < m; i++) {
            int from, to;
            scanf("%d%d", &from, &to);
            push(&graph[from - 1], to - 1);
            push(&graph[to - 1], from - 1);
        }

        printf("%d\n", bfs(graph, n));

        freeGraph(graph, n);
    }
}

int main() {
    findShortestPath("./graph/input");

    return 0;
}
