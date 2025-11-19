//Declare an Array, take Size, Elements dynamically.
//Delete 2 even elements from the last position.
//If the array has only 1 even element, insert 2 elements in the middle & the very next index.
//If there is no even element, then delete the middle indexed element and insert a new element to the very next index of the middle index. [Take elements for insertion dynamically].
//Count odd and even elements in the array to solve the problem
#include <stdio.h>

int main() {
    int size, elements;

    // 1) Read capacity (size) and how many elements will be stored
    printf("Enter array capacity (size): ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Size must be positive.\n");
        return 0;
    }

    int arr[size];

    printf("How many elements will you insert (<= %d)? ", size);
    scanf("%d", &elements);

    if (elements < 0 || elements > size) {
        printf("Invalid number of elements.\n");
        return 0;
    }

    // 2) Read elements
    printf("Enter %d elements:\n", elements);
    for (int i = 0; i < elements; i++) {
        scanf("%d", &arr[i]);
    }

    // 3) Count even and odd
    int even_count = 0, odd_count = 0;
    for (int i = 0; i < elements; i++) {
        if (arr[i] % 2 == 0) even_count++;
        else odd_count++;
    }

    printf("\nInitial counts -> Even: %d, Odd: %d\n", even_count, odd_count);

    // Helper lambdas not available in C, so use inline code blocks.

    // CASE A: >= 2 even elements -> delete two even elements from the last (rightmost)
    if (even_count >= 2) {
        int to_delete = 2;
        for (int i = elements - 1; i >= 0 && to_delete > 0; i--) {
            if (arr[i] % 2 == 0) {
                // delete arr[i] by shifting left
                for (int j = i; j < elements - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                elements--;
                to_delete--;
            }
        }
        // recount
        even_count = 0; odd_count = 0;
        for (int i = 0; i < elements; i++) {
            if (arr[i] % 2 == 0) even_count++;
            else odd_count++;
        }
        printf("Deleted 2 even elements from the end.\n");
    }
    // CASE B: exactly 1 even element -> insert 2 elements at middle and middle+1
    else if (even_count == 1) {
        if (elements + 2 > size) {
            printf("Not enough capacity to insert 2 elements (capacity %d, used %d).\n", size, elements);
            // we could realloc, but assignment used VLA style; so we stop here.
        } else {
            int mid = elements / 2; // insert at mid and mid+1
            int a, b;
            printf("Array has exactly 1 even element.\n");
            printf("Enter 2 elements to insert at middle and next index:\n");
            scanf("%d %d", &a, &b);

            // shift right to make space for 2 elements
            for (int j = elements - 1; j >= mid; j--) {
                arr[j + 2] = arr[j];
            }
            arr[mid] = a;
            arr[mid + 1] = b;
            elements += 2;

            // recount
            even_count = 0; odd_count = 0;
            for (int i = 0; i < elements; i++) {
                if (arr[i] % 2 == 0) even_count++;
                else odd_count++;
            }
            printf("Inserted 2 elements at middle and next index.\n");
        }
    }
    // CASE C: zero even elements -> delete middle indexed element and insert a new element to the very next index of the middle index
    else { // even_count == 0
        if (elements == 0) {
            printf("Array is empty: nothing to delete or insert.\n");
        } else {
            int mid = elements / 2; // middle index (0-based)
            // delete arr[mid] by shifting left
            int deleted = arr[mid];
            for (int j = mid; j < elements - 1; j++) {
                arr[j] = arr[j + 1];
            }
            elements--;
            printf("No even elements. Deleted middle element (value %d at index %d).\n", deleted, mid);

            // now insert new element at the "very next index of the middle index"
            // After deletion, inserting at index 'mid' corresponds to original mid+1.
            if (elements + 1 > size) {
                printf("Not enough capacity to insert 1 element (capacity %d, used %d).\n", size, elements);
            } else {
                int newVal;
                printf("Enter 1 element to insert at the very next index of the middle: ");
                scanf("%d", &newVal);

                // shift right from end to mid to make space
                for (int j = elements - 1; j >= mid; j--) {
                    arr[j + 1] = arr[j];
                }
                arr[mid] = newVal;
                elements++;

                // recount
                even_count = 0; odd_count = 0;
                for (int i = 0; i < elements; i++) {
                    if (arr[i] % 2 == 0) even_count++;
                    else odd_count++;
                }
                printf("Inserted the new element after middle position.\n");
            }
        }
    }

    // Final output
    printf("\nFinal array (%d elements):\n", elements);
    for (int i = 0; i < elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nFinal counts -> Even: %d, Odd: %d\n", even_count, odd_count);

    return 0;
}
