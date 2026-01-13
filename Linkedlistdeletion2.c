// C Program: Deletion at Position (User Input)
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

// Delete node at a given position
Node *deleteAtPosition(Node *first, int pos) {

    // Case 1: Empty list
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    // Case 2: Delete first node
    if (pos == 1) {
        Node *temp = first;
        first = first->next;
        free(temp);
        return first;
    }

    // Case 3: Delete middle or last node
    Node *temp = first;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp->next == NULL) {
        printf("Invalid position\n");
        return first;
    }

    Node *del = temp->next;
    temp->next = del->next;
    free(del);

    return first;
}

int main() {
    Node *first = NULL;
    Node *temp = NULL;
    int n, value, i, pos;

    // User input: number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
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

    // User input: deletion position
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    first = deleteAtPosition(first, pos);

    // Display list
    printf("Linked List: ");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
