//Declare an Array, take Size, Elements dynamically. Delete an
  //  element in any of the odd index position. [Take the position dynamically]
#include <stdio.h>

int main() {
    int size, elements, pos;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("How many elements you want to store (<= %d)? ", size);
    scanf("%d", &elements);

    printf("Enter %d elements:\n", elements);
    for (int i = 0; i < elements; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to delete (ODD index only): ");
    scanf("%d", &pos);

    pos--;

    if (pos < 0 || pos >= elements) {
        printf("Invalid position!\n");
        return 0;
    }

    if (pos % 2 == 0) {
        printf("Error: Only ODD index deletions allowed (1,3,5,...)\n");
        return 0;
    }

    printf("Deleted element: %d\n", arr[pos]);

    for (int i = pos; i < elements - 1; i++) {
        arr[i] = arr[i + 1];
    }

    elements--;

    printf("Array after deletion:\n");
    for (int i = 0; i < elements; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
