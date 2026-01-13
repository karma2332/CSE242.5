// C Program: Insertion at Position
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create a new node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at a given position
Node *insertAtPosition(Node *first, int data, int pos) {
    Node *newNode = createNode(data);

    if (pos == 1) {
        newNode->next = first;
        return newNode;
    }

    Node *temp = first;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return first;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return first;
}

int main() {
    Node *first = NULL;
    Node *temp = NULL;
    int n, value, i;
    int k, D;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create initial list
    for (i = 1; i <= n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        if (first == NULL) {
            first = createNode(value);
            temp = first;
        } else {
            temp->next = createNode(value);
            temp = temp->next;
        }
    }

    // Insertion input
    printf("Enter insertion position: ");
    scanf("%d", &k);

    printf("Enter insertion value: ");
    scanf("%d", &D);

    first = insertAtPosition(first, D, k);

    // Display list
    printf("Linked List: ");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
