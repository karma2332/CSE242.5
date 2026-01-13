// C Program: Deletion at End
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* ===== ADD-ON: Delete at End ===== */
Node *deleteAtEnd(Node *first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (first->next == NULL) {   // CHANGED: only one node
        free(first);
        return NULL;
    }

    Node *temp = first;
    while (temp->next->next != NULL) { // CHANGED: reach 2nd last
        temp = temp->next;
    }

    free(temp->next);            // CHANGED: delete last node
    temp->next = NULL;           // CHANGED: update link
    return first;
}
/* ================================= */

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
    first = deleteAtEnd(first);
    /* ====================== */

    printf("Linked List: ");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
