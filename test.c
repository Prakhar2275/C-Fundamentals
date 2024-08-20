#include <stdio.h>

// Function to check if a triple is present in the array
int hasTriple(int arr[], int size) {
    // Traverse the array
    for (int i = 0; i < size - 2; i++) {
        // Check if the current element and the next two elements are the same
        if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) {
            return 1; // Triple found
        }
    }
    return 0; // No triple found
}

int main() {
    int n;

    // Input size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Declare the array
    int arr[n];

    // Input the array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check if there is a triple in the array
    if (hasTriple(arr, n)) {
        printf("A triple is present in the array.\n");
    } else {
        printf("No triple is present in the array.\n");
    }

    return 0;
}
