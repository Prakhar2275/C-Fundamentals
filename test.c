#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // For abs function

bool isWithin10Of100Or200(int number) {
    // Check if the number is within 10 of 100 or 200
    return (abs(number - 100) <= 10) || (abs(number - 200) <= 10);
}

int main() {
    int number;
    
    // Prompt user for input
    printf("Enter an integer: ");
    scanf("%d", &number);
    
    // Check and display result
    if (isWithin10Of100Or200(number)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    
    return 0;
}
