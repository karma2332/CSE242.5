// C Program: Insertion at End
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

// ADD-ON: Insert at End
Node *insertAtEnd(Node *first, int data) {
    Node *newNode = createNode(data);

    if (first == NULL)
        return newNode;

    Node *temp = first;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return first;
}

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
int k;
 printf("Enter insertion value: ");
        scanf("%d", &k);
    // Insertion at End
    first = insertAtEnd(first,k);

    printf("Linked List: ");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
