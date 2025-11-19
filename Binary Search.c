#include <stdio.h>

int main() {
    int size, elements, key;
    int low, high, mid;
    int found = -1;

    // Take size
    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];

    // How many elements
    printf("How many elements (<= %d)? ", size);
    scanf("%d", &elements);

    // Take elements (MUST be sorted)
    printf("Enter %d sorted elements:\n", elements);
    for (int i = 0; i < elements; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = elements - 1;

    // Binary Search
    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            found = mid;
            break;
        }
        else if (key > arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (found != -1)
        printf("Element found at position: %d\n", found + 1);
    else
        printf("Element not found!\n");

    return 0;
}
