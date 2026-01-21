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

int main() {
    node *first = NULL;
    node *temp = NULL;
    int i, n, value;

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
            //temp->next->prev = temp;
            temp = temp->next;
        }
    }

    printf("Linked List: ");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
