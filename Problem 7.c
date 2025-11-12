// 7. Declare an Array, take Size, Elements dynamically.
// Insert an element at any position of the array.
// [Take the elements & position dynamically]

#include <stdio.h>

int main() {
    int n, m, pos, newElement;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n + 1]; // +1 for inserting a new element

    printf("Enter how many elements (<= %d): ", n);
    scanf("%d", &m);

    printf("Enter %d elements:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position (0 to %d) where you want to insert: ", m);
    scanf("%d", &pos);

    if (pos < 0 || pos > m) {
        printf("Invalid position!\n");
        return 0;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &newElement);

    // Shift elements to make space
    for (int i = m; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = newElement;
    m++;

    printf("\nArray after insertion:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
