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

    /* Bubble sort on the actual element count m */
    int n1 = m;  //Putting my array values into a new variable

    while (n1 > 1) { //this loop keeps running as long as there is more than 1 element left to check.
        for (int i = 0; i < n1 - 1; i++) {
            if (myNum[i] > myNum[i + 1]) {
                int temp = myNum[i];
                myNum[i] = myNum[i + 1];
                myNum[i + 1] = temp;
            }
        }
        n1--;   // pass number decreasing
    }

    printf("Sorted array: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", myNum[i]);
    }
    printf("\n");

    return 0;
}
