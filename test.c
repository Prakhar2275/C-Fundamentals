#include <stdio.h>

void shiftLeft(int arr[], int size) {
    // Save the first element to be placed at the end
    int first = arr[0];
    
    // Shift all elements to the left by one position
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Place the saved first element at the end
    arr[size - 1] = first;
}

int main() {
    int size;

    // Input size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Array size must be greater than 0.\n");
        return 1;
    }

    int arr[size];

    // Input elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform left shift
    shiftLeft(arr, size);

    // Output the shifted array
    printf("Shifted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
