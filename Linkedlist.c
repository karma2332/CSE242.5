// C Program to create a Linked List dynamically using loop
#include <stdio.h>
#include <stdlib.h>

// Define the structure of Node
typedef struct Node {
    int data;              // Data part
    struct Node *next;     // Address of next node
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    Node *first = NULL;    // Head of the linked list
    Node *temp = NULL;     // Temporary pointer
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        // If this is the first node
        if (first == NULL) {
            first = createNode(value);
            temp = first;
        }
        // For remaining nodes
        else {
            temp->next = createNode(value);
            temp = temp->next;
        }
    }

    // Traversing the linked list
    printf("Linked List: ");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
