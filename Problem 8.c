//Declare an Array, take Size, Elements dynamically. Insert an
   //element in any of the Even index position except 0th index.
  // [Take the position dynamically]

#include <stdio.h>
int main() {
    int size, elements, position, NewElement;

    printf("Input the size of the array: ");
    scanf("%d", &size);

    printf("Input the number of elements you will be putting: ");
    scanf("%d", &elements);

    printf("Put the values one by one inside the array: ");
    int arr[size + 1];
    for(int i = 0 ; i < elements ; i++){
        scanf("%d", &arr[i]);
    }

    printf("The values of the array are: ");
    for(int i = 0 ; i < elements ; i++){
        printf("%d ", arr[i]);
    }

     printf("Put the position for your new value insertion (allowed human positions: 3,5,7,...): ");
    if (scanf("%d", &position) != 1) {
        printf("Invalid position input.\n");
        return 1;
    }

    /* convert to 0-based index */
    position--;

    if (position <= 0) {
        printf("Invalid: position refers to index 0 or negative. Use 3,5,7,... only.\n");
        return 1;
    }
    if ((position % 2) != 0) {
        /* position must be even (0-based) -> position%2 == 0 */
        printf("Invalid: chosen position is not an even index (0-based). Use human positions 3,5,7,...\n");
        return 1;
    }
    if (position > elements) {
        printf("Invalid: position outside current allowable range (max allowed human position is %d).\n", elements + 1);
        return 1;
    }

    /* Ensure there is room for one more element: we declared size+1 slots */
    if (elements >= size + 1) {
        printf("Array is full — cannot insert.\n");
        return 1;
    }

    /* Shift elements right to make space */
    for (int i = elements; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    printf("Put the NewElement value in the array: ");
    if (scanf("%d", &NewElement) != 1) {
        printf("Invalid new element input.\n");
        return 1;
    }

    arr[position] = NewElement;
    elements++;

    printf("The array values after insertion are: ");
    for (int i = 0; i < elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
