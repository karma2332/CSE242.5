//Declare an Array, take Size, Elements dynamically. 
//Delete an element from the last position. [Take the position dynamically] 

#include <stdio.h>

int main() {
    int size, elements, pos;

    // 1. Take size of array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // 2. Take how many elements you want to store
    printf("How many elements you want to insert (<= %d)? ", size);
    scanf("%d", &elements);

    // 3. Take the elements
    printf("Enter %d elements:\n", elements);
    for (int i = 0; i < elements; i++) {
        scanf("%d", &arr[i]);
    }

    // 4. Take the position to delete
    printf("Enter the position to delete (only last position allowed): ");
    scanf("%d", &pos);

    pos--; // convert human position → index

    // Check if pos is the last element
    if (pos != elements - 1) {
        printf("Error: You can delete only the LAST position (%d)\n", elements);
        return 0;
    }

    // 5. Show deleted element
    printf("Deleted element: %d\n", arr[pos]);

    // 6. Delete by reducing element count
    elements--;

    // 7. Print updated array
    printf("Array after deletion:\n");
    for (int i = 0; i < elements; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
