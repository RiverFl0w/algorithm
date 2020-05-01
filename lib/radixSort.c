#include <malloc.h>
#include <stdio.h>
#include <math.h>

#define BUCKET_BASE 10

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

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d", arr[i]);
    }
    printf("\n");
}


void radixSort(int arr[], int n) {
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) largest = arr[i];
    }

    int level = (int)log10(largest) + 1;

    List buckets[BUCKET_BASE];
    for (int i = 0; i < BUCKET_BASE; i++) {
        makeNull(&buckets[i]);
    }

    for (int i = 0; i < level; i++) {
        for (int j = 0; j < n; j++) {
            int bucketIndex = (arr[j] / (int)pow(10, i)) % BUCKET_BASE;
            push(&buckets[bucketIndex], arr[j]);
        }
        printArr(arr, n);

        int k = 0;
        for (int j = 0; j < BUCKET_BASE; j++) {
            while (buckets[j].front != buckets[j].rear) {
                arr[k++] = shift(&buckets[j]);
            }
        }
    }

}

int main() {
    int arr[] = {11,4444,3,4,2,11,25,4993,295,19};
    int n = 10;

    radixSort(arr, n);
    printArr(arr, n);

    return 0;
}
