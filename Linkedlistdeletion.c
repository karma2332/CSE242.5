// C Program: Deletion at Beginning
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

/* ===== ADD-ON: Delete at Beginning ===== */
Node *deleteAtBeginning(Node *first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    Node *temp = first;        // CHANGED: store first node
    first = first->next;       // CHANGED: move head
    free(temp);                // CHANGED: free old first
    return first;
}
/* ====================================== */

int main() {
    Node *first = NULL;
    Node *temp = NULL;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

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

    /* ===== ADD-ON CALL ===== */
    first = deleteAtBeginning(first);
    /* ====================== */

    printf("Linked List: ");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
