#include <stdio.h>

int main() {
    int n, m;

    printf("Enter the size of the array : ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter how many number will be there 0<=%d: ", n);
    if (scanf("%d", &m) != 1 || m < 0 || m > n) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    int myNum[n];

    if (m > 0) {
        printf("Enter the %d values: ", m);
        for (int i = 0; i < m; i++) {
            if (scanf("%d", &myNum[i]) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
        }
    }

    printf("The %d values of the array are: ", m);
    for (int i = 0; i < m; i++) {
        printf("%d ", myNum[i]);
    }
    printf("\n");

    /* Insertion Sort (ascending) - sort only the m elements entered */
    for (int i = 1; i < m; i++) {
        int key = myNum[i];
        int j = i - 1;
        while (j >= 0 && myNum[j] > key) {
            myNum[j + 1] = myNum[j]; // shift right
            j--;
        }
        myNum[j + 1] = key; // insert key in correct place
    }

    printf("After insertion sort: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", myNum[i]);
    }
    printf("\n");

    return 0;
}
