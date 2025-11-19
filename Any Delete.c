#include <stdio.h>

int main() {
    int size, elements, pos;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("How many elements you want to store (<= %d)? ", size);
    scanf("%d", &elements);

    printf("Enter %d elements:\n", elements);
    for (int i = 0; i < elements; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    pos--; // convert human position to index

    if (pos < 0 || pos >= elements) {
        printf("Invalid position!\n");
        return 0;
    }

    printf("Deleted element: %d\n", arr[pos]);

    // shift left
    for (int i = pos; i < elements - 1; i++) {
        arr[i] = arr[i + 1];
    }

    elements--; // reduce count

    printf("Array after deletion:\n");
    for (int i = 0; i < elements; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
