#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    // struct node *prev;   // Uncomment for DLL
} node;

/* Create a new node */
node *createNode(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    // newNode->prev = NULL;
    return newNode;
}

/* Delete at a given position */
node *deleteAtPosition(node *first, int pos) {
    node *temp = first;
    node *prevNode = NULL;
    int i;

    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }

    /* Delete first node */
    if (pos == 1) {
        first = first->next;
        // if (first != NULL)
        //     first->prev = NULL;
        free(temp);
        return first;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        prevNode = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return first;
    }

    prevNode->next = temp->next;
    // if (temp->next != NULL)
    //     temp->next->prev = prevNode;

    free(temp);
    return first;
}

int main() {
    node *first = NULL;
    node *temp = NULL;
    int i, n, value;
    int pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        if (first == NULL) {
            first = createNode(value);
            temp = first;
        } else {
            temp->next = createNode(value);
            // temp->next->prev = temp;
            temp = temp->next;
        }
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    first = deleteAtPosition(first, pos);

    printf("Linked List: ");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
