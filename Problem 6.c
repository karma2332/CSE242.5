// Declare an Array, take Size, Elements dynamically.
// Insert an element in the last index.
#include <stdio.h>

int main() {
    int n, m;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter how many numbers will be there (0 <= %d): ", n);
    scanf("%d", &m);

    

    // +1 to ensure room for the new element to insert at the end
    int myNum[n + 1];

    printf("Enter the %d values: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &myNum[i]);
    }

    printf("The %d values of the array are: ", m);
    for (int i = 0; i < m; i++) {
        printf("%d ", myNum[i]);
    }
    printf("\n");

    // Insert a new element at the "last index" (end of the current elements)
    int newElement;
    printf("Enter an element to insert at the end: ");
    scanf("%d", &newElement);

    myNum[m] = newElement; // place at index m (after the current last)
    m++;                   // now array has m elements

    printf("Array after insertion: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", myNum[i]);
    }
    printf("\n");

    return 0;
}
