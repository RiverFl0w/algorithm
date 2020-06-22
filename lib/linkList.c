#include <malloc.h>

typedef int Datatype;

typedef struct Node {
    Datatype key;
    struct Node* next;
} Node;

typedef Node* List;

void makeNull(List *list) {
    *list = (Node*)malloc(sizeof(Node));
    (*list)->next = NULL;
}

void unshift(List *list, Datatype key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    newNode->next = (*list)->next;
    (*list)->next = newNode;
}
