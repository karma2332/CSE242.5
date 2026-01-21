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

/* Insert at a given position */
node *insertAtPosition(node *first, int value, int pos) {
    node *newNode = createNode(value);

    /* Insert at beginning */
    if (pos == 1) {
        newNode->next = first;
        // if (first != NULL)
        //     first->prev = newNode;
        return newNode;
    }

    node *temp = first;
    int i;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return first;
    }

    newNode->next = temp->next;
    // if (temp->next != NULL)
    //     temp->next->prev = newNode;

    // newNode->prev = temp;
    temp->next = newNode;

    return first;
}

int main() {
    node *first = NULL;
    node *temp = NULL;
    int i, n, value;
    int pos, insertValue;

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

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &insertValue);

    first = insertAtPosition(first, insertValue, pos);

    printf("Linked List: ");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
