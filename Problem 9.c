//Declare an Array, take Size, Elements dynamically. 
   //Delete an element from the last position. [Take the position dynamically]
#include <stdio.h>

int main() {
    int size, pos;

    // 1. Take size of the array
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    // 2. Take array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Take delete position (human position)
    printf("Enter position to delete (1 to %d): ", size);
    scanf("%d", &pos);

    // Convert to index
    pos--;

    // 4. Delete from that position
    if (pos < 0 || pos >= size) {
        printf("Invalid position!\n");
        return 0;
    }

    // Shift elements left
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--; // reduce array size

    // 5. Print final array
    printf("Array after deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
