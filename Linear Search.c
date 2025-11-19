#include <stdio.h>

int main() {
    int size, elements, key, found = -1;

    // Take size
    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];

    // How many elements to store
    printf("How many elements (<= %d)? ", size);
    scanf("%d", &elements);

    // Take elements
    printf("Enter %d elements:\n", elements);
    for (int i = 0; i < elements; i++) {
        scanf("%d", &arr[i]);
    }

    // Take element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Linear Search
    for (int i = 0; i < elements; i++) {
        if (arr[i] == key) {
            found = i;   // store index
            break;
        }
    }

    if (found != -1)
        printf("Element found at position: %d\n", found + 1);
    else
        printf("Element not found!\n");

    return 0;
}
