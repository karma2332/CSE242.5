//Declare an Array, take Size, Elements dynamically. Delete an
  //  element in any of the odd index position. [Take the position dynamically]
#include <stdio.h>

int main() {
    int size, pos;

    // 1. Take array size
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    // 2. Take elements dynamically
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Take position (human position)
    printf("Enter position to delete (even index only): ");
    scanf("%d", &pos);

    // Convert human position to index
    pos--;

    // 4. Check if valid even index
    if (pos < 0 || pos >= size) {
        printf("Invalid position!\n");
        return 0;
    }

    if (pos % 2 != 1) {
        printf("Error: You can delete only EVEN index positions (0,2,4,...)\n");
        return 0;
    }

    // 5. Delete: shift elements left
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;  // decrease array size

    // 6. Print updated array
    printf("Array after deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

